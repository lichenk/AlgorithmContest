#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		
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
		cout << "Testing BearPlays (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449389953;
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
		BearPlays _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 4;
				int B = 7;
				int K = 2;
				_expected = 5;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 1:
			{
				int A = 5;
				int B = 5;
				int K = 3;
				_expected = 0;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 2:
			{
				int A = 2;
				int B = 6;
				int K = 1;
				_expected = 4;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 3:
			{
				int A = 2;
				int B = 8;
				int K = 2000000000;
				_expected = 2;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 4:
			{
				int A = 900000000;
				int B = 350000000;
				int K = 3;
				_expected = 300000000;
				_received = _obj.pileSize(A, B, K); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
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
