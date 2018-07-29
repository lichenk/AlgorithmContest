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
ll f[10000];
class LongWordsDiv1 {
	public:
	int count(int _n) {
		ll n=_n;
		for (ll x=0;x<=n;x++) f[x]=0;
		f[1]=1;
		for (ll x=2;x<=n;x++) {
			ll ans=f[x-1];
			for (ll y=1;y<x;y++) {
				ll z=x-1-y;
				ans += (f[y]*f[z])%MOD;
			}
			f[x]=ans%MOD;
		}
		ll final=f[n];
		for (ll x=2;x<=n;x++) {
			final *=x;
			final%=MOD;
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
		cout << "Testing LongWordsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457770780;
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
		LongWordsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = 2;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				int n = 5;
				_expected = 1080;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				int n = 100;
				_expected = 486425238;
				_received = _obj.count(n); break;
			}
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
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
