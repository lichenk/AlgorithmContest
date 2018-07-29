#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll f[51];
bool seen[51];
class Privateparty {
	public:
	double getexp(vector <int> a) {
		ll n = a.size();
		for (ll i = 0; i <= n; i++) {
			f[i] = 0;
		}
		for (ll x = 0; x < n; x++) {
			for (ll i = 0; i < n; i++) seen[i] = false;
			ll y = x;
			ll len = 1;
			seen[x] = true;
			while(1) {
				y = a[y];
				if (seen[y]) break;
				seen[y] = true;
				len++;
			}
			ll add = 1;
			//printf("%lld has len %lld\n",x,len);
			for (ll k = 1; k <= len; k++) {
				//printf("Adding %lld to %lld\n",add,k);
				f[k] += add;
				add *= -1;
			}
		}
		ld invfac = 1;
		ld ans = 0;
		for (ll k = 1; k <= n; k++) {
			ans += invfac*f[k];
			invfac /= (k+1);
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
		cout << "Testing Privateparty (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450804233;
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
		Privateparty _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,1};
				_expected = 2.0;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,0};
				_expected = 1.5;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,1,1};
				_expected = 2.5;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0,1,1,2};
				_expected = 3.166666666666667;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {3,2,1,0};
				_expected = 2.0;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {1,0,2};
				_expected = 2;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getexp(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
