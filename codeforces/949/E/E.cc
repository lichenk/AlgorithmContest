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
const int mk=18;
int bins(vi &v, int x) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;  
}
bool haslt(vi &v, int x) {
  int imin=bins(v,x);
  return (v.size()>0)&&(imin>=1);
}
bool hasgeq(vi &v, int x) {
  int imin=bins(v,x);
  return (0<=imin&&imin<v.size());
}
vi v[mk][2];
pair<int,pii> solve(vi &inp) {
  int inpmin=INF;
  for (auto &x:inp) {
    chkmin(inpmin,x);
  }
  for (auto &rawx:inp) {
    int x=rawx-inpmin;
    for (int k=0;k<mk;k++) {
      v[k][(x>>k)&1].PB(x&((1<<k)-1));
    }
  }
  for (int k=0;k<mk;k++) for (int b=0;b<2;b++) {
    sort(v[k][b].begin(),v[k][b].end());
    auto it = std::unique(v[k][b].begin(), v[k][b].end());
    v[k][b].resize( std::distance(v[k][b].begin(),it) );
  }
  pair<int,pii> ans=MP(INF,MP(INF,INF));
  for (int sub=0;sub<(1<<mk);sub++) {
    int toadd=inpmin+sub;
    if (toadd<0) continue;
    int res=0;
    for (int k=0;k<mk;k++) {
      int t=(toadd>>k)&1;
      {
        int b=t; // b needs to flip
        int toaddmsk=toadd&((1<<k)-1);
        int needatleast=(1<<k)-toaddmsk;
        if (hasgeq(v[k][b], needatleast)) {res|=1<<k; continue;}
      }
      {
        int b=t^1; // b needs to remain constant
        int toaddmsk=toadd&((1<<k)-1);
        int needlessthan=(1<<k)-toaddmsk;
        if (haslt(v[k][b], needlessthan)) {res|=1<<k;}
      }
    }
    int pz=res&(~sub);
    int pop=__builtin_popcount(sub|pz);
    if (pop<ans.fst) ans=MP(pop,MP(sub,pz));
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
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