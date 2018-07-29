#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

class LagrangeInterpolation {
	static const int mod = 1000 * 1000 * 1000 + 7;
	int gcd(int a, int b, int& x, int& y) {
		if (!a) {
			x = 0, y = 1;
			return b;
		}
		int xx, yy, g = gcd(b % a, a, xx, yy);
		x = yy - b / a * xx;
		y = xx;
		return g;
	}

	inline int normal(int n) {
		n %= mod;
		(n < 0) && (n += mod);
		return n;
	}

	inline int inv(int a) {
		int x, y;
		assert(gcd(a, mod, x, y) == 1);
		return normal(x);
	}

	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return int((a * (ll)b) % mod); }
	inline int _div(int a, int b) { return mul(a, inv(b)); }
public:
	int interpolate(const vector<int>& y, int x) {
		int ans = 0;
		int k = 1;
		int ysz=(int)(y.size());
		if (x<ysz) return y[x];
		for (int j=1;j<ysz;j++) {
			k = mul(k, normal(x - j));
			k = _div(k, normal(0 - j));
		}
		for (int i=0;i<ysz;i++) {
			ans = add(ans, mul(y[i], k));
			if (i + 1 >= ysz) break;
			k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
			k = mul(k, _div(normal(i - (ysz - 1)), normal(i + 1)));
		}
		return ans;
	}
};

int dp[51][100];
int f(int k, int n) {
	int dpval=dp[k][n]; if (dpval!=-1) return dpval;
	if (k==0) return dp[k][n]=n;
	ll ans=0;
	for (int x=1;x<=n;x++) ans+=f(k-1,x);
	return dp[k][n]=(int)(ans%MOD);
}
LagrangeInterpolation lg;
class SuperSum {
	public:
	int calculate(int k, int n) {
		memset(dp,-1,sizeof dp);
		vector<int> y;
		for (int x=1;x<=(k+2);x++) {
			//printf("x:%d res:%d\n",x,f(k,x));
			y.PB(f(k,x));
		}
		int ans=lg.interpolate(y,n-1);
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
		cout << "Testing SuperSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523831815;
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
		SuperSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				int n = 3;
				_expected = 6;
				_received = _obj.calculate(k, n); break;
			}
			case 1:
			{
				int k = 2;
				int n = 3;
				_expected = 10;
				_received = _obj.calculate(k, n); break;
			}
			case 2:
			{
				int k = 4;
				int n = 10;
				_expected = 2002;
				_received = _obj.calculate(k, n); break;
			}
			case 3:
			{
				int k = 10;
				int n = 35;
				_expected = 150595840;
				_received = _obj.calculate(k, n); break;
			}
			/*case 4:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
			}*/
			/*case 5:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
			}*/
			/*case 6:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
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
