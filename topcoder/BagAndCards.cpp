#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll f[508][508];
ll cnt[508][508];
class BagAndCards {
	public:
	int getHash(int ni, int mi, int xi, int ai, int bi, int ci, string isGood) {
ll n = ni;
ll m = mi;
ll x = xi;
ll a = ai;
ll b = bi;
ll c = ci;
		for (ll i = 0; i <= n-1; i++) {
			for (ll j = 0; j <= m-1; j++) {
				cnt[i][j] = x;
				x = ((x * a + b) ^ c) % MOD;
			}
		}
		for (ll i=0; i < n; i++) {
			for (ll t=0;t<m;t++) {
				f[i][t] = 0;
			}
		}
		for (ll i=0; i < n; i++) {
			for (ll t = 0; t < m; t++) {
				for (ll s = 0; s < m; s++) {
					if (isGood[t+s] == 'Y') {
						f[i][t] = (f[i][t] + cnt[i][s])%MOD;
					}
				}
			}
		}
		ll final = 0;
		for (ll i=0; i<n; i++) {
			for (ll j=i+1;j<n;j++) {
				ll ans = 0;
				for (ll t=0;t<m;t++) {
					ll cand = (f[i][t]*cnt[j][t])%MOD;
					while (cand<0) cand += MOD;
					ans = (ans+cand)%MOD;
					while (ans<0) ans += MOD;
				}
				final = (ans ^ final);
			}
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
		cout << "Testing BagAndCards (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453350999;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BagAndCards _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 4;
				int x = 1;
				int a = 1;
				int b = 0;
				int c = 0;
				string isGood = "NNYYNYN";
				_expected = 9;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 1:
			{
				int n = 3;
				int m = 5;
				int x = 1;
				int a = 1;
				int b = 1;
				int c = 2;
				string isGood = "NNYYNYNYN";
				_expected = 1532;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 2:
			{
				int n = 10;
				int m = 20;
				int x = 111;
				int a = 222;
				int b = 333;
				int c = 444;
				string isGood = "NNNNNYYYNNNYYYYYYNNYYYYNNNNYNNYYYNNNYYN" ;
				_expected = 450750683;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 3:
			{
				int n = 2;
				int m = 2;
				int x = 1;
				int a = 1;
				int b = 0;
				int c = 0;
				string isGood = "NNY";
				_expected = 1;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 4:
			{

				int n = 23;
				int m = 238;
				int x = 604413236;
				int a = 982446405;
				int b = 888679033;
				int c = 335365687;
				string isGood = "NNNNYYYNYNYYYYYNYNNNYYYYNNNYYNYYYYNNNYYYYYYNYNYNYNNYYNYNNYYYYYNNNNYYNYNNYYYNYNYNNYNNNNYNYYNYYYNNYYNNYYNYNNNNNYYNNNYNNYNYNYNYYYNYYYYYYYYNYNYNNNNNNYNYNNNNYNYNNYYYNNYYYYNYNYYYYNYNNNNNYYNNNYYYNYNNYNNNYNYNNYNYNYYYNNNYNYNNYYNNNYYYYYYYYNYYYNNYNNNYNYNYYYNNNYYNYNYNNYYNNYYYNYYYYNYNNYYYNYNNNNYNNNYNYYYYNNYYYNYYNYNYYNYNNYNNYNYYNYYYNYYNNYNNYYYNNYNNNYNNNNNNNYYNYNYNYYNNNNYYNNYNYYYYNNYNYNNYNYNYYYYYNNYYYNNNNYNNNNNYYYNNYNYYNYYNNYYYNNNYYYNNYYNNYNYYYYYYNNYYYNNNYNYYNYYYYNYYNNYNYYYNNNYYNNNNNYN";
				_expected = 689993098;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				int x = ;
				int a = ;
				int b = ;
				int c = ;
				string isGood = ;
				_expected = ;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int x = ;
				int a = ;
				int b = ;
				int c = ;
				string isGood = ;
				_expected = ;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
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
