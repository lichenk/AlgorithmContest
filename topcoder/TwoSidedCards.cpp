#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=100+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
	int got=1;
	for (int x=0;x<=MAXFACT;x++) {
		fact[x]=got;
		got=mul(got,x+1);
	}
	got=mod_pow(got,MOD-2,MOD);
	for (int x=MAXFACT;x>=0;x--) {
		got=mul(got,x+1);
		invfact[x]=got;
	}
}

const int mn=54;
vector<int> gr[mn];
bool seen[mn];
int cyc;
int dfs(int x, int p) {
	if (seen[x]) {
		cyc=1; return 0;
	}
	seen[x]=true;
	int ans=1;
	for (auto &y:gr[x]) {
		if (y==p) continue;
		ans+=dfs(y,x);
	}
	return ans;
}

int modinv(int x) {
	return mod_pow(x,MOD-2,MOD);
}
int inv2;
int g[2][mn][2];
void go2(int n) {
	memset(g,0,sizeof g);
	g[0][0][1]=1;
	g[1][0][0]=1;
	for (int k=0;k<2;k++) for (int x=0;x<=n;x++) {
		for (int h=0;h<2;h++) {
			int ff=g[k][x][h];
			//printf("k:%d x:%d h:%d ff:%d\n",k,x,h,ff);
			for (int t=0;t<2;t++) {
				int s=h+t;
				int toadd=ff;
				if (s==2) toadd=mul(toadd,inv2);
				g[k][x+1][1-t]+=toadd;
				g[k][x+1][1-t]%=MOD;
			}
		}
	}
}

int getcyc(int n) {
	ll ans=0;
	for (int s=0;s<1;s++) {
		for (int e=0;e<2;e++) {
			//if (n==2&&s==1&&e==0) continue;
			int c=g[s][n-1][e];
			int last=(s+e);
			if (last==2) c*=inv2; c%=MOD;
			int got=mul(1,c);
			//printf("n:%d s:%d e:%d got:%d\n",n,s,e,mul(fact[n],got));
			ans+=got;
		}
	}
	ans*=2;
	ans--;
	ans%=MOD;
	if (ans<0) ans+=MOD;
	return ans%MOD;
}
int f[mn][2];
void go(int n) {
	memset(f,0,sizeof f);
	f[0][0]=1;
	for (int x=0;x<=n;x++) {
		for (int h=0;h<2;h++) {
			int ff=f[x][h];
			//printf("x:%d h:%d ff:%d\n",x,h,ff);
			for (int t=0;t<2;t++) {
				int s=h+t;
				int toadd=ff;
				if (s==2) toadd=mul(toadd,inv2);
				f[x+1][1-t]+=toadd;
				f[x+1][1-t]%=MOD;
			}
		}
	}
}

int getpath(int n) {
	int c0=f[n-1][0];
	int c1=f[n-1][1];
	//printf("c0:%d c1:%d\n",c0,c1);
	int ans0=mul(1,c0);
	int ans1=mul(1,c1);
	int ans=ans0+ans1;
	return ans%MOD;
}
int brute(vector<int> a, vector<int> b) {
	set<vector<int> > ss;
	int n=a.size();
	vector<int> p;
	for (int i=0;i<n;i++) p.PB(i);
	do {
		for (int z = 0; z < (1 << n); z++) {
			vector<int> t;
			for (int i=0;i<n;i++) {
				if (z&(1<<i)) t.PB(a[p[i]]);
				else t.PB(b[p[i]]);
			}
			ss.insert(t);
		}
	} while(next_permutation(p.begin(),p.end()));
	/*for (auto &w:ss) {
		for (auto &ww:w) printf("%d",ww);
		printf("\n");
	}*/
	return ss.size()%MOD;
}
class TwoSidedCards {
	public:
	int theCount(vector <int> a, vector <int> b) {
		inv2=modinv(2);
		init();
		int n=a.size();
		for (int i=0;i<n;i++) {
			int x=a[i],y=b[i];
			gr[x].PB(y); gr[y].PB(x);
		}
		go(n+1);
		go2(n+1);
		ll final=1;
		for (int x=1;x<=n;x++) {
			if (seen[x]) continue;
			cyc=0;
			int len=dfs(x,-1);
			//printf("len:%d cyc:%d\n",len,cyc);
			ll got;
			if (cyc&&len>1) {
				got=getcyc(len);
			}
			else got=getpath(len);
			final=mul(final,got);
		}
		final=mul(final,fact[n]);
		int bf=brute(a,b);
		if (final!=bf) {
			for (auto &w:a) printf("%d ",w); printf("\n");
			for (auto &w:b) printf("%d ",w); printf("\n");
			printf("final:%lld bf:%d\n", final,bf);
		}
		printf("OK ok\n", final,bf);
		return final%MOD;
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
		cout << "Testing TwoSidedCards (600.0 points)" << endl << endl;
		for (int i = 0; i < 50; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1506959317;
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
		TwoSidedCards _obj;
		int _expected, _received;
		time_t _start = clock();
		_tc=-1;
		switch (_tc)
		{
			case -1:
			{
				srand(clock()+rand());
				int n=rand()%7+1;
				vector<int> a;
				for (int i=0;i<n;i++) a.PB(i+1);
				srand(clock()+rand());
				random_shuffle(a.begin(),a.end());
				vector<int> b=a;
				srand(clock()+rand());
				random_shuffle(b.begin(),b.end());
				_received = _obj.theCount(a,b);
				exit(0);
			}
			case 0:
			{
				int taro[] = {1, 2, 3};
				int hanako[] = {1, 3, 2};
				_expected = 12;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 1:
			{
				int taro[] = {1, 2, 3};
				int hanako[] = {1, 2, 3};
				_expected = 6;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 2:
			{
				int taro[] = {1, 2};
				int hanako[] = {2, 1};
				_expected = 4;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 3:
			{
				int taro[] = {5, 8, 1, 2, 3, 4, 6, 7};
				int hanako[] = {1, 2, 3, 4, 5, 6, 7, 8};
				_expected = 2177280;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 4:
			{
				int taro[] = {41, 22, 17, 36, 26, 15, 10, 23, 33, 48, 49, 9, 34, 6, 21, 2, 46, 16, 25, 3, 24, 13, 40, 37, 35,
				             50, 44, 42, 31, 12, 29, 7, 43, 18, 30, 19, 45, 32, 39, 14, 8, 27, 1, 5, 38, 11, 4, 20, 47, 28};
				int hanako[] = {19, 6, 23, 35, 17, 7, 50, 2, 33, 36, 12, 31, 46, 21, 30, 13, 47, 22, 44, 4, 25, 24, 3, 15, 20,
				               48, 10, 28, 26, 18, 5, 45, 49, 16, 40, 42, 43, 14, 1, 37, 29, 8, 41, 38, 9, 11, 34, 32, 39, 27};
				_expected = 529165844;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 5:
			{
				int taro[] = {1};
				int hanako[] = {2};
				_expected = 2;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 6:
			{
				int taro[] = {1,2};
				int hanako[] = {2,3};
				_expected = 7;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 7:
			{
				int taro[] = {1,2};
				int hanako[] = {2,1};
				_expected = 4;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 8:
			{
				int taro[] = {1,2,3};
				int hanako[] = {2,3,1};
				_expected = 24;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			case 9:
			{
				int taro[] = {1,2,3,4};
				int hanako[] = {2,3,4,1};
				_expected = 180;
				_received = _obj.theCount(vector <int>(taro, taro+sizeof(taro)/sizeof(int)), vector <int>(hanako, hanako+sizeof(hanako)/sizeof(int))); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
