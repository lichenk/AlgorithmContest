#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class Singing {
	public:
	int solve(int N, int low, int high, vector <int> pitch) {
		
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
		cout << "Testing Singing (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452489100;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Singing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int low = 2;
				int high = 2;
				int pitch[] = {1,2,3,2,1,2};
				_expected = 2;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 10;
				int low = 3;
				int high = 7;
				int pitch[] = {4,4,5,5,6,5,3,6};
				_expected = 0;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 6;
				int low = 2;
				int high = 5;
				int pitch[] = {5,3,1,6,4,2};
				_expected = 1;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 10;
				int low = 4;
				int high = 5;
				int pitch[] = {1,4,3,5,2,5,7,5,9};
				_expected = 3;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 100;
				int low = 20;
				int high = 80;
				int pitch[] = {2,27,3,53,53,52,52,60,85,89,100,53,60,2,3,53,100,89,40,42,2,53,2,85};
				_expected = 5;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int low = ;
				int high = ;
				int pitch[] = ;
				_expected = ;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int low = ;
				int high = ;
				int pitch[] = ;
				_expected = ;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int low = ;
				int high = ;
				int pitch[] = ;
				_expected = ;
				_received = _obj.solve(N, low, high, vector <int>(pitch, pitch+sizeof(pitch)/sizeof(int))); break;
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
