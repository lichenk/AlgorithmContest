#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1<<30;
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
ll rint();char rch();long long rlong();

const ll mn=(2e5)+4;
vector<ll> g[mn];
ll a[mn];
ll dpn[2][mn];
ll dps[2][mn];;
ll numpaths(ll t, ll x, ll p) {
  ll dpval=dpn[t][x];
  if (dpval!=-1) return dpval;
  ll now=t;
  for (auto &y:g[x]) {
    if (y==p) continue;
    now+=numpaths(t^1,y,x);
  }
  return dpn[t][x]=(now%MOD);
}
ll sumpaths(ll t, ll x, ll p) {
  ll dpval=dps[t][x];
  if (dpval!=-1) return dpval;
  ll now=t?a[x]:0;
  ll toadd=t?a[x]:(MOD-a[x]);
  for (auto &y:g[x]) {
    if (y==p) continue;
    now=(now+sumpaths(t^1,y,x)+numpaths(t^1,y,x)*(ll)toadd)%MOD;
  }
  return dps[t][x]=now;
}
ll final=0;
void dfs(ll x, ll p) {
  for (ll t=0;t<2;t++) {
    ll toadd=t?a[x]:(MOD-a[x]);
    ll prevcnt=t;
    ll prevsum=t?a[x]:0;
    for (auto &y:g[x]) {
      if (y==p) continue;
      ll rightcnt=numpaths(t^1,y,x);
      ll rightsum=sumpaths(t^1,y,x);
      //printf("x:%d t:%d y:%d prevcnt:%d prevsum:%d rightcnt:%d rightsum:%d. Add %lld %lld\n",x,t,y,prevcnt,prevsum,rightcnt,rightsum,
      //  prevcnt*(ll)rightsum,prevsum*(ll)rightcnt);
      final=(final+prevcnt*(ll)rightsum)%MOD;
      final=(final+prevsum*(ll)rightcnt)%MOD;
      prevcnt+=rightcnt; if (prevcnt>=MOD) prevcnt-=MOD;
      prevsum=(prevsum+rightsum+rightcnt*(ll)toadd)%MOD;
    }
  }
  for (auto &y:g[x]) {
    if (y==p) continue;
    dfs(y,x);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dps,-1,sizeof dps);
  memset(dpn,-1,sizeof dpn);
  
  ll n=rint();
  for (ll x=1;x<=n;x++) {
    ll got=rint(); if (got<0) got+=MOD;
    a[x]=got;
  }
  for (ll i=0;i<n-1;i++) {
    ll x=rint(),y=rint(); g[x].PB(y); g[y].PB(x);
  }
  dfs(1,-1);
  ll ans=(final*2)%MOD; if (ans<0) ans+=MOD;
  for (ll x=1;x<=n;x++) {
    ans+=a[x]; if (ans>=MOD) ans-=MOD;
  }
  ans%=MOD; if (ans<0) ans+=MOD;
  printf("%lld\n",ans);
}





long long rint()
{
  long long x; scanf("%lld",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}