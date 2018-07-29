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
inline ll getsqrt(ll x) {
	return floor(sqrt(x+1e-9));
}

class MagicCandy {
	public:
	int whichOne(int _n) {
		ll n=_n;
		if (n==1) return n;
		ll s=getsqrt(n);
		if (s*s==n) {n--; s=getsqrt(n);}
		return ((n-1)/s)*s+1;
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
		cout << "Testing MagicCandy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472227200;
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
		MagicCandy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				_expected = 5;
				_received = _obj.whichOne(n); break;
			}
			case 1:
			{
				int n = 9;
				_expected = 7;
				_received = _obj.whichOne(n); break;
			}
			case 2:
			{
				int n = 20;
				_expected = 17;
				_received = _obj.whichOne(n); break;
			}
			case 3:
			{
				int n = 5265;
				_expected = 5257;
				_received = _obj.whichOne(n); break;
			}
			case 4:
			{
				int n = 20111223;
				_expected = 20110741;
				_received = _obj.whichOne(n); break;
			}
			case 5:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.whichOne(n); break;
			}
			case 6:
			{
				int n = 166207090;
				_expected = 166203665;
				_received = _obj.whichOne(n); break;
			}
			case 7:
			{
				int n = 460216916;
				_expected = 460209757;
				_received = _obj.whichOne(n); break;
			}
			case 8:
			{
				int n = 3;
				_expected = 3;
				_received = _obj.whichOne(n); break;
			}
			case 9:
			{
				int n = 2;
				_expected = 2;
				_received = _obj.whichOne(n); break;
			}
			case 10:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.whichOne(n); break;
			}
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
