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
class AlternateColors2 {
	public:
	long long countWays(int n, int k) {
		k--;
		ll final=0;
		if ((k%3)==0) {
			// First phase
			ll ans=0;
			{
				ll f=k+3;
				ll left=n-f;
				ans+=((left+2)*(left+1))/2;
			}
			final+=ans;
			cout<<ans<<",";
		}
		{
			// Second phase
			ll ans=0;
			for (ll f=0;f<=n;f+=3) {
				if (k-f>=0&&((k-f)%2)==0) {
					ll take=k+2;
					ll left=n-take;
					ans+=max(0LL,left+1);
				}
			}
			ans*=2;
			final+=ans;
			cout<<ans<<",";
		}
		{
			// Third phase
			ll ans=0;
			for (ll f=0;f<=n;f+=3) {
				ll s=k-f;
				if (s>=0) {
					ll init=s/2;
					ans+=1+2*init;
				}
			}
			final+=ans;
			cout<<ans<<",";
		}
		return final;
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
		cout << "Testing AlternateColors2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462340756;
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
		AlternateColors2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int k = 1;
				_expected = 1LL;
				_received = _obj.countWays(n, k); break;
			}
			case 1:
			{
				int n = 3;
				int k = 3;
				_expected = 3LL;
				_received = _obj.countWays(n, k); break;
			}
			case 2:
			{
				int n = 6;
				int k = 4;
				_expected = 9LL;
				_received = _obj.countWays(n, k); break;
			}
			case 3:
			{
				int n = 6;
				int k = 1;
				_expected = 21LL;
				_received = _obj.countWays(n, k); break;
			}
			case 4:
			{
				int n = 1000;
				int k = 2;
				_expected = 1LL;
				_received = _obj.countWays(n, k); break;
			}
			case 5:
			{
				int n = 100000;
				int k = 100000;
				_expected = 1666700000LL;
				_received = _obj.countWays(n, k); break;
			}
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.countWays(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.countWays(n, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.countWays(n, k); break;
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
