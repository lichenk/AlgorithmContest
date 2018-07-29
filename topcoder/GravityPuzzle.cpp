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
class GravityPuzzle {
	public:
	int count(vector <string> board) {
		
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
		cout << "Testing GravityPuzzle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517249861;
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
		GravityPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#...",
				                  "....",
				                  "...."};
				_expected = 12;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {".#."};
				_expected = 1;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"#.",
				                  "##"};
				_expected = 4;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".##",
				                  "..#",
				                  "..."};
				_expected = 72;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".##########.",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............"};
				_expected = 999999937;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"."};
				_expected = 1;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"###.",
				                  "#...",
				                  "...."};
				_expected = 348;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"###.",
				                  "##..",
				                  "...."};
				_expected = 396;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"###.",
				                  "##..",
				                  "#..."};
				_expected = 648;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 9:
			{
				string board[] = {"#...",
				                  "##..",
				                  "#..."};
				_expected = 96;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 10:
			{
				string board[] = {"#...",
				                  "###.",
				                  "#..."};
				_expected = 64;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 11:
			{
				string board[] = {"############",
				                  ".###########",
				                  ".......#####",
				                  "........####",
				                  "...........#",
				                  "...........#",
				                  "............",
				                  "............",
				                  "............",
				                  "............"};
				_expected = 338007305;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 12:
			{
				string board[] = {"############",
				                  ".####.######",
				                  "..#.#..#####",
				                  "..#.#...####",
				                  "....#......#",
				                  "...........#",
				                  "............",
				                  "............",
				                  "............",
				                  "............"};
				_expected = 877681179;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
