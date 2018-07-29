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
ll a[2004];
class FoxMakingDice {
	public:
	long long theCount(int N, int K) {
		memset(a,0,sizeof a);
		for (ll i=1;i<=N;i++) for (ll j=1;j<=N;j++) {
			if (i!=j)a[i+j]++;
		}
		ll ans=0;
		for (ll k=K;k<=2*N;k++) {
			ll x=a[k]/2;
			//printf("k:%lld x:%lld\n",k,x);
			ll add=(x*(x-1)*(x-2))/6;
			ans+=add;
		}
		return ans*2;
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
		cout << "Testing FoxMakingDice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484603731;
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
		FoxMakingDice _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 6;
				int K = 7;
				_expected = 2LL;
				_received = _obj.theCount(N, K); break;
			}
			case 1:
			{
				int N = 5;
				int K = 7;
				_expected = 0LL;
				_received = _obj.theCount(N, K); break;
			}
			case 2:
			{
				int N = 1000;
				int K = 1;
				_expected = 20625666000LL;
				_received = _obj.theCount(N, K); break;
			}
			case 3:
			{
				int N = 456;
				int K = 123;
				_expected = 879075732LL;
				_received = _obj.theCount(N, K); break;
			}
			case 4:
			{
				int N = 913;
				int K = 1014;
				_expected = 4506149340LL;
				_received = _obj.theCount(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.theCount(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.theCount(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.theCount(N, K); break;
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
