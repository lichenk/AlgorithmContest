#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define sz(c) ((ll)(c).size())
using namespace std;
typedef long long ll;
// FFT
typedef pair<ll, ll> Pii;
 
#define FOR(i,n) for(ll i = 0; i < (n); i++)
 
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
 
template<ll mod, ll primitive_root>
class NTT {
public:
  ll get_mod() const { return mod; }
  void _ntt(vector<ll>& a, ll sign) {
    const ll n = sz(a);
 
    const ll g = primitive_root; //g is primitive root of mod
    ll h = (ll)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
    if (sign == -1) h = (ll)mod_inv(h, mod); //h = h^-1 % mod
 
    ll i = 0;
    for (ll j = 1; j < n - 1; ++j) {
      for (ll k = n >> 1; k >(i ^= k); k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }
 
    for (ll m = 1; m < n; m *= 2) {
      const ll m2 = 2 * m;
      const ll base = mod_pow(h, n / m2, mod);
      ll w = 1;
      FOR(x, m) {
        for (ll s = x; s < n; s += m2) {
          ll u = a[s];
          ll d = a[s + m] * w % mod;
          a[s] = u + d;
          if (a[s] >= mod) a[s] -= mod;
          a[s + m] = u - d;
          if (a[s + m] < 0) a[s + m] += mod;
        }
        w = w * base % mod;
      }
    }
 
    for (auto& x : a) if (x < 0) x += mod;
  }
  void ntt(vector<ll>& input) {
    _ntt(input, 1);
  }
  void intt(vector<ll>& input) {
    _ntt(input, -1);
    const ll n_inv = mod_inv(sz(input), mod);
    for (auto& x : input) x = x * n_inv % mod;
  }
 
  vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
    ll ntt_size = 1;
    while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;
 
    vector<ll> _a = a, _b = b;
    _a.resize(ntt_size); _b.resize(ntt_size);
 
    ntt(_a);
    ntt(_b);
 
    FOR(i, ntt_size){
      (_a[i] *= _b[i]) %= mod;
    }
 
    intt(_a);
    return _a;
  }
  vector<ll> powup(const vector<ll>& a, ll exponent){
    ll ntt_size = 1;
    while (ntt_size < (sz(a)*exponent)) ntt_size *= 2;
 
    vector<ll> _a = a;
    _a.resize(ntt_size);
 
    ntt(_a);
 
    FOR(i, ntt_size){
      _a[i]=mod_pow(_a[i], exponent, mod);
    }
 
    intt(_a);
    return _a;
  }
};
 
typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;
 
vector<ll> mulfft(vector<ll> a, vector<ll> b,ll mod){
  for (auto& x : a) x %= mod;
  for (auto& x : b) x %= mod;
  
  NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);
 
  const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
  const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
  const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
  const ll m12_mod = m1 * m2 % mod;
  vector<ll> ret(sz(x));
  FOR(i, sz(x)){
    ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
    if (v1 < 0) v1 += m2;
    ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
    if (v2 < 0) v2 += m3;
    ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
    if (constants3 < 0) constants3 += mod;
    ret[i] = constants3;
  }
 
  return ret;
}
 
vector<ll> exppoly(vector<ll> base, ll e, ll mod) {
  vector<ll> ans = {1};
  while(e > 0) {
    if (e % 2 == 1) {
      ans = mulfft(ans, base, mod);
      ans.resize(5004);
      e--;
    }
    else {
      base = mulfft(base, base, mod);
      base.resize(5004);
      e /= 2;
    }
  }
  return ans;
}
 
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=5002;
int g[mn+2][mn+2];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n; string s; cin>>n>>s;
	for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) g[x][y]=0;
	g[0][0]=1;
	for (ll x=0;x<mn;x++) {
		for (ll y=0;y<mn;y++) {
			ll v=g[x][y];
			if (v==0) continue;
			g[x+1][y+1]+=2*v;
			g[x+1][y+1]%=MOD;
			g[x+1][max(0LL,y-1)]+=v;
			g[x+1][max(0LL,y-1)]%=MOD;
		}
	}
	vector<ll> f;
	for (ll y=0;y<mn;y++) f.PB(g[y][0]);
 
	for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) g[x][y]=0;
	g[0][0]=1;
	for (ll x=0;x<mn;x++) {
		for (ll y=0;y<mn;y++) {
			ll v=g[x][y];
			if (v==0) continue;
			g[x+1][y+1]+=2*v;
			g[x+1][y+1]%=MOD;
			if (y-1>=0) {
				g[x+1][y-1]+=v;g[x+1][y-1]%=MOD;
			}
		}
	}
	ll k=s.length();
	vector<ll> h;
	for (ll y=0;y<mn;y++) h.PB(g[y][0]);
	vector<ll> hpow=exppoly(h,k,MOD);
	vector<ll> ans=mulfft(hpow,f,MOD);
	ll final=ans[n-k];
	printf("%lld\n",final);
}