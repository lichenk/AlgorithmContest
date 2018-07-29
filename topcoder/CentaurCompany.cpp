#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=40;
vector<ll> g[MAXN];
ll col[MAXN];
vector<ll> v[2];
void dfs(ll x, ll p, ll c) {
	col[x]=c;
	for (auto &w:g[x]) {
		if (w==p) continue;
		dfs(w,x,c^1);
	}
}
bool h[MAXN][MAXN];
const ll BASE=(36*2);
const ll MAXK=BASE+(36*3);
ld f[2][MAXK];
class CentaurCompany {
	public:
	double getvalue(vector <int> a, vector <int> b) {
		ll n=a.size()+1;
		for (ll i=0;i<n-1;i++) {a[i]--;b[i]--;}
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				h[x][y]=false;
			}
		}
		for (ll i=0;i<n-1;i++) {
			ll x=a[i],y=b[i];
			g[x].PB(y); g[y].PB(x);
			h[x][y]=true; h[y][x]=true;
		}
		dfs(0,-1,0);
		for (ll x=0;x<n;x++) {
			v[col[x]].PB(x);
		}
		if (v[0].size()>v[1].size()) swap(v[0],v[1]);
		ll v0sz=v[0].size();
		ll v1sz=v[1].size();
		ll zlim=1ULL<<v0sz;
		ld final=0;
		for (ll z=0;z<zlim;z++) {
			for (ll k=0;k<MAXK;k++) {f[0][k]=0;}
			ll sk=__builtin_popcountll(z)-2+BASE;
			f[0][sk]=1;
			ll mink=sk,maxk=sk;
			for (ll t=0;t<v1sz;t++) {
				ll cur=t%2, nxt=(t+1)%2;
				ll e=0;
				ll y=v[1][t];
				for (ll i=0;i<v0sz;i++) {
					if (z&(1ULL<<i)) {
						ll x=v[0][i];
						if (h[x][y]) e++;
					}
				}
				ll diff=1-2*e;
				chkmin(mink,mink+diff);
				chkmax(maxk,maxk+diff);
				for (ll k=0;k<MAXK;k++) {f[nxt][k]=0;}
				for (ll k=mink;k<=maxk;k++) {
					ld val=f[cur][k]/2;
					ll nk=k+1-2*e;
					f[nxt][nk]+=val;
					f[nxt][k]+=val;
				}
			}
			{
				ll cur=v1sz%2;
				for (ll k=BASE+1;k<MAXK;k++) {
					final+=f[cur][k]*(k-BASE);
				}
			}
		}
		final/=(ld)zlim;
		final *=2;
		return final;
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
		cout << "Testing CentaurCompany (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460311368;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CentaurCompany _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1};
				int b[] = {2};
				_expected = 0.0;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {1,1,1};
				int b[] = {2,3,4};
				_expected = 0.125;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1,2,3,2,2};
				int b[] = {2,3,4,5,6};
				_expected = 0.375;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1,2,3,4,5,6,7,8,9};
				int b[] = {2,3,4,5,6,7,8,9,10};
				_expected = 0.41796875;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int b[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
				_expected = 15.500000001076842;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
				int b[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
				_expected = 0.646484375;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {1, 29, 34, 17, 13, 22, 18, 5, 35, 14, 10, 33, 23, 27, 13, 14, 32, 32, 18, 15, 33, 2, 9, 35, 8, 21, 12, 22, 33, 1, 24, 17, 7, 29, 23};
				int b[] = {31, 3, 8, 32, 31, 11, 8, 34, 36, 29, 2, 2, 28, 10, 30, 31, 31, 4, 36, 13, 25, 26, 32, 19, 33, 7, 21, 14, 7, 23, 7, 16, 20, 6, 33};
				_expected = 2.7784599020669702;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getvalue(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
