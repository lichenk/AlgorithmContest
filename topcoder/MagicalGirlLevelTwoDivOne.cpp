#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll a[55][55];
ll q[55][55];
ll fr[55][55];
ll dp[2][2][1<<10];
ll g[2][2502];
class MagicalGirlLevelTwoDivOne {
	public:
	int theCount(vector <string> palette, int n, int m) {
		g[0][0]=1; g[1][0]=1;
		for (ll x=0;x<2501;x++) {
			g[0][x+1]=(g[0][x]*4)%MOD;
			g[1][x+1]=(g[1][x]*5)%MOD;
		}
		ll h=palette.size(),w=palette[0].length();
		for (ll x=0;x<h;x++) {
			for (ll y=0;y<w;y++) {
				char c=palette[x][y];
				if (c=='.') a[x][y]=-1;
				else a[x][y]=(1+(c-'1'))%2;
			}
		}
		memset(q,-1,sizeof q);
		memset(fr,0,sizeof fr);
		for (ll x=0;x<h;x++) {
			for (ll y=0;y<w;y++) {
				if (a[x][y]!=-1) {
					if (q[x%n][y%m]!=-1&&q[x%n][y%m]!=a[x][y]) return 0;
					q[x%n][y%m]=a[x][y];
				}
				else {
					fr[x%n][y%m]++;
				}
			}
		}
		memset(dp[0],0,sizeof dp[0]);
		dp[0][0][0]=1;
		ll cur=0,nxt=1;
		ll zlim=1<<m;
		//printf("%d %d\n",n,m);
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				ll fre=fr[x][y];
				ll g0=g[0][fre];
				ll g1=g[1][fre];
				//printf("x:%d y:%d q:%d f:%d\n",x,y,q[x][y],fr[x][y]);
				memset(dp[nxt],0,sizeof dp[nxt]);
				for (ll k=0;k<2;k++) for (ll z=0;z<zlim;z++) {
					ll v=dp[cur][k][z]%MOD;
					if (q[x][y]!=1) {
						dp[nxt][k][z]+=(v*g0)%MOD;
					}
					if (q[x][y]!=0) {
						dp[nxt][k^1][z^(1LL<<y)]+=(v*g1)%MOD;
					}
				}
				swap(cur,nxt);
			}
			for (ll z=0;z<zlim;z++) dp[cur][0][z]=dp[cur][1][z];
			memset(dp[cur][1],0,sizeof dp[cur][1]);
		}
		ll final=dp[cur][0][zlim-1]%MOD;
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
		cout << "Testing MagicalGirlLevelTwoDivOne (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483849151;
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
		MagicalGirlLevelTwoDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string palette[] = {"12",
				                    "2."};
				int n = 2;
				int m = 2;
				_expected = 5;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 1:
			{
				string palette[] = {"21",
				                    "1."};
				int n = 2;
				int m = 2;
				_expected = 4;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 2:
			{
				string palette[] = {"...",
				                    "...",
				                    "..."};
				int n = 1;
				int m = 1;
				_expected = 1953125;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 3:
			{
				string palette[] = {"..58..",
				                    "..47.."};
				int n = 2;
				int m = 3;
				_expected = 0;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 4:
			{
				string palette[] = {"...1.2.3",
				                    "4.5.6...",
				                    "...7.8.9",
				                    "1.2.3..."};
				int n = 4;
				int m = 4;
				_expected = 886073030;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 5:
			{
				string palette[] = {"....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "....................",
				                    "...................."};
				int n = 10;
				int m = 10;
				_expected = 240076532;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 6:
			{
				string palette[] = {"."};
				int n = 1;
				int m = 1;
				_expected = 5;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 7:
			{
				string palette[] = {"..",".."};
				int n = 1;
				int m = 1;
				_expected = 5*5*5*5;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 8:
			{
				string palette[] = {".."};
				int n = 1;
				int m = 1;
				_expected = 5*5;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
			}
			case 9:
			{
				string palette[] = {".","."};
				int n = 1;
				int m = 1;
				_expected = 5*5;
				_received = _obj.theCount(vector <string>(palette, palette+sizeof(palette)/sizeof(string)), n, m); break;
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
