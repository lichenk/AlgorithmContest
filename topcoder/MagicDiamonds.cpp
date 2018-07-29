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
ll f(ll n) {
	if (n==0) return 0;
	ll k=min(n,(ll)(sqrt(n)+2));
	for (ll x=2;x<k;x++) {
		if (n%x==0) return 1;
	}
	return f(n-1)+1;
}
class MagicDiamonds {
	public:
	long long minimalTransfer(long long n) {
		return f(n);
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
		cout << "Testing MagicDiamonds (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472829472;
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
		MagicDiamonds _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 2LL;
				_expected = 2LL;
				_received = _obj.minimalTransfer(n); break;
			}
			case 1:
			{
				long long n = 4294967297LL;
				_expected = 1LL;
				_received = _obj.minimalTransfer(n); break;
			}
			case 2:
			{
				long long n = 2147483647LL;
				_expected = 2LL;
				_received = _obj.minimalTransfer(n); break;
			}
			case 3:
			{
				long long n = 1LL;
				_expected = 1LL;
				_received = _obj.minimalTransfer(n); break;
			}
			case 4:
			{
				long long n = 3LL;
				_expected = 3LL;
				_received = _obj.minimalTransfer(n); break;
			}
			/*case 5:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.minimalTransfer(n); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.minimalTransfer(n); break;
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
