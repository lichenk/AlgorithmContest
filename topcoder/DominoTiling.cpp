#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[2][1<<12];
class DominoTiling {
	public:
	long long count(vector <string> grid) {
		int rn=grid.size(),cn=grid[0].length();
		int zlim=1<<cn;
		int cur=0,nxt=1;
		f[cur][0]=1;
		for (int r=0;r<rn;r++) {
			for (int c=0;c<cn;c++) {
				memset(f[nxt],0,sizeof f[nxt]);
				bool curo=grid[r][c]=='.';
				bool righto=(c!=cn-1)&&(grid[r][c+1]=='.');
				bool downo=(r!=rn-1)&&(grid[r+1][c]=='.');
				for (int z=0;z<zlim;z++) {
					ll now=f[cur][z];
					if (((z&1)==0)&&curo) { // Current uncovered
						if (downo) { // Go down
							int nz=(z>>1)|(1<<(cn-1));
							f[nxt][nz]+=now;
						}
						if (righto&&(0==(z&2))) { // Go right
							int nz=(z>>1)|1;
							f[nxt][nz]+=now;
						}
					}
					else { // Covered
						int nz=z>>1;
						f[nxt][nz]+=now;
					}
				}
				swap(cur,nxt);
			}
		}
		ll ans=f[cur][0];
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
		cout << "Testing DominoTiling (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520821234;
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
		DominoTiling _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"..",
				                 ".."};
				_expected = 2LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"...",
				                 ".X.",
				                 "..."};
				_expected = 2LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"...",
				                 "...",
				                 "..X"};
				_expected = 4LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".....",
				                 ".....",
				                 ".X...",
				                 ".X..."};
				_expected = 29LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"."};
				_expected = 0LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 5:
			{
				string grid[] = {"X"};
				_expected = 1LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 6:
			{
				string grid[] = {
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
					"............",
			};
				_expected = 0LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
