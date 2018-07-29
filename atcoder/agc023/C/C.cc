#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};
const int mn=11;
bitset<mn+1> b;
mint bf(int n) {
  vector<int> v; for (int x=0;x<n;x++) v.PB(x);
  int ans=0;
  do {
    b.reset();
    for (int t=0;t<n;t++) {
      int i=v[t];
      b[i]=true;
      b[i+1]=true;
      if (b.count()==n+1) {
        ans+=t+1;
        break;
      }
    }
  } while(next_permutation(v.begin(),v.end()));
  return ans;
}


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
LagrangeInterpolation lg;
void solve(int n){
  vector<int> vy;
  for (int x=1;x<mn;x++) {
    mint ans=bf(x);
    vy.PB(ans.get());
  }
  int ans=lg.interpolate(vy,n-2);
  printf("%d\n",ans);
  //for (int x=0;x<5;x++) printf("%d %d bf:%d\n",x,lg.interpolate(vy,x),bf(x));
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	solve(N);
	return 0;
}

