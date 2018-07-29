#include <bits/stdc++.h>
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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
map<ll,ll> h;
ll solve(ll init) {
	{
		ll x=0;
		ll inv4=mod_inv(4ll,MOD);
		for (ll k=0;k<=100000;k++) {
			auto it=h.find(x);
			if (it==h.end()) {
				h[x]=k;
			}
			else chkmin(it->second,k);
			x=((x-3+MOD)*inv4)%MOD;
		}
	}
	{
		ll x=init;
		ll ans=INF;
		for (ll k=0;k<=100000;k++) {
			auto it=h.find(x);
			if (it!=h.end()) {
				ll cand=k+it->second;
				chkmin(ans,cand);
			}
			x=(8*x+7)%MOD;
		}
		return ans;
	}
}
class CarrotJumping {
	public:
	int theJump(int init) {
		ll ans=solve(init);
		if (ans>100000) return -1;
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
		cout << "Testing CarrotJumping (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491680101;
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
		CarrotJumping _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int init = 125000000;
				_expected = 1;
				_received = _obj.theJump(init); break;
			}
			case 1:
			{
				int init = 281250001;
				_expected = 2;
				_received = _obj.theJump(init); break;
			}
			case 2:
			{
				int init = 18426114;
				_expected = 58;
				_received = _obj.theJump(init); break;
			}
			case 3:
			{
				int init = 4530664;
				_expected = 478;
				_received = _obj.theJump(init); break;
			}
			case 4:
			{
				int init = 705616876;
				_expected = 100000;
				_received = _obj.theJump(init); break;
			}
			case 5:
			{
				int init = 852808441;
				_expected = -1;
				_received = _obj.theJump(init); break;
			}
			/*case 6:
			{
				int init = ;
				_expected = ;
				_received = _obj.theJump(init); break;
			}*/
			/*case 7:
			{
				int init = ;
				_expected = ;
				_received = _obj.theJump(init); break;
			}*/
			/*case 8:
			{
				int init = ;
				_expected = ;
				_received = _obj.theJump(init); break;
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
