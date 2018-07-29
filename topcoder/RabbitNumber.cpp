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
ll S(ll x) {
	ll ans=0;
	while(x>0) {
		ans+=(x%10);
		x/=10;
	}
	return ans;
}
ll final=0;
ll lo,hi;
void dfs(ll x, ll left, ll k) {
	if (k==0) {
		if (lo<=x&&x<=hi) {
			ll Sx=S(x);
			if (S(x*x)==Sx*Sx) final++;
		}
	}
	else {
		ll dlim=min(9ll,left);
		for (ll d=0;d<=dlim;d++) {
			dfs(x*10+d,left-d,k-1);
		}
	}
}
class RabbitNumber {
	public:
	int theCount(int _low, int _high) {
		lo=_low,hi=_high;
		ll lim=16;
		dfs(0,lim,10);
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
		cout << "Testing RabbitNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487954773;
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
		RabbitNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low = 22;
				int high = 22;
				_expected = 1;
				_received = _obj.theCount(low, high); break;
			}
			case 1:
			{
				int low = 484;
				int high = 484;
				_expected = 0;
				_received = _obj.theCount(low, high); break;
			}
			case 2:
			{
				int low = 1;
				int high = 58;
				_expected = 12;
				_received = _obj.theCount(low, high); break;
			}
			case 3:
			{
				int low = 58;
				int high = 484;
				_expected = 24;
				_received = _obj.theCount(low, high); break;
			}
			case 4:
			{
				int low = 1000000000;
				int high = 1000000000;
				_expected = 1;
				_received = _obj.theCount(low, high); break;
			}
			/*case 5:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.theCount(low, high); break;
			}*/
			/*case 6:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.theCount(low, high); break;
			}*/
			/*case 7:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.theCount(low, high); break;
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
