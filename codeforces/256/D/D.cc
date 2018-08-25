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
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int VMOD=777777777;
vector<int> VMODP;
void specialInit() {
  //VMOD=vmod;
  const int vmod=VMOD;
  VMODP.clear();
  int slim=min(vmod-1,((int)sqrt(vmod))+2);
  for (int x=2;x<=slim;x++) {
    if (vmod%x==0) {
      int ok=1;
      for (auto &w:VMODP) if (x%w) {ok=0; break;}
      if (ok) VMODP.PB(x);
    }
  }
}

struct SpecialInt {
  static const int VMODPSZ;
  unsigned x;
  int pe[9]; // Primorial(10)=6469693230> 2e9 limit
  SpecialInt() {memset(pe,0,sizeof pe);}
  SpecialInt(signed sig) {
    for (int i=0;i<(int)VMODP.size();i++) {
      int p=VMODP[i]; int e=0;
      while(sig%p==0) {sig/=p; e++;}
      pe[i]=e;
    }
    x=sig;
  }
  int get() const {
    int ans=x;
    for (int i=0;i<(int)VMODP.size();i++) {
      int p=VMODP[i]; int e=pe[i];
      for (int j=0;j<e;j++) ans=(int)((ans*(ll)p)%VMOD);
    }
    return ans;
  }
 
  SpecialInt &operator*=(SpecialInt that) {
    for (int i=0;i<(int)VMODP.size();i++) pe[i]+=that.pe[i];
    x = (unsigned)(((unsigned long long)x * that.x) % VMOD);
    return *this;
  }
  SpecialInt &operator/=(SpecialInt that) { return *this *= that.inverse(); }

  SpecialInt &operator*=(int that) {(*this)*=SpecialInt(that); return *this;}
  SpecialInt &operator/=(int that) {(*this)/=SpecialInt(that); return *this;}

  SpecialInt operator*(SpecialInt that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(SpecialInt that) const { return SpecialInt(*this) /= that; }

  SpecialInt operator*(int that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(int that) const { return SpecialInt(*this) /= that; }


  SpecialInt inverse() const {
    signed a = x, b = VMOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += VMOD;
    SpecialInt res; res.x = (unsigned)u; for (int i=0;i<(int)VMODP.size();i++) res.pe[i]=-pe[i];
    return res;
  }
 
  bool operator==(SpecialInt that) const {
    for (int i=0;i<(int)VMODP.size();i++) if (pe[i]!=that.pe[i]) return false;
    return x == that.x;
  }
  bool operator!=(SpecialInt that) const {
    return !(*this!=that);
  }
  SpecialInt operator-() const {
    SpecialInt t;
    t.x = x == 0 ? 0 : VMOD - x;
    for (int i=0;i<(int)VMODP.size();i++) t.pe[i]=pe[i];
    return t;
  }
};
SpecialInt operator^(SpecialInt a, unsigned long long k) {
  SpecialInt r(1);
  while(k) {
    if(k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}

typedef SpecialInt sint;

const int mn=(1<<8)+1;
SpecialInt fac[mn],invfac[mn];
void facInit() {
  invfac[0]=fac[0]=SpecialInt(1);
  for (int x=1;x<mn;x++) {
    fac[x]=fac[x-1]*x;
    invfac[x]=fac[x].inverse();
  }
}
SpecialInt binom(int n, int k) {
  if (0<=k&&k<=n) return fac[n]*invfac[k]*invfac[n-k];
  else return 0;
}
int gk;

int dp[mn][mn];
int f(int val, int cnt) {
	int dpval=dp[val][cnt]; if (dpval!=-1) return dpval;
	if (val==0) {
		if (cnt==0) return 1;
		else return 0;
	}
	int final=0;
	for (int take=0;take<=cnt;take++) {
		if ((take==val)==(val==gk)) {
			int got=f(val-1,cnt-take);
			int C=binom(cnt,take).get();
			final=(final+got*(ll)C)%VMOD;
		}
	}
	return dp[val][cnt]=final%VMOD;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  specialInit(); facInit(); memset(dp,-1,sizeof dp);
  int n,inpk; scanf("%d%d",&n,&inpk);
  gk=n-inpk;
  int final=f(n,n);
  printf("%d\n",final);
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}