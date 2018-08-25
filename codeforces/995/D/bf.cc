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
const int mn=1<<10;
int a[mn];
ll dp[mn][mn];
int n,t;
ll f(int c, int u) {
  ll dpval=dp[c][u];
  if (dpval!=-1) return dpval;
  if (u==0) return dp[c][u]=a[c];
  ll lo=LLONG_MAX,hi=LLONG_MIN;
  for (int i=0;i<n;i++) {
    if (u&(1<<i)) {
      for (int b=0;b<2;b++) {
        int nc=c|(b<<i);
        int nu=u^(1<<i);
        ll got=f(nc,nu);
        //printf("got:%lld\n",got);
        chkmin(lo,got);
        chkmax(hi,got);
      }
    }
  }
  //printf("c:%d u:%d lo:%lld hi:%lld\n",c,u,lo,hi);
  return dp[c][u]=lo+hi;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int r=rint();
  t=1<<n;
  for (int i=0;i<t;i++) {
    a[i]=rint();
  }
  double d=t;
  memset(dp,-1,sizeof dp);
  printf("%.7f\n",f(0,t-1)/d);
  for (int i=0;i<r;i++) {
    int z=rint(),v=rint();
    a[z]=v;
    memset(dp,-1,sizeof dp);
    printf("%.7f\n",f(0,t-1)/d);
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