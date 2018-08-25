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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int MAXN=1e5+4;
const int MAXP=MAXN;
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

pair<int,int> factorize_dest[500*5];
int factorize_tmp[500*5];
int factorize(int x) {
  const int power=1;
  int tsz=0;
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
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  return didx;
}

//int divisors_dest[50000*2]; // This needs to be larger than you think
void getdivisors(int x, vi &divisors_dest) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize(x);
  int sz=1;
  divisors_dest.PB(1);
  for (int pi=0;pi<numprimes;pi++) {
    int p=factorize_dest[pi].fst; int elim=factorize_dest[pi].snd;
    int pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        divisors_dest.PB(divisors_dest[i]*pp);
        sz++;
      }
    }
  }
}
ll c3(ll n) {
  return (n*(n-1)*(n-2))/6;
}
ll c2(ll n) {
  return (n*(n-1))/2;
}

const int mn=MAXN;
vi vd[mn];
pii v[3*mn];
int dest[3*mn];

ll solve(int vsz) {
  sort(v,v+vsz);
  int didx=0;
  for (int tidx=0;tidx<vsz;tidx++) {
    int p=v[tidx];
    if (tidx==0||p!=v[tidx-1]) {
      dest[didx++]=MP(p,1);
    }
    else dest[didx-1].snd+=1;
  }
  // All distinct
  ll ans=c3(didx);
  printf("All dist:%lld\n",ans);
  for (int i=0;i<didx;i++) {
    int p=dest[i].snd;
    // 2 same
    if (p>=2) ans+=(didx-1);
    printf("2 same:%lld p:%d didx:%d\n",c2(p)*(didx-1),p,didx);
    // Same
    ans+=c3(p);
    printf("All same:%lld\n",c3(p));
  }
  return ans;
}

int inp[3];
const int ms=1<<3;
int h[ms];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int h=0;
  for (int x=1;x<mn;x++) {
    getdivisors(x,vd[x]);
    chkmax(h,(int)vd[x].size());
  }
  int t=rint();
  for (int ti=0;ti<t;ti++) {
    for (int i=0;i<3;i++) inp[i]=rint();
    int final=0;
    {
      memset(h,0,sizeof h);
      for (int i=0;i<3;i++) for (auto &w:vd[inp[i]]) v[vsz++]=MP(w,1<<i);
      sort(v,v+vsz);
      {
        int sig=0;
        for (int tidx=0;tidx<vsz;tidx++) {
          int p=v[tidx].fst;
          int s=v[tidx].snd;
          if (tidx==0||p!=v[tidx-1].fst) {
            if (sig) ++h[sig];
            sig|=s;
          }
          else sig|=s;
        }
        if (sig) ++h[sig];
      }
      // 3 same
      final+=h[ms-1];
      // 2 same
      for (int s=0;s<ms;s++) {
        if (__builtin_popcount(s)==2) {
          int os=(ms-1)^s;
          final+=h[s]*h[os];
        }
      }
    }
    /*
    ll final=0;
    for (int z=1;z<(1<<3);z++) {
      int vsz=0;
      for (int i=0;i<3;i++) if (z&(1<<i)) for (auto &w:vd[inp[i]]) v[vsz++]=w;
      ll got=solve(vsz);
      printf("z:%d got:%lld\n",z,got);
      if (__builtin_popcount(z)&1) final+=got;
      else final-=got;
    }
    printf("%lld\n",final);*/
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