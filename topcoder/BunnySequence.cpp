#include <bits/stdc++.h>
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
class BunnySequence {
	public:
	int getNumber(int m, int n) {
		
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
		cout << "Testing BunnySequence (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486953924;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BunnySequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 5;
				int n = 3;
				_expected = 4;
				_received = _obj.getNumber(m, n); break;
			}
			case 1:
			{
				int m = 487;
				int n = 0;
				_expected = 1;
				_received = _obj.getNumber(m, n); break;
			}
			case 2:
			{
				int m = 19;
				int n = 10;
				_expected = 512;
				_received = _obj.getNumber(m, n); break;
			}
			case 3:
			{
				int m = 3;
				int n = 4;
				_expected = 6;
				_received = _obj.getNumber(m, n); break;
			}
			case 4:
			{
				int m = 10;
				int n = 487;
				_expected = 829515032;
				_received = _obj.getNumber(m, n); break;
			}
			/*case 5:
			{
				int m = ;
				int n = ;
				_expected = ;
				_received = _obj.getNumber(m, n); break;
			}*/
			/*case 6:
			{
				int m = ;
				int n = ;
				_expected = ;
				_received = _obj.getNumber(m, n); break;
			}*/
			/*case 7:
			{
				int m = ;
				int n = ;
				_expected = ;
				_received = _obj.getNumber(m, n); break;
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
