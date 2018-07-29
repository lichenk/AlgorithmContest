#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

bool f(ll z, ll n, ll w, ll h) {
	for (ll k = n-1; k >= 0; k--) {
		ll mask = 1ULL<<k;
		if ((z & mask)) {
			if (!(h <= w)) swap(h,w);
			assert(h <= w);
			w -= mask;
			if (w <= 0) return true;
		}
	}
	return false;
}

class BearFills {
	public:
	long long countSets(int Ni, long long W, long long H) {
		ll n = Ni;
		ll lim = 1ULL<<n;
		ll imin = 0; ll imax = lim;
		while (imin < imax) {
			ll imid = imin + (imax - imin)/2;
			if (!f(imid, n, W, H)) {
				imin = imid+1;
			}
			else {
				imax = imid;
			}
		}
		assert(imin==imax);
		return lim - imin;
		/*if (f(imin,n,W,H)) {
			return lim - imin;
		}
		else {
			return 0;
		}*/
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
		cout << "Testing BearFills (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453177197;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearFills _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				long long W = 1LL;
				long long H = 3LL;
				_expected = 5LL;
				_received = _obj.countSets(N, W, H); break;
			}
			case 1:
			{
				int N = 3;
				long long W = 3LL;
				long long H = 5LL;
				_expected = 1LL;
				_received = _obj.countSets(N, W, H); break;
			}
			case 2:
			{
				int N = 60;
				long long W = 3LL;
				long long H = 2LL;
				_expected = 1152921504606846972LL;
				_received = _obj.countSets(N, W, H); break;
			}
			case 3:
			{
				int N = 6;
				long long W = 5LL;
				long long H = 4LL;
				_expected = 56LL;
				_received = _obj.countSets(N, W, H); break;
			}
			case 4:
			{
				int N = 1;
				long long W = 1LL;
				long long H = 2LL;
				_expected = 0LL;
				_received = _obj.countSets(N, W, H); break;
			}
			/*case 5:
			{
				int N = ;
				long long W = LL;
				long long H = LL;
				_expected = LL;
				_received = _obj.countSets(N, W, H); break;
			}*/
			/*case 6:
			{
				int N = ;
				long long W = LL;
				long long H = LL;
				_expected = LL;
				_received = _obj.countSets(N, W, H); break;
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
