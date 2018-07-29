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
class KingdomAndCities {
	public:
	int howMany(int N, int M, int K) {
		
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
		cout << "Testing KingdomAndCities (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470675781;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingdomAndCities _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 0;
				int K = 3;
				_expected = 1;
				_received = _obj.howMany(N, M, K); break;
			}
			case 1:
			{
				int N = 4;
				int M = 1;
				int K = 4;
				_expected = 9;
				_received = _obj.howMany(N, M, K); break;
			}
			case 2:
			{
				int N = 5;
				int M = 2;
				int K = 11;
				_expected = 0;
				_received = _obj.howMany(N, M, K); break;
			}
			case 3:
			{
				int N = 5;
				int M = 0;
				int K = 8;
				_expected = 45;
				_received = _obj.howMany(N, M, K); break;
			}
			case 4:
			{
				int N = 10;
				int M = 2;
				int K = 20;
				_expected = 150810825;
				_received = _obj.howMany(N, M, K); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.howMany(N, M, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.howMany(N, M, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.howMany(N, M, K); break;
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
