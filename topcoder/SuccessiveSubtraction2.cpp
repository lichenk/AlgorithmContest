#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXK 5
#define MAXN 2000
#define NEGINF -999999999999999LL
ll f[MAXK][MAXN];
class SuccessiveSubtraction2 {
	public:
	vector <int> calc(vector <int> a, vector <int> p, vector <int> v) {
		vector<int> final;
		ll n = a.size();
		ll vsz = v.size();
		for (ll t = 0; t < vsz; t++) {
			a[p[t]] = v[t];
			for (ll k = 0; k < MAXK; k++) {
				f[k][0] = (k==0)?a[0]:NEGINF;
				ll sgn = (k%2)?1:-1;
				for (ll x = 1; x < n; x++) {
					f[k][x] = NEGINF;
					if (f[k][x-1] != NEGINF) {
						f[k][x] = f[k][x-1] + sgn*a[x];
					}
					if (k > 0 && f[k-1][x-1] != NEGINF) {
						f[k][x] = max(f[k-1][x-1] + sgn*(-1)*a[x], f[k][x]);
					}
					//printf("k: %lld x: %lld f: %lld\n",k,x,f[k][x]);
				}
			}
			ll ans = f[0][n-1];
			for (ll k = 0; k < MAXK; k++) {
				ans = max(ans, f[k][n-1]);
			}
			final.PB(ans);
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
		cout << "Testing SuccessiveSubtraction2 (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452395704;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SuccessiveSubtraction2 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1, 2, 3, 4, 5};
				int p[] = {1, 2, 0, 4, 3};
				int v[] = {3, 9, -10, 5, 1};
				int __expected[] = {10, 16, 5, 5, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {-100, -100, -100, -100, -100};
				int p[] = {0, 1, 2, 3, 4};
				int v[] = {0, 0, 0, 0, 0};
				int __expected[] = {400, 300, 200, 100, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {83, 0, 25, 21};
				int p[] = {0, 3, 2, 1, 3, 1, 2};
				int v[] = {10, -90, 33, 52, -100, 0, 45};
				int __expected[] = {56, 125, 133, 81, 91, 143, 155 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1};
				int p[] = {0, 0, 0, 0};
				int v[] = {10, -10, 100, -100};
				int __expected[] = {10, -10, 100, -100 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63};
				int p[] = {19, 5, 3, 10, 4, 18, 5, 2, 0, 15};
				int v[] = {-19, 21, 7, -66, 38, -39, -22, 24, -32, 13};
				int __expected[] = {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {1,1};
				int p[] = {0};
				int v[] = {1};
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {1,1,1};
				int p[] = {0};
				int v[] = {1};
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			/*case 7:
			{
				int a[] = ;
				int p[] = ;
				int v[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.calc(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
