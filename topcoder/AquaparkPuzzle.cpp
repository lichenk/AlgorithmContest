#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class AquaparkPuzzle {
	public:
	int countSchedules(int k, int m, vector <int> c) {
		
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
		cout << "Testing AquaparkPuzzle (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453356193;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AquaparkPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 3;
				int m = 3;
				int c[] = {1, 2};
				_expected = 16;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int k = 3;
				int m = 3;
				int c[] = {2, 2};
				_expected = 0;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int k = 4;
				int m = 3;
				int c[] = {1, 2, 2};
				_expected = 66;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int k = 6;
				int m = 7;
				int c[] = {2, 3, 4, 7};
				_expected = 4800;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int k = 1000;
				int m = 20;
				int c[] = {8, 2, 13, 18, 7, 3};
				_expected = 15681195;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int k = ;
				int m = ;
				int c[] = ;
				_expected = ;
				_received = _obj.countSchedules(k, m, vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
