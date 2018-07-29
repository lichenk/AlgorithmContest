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
bool overflow(ll a, ll b) {
	ll x = a * b;
	return  (a != 0 && x / a != b);
}
class CountingSeries {
	public:
	long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
		ll u=upperBound;
		ll arith=1+(u-a)/b;
		if (a>u) arith=0;
		if (d==1) {
			ll res=c;
			ll x=(res-a)/b;
			if (res>upperBound) return arith;
			if (a+b*x==res&&x>=0) return arith;
			else return arith+1;
		}
		ll geom=0;
		ll res=c;
		for (ll y=0;y<=60;y++) {
			if (overflow(res,d)||res*d>upperBound) {
				if(res<=upperBound) geom=y+1;
				break;
			}
			res*=d;
		}
		res=c;
		ll inter=0;
		for (ll y=0;y<geom;y++) {
			ll x=(res-a)/b;
			if (a+b*x==res&&x>=0) {
				inter++;
			}
			res*=d;
		}
		ll ans=arith+geom-inter;
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
		cout << "Testing CountingSeries (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472955141;
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
		CountingSeries _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long a = 1LL;
				long long b = 1LL;
				long long c = 1LL;
				long long d = 2LL;
				long long upperBound = 1000LL;
				_expected = 1000LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 1:
			{
				long long a = 3LL;
				long long b = 3LL;
				long long c = 1LL;
				long long d = 2LL;
				long long upperBound = 1000LL;
				_expected = 343LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 2:
			{
				long long a = 40LL;
				long long b = 77LL;
				long long c = 40LL;
				long long d = 100000LL;
				long long upperBound = 40LL;
				_expected = 1LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 3:
			{
				long long a = 452LL;
				long long b = 24LL;
				long long c = 4LL;
				long long d = 5LL;
				long long upperBound = 600LL;
				_expected = 10LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 4:
			{
				long long a = 234LL;
				long long b = 24LL;
				long long c = 377LL;
				long long d = 1LL;
				long long upperBound = 10000LL;
				_expected = 408LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 5:
			{
				long long a = 1000000000000000000LL;
				long long b = 1000000000000000000LL;
				long long c = 1000000000000000000LL;
				long long d = 1000000000000000000LL;
				long long upperBound = 1000000000000000000LL;
				_expected = 1LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 6:
			{
				long long a = 1000000000000000000LL;
				long long b = 1000000000000000000LL;
				long long c = 1000000000000000000LL;
				long long d = 1000000000000000000LL;
				long long upperBound = 1000000000000000000LL-1LL;
				_expected = 0LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 7:
			{
				long long a = 2LL;
				long long b = 2LL;
				long long c = 2LL;
				long long d = 2LL;
				long long upperBound = 5LL;
				_expected = 2LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
			}
			case 8:
			{
				long long a = 720176314585LL;
				long long b = 488693376359LL;
				long long c = 514776939786LL;
				long long d = 38245LL;
				long long upperBound = 382227406106LL;
				_expected = 0LL;
				_received = _obj.countThem(a, b, c, d, upperBound); break;
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
