#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll ilog2(ll x) {
	assert(x != 0);
	return 63 - __builtin_clzll(x);
}

ll g(ll x, ll y) {
	assert(x >= y);
	return 1+ilog2(x/y);
}

ll f(ll x) {
	if (x == 0) return 0;
	ll sum = 0;
	ll lgmax = g(x,1);
	////printf("x: %lld lgmax:%lld\n",x,lgmax);
	ll right = x+1;
	for (ll lg = 1; lg <= lgmax; lg++) {
		ll imin = 1; ll imax = x+1;
		while(imin < imax) {
			ll imid = imin + (imax - imin)/2;
			ll candlg = g(x, imid);
			if (candlg > lg) imin = imid+1;
			else imax = imid;
		}
		assert(imin == imax);
		if (g(x,imin) == lg) {
			ll left = imin;
			////printf("Adding lg:%lld to left %lld right %lld\n",lg,left,right);
			sum += lg*(right - left);
			right = left;
		}
	}
	return sum;
}

ll h(ll k, ll x) {
	ll left = k/2; ll right = x;
	assert(left < x && x <= k);
	return f(right) - f(left);
}

ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	return ans;
}

class KitayutaMart {
	public:
	int lastPrice(int Ni, int Ki) {
		ll n = Ni; ll k = Ki;
		ll init = f(k);
		//printf("init: %lld\n",init);
		if (n > init) {
			//printf("Using cycling algo\n");
			ll left = n - init;
			ll cycles = 1 + ((left-1)/k);
			ll tgt = left - (cycles-1)*k;
			//printf("left:%lld cycles:%lld tgt:%lld\n",left,cycles,tgt);
			ll imin = k/2 + 1; ll imax = k+1;
			while(imin < imax) {
				ll imid = imin + (imax - imin)/2;
				if (h(k, imid) < tgt) {
					imin = imid+1;
				}
				else {
					imax = imid;
				}
			}
			//printf("imin: %lld exp: %lld\n",imin, modexp(2, cycles));
			assert(imin == imax);
			assert(h(k,imin) >= tgt);
			ll ans = imin * modexp(2, cycles);
			return ans%MOD;
		}
		else {
			//printf("Using preinit algo\n");
			ll imin = 1; ll imax = k+1;
			while(imin < imax) {
				ll imid = imin + (imax - imin)/2;
				ll sum = f(imid);
				////printf("imid:%lld sum:%lld k:%lld\n",imid,sum,k);
				if (sum < n) {
					imin = imid+1;
				}
				else {
					imax = imid;
				}
			}
			assert(imin == imax);
			ll ans = imin;
			return ans%MOD;
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
		cout << "Testing KitayutaMart (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451779181;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KitayutaMart _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 1;
				_expected = 4;
				_received = _obj.lastPrice(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 2;
				_expected = 2;
				_received = _obj.lastPrice(N, K); break;
			}
			case 2:
			{
				int N = 5;
				int K = 3;
				_expected = 4;
				_received = _obj.lastPrice(N, K); break;
			}
			case 3:
			{
				int N = 1000000000;
				int K = 1;
				_expected = 570312504;
				_received = _obj.lastPrice(N, K); break;
			}
			case 4:
			{
				int N = 987654321;
				int K = 876543210;
				_expected = 493827168;
				_received = _obj.lastPrice(N, K); break;
			}
			case 5:
			{
				int N = 1;
				int K = 1;
				_expected = 1;
				_received = _obj.lastPrice(N, K); break;
			}
			case 6:
			{
				int N = 3;
				int K = 100;
				_expected = 2;
				_received = _obj.lastPrice(N, K); break;
			}
			case 7:
			{
				int N = 81;
				int K = 7;
				_expected = 7168;
				_received = _obj.lastPrice(N, K); break;
			}
			case 8:
			{
				int N = 4;
				int K = 100;
				_expected = 3;
				_received = _obj.lastPrice(N, K); break;
			}
			case 9:
			{
				int N = 4;
				int K = 2;
				_expected = 4;
				_received = _obj.lastPrice(N, K); break;
			}
			case 10:
			{
				int N = 5;
				int K = 100;
				_expected = 4;
				_received = _obj.lastPrice(N, K); break;
			}
			case 11:
			{
				int N = 6;
				int K = 100;
				_expected = 4;
				_received = _obj.lastPrice(N, K); break;
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
