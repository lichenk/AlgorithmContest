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
ll n,k;
bool ok(ll imid) {
	return k>=(imid-k+1)/2;
}
class BallsInBoxes {
	public:
	long long maxTurns(long long N, long long K) {
		ll ans1=0,ans2=0;
		n=N;k=K;
		ll x=-1;
		{
			ll imin=0; ll imax=n+1;
			while(imin<imax) {
				ll imid=imin+(imax-imin)/2;
				if (ok(imid)) {
					imin=imid+1;
				}
				else {
					imax=imid;
				}
			}
			if(ok(n)) {x=n;}
			else {
				assert(!ok(imin));
				imin--;
				assert(ok(imin));
				{
					ll d = k;
					ll take = (n-imin+d-1)/d;
					x = n-take*d;
					ans1 = take;
					ans2 = take;
				}
			}
		}
		{
			assert(x!=-1);
			ll t=x-k+1;
			while(t>1) {
				t=(t+1)/2;
				ans1++;
			}
		}
		{
			if (ans2>0) {
				ans2--;
				ll t=k;
				while(t>1) {
					t=(t+1)/2;
					ans2++;
				}
			}
		}
		return max(ans1,ans2);
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
		cout << "Testing BallsInBoxes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456622137;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BallsInBoxes _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 10LL;
				long long K = 10LL;
				_expected = 0LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 1:
			{
				long long N = 100LL;
				long long K = 1LL;
				_expected = 99LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 2:
			{
				long long N = 1000LL;
				long long K = 999LL;
				_expected = 1LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 3:
			{
				long long N = 10LL;
				long long K = 5LL;
				_expected = 3LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 4:
			{
				long long N = 6LL;
				long long K = 2LL;
				_expected = 3LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 5:
			{
				long long N = 9LL;
				long long K = 5LL;
				_expected = 3LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 6:
			{
				long long N = 3LL;
				long long K = 2LL;
				_expected = 1LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 7:
			{
				long long N = 5LL;
				long long K = 3LL;
				_expected = 2LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 8:
			{
				long long N = (ll)1e18;
				long long K = 1;
				_expected = ((ll)1e18)-1;
				_received = _obj.maxTurns(N, K); break;
			}
			case 9:
			{
				long long N = (ll)1e18;
				long long K = (ll)1e18;
				_expected = 0;
				_received = _obj.maxTurns(N, K); break;
			}
			case 10:
			{
				long long N = (ll)1e18;
				long long K = ((ll)1e18)-1;
				_expected = 1;
				_received = _obj.maxTurns(N, K); break;
			}
			case 11:
			{
				long long N = 9;
				long long K = 3;
				_expected = 3;
				_received = _obj.maxTurns(N, K); break;
			}
			case 12:
			{
				long long N = 10;
				long long K = 3;
				_expected = 4;
				_received = _obj.maxTurns(N, K); break;
			}
			case 13:
			{
				long long N = 11;
				long long K = 3;
				_expected = 4;
				_received = _obj.maxTurns(N, K); break;
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
