#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define SZ 4000000
#define SQRTSZ 2000
ll a[SZ+1],c[SZ+1],d[SZ+1],sp[SZ+1];
class MissingLCM {
	public:
	int getMin(int N) {
		for (ll i = 2; i <= SZ; i++) {a[i] = true; sp[i] = i;}
		sp[1] = 1;
		for (ll i = 2; i <= SQRTSZ; i++) {
			if (a[i]) {
				sp[i] = i;
				for (ll j = i*i; j <= SZ; j += i) {
					a[j] = false;
					sp[j] = min(i, sp[j]);
				}
			}
		}
		for (ll i = 0; i <= SZ; i++) {
			c[i] = 0;
		}
		for (ll x = 1; x <= N; x++) {
			ll y = x;
			ll p = sp[y];
			ll k = 0;
			while(y > 1) {
				y /= p;
				k++;
				if (sp[y] != p) {
					c[p] = max(k, c[p]);
					k = 0;
					p = sp[y];
				}
			}
		}
		for (ll i = 0; i <= SZ; i++) {
			d[i] = 0;
		}
		ll diff = 0;
		for (ll i = 0; i <= SZ; i++) {
			if (c[i] > 0) diff++;
		}
		ll ans = -1;
		for (ll x = N+1;; x++) {
			ll y = x;
			ll p = sp[y];
			ll k = 0;
			while(y > 1) {
				y /= p;
				k++;
				if (sp[y] != p) {
					bool preveq = (c[p] == d[p]);
					c[p] = max(k, c[p]);
					d[p] = max(k, d[p]);
					bool noweq = (c[p] == d[p]);
					if (preveq == false && noweq == true) diff--;
					if (preveq == true && noweq == false) diff++;
					k = 0;
					p = sp[y];
				}
			}
			if (diff == 0) {
				ans = x; break;
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
		cout << "Testing MissingLCM (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449400778;
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
		MissingLCM _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 2;
				_received = _obj.getMin(N); break;
			}
			case 1:
			{
				int N = 2;
				_expected = 4;
				_received = _obj.getMin(N); break;
			}
			case 2:
			{
				int N = 3;
				_expected = 6;
				_received = _obj.getMin(N); break;
			}
			case 3:
			{
				int N = 4;
				_expected = 8;
				_received = _obj.getMin(N); break;
			}
			case 4:
			{
				int N = 5;
				_expected = 10;
				_received = _obj.getMin(N); break;
			}
			case 5:
			{
				int N = 42;
				_expected = 82;
				_received = _obj.getMin(N); break;
			}
			case 6:
			{
				int N = 999999;
				_expected = 1999966;
				_received = _obj.getMin(N); break;
			}
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.getMin(N); break;
			}*/
			/*case 8:
			{
				int N = ;
				_expected = ;
				_received = _obj.getMin(N); break;
			}*/
			/*case 9:
			{
				int N = ;
				_expected = ;
				_received = _obj.getMin(N); break;
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
