#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class TheNumberGameDiv2 {
	public:
	int minimumMoves(int A, int B) {
		
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
		cout << "Testing TheNumberGameDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737517;
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
		TheNumberGameDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 25;
				int B = 5;
				_expected = 2;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 1:
			{
				int A = 5162;
				int B = 16;
				_expected = 4;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 2:
			{
				int A = 334;
				int B = 12;
				_expected = -1;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 3:
			{
				int A = 218181918;
				int B = 9181;
				_expected = 6;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 4:
			{
				int A = 9798147;
				int B = 79817;
				_expected = -1;
				_received = _obj.minimumMoves(A, B); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
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
