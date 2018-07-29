#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair

ll modexp(ll b, ll n, ll MOD) {
	ll ans = 1;
	while(n > 0) {
		if (n % 2 == 1) {
			ans = (ans * b) % MOD;
			n--;
		}
		else {
			b = (b*b) % MOD;
			n /= 2;
		}
	}
	return ans;
}


class ColorfulLineGraphs {
	public:
	int countWays(long long N, long long K, int M) {
		ll n = N+1;
		ll k = K-1;
		N++; K--;
		ll x = 1;
		ll len = -1; ll z = -1;
		ll lim = 2*M;
		for (ll i = 1; i <= lim; i++) {
			x = (x+k)%M;
			if (x == 1) {len = i; break;}
			else if (x == 0) {z = i; break;}
		}
		assert(!(len == -1 && z == -1));
		if (z != -1) {
			if (n > 2*z) {
				return 0;
			}
		}
		if (len != -1) {
			if (n > 2*len) {
				ll p = n/len;
				ll r = n%len;
				ll x = 1;
				ll y = 1;
				for (ll i = 1; i <= len; i++) {
					x = (x*y)%M;
					y = (y+k)%M;
				}
				ll ans = modexp(x, p, M);
				y = 1;
				for (ll i = 1; i <= r; i++) {
					ans = (ans*y)%M;
					y = (y+k)%M;
				}
				return ans;
			}
		}
		{
			ll x = 1;
			ll y = 1;
			for (ll i = 1; i <= n; i++) {
				x = (x*y)%M;
				y = (y+k)%M;
			}
			return x;
		}

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
		cout << "Testing ColorfulLineGraphs (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449563952;
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
		ColorfulLineGraphs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 3LL;
				long long K = 2LL;
				int M = 100000;
				_expected = 24;
				_received = _obj.countWays(N, K, M); break;
			}
			case 1:
			{
				long long N = 15LL;
				long long K = 3LL;
				int M = 1000000;
				_expected = 510625;
				_received = _obj.countWays(N, K, M); break;
			}
			case 2:
			{
				long long N = 100000LL;
				long long K = 100000LL;
				int M = 999999;
				_expected = 185185;
				_received = _obj.countWays(N, K, M); break;
			}
			case 3:
			{
				long long N = 1000000000000LL;
				long long K = 6LL;
				int M = 1000000;
				_expected = 109376;
				_received = _obj.countWays(N, K, M); break;
			}
			case 4:
			{
				long long N = 5000LL;
				long long K = 1000000000000LL;
				int M = 314159;
				_expected = 202996;
				_received = _obj.countWays(N, K, M); break;
			}
			/*case 5:
			{
				long long N = LL;
				long long K = LL;
				int M = ;
				_expected = ;
				_received = _obj.countWays(N, K, M); break;
			}*/
			/*case 6:
			{
				long long N = LL;
				long long K = LL;
				int M = ;
				_expected = ;
				_received = _obj.countWays(N, K, M); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				long long K = LL;
				int M = ;
				_expected = ;
				_received = _obj.countWays(N, K, M); break;
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
