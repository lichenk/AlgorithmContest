#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class BearAttacks {
	public:
	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH) {
		
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
		cout << "Testing BearAttacks (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449389961;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearAttacks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int R0 = 0;
				int A = 2;
				int B = 3;
				int M = 100;
				int LOW = 938593850;
				int HIGH = 1000000000;
				_expected = 21;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 1:
			{
				int N = 3;
				int R0 = 0;
				int A = 0;
				int B = 0;
				int M = 1;
				int LOW = 0;
				int HIGH = 0;
				_expected = 23;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 2:
			{
				int N = 6;
				int R0 = 303840291;
				int A = 848660283;
				int B = 395739574;
				int M = 950123456;
				int LOW = 0;
				int HIGH = 1000000000;
				_expected = 3856;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 3:
			{
				int N = 1;
				int R0 = 0;
				int A = 0;
				int B = 0;
				int M = 1;
				int LOW = 0;
				int HIGH = 0;
				_expected = 1;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 4:
			{
				int N = 19;
				int R0 = 384038999;
				int A = 938592393;
				int B = 692854433;
				int M = 1000000000;
				int LOW = 300000000;
				int HIGH = 600000000;
				_expected = 473263988;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			/*case 5:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}*/
			/*case 6:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}*/
			/*case 7:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
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
