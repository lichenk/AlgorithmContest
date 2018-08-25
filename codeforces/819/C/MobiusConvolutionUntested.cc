#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint();char rch();long long rlong();
const int MAXP=1e6+1;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}



int factorize_tmp[64];
void factorize(int *inp, vpii &factorize_dest) {
  const int power=1;
  int tsz=0;
  for (int i=0;i<3;i++) {
    int x=inp[i];
    while(x>=MAXP) {
      bool found=false;
      for (auto &p:gpv) {
        if (p*(ll)p>x) break;
        while ((x%p)==0) {
          //printf("x:%lld p:%d\n",x,p);
          x/=p;
          factorize_tmp[tsz++]=p;
          found=true;
        }
      }
      if (x<MAXP) break;
      if (!found) break;
    }
    if (x<MAXP) {
      while(x>1) {
        int p=ap[x];
        x/=p;
        factorize_tmp[tsz++]=p;
      }
    }
    if (x>1) factorize_tmp[tsz++]=x;
  }
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  factorize_dest.resize(64);
  for (int tidx=0;tidx<tsz;tidx++) {
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  factorize_dest.resize(didx);
}


vpii gcd(const vpii &af,const vpii &bf) {
  vpii ans;
  int bsz=bf.size();
  int bi=0;
  for (auto &aw:af) {
    int p=aw.fst;
    while(bi<bf.size()&&bf[bi].fst<p) {bi++;}
    int e=0;
    if (bi<bf.size()&&p==bf[bi].fst) {
      e=min(aw.snd,bf[bi].snd);
    }
    ans.PB(MP(p,e));
  }
  return ans;
}

/*vpii divide(vpii af,const vpii &bf) {
  int asz=af.size();
  int ai=0;
  for (auto &bw:bf) {
    int p=bw.fst;
    while(af[ai]<p) {ai++;}
    if (p==af[ai].fst) {
      af[ai].snd-=bw.snd;
    }
  }
  return af;
}*/
class MobiusConvolution {
static const int maxn=1e5+2;
static const int maxk=15+2;
public:
  vpii gcdsa;
  vi ve;
  vi vp;
  int preProd[maxk],sufProd[maxk];
  int klim;
  ll a[maxn];
  ll final;
  ll b;
  void load(vpii vfac, ll inpb) {
    b=inpb;
    ve.clear(); vp.clear();
    ve.reserve(vfac.size());vp.reserve(vfac.size());
    for (auto &w:vfac) {
      vp.PB(w.fst); ve.PB(w.snd+1);
    }
    init();
  }
  void init() {
    final=0;
    klim=ve.size();
    printf("klim:%d\n",klim);
    preProd[0]=1;
    for (int k=0;k<klim;k++) preProd[k+1]=preProd[k]*ve[k];
    sufProd[klim]=1;
    for (int k=klim-1;k>=0;k--) sufProd[k]=sufProd[k+1]*ve[k];
  }
  void initrecur(int k, int idx, ll val) {
    printf("k:%d klim:%d\n",k,klim);
    if (k==klim) {
      printf("idx:%d val:%lld\n",idx,val);
      a[idx]=val;
      return;
    }
    int step=preProd[k];
    ll nval=0;
    int elim=ve[k];
    for (int e=0;e<elim;e++) {
      nval+=val;
      initrecur(k+1,idx,nval);
      idx+=step;
    }
  }
  void conv() {
    for (int k=0;k<klim;k++) {
      for (int pre=0;pre<preProd[k];pre++) {
        int sufLim=sufProd[k+1]*preProd[k+1];
        for (int suf=0;suf<sufLim;suf+=preProd[k+1]) {
          int base=pre+suf;
          int step=preProd[k];
          int elim=ve[k];
          int lo=base,hi=base+step;
          for (int e=0;e<elim-1;e++) {
            a[hi]+=a[lo];
            lo=hi;
            hi+=step;
          }
        }
      }
    }
  }
  void compute(int k, bool above, int idx) {
    if (k==gcdsa.size()) {
      if (above) final+=a[idx];
      return;
    }
    int elim=ve[k];
    int step=preProd[k];
    for (int e=0;e<elim;e++) {
      int el=elim-1-e;
      if (el>gcdsa[k].snd) {
        compute(k+1,true,idx);
      }
      else {
        compute(k+1,above,idx);
      }
      idx+=step;
    }
  }

};
MobiusConvolution mc;
vpii af,bf,sf;


int va[3],vb[3],vs[3];
ll solve() {
  //af.clear(); bf.clear(); sf.clear();
  vs[0]*=2;
  //ll a=va[0]*(ll)va[1]*(ll)va[2];
  ll b=vb[0]*(ll)vb[1]*(ll)vb[2];
  //ll s=vs[0]*(ll)vs[1]*(ll)vs[2];
  factorize(va,af);
  mc.load(af,b);
  mc.initrecur(0,0,1);
  mc.conv();
  factorize(vs,sf);
  mc.gcdsa=gcd(af,sf);
  mc.compute(0,false,0);
  ll ans1=b-mc.final;

  factorize(vb,bf);
  vpii g=gcd(bf,sf);
  ll ans2=1;
  for (auto &w:g) {
    printf("p:%d e:%d\n",w.fst,w.snd);
    ans2*=(w.snd+1);
  }
  printf("ans1:%lld ans2:%lld\n",ans1,ans2);
  ll final=ans1+ans2;
  return final;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int t=rint();
  for (int ti=0;ti<t;ti++) {
    
    for (int i=0;i<3;i++) va[i]=rint();
    for (int i=0;i<3;i++) vb[i]=rint();
    for (int i=0;i<3;i++) vs[i]=rint();
    ll ans=solve();
    printf("%lld\n",ans);
  }
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