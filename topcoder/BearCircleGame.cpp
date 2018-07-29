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
class BearCircleGame {
	public:
	int winProbability(int n, int k) {
		
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
		cout << "Testing BearCircleGame (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466278431;
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
		BearCircleGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int k = 1;
				_expected = 333333336;
				_received = _obj.winProbability(n, k); break;
			}
			case 1:
			{
				int n = 2;
				int k = 2;
				_expected = 1;
				_received = _obj.winProbability(n, k); break;
			}
			case 2:
			{
				int n = 3;
				int k = 2;
				_expected = 142857144;
				_received = _obj.winProbability(n, k); break;
			}
			case 3:
			{
				int n = 3;
				int k = 1;
				_expected = 238095240;
				_received = _obj.winProbability(n, k); break;
			}
			case 4:
			{
				int n = 4;
				int k = 4;
				_expected = 142857144;
				_received = _obj.winProbability(n, k); break;
			}
			case 5:
			{
				int n = 5;
				int k = 1000000000;
				_expected = 142857144;
				_received = _obj.winProbability(n, k); break;
			}
			case 6:
			{
				int n = 2000;
				int k = 123;
				_expected = 429232785;
				_received = _obj.winProbability(n, k); break;
			}
			case 7:
			{
				int n = 1987;
				int k = 987654321;
				_expected = 623410299;
				_received = _obj.winProbability(n, k); break;
			}
			/*case 8:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.winProbability(n, k); break;
			}*/
			/*case 9:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.winProbability(n, k); break;
			}*/
			/*case 10:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.winProbability(n, k); break;
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
