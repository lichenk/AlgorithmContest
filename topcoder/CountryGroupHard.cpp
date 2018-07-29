#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 108
ll f[MAXN][MAXN], g[MAXN][MAXN];
class CountryGroupHard {
	public:
	string solve(vector <int> a) {
		ll n = a.size();
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < n; y++) {
				g[x][y] = 0;
			}
		}
		for (ll d = 1; d <= n; d++) {
			for (ll x = 0; x < n; x++) {
				ll y = x+d-1;
				if (y >= n) break;
				bool good = true;
				for (ll i = x; i <= y; i++) {
					if (!(a[i] == d || a[i] == 0)) {
						good = false; break;
					}
				}
				if (good) {
					g[x][y]++;
				}
				f[x][y] = g[x][y];
				for (ll k = x; k < y; k++) {
					f[x][y] += f[x][k]*g[k+1][y];
					//if (f[x][k]*g[k+1][y]) {
					//	printf("k:%lld c:%lld\n",k,f[x][k]*g[k+1][y]);
					//}
				}
				if (f[x][y] > 1) f[x][y] = 2;
			}
		}
		assert(f[0][n-1] > 0);
		if (f[0][n-1] == 1) {
			return "Sufficient";
		}
		else {
			return "Insufficient";
		}

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
		cout << "Testing CountryGroupHard (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452489105;
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
		CountryGroupHard _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,2,3,0,0};
				_expected = "Sufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,2,0};
				_expected = "Insufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,3,0,0,3,0};
				_expected = "Sufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0,0,3,3,0,0};
				_expected = "Insufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2,2,0,2,2};
				_expected = "Sufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {0};
				_expected = "Sufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {0,0};
				_expected = "Insufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 7:
			{
				int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = "Insufficient";
				_received = _obj.solve(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
