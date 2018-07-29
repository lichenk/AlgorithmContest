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

mint f[2][4][4];

mint getn(int n, int x) {
	if (x==0) return mint(2)^n;
	else if (x==1) return (mint(2)^n)-1;
	else if (x==2) return mint(2);
	else return mint(2);
}

mint getc(int n, int x) {
	if (x==0) return mint(2)^n;
	else if (x==1) return mint(1);
	else if (x==2) return mint(2);
	else return mint(1);
}

mint solve(vector<ll> h) {
	if (h.size()==0) return mint(1);
	int n=h.size();
	int cur=0,nxt=1;
	memset(f,0,sizeof f);
	int cur=0,nxt=1;
	for (int i=0;i<n;i++) {
		int l=(i-1>=0)?h[i-1]:0;
		int m=h[i];
		int r=(i+1<n)?h[i+1]:0;
		memset(f[nxt],0,sizeof f[nxt]);
		for (int lx=0;lx<4;lx++) for (int ly=0;ly<4;ly++) {
			mint now=f[cur][x][y]; if (now.get()==0) continue;
			for (int rx=0;rx<4;rx++) for (int ry=0;ry<4;ry++) {
				bool ok=0;
				if (l==r) {
					if ((lx&rx)&&(ly&ry)) ok=1;
				}
				else if (l<r) {
					if ((lx&rx)&&(ly&ry)&&(ly&rx)) ok=1;
				}
				else {
					if ((lx&rx)&&(ly&ry)&&(lx&ry)) ok=1;
				}
				if (r>=m&&ry!=3) ok=0;
				if (ok) {
					mint cx=getc(min(r,h),rx);
					mint cy=(r>=l)?getn(h-min(r,h),ry):getc(h-min(r,h),ry);
					f[nxt][rx][ry]+=now*c;
				}
			}
		}
		swap(cur,nxt);
	}
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
	//printf("g:%lld e:%lld hir:%lld n:%lld ans:%d\n",g,e,hir,n,ans.get());
	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<ll> h(n);
	for (int i=0;i<n;i++) cin>>h[i];
	ll ones=0;
	vector<ll> v;
	mint prod=1;
	for (auto &w:h) {
		if (w==1) {
			ones++;
			prod*=solve(v);
			v.clear();
		}
		else {
			v.PB(w);
		}
	}
	prod*=solve(v);
	prod*=(mint(2)^ones);
	printf("%d\n",prod.get());
}

