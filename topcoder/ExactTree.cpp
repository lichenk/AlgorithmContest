#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define INF 9999999999LL
ll f[51][100];
class ExactTree {
	public:
	int getTree(int ni, int mi, int ri) {
		ll n = ni; ll m = mi; ll r = ri;
		// Fill f with INF
		for (ll x = 0; x <= n; x++) {
			for (ll a = 0; a < m; a++) {
				f[x][a] = INF;
			}
		}
		f[1][0] = 0;
		for (ll k = 2; k <= n; k++) {
			for (ll x = 2; x <= k+1-x; x++) { // 1...k-1 if failure
				ll y = k+1-x;
				for (ll a = 0; a < m; a++) {
					for (ll b = 0; b < m; b++) {
						ll c = (a+b)%m;
						f[k][c] = min(f[x][a] + f[y][b], f[k][c]);
					}
				}
			}
			for (ll a = 0; a < m; a++) {
				ll q = k-1;
				ll t = f[q][a] + q * (n-q);
				ll c = t % m;
				f[k][c] = min(t, f[k][c]);
			}
			//for (ll c = 0; c < m; c++) {
			//	printf("%lld %lld: %lld\n",k,c,f[k][c]);
			//}
		}
		ll ans = f[n][r];
		if (ans >= INF) {
			return -1;
		}
		else {
			return ans;
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
		cout << "Testing ExactTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449132002;
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
		ExactTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int m = 100;
				int r = 9;
				_expected = 9;
				_received = _obj.getTree(n, m, r); break;
			}
			
			case 1:
			{
				int n = 4;
				int m = 100;
				int r = 10;
				_expected = 10;
				_received = _obj.getTree(n, m, r); break;
			}
			case 2:
			{
				int n = 4;
				int m = 100;
				int r = 0;
				_expected = -1;
				_received = _obj.getTree(n, m, r); break;
			}
			case 3:
			{
				int n = 6;
				int m = 2;
				int r = 0;
				_expected = 28;
				_received = _obj.getTree(n, m, r); break;
			}
			case 4:
			{
				int n = 6;
				int m = 2;
				int r = 1;
				_expected = 25;
				_received = _obj.getTree(n, m, r); break;
			}
			case 5:
			{
				int n = 25;
				int m = 100;
				int r = 0;
				_expected = 700;
				_received = _obj.getTree(n, m, r); break;
			}
			case 6:
			{
				int n = 50;
				int m = 97;
				int r = 89;
				_expected = 2708;
				_received = _obj.getTree(n, m, r); break;
			}
			case 7:
			{
				int n = 3;
				int m = 100;
				int r = 4;
				_expected = 4;
				_received = _obj.getTree(n, m, r); break;
			}
			case 8:
			{
				int n = 2;
				int m = 100;
				int r = 1;
				_expected = 1;
				_received = _obj.getTree(n, m, r); break;
			}
			
			/*case 9:
			{
				int n = ;
				int m = ;
				int r = ;
				_expected = ;
				_received = _obj.getTree(n, m, r); break;
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
