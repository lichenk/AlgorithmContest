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
ll c[2000],d[2000];
class MoveStones {
	public:
	long long get(vector <int> a, vector <int> b) {
		ll n=a.size();
		ll suma=0,sumb=0; for (ll i=0;i<n;i++) {suma+=a[i]; sumb+=b[i];}
		if (suma!=sumb) return -1;
		for (ll x=0;x<n;x++) {
			d[x]=a[x]-b[x];
		}
		ll final=INF;
		for (ll y=0;y<n;y++) {
			for (ll x=0;x<n;x++) {
				c[x] = d[(x+y)%n];
			}
			ll ans=0;
			ll k=0;
			for (ll x=0;x<=n;x++) {
				ans+=abs(k);
				k+=c[x%n];
			}
			final=min(final,ans);
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
		cout << "Testing MoveStones (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456766358;
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
		MoveStones _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {12};
				int b[] = {12};
				_expected = 0LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {10};
				int b[] = {9};
				_expected = -1LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0, 5};
				int b[] = {5, 0};
				_expected = 5LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1, 2, 3};
				int b[] = {3, 1, 2};
				_expected = 2LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {1, 0, 1, 1, 0};
				int b[] = {0, 3, 0, 0, 0};
				_expected = 4LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {1000000000, 0, 0, 0, 0, 0};
				int b[] = {0, 0, 0, 1000000000, 0, 0};
				_expected = 3000000000LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {2,0,0,1,0,0,0};
				int b[] = {0,1,1,0,0,0,1};
				_expected = 3LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int a[] = {1,0,1,0,0};
				int b[] = {0,1,0,1,0};
				_expected = 2LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 8:
			{
				int a[] = {1,0,0,1,0};
				int b[] = {0,0,1,0,1};
				_expected = 2LL;
				_received = _obj.get(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
