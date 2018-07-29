#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class WheelofFortune {
	public:
	double maxExpectedValue(int N, vector <int> s) {
		
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
		cout << "Testing WheelofFortune (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453599719;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WheelofFortune _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int s[] = {2};
				_expected = 1.25;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 6;
				int s[] = {1,1,1,1,1,1};
				_expected = 2.0000000000000004;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 20;
				int s[] = {1,20,1,20,1};
				_expected = 4.299999999999999;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 10;
				int s[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5};
				_expected = 31.973469385798197;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 15;
				int s[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
				_expected = 16.691531334568044;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int s[] = ;
				_expected = ;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int s[] = ;
				_expected = ;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int s[] = ;
				_expected = ;
				_received = _obj.maxExpectedValue(N, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
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
