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
class CliqueParty {
	public:
	int maxsize(vector <int> a, int k) {
		sort(a.begin(),a.end());
		ll n=a.size();
		set<ll> s;
		for (ll i=0;i<n;i++) {
			for (ll j=i+1;j<n;j++) {
				s.insert(a[j]-a[i]);
			}
		}
		ll ans=1;
		for (auto &l:s) {
			ll u=l*k;
			for (ll init=0;init<n;init++) {
				ll cand=1;
				ll prev=a[init];
				for (ll x=init+1;x<n;x++) {
					ll hidiff=a[x]-a[init];
					ll lodiff=a[x]-prev;
					if (l<=lodiff&&hidiff<=u) {
						cand++;
						prev=a[x];
					}
				}
				//if(cand==5) printf("%lld %lld %lld\n",l,u,init);
				ans=max(ans,cand);
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
		cout << "Testing CliqueParty (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457366402;
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
		CliqueParty _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 1:
			{
				int a[] = {1,2,3};
				int k = 1;
				_expected = 2;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 2:
			{
				int a[] = {4,10,5,6};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 3:
			{
				int a[] = {1,2,3,4,5,6};
				int k = 3;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 4:
			{
				int a[] = {10,9,25,24,23,30};
				int k = 7;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 5:
			{
				int a[] = {1};
				int k = 1;
				_expected = 1;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 6:
			{
				int a[] = {2,4};
				int k = 2;
				_expected = 2;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 7:
			{
				int a[] = {1,2,4,6,8,10};
				int k = 4;
				_expected = 5;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
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
