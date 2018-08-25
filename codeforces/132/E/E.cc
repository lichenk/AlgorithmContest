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
const int mv=26,mn=256;
int a[mn];
int vlastocc[mn];
int dp[mv][mn][mn];
int f(int l, int r, int vars) {
  if (l>r) return 0;
  if (l==r) return 0;
  int dpval=dp[vars][l][r];
  if (dpval!=-1) return dpval;
  int ans1=max(
    f(l+1,r,vars),
    f(l,r-1,vars)
    );
  int final=ans1;
  if (vars>0&&vlastocc[r]==l) {
    int cand=f(l+1,r-1,vars-1)+__builtin_popcount(a[r]);
    chkmax(final,cand);
  }
  return dp[vars][l][r]=final;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),vars=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  map<int,int> h;
  for (int i=1;i<=n;i++) {
    int x=a[i];
    auto it=h.find(x);
    if (it!=h.end()) vlastocc[i]=it->snd;
    else vlastocc[i]=-1;
    h[x]=i;
  }
  memset(dp,-1,sizeof dp);
  int final=f(1,n,vars);
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