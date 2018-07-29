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

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i < ll(r); i++)

ll mod;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (!a) {
        x = 0, y = 1;
        return b;
    }
    ll xx, yy, g = gcd(b % a, a, xx, yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}
 
inline ll normal(ll n) {
    n %= mod;
    (n < 0) && (n += mod);
    return n;
}
 
inline ll inv(ll a) {
    ll x, y;
    assert(gcd(a, mod, x, y) == 1);
    return normal(x);
}
 
inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
inline ll mul(ll a, ll b) { return ll(a * 1ll * b % mod); }
inline ll _div(ll a, ll b) { return mul(a, inv(b)); }
 
inline ll binPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

// Lagrange polynomial. Input is f(0),f(1),...,f(n). Returns f(x)
ll calc(const vector<ll>& y, ll x) {
    ll ysz = y.size();
    if (x<ysz) return y[x];
    ll ans = 0;
    ll k = 1;
    fore(j, 1, ysz) {
        k = mul(k, normal(x - j));
        k = _div(k, normal(0 - j));
    }
    forn(i, ysz) {
        ans = add(ans, mul(y[i], k));
        if (i + 1 >= ysz) break;
        k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
        k = mul(k, _div(normal(i - (ysz - 1)), normal(i + 1)));
    }
    return ans;
}
ll garner(vector<Pii> mr, ll mod){
  mr.emplace_back(mod, 0);

  vector<ll> coffs(sz(mr), 1);
  vector<ll> constants(sz(mr), 0);
  FOR(i, sz(mr) - 1){
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
    ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
    if (v < 0) v += mr[i].first;

    for (ll j = i + 1; j < sz(mr); j++) {
      (constants[j] += coffs[j] * v) %= mr[j].first;
      (coffs[j] *= mr[i].first) %= mr[j].first;
    }
  }

  return constants[sz(mr) - 1];
}

ll f[2][2004];
class CandyDrawing {
	public:
	int findProbability(int N, int K, int MOD) {
		mod=MOD;
		for (ll i=0;i<=K;i++) f[0][i]=0;
		f[0][0]=1;
		ll lim = 3*K+100;
		vector<ll> y;
		for (ll t=1;t<=lim;t++) {
			ll curr=t%2; ll prev=(t+1)%2;
			for (ll i=0;i<=K;i++) f[curr][i]=0;
			for (ll i=0;i<=K;i++) {
				f[curr][i] = add(f[curr][i], f[prev][i]);
				f[curr][i+1] = add(f[curr][i+1], mul(f[prev][i],t));
			}
			//printf("%d:%d\n",t,f[curr][K]);
			y.PB(f[curr][K]);
		}
		ll ans = calc(y,N-1);
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
		cout << "Testing CandyDrawing (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457078689;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CandyDrawing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 1;
				int MOD = 1000000007;
				_expected = 3;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 1:
			{
				int N = 3;
				int K = 2;
				int MOD = 1000000007;
				_expected = 11;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 2:
			{
				int N = 10;
				int K = 4;
				int MOD = 1000000007;
				_expected = 157773;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 3:
			{
				int N = 1000000000;
				int K = 1000;
				int MOD = 1000000009;
				_expected = 629516825;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 4:
			{
				int N = 3;
				int K = 1;
				int MOD = 1000000007;
				_expected = 6;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 5:
			{
				int N = 4;
				int K = 1;
				int MOD = 1000000007;
				_expected = 10;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			case 6:
			{
				int N = 5;
				int K = 1;
				int MOD = 1000000007;
				_expected = 15;
				_received = _obj.findProbability(N, K, MOD); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int MOD = ;
				_expected = ;
				_received = _obj.findProbability(N, K, MOD); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int MOD = ;
				_expected = ;
				_received = _obj.findProbability(N, K, MOD); break;
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
