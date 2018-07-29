#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[54][54];
class TwoConvexShapes {
	public:
	int countWays(vector <string> _grid) {
		ll ylim=_grid.size();
		ll xlim=_grid[0].length();
		ll final=0;
		char loc='W',upc='B';
		for (ll t=0;t<3;t++) {
			for (ll k=0;k<2;k++) {
				//printf("t:%lld loc:%c upc:%c\n",t,loc,upc);
				for (ll x=0;x<=xlim;x++) for (ll y=0;y<=ylim;y++) f[x][y]=0;
				f[0][0]=1;
				for (ll x=0;x<xlim;x++) {
					for (ll sy=0;sy<=ylim;sy++) {
						for (ll ny=sy;ny<=ylim;ny++) {
							if (x==0&&ny==ylim) continue;
							if (t==2&&x>0) {
								bool ok=false;
								if (ny==sy) ok=true;
								if (sy==0&&ny==ylim) ok=true;
								if (!ok) continue;
							}
							bool ok=true;
							ll gx=(t==1)?xlim-1-x:x;
							for (ll y=0;y<ny;y++) {
								if (_grid[y][gx]==upc) {
									//printf("Consider %lld %lld->%lld %lld: %lld\n",x,sy,x+1,ny,y);
									ok=false; break;
								}
							}
							for (ll y=ny;y<ylim;y++) {
								if (_grid[y][gx]==loc) {
									//printf("Consider %lld %lld->%lld %lld: %lld\n",x,sy,x+1,ny,y);
									ok=false; break;
								}
							}
							if (ok) {
								//printf("%lld %lld->%lld %lld: %lld\n",x,sy,x+1,ny,f[x][sy]);
								f[x+1][ny]+=f[x][sy];
								f[x+1][ny]%=MOD;
							}
						}
					}
				}
				ll ans=0;
				for (ll y=0;y<=ylim;y++) {
					ans=(ans+f[xlim][y])%MOD;
				}
				//printf("t:%lld loc:%c upc:%c ans:%lld\n\n",t,loc,upc,ans);
				if (t==2) ans=MOD-ans;
				final=(final+ans)%MOD;
				swap(loc,upc);
			}
		}
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
		cout << "Testing TwoConvexShapes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469678969;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TwoConvexShapes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"??",
				                 "??"};
				_expected = 14;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"B?",
				                 "??"};
				_expected = 7;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"WWB",
				                 "WWW",
				                 "WWW",
				                 "WWW"};
				_expected = 1;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"BBBBBB",
				                 "WWBBBB",
				                 "WBBBBB"};
				_expected = 0;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"?BB?",
				                 "BBBB",
				                 "?BB?"};
				_expected = 5;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 5:
			{
				string grid[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"};
				_expected = 73741817;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 6:
			{
				string grid[] = {"B"};
				_expected = 1;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 7:
			{
				string grid[] = {"?"};
				_expected = 2;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 8:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
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
