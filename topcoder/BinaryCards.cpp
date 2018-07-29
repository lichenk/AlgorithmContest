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
class BinaryCards {
	public:
	long long largestNumber(long long A, long long B) {
		if (A==B) return A;
		ll ans=B;
		for (ll k=63;k>=0;k--) {
			ll msk=1ll<<k;
			if ((B&msk)&&!(A&msk)) {
				ll cand=B;
				cand|=(1ll<<(k))-1;
				chkmax(ans,cand);
			}
		}
		return ans;
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
		cout << "Testing BinaryCards (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1475038624;
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
		BinaryCards _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long A = 6LL;
				long long B = 6LL;
				_expected = 6LL;
				_received = _obj.largestNumber(A, B); break;
			}
			case 1:
			{
				long long A = 6LL;
				long long B = 7LL;
				_expected = 7LL;
				_received = _obj.largestNumber(A, B); break;
			}
			case 2:
			{
				long long A = 6LL;
				long long B = 8LL;
				_expected = 15LL;
				_received = _obj.largestNumber(A, B); break;
			}
			case 3:
			{
				long long A = 1LL;
				long long B = 11LL;
				_expected = 15LL;
				_received = _obj.largestNumber(A, B); break;
			}
			case 4:
			{
				long long A = 35LL;
				long long B = 38LL;
				_expected = 39LL;
				_received = _obj.largestNumber(A, B); break;
			}
			case 5:
			{
				long long A = 1125899906842630LL;
				long long B = 1125899906842632LL;
				_expected = 1125899906842639LL;
				_received = _obj.largestNumber(A, B); break;
			}
			/*case 6:
			{
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.largestNumber(A, B); break;
			}*/
			/*case 7:
			{
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.largestNumber(A, B); break;
			}*/
			/*case 8:
			{
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.largestNumber(A, B); break;
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
