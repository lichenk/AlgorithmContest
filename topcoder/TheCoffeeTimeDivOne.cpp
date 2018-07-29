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
class TheCoffeeTimeDivOne {
	public:
	long long find(int _n, vector <int> tea) {
		ll n=_n;
		sort(tea.begin(),tea.end());
		reverse(tea.begin(),tea.end());
		ll tsz=tea.size();
		ll teafill=((tsz+6)/7)*47;
		ll coffeefill=((n-tsz+6)/7)*47;
		ll teawalk=0;
		{
			ll cnt=1;
			for (ll x=0;x<tsz;x++) {
				if (cnt==1) {
					teawalk+=tea[x];
				}
				if (cnt==7) {
					cnt=0;
				}
				cnt++;
			}
		}
		ll coffeewalk=0;
		ll lastcoffee=0;
		ll idx=0;
		{
			ll lastx=0;
			ll cnt=1;
			for (ll x=n;x>=1;x--) {
				if (idx<tea.size()&&x==tea[idx]) {
					idx++;
					continue;
				}
				if (cnt==1) {
					coffeewalk+=x;
				}
				if (cnt==7) {
					cnt=0;
				}
				lastx=x;
				cnt++;
			}
		}
		ll ans=teafill+coffeefill+2*coffeewalk+2*teawalk+4*n;
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
		cout << "Testing TheCoffeeTimeDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491583590;
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
		TheCoffeeTimeDivOne _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int tea[] = {1};
				_expected = 108LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int tea[] = {2, 1};
				_expected = 59LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 15;
				int tea[] = {1, 2, 3, 4, 5, 6, 7};
				_expected = 261LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 47;
				int tea[] = {1, 10, 6, 2, 4};
				_expected = 891LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 14;
				int tea[] = {1, 2, 3, 4, 5, 6, 7};
				_expected = 261LL-2-8*2-47-4LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1;
				int tea[] = {1};
				_expected = 53LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 1;
				int tea[] = {};
				_expected = 53LL;
				_received = _obj.find(n, vector <int>(tea, tea+sizeof(tea)/sizeof(int))); break;
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
