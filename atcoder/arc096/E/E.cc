#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
int MOD;
 
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
const int MAXFACT=3000+4;
mint fact[MAXFACT+1],invfact[MAXFACT+1];
void init() {
  mint got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got*=(x+1);
  }
  got=got.inverse();
  for (int x=MAXFACT;x>=0;x--) {
    got*=(x+1);
    invfact[x]=got;
  }
}
mint binom(int n,int k) {
  if (n<k) return mint(0);
  if (n<0||k<0) return mint(0);
  return fact[n]*invfact[k]*invfact[n-k];
}
 
mint starbar(int stars, int parts) {
  if (parts==0) {
    return mint((stars==0)?1:0);
  }
  if (parts<=0||stars<0) return mint(0);
  return binom(stars+parts-1,parts-1);
}
 
mint geom(int r, int n) {
  // 1+r+...+r^n. Note 0^0 is 1
  if (r==1) return mint(n+1);
  return (mint(r)^(n+1)-1)/(r-1);
}
 
const int STIRLING2_MAX=3004;
mint _stirling2[STIRLING2_MAX+1][STIRLING2_MAX+1];
bitset<STIRLING2_MAX+1> _stirling2_valid[STIRLING2_MAX+1];
mint stirling2(int n, int k) {
  if (_stirling2_valid[n][k]) {
    return _stirling2[n][k];
  }
  _stirling2_valid[n][k]=true;
  if (n==0&&k==0) {
    return _stirling2[n][k]=1;
  }
  else if (n==0||k==0) {
    return _stirling2[n][k]=0;
  }
  else {
    return _stirling2[n][k]=stirling2(n-1,k)*k+stirling2(n-1,k-1);
  }
}
 
const int STIRLING1_MAX=3000;
mint _stirling1[STIRLING1_MAX+1][STIRLING1_MAX+1];
bitset<STIRLING1_MAX+1> _stirling1_valid[STIRLING1_MAX+1];
mint stirling1(int n, int k) {
  if (_stirling1_valid[n][k]) {
    return _stirling1[n][k];
  }
  _stirling1_valid[n][k]=true;
  if (n==0&&k==0) {
    return _stirling1[n][k]=1;
  }
  else if (n==0||k==0) {
    return _stirling1[n][k]=0;
  }
  else {
    return _stirling1[n][k]=stirling1(n-1,k)*n+stirling1(n-1,k-1);
  }
}
 
mint stirling2Special(int n, int k) {
	// Split n distinct objects into k+1 identical boxes, and last box can be empty.
	return stirling2(n+1,k+1);
	mint ans=0;
	for (int x=0;x<=n;x++) {
		ans+=stirling2(x,k)*binom(n,x);
	}
	return ans;
}
 
 
int mod_pow(int a, int n, int MOD) { int ret = 1; int p = a % MOD; while (n) { if (n & 1) ret = (ret *(ll) p) % MOD; p = (p *(ll) p) % MOD; n >>= 1; } return ret; }
void solve(long long n, long long _M){
	MOD=_M;
	init();
	mint final=0,sgn=1;
	for (int k=0;k<=n;k++) {
		mint ways=0;
		mint C=mint(2)^(n-k);
		mint cur=1;
		for (int i=0;i<=k;i++) {
			ways+=stirling2Special(k,i)*cur;
			//printf("k:%d i:%d s:%d cur:%d\n",k,i,stirling2Special(k,i).get(),cur.get());
			cur*=C;
		}
		mint mul=mint(2)^(mod_pow(2,n-k,MOD-1));
		mint bin=binom(n,k);
		mint contrib=ways*mul*bin;
		//printf("k:%d ways:%d mul:%d bin:%d contrib:%d\n",k,ways.get(),mul.get(),bin.get(),contrib.get());
		final+=sgn*contrib;
		sgn=-sgn;
	}
	printf("%d\n",final.get());
}
 
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	solve(N, M);
	return 0;
}
