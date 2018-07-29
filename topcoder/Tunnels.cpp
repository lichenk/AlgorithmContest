#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class Tunnels {
	public:
	int minimumTunnels(vector <string> frame) {
		
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
		cout << "Testing Tunnels (1050.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737043;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1050.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Tunnels _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string frame[] = {"XXX.XXXX.....X",
				                  "..X....XXX...X",
				                  "XXX......X...."};
				_expected = 3;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 1:
			{
				string frame[] = {".......X.....",
				                  ".............",
				                  "XXX.XXXXXXXXX"};
				_expected = 3;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 2:
			{
				string frame[] = {".............",
				                  "XXXXXXXXXXXXX",
				                  ".............",
				                  "XXX.......XXX",
				                  "..........X..",
				                  "..........XXX"};
				_expected = 2;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 3:
			{
				string frame[] = {"XXXX...X..",
				                  "....XXXX.X",
				                  "XX.......X",
				                  "..........",
				                  "....XXXXXX"};
				_expected = 4;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 4:
			{
				string frame[] = {"X........X..",
				                  ".........XXX",
				                  "............",
				                  "XXXXXXXXXXXX",
				                  "............",
				                  "XXXXXXXXXXXX",
				                  "............",
				                  ".........XXX",
				                  "..XXXXXXXX.."};
				_expected = 2;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 5:
			{
				string frame[] = {"...............X.X....X",
				                  "XXXXX..........X.......",
				                  "....X..................",
				                  "XXX.X.........XXXXXXXXX",
				                  "..X.X.........X........",
				                  "XXX.X.........XXXXXXXXX",
				                  "....X..................",
				                  "XXXXX......XXXXXXXXXXXX"};
				_expected = 5;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 6:
			{
				string frame[] = {".",
				                  "X",
				                  "X",
				                  ".",
				                  "X"};
				_expected = 1;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 7:
			{
				string frame[] = {"X.XX",
				                  "X...",
				                  "...X",
				                  "X...",
				                  "X..X"};
				_expected = 3;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			case 8:
			{
				string frame[] = {"...",
				                  "..."};
				_expected = 0;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}
			/*case 9:
			{
				string frame[] = ;
				_expected = ;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string frame[] = ;
				_expected = ;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string frame[] = ;
				_expected = ;
				_received = _obj.minimumTunnels(vector <string>(frame, frame+sizeof(frame)/sizeof(string))); break;
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
