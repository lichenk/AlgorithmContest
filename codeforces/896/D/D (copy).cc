#include "bits/stdc++.h"
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
const int INF=1<<30;
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

int VMOD;
vector<int> VMODP;
void specialInit(int vmod) {
  VMOD=vmod;
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

const int mn=2e5+4;

SpecialInt fac[mn],invfac[mn];
void facInit(int n) {
  invfac[0]=fac[0]=SpecialInt(1);
  for (int x=1;x<=n;x++) {
    fac[x]=fac[x-1]*x;
    invfac[x]=fac[x].inverse();
  }
}

SpecialInt binom(int n, int k) {
  if (0<=k&&k<=n) return fac[n]*invfac[k]*invfac[n-k];
  else return 0;
}

SpecialInt catalan(int n) {
  return fac[2*n]*invfac[n+1]*invfac[n];
}

int cat[mn/2];
/*int sumcatrange(int l, int r) {
  int ans=cat[r];
  if (l>0) ans-=cat[l-1];
  if (ans<0) ans+=VMOD;
  return ans;
}*/
int solve(int n, int r) {
  if (r<0) return 0;
  int final=0;
  for (int t=0;t<=n/2;t++) {
    int con=binom(n,2*t).get();
    int elim=min(t,r/2);
    int sum=cat[t+elim];
    //sumcatrange(t,t+elim);
    //printf("A t:%d con:%d sum:%d elim:%d\n",t,con,sum,elim);
    final=(final+con*(ll)sum)%VMOD;
  }
  if (r>0) {
    for (int t=0;t<=(n-1)/2;t++) {
      int con=binom(n,2*t+1).get();
      int elim=min(t,(r-1)/2);
      int sum=cat[t+1+elim];
      //int sum=(cat[t+1]*(ll)(elim+1))%VMOD;
      //int sum=sumcatrange(t+1,t+1+elim);
      //printf("B t:%d con:%d sum:%d elim:%d\n",t,con,sum,elim);
      final=(final+con*(ll)sum)%VMOD;
    }
  }
  return final;
}

int bf(int n, int r) {
  int ans=0;
  int zlim=1; for (int i=0;i<n;i++) zlim*=3;
  for (int zz=0;zz<zlim;zz++) {
    int z=zz;
    int s=0;
    for (int i=0;i<n;i++) {
      s+=((z%3)-1);
      z/=3;
      if (s<0) s=-INF;
    }
    if (s==r) ans++;
  }
  return ans;
}

int smart(int n, int r) {
  if ((n+r)&1) return 0;
  if (r>n) return 0;
  n/=2;
  //               1        prefixsum of previous
  if (r==0) return cat[n];
  if (r==1) return cat[n+1];
  if (r==2) return cat[n+1]-cat[n];
  if (r==3) return cat[n+2]-2*cat[n+1];
  if (r==4) return cat[n+2]-3*cat[n+1]+cat[n];
  if (r==5) return cat[n+3]-4*cat[n+2]+3*cat[n+1];
  if (r==6) return cat[n+3]-5*cat[n+2]+6*cat[n+1]-cat[n];
  if (r==7) return cat[n+4]-6*cat[n+3]+10*cat[n+2]-4*cat[n+1];
  if (r==8) return cat[n+4]-7*cat[n+3]+15*cat[n+2]-10*cat[n+1]+cat[n];
}

void go() {
  for (int n=1;n<=16;n++) {
    ll sum=0;
    for (int k=0;k<=n;k++) {
      auto ans=binom(2*n,2*k)*binom(2*k,k)/(k+1);
      sum+=ans.get();
    }
    printf("%d\n",(int)(sum%VMOD));
  }

  for (int n=1;n<=16;n++) {
    for (int r=0;r<=8;r++) {
      int bff=bf(n,r);
      int ss=smart(n,r);
      if (bff!=ss) {
        printf("n:%d r:%d ss:%d bff:%d\n",n,r,ss,bff);
      }
    }
  }
}



int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  VMOD=1000000007;
  specialInit(VMOD);
  facInit(mn-1);
  cat[0]=1;
  for (int x=1;x<mn/2;x++) {
    cat[x]=catalan(x).get();
  }
  go(); return 0;
  int n,l,r; scanf("%d%d%d%d",&n,&VMOD,&l,&r);
  int ar=solve(n,r);
  int al=solve(n,l-1);
  int ans=ar-al;
  printf("%d\n",ans);
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