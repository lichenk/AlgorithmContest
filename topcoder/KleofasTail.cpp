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
ll f(ll K,ll A,ll B) {
	ll ans=0;
	for (ll t=0;;t++) {
		ll got=K<<t;
		if (got>B) break;
		ll lo,hi;
		{
			ll imin=0,imax=1LL<<t;
			while(imin<imax) {
				ll imid=(imin+imax)/2;
				ll cand=got|imid;
				if (cand<A) imin=imid+1;
				else imax=imid;
			}
			lo=imin;
		}
		{
			ll imin=0,imax=1LL<<t;
			while(imin<imax) {
				ll imid=(imin+imax)/2;
				ll cand=got|imid;
				if (cand<=B) imin=imid+1;
				else imax=imid;
			}
			hi=imin;
		}
		ans+=(hi-lo);
	}
	return ans;
}
class KleofasTail {
	public:
	long long countGoodSequences(long long K, long long A, long long B) {
		if (K==0) return B-A+1;
		if (K&1) {
			ll ans=f(K,A,B);
			return ans;
		}
		else {
			ll ans=f(K,A,B)+f(K+1,A,B);
			return ans;
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
		cout << "Testing KleofasTail (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470716752;
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
		KleofasTail _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long K = 3LL;
				long long A = 4LL;
				long long B = 8LL;
				_expected = 2LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			case 1:
			{
				long long K = 1LL;
				long long A = 23457LL;
				long long B = 123456LL;
				_expected = 100000LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			case 2:
			{
				long long K = 1234567890123456LL;
				long long A = 10LL;
				long long B = 1000000LL;
				_expected = 0LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			case 3:
			{
				long long K = 0LL;
				long long A = 0LL;
				long long B = 2LL;
				_expected = 3LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			case 4:
			{
				long long K = 2LL;
				long long A = 3LL;
				long long B = 3LL;
				_expected = 1LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			case 5:
			{
				long long K = 13LL;
				long long A = 12345LL;
				long long B = 67890123LL;
				_expected = 8387584LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}
			/*case 6:
			{
				long long K = LL;
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}*/
			/*case 7:
			{
				long long K = LL;
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.countGoodSequences(K, A, B); break;
			}*/
			/*case 8:
			{
				long long K = LL;
				long long A = LL;
				long long B = LL;
				_expected = LL;
				_received = _obj.countGoodSequences(K, A, B); break;
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
