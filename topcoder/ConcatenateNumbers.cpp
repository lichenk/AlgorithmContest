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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll digits(ll x) {
	ll ans=0;
	while(x>0) {x/=10;ans++;}
	return ans;
}
unordered_map<ll,ll> h;
const ll invten = 700000005LL;
class ConcatenateNumbers {
	public:
	long long numberOfSegments(int _L, int _R, int _v) {
		ll l=_L; ll r=_R; ll v=_v;
		{
			ll y=0;
			ll powten = 1;
			for (ll x=r;x>=l;x--) {
				ll add = (x*powten)%MOD;
				y = (y+add)%MOD;
				h[y]++;
				ll k=digits(x);
				for (ll i=0;i<k;i++) {
					powten = (powten*10)%MOD;
				}
			}
		}
		ll ans=0;
		{
			ll y=0;
			ll powten = 1;
			for (ll x=r;x>=l;x--) {
				ll expect = (((v*powten)%MOD)+y)%MOD;
				ans += h[expect];
				ll add = (x*powten)%MOD;
				y = (y+add)%MOD;
				ll k=digits(x);
				for (ll i=0;i<k;i++) {
					powten = (powten*10)%MOD;
				}
				h[y]--;
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
		cout << "Testing ConcatenateNumbers (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456377699;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ConcatenateNumbers _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 11;
				int R = 13;
				int v = 111213;
				_expected = 1LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 1:
			{
				int L = 11;
				int R = 13;
				int v = 11213;
				_expected = 0LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 2:
			{
				int L = 11;
				int R = 13;
				int v = 14;
				_expected = 0LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 3:
			{
				int L = 1;
				int R = 100000;
				int v = 12345;
				_expected = 10LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 4:
			{
				int L = 999900001;
				int R = 1000000000;
				int v = 0;
				_expected = 7LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 5:
			{
				int L = 11;
				int R = 14;
				int v = 111213;
				_expected = 1LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			case 6:
			{
				int L = 11;
				int R = 17;
				int v = 111213;
				_expected = 1LL;
				_received = _obj.numberOfSegments(L, R, v); break;
			}
			/*case 7:
			{
				int L = ;
				int R = ;
				int v = ;
				_expected = LL;
				_received = _obj.numberOfSegments(L, R, v); break;
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
