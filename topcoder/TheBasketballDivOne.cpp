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

unordered_set<ll> s;
ll f[10];
class TheBasketballDivOne {
	public:
	int find(int _n, int _m) {
		ll n=_n,m=_m;
		ll e=(n*(n-1))/2;
		ll lim=1ULL<<(2LL*e);
		for (ll z=0;z<lim;z++) {
			ll k=0;
			for (ll x=0;x<n;x++) {
				f[x]=0;
			}
			bool ok=true;
			for (ll x=0;x<n;x++) {
				for (ll y=x+1;y<n;y++) {
					for (ll i=0;i<2;i++) {
						if ((z>>k)&1) f[x]++;
						else f[y]++;
						k++;
					}
				}
			}
			assert(k==2*e);
			sort(f,f+n);
			if (f[n-1]!=m) continue;
			vector<int> v;
			ll h=0;
			for (ll x=0;x<n-1;x++) {
				h*=10;
				h+=f[x];
			}
			s.insert(h);
		}
		return s.size();
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
		cout << "Testing TheBasketballDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458705337;
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
		TheBasketballDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 1;
				_expected = 1;
				_received = _obj.find(n, m); break;
			}
			case 1:
			{
				int n = 3;
				int m = 1;
				_expected = 0;
				_received = _obj.find(n, m); break;
			}
			case 2:
			{
				int n = 3;
				int m = 3;
				_expected = 2;
				_received = _obj.find(n, m); break;
			}
			case 3:
			{
				int n = 4;
				int m = 6;
				_expected = 5;
				_received = _obj.find(n, m); break;
			}
			/*case 4:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
			}*/
			/*case 5:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
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
