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
#define MAXP 3165
bool a[MAXP+1];
void sieve() {
	for (ll i = 0; i <= MAXP; i++) a[i] = true;
	a[0] = false; a[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(a[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				a[j] = false;
			}
		}
	}
}


class ExploringNumbers {
	public:
	int numberOfSteps(int n) {
		time_t start = clock();
		sieve();
		ll slim=sqrt(n)+1;
		slim=min(slim,(ll)n-1);
		bool isp=(n!=1);
		for (ll x=2;x<=slim;x++) {
			if ((n%x)==0) {isp=false; break;}
		}
		if (isp) {
			return 1;
		}
		ll ans=n;
		ll ilim=min(n,100000000);
		for (ll i=2;i<=ilim;i++) {
			ll nxt=0;
			while(ans>0) {
				ll d=ans%10;
				ans/=10;
				nxt+=d*d;
			}
			ans=nxt;
			if (a[ans]) {
				return i;
			}
		}
		return -1;
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
		cout << "Testing ExploringNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461733887;
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
		ExploringNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				_expected = 1;
				_received = _obj.numberOfSteps(n); break;
			}
			case 1:
			{
				int n = 57;
				_expected = 4;
				_received = _obj.numberOfSteps(n); break;
			}
			case 2:
			{
				int n = 1;
				_expected = -1;
				_received = _obj.numberOfSteps(n); break;
			}
			case 3:
			{
				int n = 6498501;
				_expected = 2;
				_received = _obj.numberOfSteps(n); break;
			}
			case 4:
			{
				int n = 989113;
				_expected = 6;
				_received = _obj.numberOfSteps(n); break;
			}
			case 5:
			{
				int n = 12366;
				_expected = -1;
				_received = _obj.numberOfSteps(n); break;
			}
			case 6:
			{
				int n = 1000000000;
				_expected = -1;
				_received = _obj.numberOfSteps(n); break;
			}
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.numberOfSteps(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				_expected = ;
				_received = _obj.numberOfSteps(n); break;
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
