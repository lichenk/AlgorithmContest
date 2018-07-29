#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
#define fst first
#define snd second
const ll maxn=55;
ld sumLinear[maxn][2][maxn];
ld sumSquare[maxn][2][maxn];
ll num[maxn][2][maxn];
ld weightSquared[maxn][2][maxn];
ll gn;
vector<ll> g[maxn];
vector<ll> gweight;
ld variance=0;
ll normalizer=0;
void dfs(ll x, ll p) {
	ll cur=1,nxt=0;
	memset(sumLinear[x][nxt],0,sizeof sumLinear[x][nxt]);
	memset(sumSquare[x][nxt],0,sizeof sumSquare[x][nxt]);
	memset(num[x][nxt],0,sizeof num[x][nxt]);
	memset(weightSquared[x][nxt],0,sizeof weightSquared[x][nxt]);
	swap(cur,nxt);
	sumLinear[x][cur][1]=gweight[x];
	sumSquare[x][cur][1]=gweight[x]*gweight[x];
	weightSquared[x][cur][1]=gweight[x]*gweight[x];
	num[x][cur][1]=1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs(y,x);
	}
	for (auto &y:g[x]) {
		if (y==p) continue;
		memset(sumLinear[x][nxt],0,sizeof sumLinear[x][nxt]);
		memset(sumSquare[x][nxt],0,sizeof sumSquare[x][nxt]);
		memset(num[x][nxt],0,sizeof num[x][nxt]);
		memset(weightSquared[x][nxt],0,sizeof weightSquared[x][nxt]);
		for (ll curnodes=0;curnodes<=gn;curnodes++) {
			for (ll childnodes=0;childnodes<=gn;childnodes++) {
				ll sumnodes=curnodes+childnodes;
				ld curSumLinear=sumLinear[x][cur][curnodes];
				ld curSumSquare=sumSquare[x][cur][curnodes];
				ll curNum=num[x][cur][curnodes];
				ld curWeightSquared=weightSquared[x][cur][curnodes];
				ld childSumLinear=sumLinear[y][0][childnodes];
				ld childSumSquare=sumSquare[y][0][childnodes];
				ll childNum=num[y][0][childnodes];
				ld childWeightSquared=weightSquared[y][0][childnodes];
				sumLinear[x][nxt][sumnodes]+=curSumLinear*(childNum)+childSumLinear*curNum;
				sumSquare[x][nxt][sumnodes]+=curSumSquare*(childNum)+childSumSquare*curNum+2*curSumLinear*childSumLinear;
				weightSquared[x][nxt][sumnodes]+=curWeightSquared*(childNum)+childWeightSquared*curNum;
				num[x][nxt][sumnodes]+=curNum*(childNum);
			}
		}
		swap(cur,nxt);
	}
	if (cur==1) {
		memcpy(sumLinear[x][0],sumLinear[x][1],sizeof sumLinear[x][1]);
		memcpy(sumSquare[x][0],sumSquare[x][1],sizeof sumSquare[x][1]);
		memcpy(num[x][0],num[x][1],sizeof num[x][1]);
		memcpy(weightSquared[x][0],weightSquared[x][1],sizeof weightSquared[x][1]);
	}
	for (ll nodes=1;nodes<=gn;nodes++) {
		ld EX2=weightSquared[x][cur][nodes]/nodes;
		ld EXSquared=sumSquare[x][cur][nodes]/(nodes*nodes);
		//printf("x:%lld nodes:%lld %f %f. norm:%f\n",x,nodes,
		//	(double)weightSquared[x][cur][nodes],(double)sumSquare[x][cur][nodes],(double)num[x][cur][nodes]);
		variance+=EX2-EXSquared;
		normalizer+=num[x][cur][nodes];
	}
	num[x][0][0]=1;
}
class AverageVarianceSubtree {
	public:
	double average(vector <int> p, vector <int> weight) {
		ll n=weight.size();
		gn=n;
		for (ll x=0;x<n-1;x++) {
			g[x+1].PB(p[x]);
			g[p[x]].PB(x+1);
		}
		for (auto &w:weight) gweight.PB(w);
		long double avg=0;
		for (auto &w:gweight) avg+=w;
		avg/=n;
		ll ravg=round(avg);
		for (auto &w:gweight) w-=ravg;
		dfs(0,-1);
		return variance/normalizer;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing AverageVarianceSubtree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1492704329;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AverageVarianceSubtree _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1};
				int weight[] = {10,20,30};
				_expected = 19.444444444444443;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,1};
				int weight[] = {10,20,7,6};
				_expected = 23.0145202020202;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0};
				int weight[] = {1,1000000000};
				_expected = 8.3333333166666672E16;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,1,0,2,3,3,6};
				int weight[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
				_expected = 4.432586365551198E14;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {};
				int weight[] = {712};
				_expected = 0.0;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 5:
			{
				int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48};
				int weight[] = {999999999, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				_expected = 0.0022541745919277614;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 6:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
