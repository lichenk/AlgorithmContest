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
class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) {
		ll rlim=grid.size(),clim=grid[0].length();
		vector<pair<ll,ll> > vr,vc;
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				if (grid[r][c]=='o') {
					vr.PB(MP(r,c));
					vc.PB(MP(c,r));
				}
			}
		}
		sort(vr.begin(),vr.end()); sort(vc.begin(),vc.end());
		ll k=vr.size();
		ll ans=INF;
		for (ll r=0;r<rlim;r++) {
			for (ll sc=0;sc<=clim-k;sc++) {
				ll idx=0;
				ll cand=0;
				for (ll c=sc;c<sc+k;c++) {
					ll x=vc[idx].second,y=vc[idx].first;
					cand+=abs(x-r)+abs(y-c);
					idx++;
				}
				//if (cand==0) printf("r:%lld sc:%lld\n",r,sc);
				chkmin(ans,cand);
			}
		}
		for (ll c=0;c<clim;c++) {
			for (ll sr=0;sr<=rlim-k;sr++) {
				ll idx=0;
				ll cand=0;
				for (ll r=sr;r<sr+k;r++) {
					ll x=vr[idx].first,y=vr[idx].second;
					cand+=abs(x-r)+abs(y-c);
					idx++;
				}
				//if (cand==0) printf("c:%lld sr:%lld\n",c,sr);
				chkmin(ans,cand);
			}
		}
		return ans;
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
		cout << "Testing DucksAlignment (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472657694;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DucksAlignment _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {".o",
				                 "o."};
				_expected = 1;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {".o...",
				                 "..o..",
				                 "....o"};
				_expected = 3;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"o..........",
				                 "..o........",
				                 ".......o...",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "........o..",
				                 "..........."};
				_expected = 16;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".........",
				                 "....o....",
				                 "........."};
				_expected = 0;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"...o..........................",
				                 "............................o.",
				                 ".o............................",
				                 "............o.................",
				                 ".................o............",
				                 "......................o.......",
				                 "......o.......................",
				                 "....o.........................",
				                 "...............o..............",
				                 ".......................o......",
				                 "...........................o..",
				                 ".......o......................"};
				_expected = 99;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
