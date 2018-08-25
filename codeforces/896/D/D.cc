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
int rint();char rch();long long rlong();

int VMOD;
vector<int> VMODP;
void specialInit(int vmod) {
  VMOD=vmod;
  VMODP.clear();
  int slim=min(vmod-1,(int)sqrt(vmod)+2);
  for (int x=2;x<=slim;x++) {
    if (x>vmod) break;
    if (vmod%x==0) {
      vmod/=x;
      while(vmod%x==0) vmod/=x;
      VMODP.PB(x);
    }
  }
}

struct SpecialInt {
  static const int VMODPSZ;
  unsigned x;
  int pe[9]; // Primorial(10)=6469693230> 2e9 limit
  SpecialInt() {memset(pe,0,sizeof pe);}
  void pr() {
    printf("x:%d ",x);
    for (int i=0;i<(int)VMODP.size();i++) printf("(%d^%d) ",VMODP[i],pe[i]);
    printf("\n");
  }
  SpecialInt(signed sig) {
    for (int i=0;i<(int)VMODP.size();i++) {
      int p=VMODP[i]; int e=0;
      while(sig%p==0) {sig/=p; e++;}
      pe[i]=e;
    }
    x=sig;
  }
  int get() const {
    unsigned ans=x;
    for (int i=0;i<(int)VMODP.size();i++) {
      int p=VMODP[i]; int e=pe[i];
      assert(e>=0);
      for (int j=0;j<e;j++) ans*=p;
    }
    return ans%VMOD;
  }

  SpecialInt &operator+=(SpecialInt that) {
    unsigned long long ax=x,bx=that.x;
    for (int i=0;i<(int)VMODP.size();i++) {
      unsigned p=VMODP[i];
      int diff=pe[i]-that.pe[i];
      for (int j=0;j<-diff;j++) bx*=p;
      if (diff>0) {
        pe[i]=that.pe[i];
        for (int j=0;j<diff;j++) ax*=p;
      }
    }
    unsigned long long sig=ax+bx;
    for (int i=0;i<(int)VMODP.size();i++) {
      int p=VMODP[i]; int e=0;
      while(sig%p==0) {sig/=p; e++;}
      pe[i]+=e;
    }
    x=(int)(sig%VMOD);
    return *this;
  }

  SpecialInt &operator-=(SpecialInt that) {*this += (-that); return *this; }

  SpecialInt &operator*=(SpecialInt that) {
    for (int i=0;i<(int)VMODP.size();i++) pe[i]+=that.pe[i];
    x = (unsigned)(((unsigned long long)x * that.x) % VMOD);
    return *this;
  }
  SpecialInt &operator/=(SpecialInt that) { return *this *= that.inverse(); }

  SpecialInt &operator*=(int that) {(*this)*=SpecialInt(that); return *this;}
  SpecialInt &operator/=(int that) {(*this)/=SpecialInt(that); return *this;}
  SpecialInt &operator+=(int that) {(*this)+=SpecialInt(that); return *this;}
  SpecialInt &operator-=(int that) {(*this)-=SpecialInt(that); return *this;}

  SpecialInt operator*(SpecialInt that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(SpecialInt that) const { return SpecialInt(*this) /= that; }
  SpecialInt operator+(SpecialInt that) const { return SpecialInt(*this) += that; }
  SpecialInt operator-(SpecialInt that) const { return SpecialInt(*this) -= that; }

  SpecialInt operator*(int that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(int that) const { return SpecialInt(*this) /= that; }
  SpecialInt operator+(int that) const { return SpecialInt(*this) += that; }
  SpecialInt operator-(int that) const { return SpecialInt(*this) -= that; }


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
    t.x = (x == 0) ? 0 : VMOD - x;
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

const int mn=30+4;

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
  if (r>n) return 0;
}

void go() {
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

SpecialInt a[mn];
void filla() {
  a[0]=SpecialInt(1);
  a[1]=SpecialInt(1);
  for (int n=2;n<7;n++) {
    if (n==6) {
      SpecialInt numer=(SpecialInt(2*n+1)*a[n-1]+SpecialInt(3*n-3)*a[n-2]);
      numer.pr();
      SpecialInt denom=SpecialInt(n+2);
      denom.pr();
    }
    a[n]=(SpecialInt(2*n+1)*a[n-1]+SpecialInt(3*n-3)*a[n-2])/SpecialInt(n+2);
    printf("n:%d a[n]:%d\n",n,a[n].get());
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  VMOD=1000000007;
  specialInit(VMOD);
  filla(); return 0;
  go(); return 0;
  /*int n,l,r; scanf("%d%d%d%d",&n,&VMOD,&l,&r);
  int ar=solve(n,r);
  int al=solve(n,l-1);
  int ans=ar-al;
  printf("%d\n",ans);*/
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