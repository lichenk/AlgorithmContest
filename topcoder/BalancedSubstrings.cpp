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
const ll MAXN = 4000;
ll a[MAXN],b[MAXN];
class BalancedSubstrings {
	public:
	int countSubstrings(string s) {
		ll n=s.length();
		for (ll i=0;i<n;i++) a[i]=(s[i]=='0')?0:1;
		ll ans=0;
		for (ll x=0;x<n;x++) {
			unordered_map<ll,ll> h,g;
			{
				ll l=0;
				g[0]=1;
				ll d=1;
				for (ll y=x-1;y>=0;y--) {
					l+=d*a[y];
					g[l]++; d++;
				}
			}
			{
				ll l=0;
				h[0]=1;
				ll d=1;
				for (ll y=x+1;y<n;y++) {
					l+=d*a[y];
					h[l]++; d++;
				}
			}
			for (auto &w: g) {
				if (w.first==0&&a[x]==0) continue;
				ans += w.second * h[w.first];
			}
		}
		// Handle 0 case
		/*ans += n;*/
		b[0]=0;
		for (ll x=0;x<n;x++) {
			b[x+1] = b[x]+a[x];
		}
		for (ll x=0;x<n;x++) {
			for (ll y=x;y<n;y++) {
				if (b[y+1]-b[x]==0) {
					ans++;
				}
			}
		}
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
		cout << "Testing BalancedSubstrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456621209;
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
		BalancedSubstrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "011";
				_expected = 4;
				_received = _obj.countSubstrings(s); break;
			}
			case 1:
			{
				string s = "10111";
				_expected = 10;
				_received = _obj.countSubstrings(s); break;
			}
			case 2:
			{
				string s = "00000";
				_expected = 15;
				_received = _obj.countSubstrings(s); break;
			}
			case 3:
			{
				string s = "0000001000000";
				_expected = 91;
				_received = _obj.countSubstrings(s); break;
			}
			case 4:
			{
				string s = "100110001001";
				_expected = 49;
				_received = _obj.countSubstrings(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
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
