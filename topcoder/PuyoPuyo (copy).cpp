#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll l;
ll dp[1002][11];
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
ll f(ll n, ll k) {
	if (n<k) return 0;
	if (dp[n][k]!=-1) return dp[n][k];
	ll ans=0;
	if (k==0) {
		for (ll x=0;x<n;x++) {
			ans+=mul(f(x,0),4*f(n-x,l));
		}
	}
	else {
		for (ll x=0;x<n;x++) {
			ans+=mul(f(x,k-1),f(n-x-1,0));
			//printf("n:%lld k:%lld x:%lld Add %lld*%lld. %lld %lld. %lld %lld\n",
			//	n,k,x,f(x,k-1),f(n-x-1,0),x,k-1,n-x-1,0);
		}
	}
	ans%=MOD;
	printf("n:%lld k:%lld ans:%lld\n",n,k,ans);
	return dp[n][k]=ans;
}
class PuyoPuyo {
	public:
	int theCount(int _L, int _N) {
		l=_L;
		ll n=_N;
		memset(dp,-1,sizeof dp);
		dp[0][0]=1;
		ll ans=f(n,0);
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
		cout << "Testing PuyoPuyo (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487955462;
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
		PuyoPuyo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 2;
				int N = 2;
				_expected = 4;
				_received = _obj.theCount(L, N); break;
			}
			case 1:
			{
				int L = 2;
				int N = 4;
				_expected = 28;
				_received = _obj.theCount(L, N); break;
			}
			case 2:
			{
				int L = 2;
				int N = 58;
				_expected = 868294620;
				_received = _obj.theCount(L, N); break;
			}
			case 3:
			{
				int L = 4;
				int N = 84;
				_expected = 621871151;
				_received = _obj.theCount(L, N); break;
			}
			case 4:
			{
				int L = 5;
				int N = 8;
				_expected = 0;
				_received = _obj.theCount(L, N); break;
			}
			case 5:
			{
				int L = 1;
				int N = 1;
				_expected = 4;
				_received = _obj.theCount(L, N); break;
			}
			case 6:
			{
				int L = 1;
				int N = 2;
				_expected = 16;
				_received = _obj.theCount(L, N); break;
			}
			/*case 7:
			{
				int L = ;
				int N = ;
				_expected = ;
				_received = _obj.theCount(L, N); break;
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
