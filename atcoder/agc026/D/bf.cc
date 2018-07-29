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


const int MOD=1000000007;
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

mint solve(vector<ll> h) {
	if (h.size()==0) return mint(1);
	ll e=0,g=0;
	ll n=h.size();
	ll hir=0;
	for (int i=0;i<n;i++) {
		assert(h[i]>=2);
		ll side=max((i-1>=0)?h[i-1]:0LL,(i+1<n)?h[i+1]:0LL);
		ll paired=min(side,h[i]);
		g+=paired;
		e+=h[i]-paired; // Unpaired with left or right -> Can choose anything.
		chkmax(hir,paired); // Max paired height
	}
	mint ans=mint(2)^e;
	if (g>0) {
		assert(g>=4);
		ans*=((mint(2)^hir)+(mint(2)^n)-mint(2));
	}
	else {
		assert(h.size()==1);
		assert(e==h[0]);
		assert(ans==mint(2)^h[0]);
	}
	printf("g:%lld e:%lld hir:%lld n:%lld ans:%d\n",g,e,hir,n,ans.get());
	return ans;
}
int a[10][10];
char b[10][10];
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<int> h(n);
	for (int i=0;i<n;i++) cin>>h[i];
  memset(a,-1,sizeof a);
	int sum=0; for (int x=0;x<n;x++) {
    for (int y=0;y<h[x];y++) a[x][y]=sum++;
  }
  int ans=0;
  for (int z=0;z<(1<<sum);z++) {
    int good=1;
    for (int x=0;x<n;x++) {
      for (int y=0;y<h[x];y++) {
        bool ok=1; int num=0;
        for (int i=x;i<=x+1;i++) for (int j=y;j<=y+1;j++) {
          int id=a[i][j];
          if (id==-1) {ok=0;}
          else {num+=(z>>id)&1;}
        }
        if (ok&&num!=2) {good=0; break;}
      }
      if (good==0) break;
    }
    if (good==0) continue;
    memset(b,'.',sizeof b);
    for (int x=0;x<n;x++) {
      for (int y=0;y<h[x];y++) {
        int id=a[x][y];
        char c='.';
        if (id!=-1) {
          c=(z&(1<<id))?'R':'B';
        }
        b[y][x]=c;
      }
    }
    for (int y=3;y>=0;y--) {b[y][9]='\0'; printf("%s\n",b[y]);}
    printf("\n");
    ans+=good;;
  }
  printf("%d\n",ans);
}

