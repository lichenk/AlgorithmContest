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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

int ilog2(unsigned int x) {
  return __builtin_clz(x);
}
const int mk=21;
pii expand(int nz, int pz) {
  for (int k=mk-2;k>=0;k--) {
    int msk0=1<<k,msk1=1<<(k+1);
    for (int r=0;r<2;r++) {
      if ((nz>>k)==3) pz|=msk0;
      if ((pz>>k)==3) nz|=msk0;
      if ((msk1&nz)!=0 && (msk0&pz)!=0) nz|=msk0;
      if ((msk1&pz)!=0 && (msk0&nz)!=0) pz|=msk0;
    }
  }
  return MP(nz,pz);
}
pii collapse(int nz, int pz) {
  for (int k=mk-2;k>=0;k--) {
    int msk0=1<<k,msk1=1<<(k+1);
    {
      if ((nz>>k)==3 && (pz&msk0)!=0) nz&=~msk0;
      if ((pz>>k)==3 && (nz&msk0)!=0) pz&=~msk0;
      if ((msk1&nz)!=0 && (msk0&pz)!=0) nz&=~msk0;
      if ((msk1&pz)!=0 && (msk0&nz)!=0) pz&=~msk0;
    }
  }
  return MP(nz,pz);
}
pair<int,pii> solve(vi &inp) {
  int nz=0,pz=0;
  for (auto x:inp) {
    if (x>=0) pz|=x;
    else nz|=(-x);
  }
  pii expanded=expand(nz,pz);
  pii collapsed=collapse(expanded.fst, expanded.snd);
  int cnt=__builtin_popcount(collapsed.fst) + __builtin_popcount(collapsed.snd);
  return MP(cnt,collapsed);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=0;x<16;x++) ilog2(x);
  int n=rint();
  vector<int> a(n);
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  pair<int,pii> ans=solve(a);
  printf("%d\n",ans.fst);
  for (int k=0;k<mk;k++) {
    if (ans.snd.fst&(1<<k)) printf("%d ",-(1<<k));
  }
  for (int k=0;k<mk;k++) {
    if (ans.snd.snd&(1<<k)) printf("%d ",(1<<k));
  }
  //printf("\n");
  //for (auto &x:vans) printf("%d ",x);
  //printf("\n");
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