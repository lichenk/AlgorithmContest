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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll MAXN=100000+4;
const ll MAXM=300+4;
ll fac[MAXN+2];
ll invfac[MAXN+2];
ll f[MAXM+2][MAXM+2];
ll s[MAXN+2][MAXM+2];
class CyclesNumber {
	public:
	vector <int> getExpectation(vector <int> nv, vector <int> mv) {
		fac[0]=1;
		for (ll x=1;x<MAXN;x++) {
			fac[x]=(fac[x-1]*x)%MOD;
		}
		invfac[0]=1;
		for (ll x=1;x<MAXN;x++) {
			invfac[x]=(invfac[x-1]*mod_inv(x,MOD))%MOD;
		}
		for (ll k=0;k<MAXM;k++) {
			for (ll x=0;x<MAXM;x++) {
				f[k][x]=0;
			}
		}
		f[0][0]=1;
		for (ll k=1;k<MAXM;k++) {
			for (ll x=0;x<MAXM;x++) {
				ll sum=0;
				for (ll y=0;y<x;y++) {
					ll d=x-y;
					sum+=(f[k-1][y]*invfac[d])%MOD;
				}
				f[k][x] = sum%MOD;
			}
		}
		for (ll k=0;k<MAXM;k++) {
			for (ll x=0;x<MAXM;x++) {
				f[k][x] = (f[k][x]*fac[x])%MOD;
			}
		}
		s[0][0]=1;
		for (ll x=1;x<MAXN;x++) {
			s[x][0]=0;
			ll klim=min(x,MAXM-1);
			for (ll k=1;k<=klim;k++) {
				s[x][k]=((x-1)*s[x-1][k]+s[x-1][k-1])%MOD;
			}
		}
		vector<int> final;
		for (ll i=0;i<nv.size();i++) {
			ll n=nv[i]; ll m=mv[i];
			ll ans=0;
			for (ll k=0;k<=m;k++) {
				ll add=(f[k][m]*s[n+1][k+1])%MOD;
				//printf("%lld: %lld %lld\n",k,f[k][m],(s[n][k]*fac[n])%MOD);
				ans=(ans+add)%MOD;
			}
			final.PB(ans%MOD);
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
		cout << "Testing CyclesNumber (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459222887;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CyclesNumber _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n[] = {2};
				int m[] = {2};
				int __expected[] = {5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 1:
			{
				int n[] = {3};
				int m[] = {0};
				int __expected[] = {6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 2:
			{
				int n[] = {1, 2, 3};
				int m[] = {1, 3, 3};
				int __expected[] = {1, 9, 53 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 3:
			{
				int n[] = {10, 20, 30};
				int m[] = {10, 20, 30};
				int __expected[] = {586836447, 544389755, 327675273 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 4:
			{
				int n[] = {2};
				int m[] = {1};
				int __expected[] = {3};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 5:
			{
				int n[] = {2};
				int m[] = {3};
				int __expected[] = {9};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 6:
			{
				int n[] = {3};
				int m[] = {3};
				int __expected[] = {53};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 7:
			{
				int n[] = {3};
				int m[] = {2};
				int __expected[] = {23};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 8:
			{
				int n[] = {3};
				int m[] = {1};
				int __expected[] = {11};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
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
