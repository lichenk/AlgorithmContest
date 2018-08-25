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
const int mk=702;
bitset<mk> dp[702][702];
bitset<mk> seen[702][702];
int a[702];
int g[702][702];
bool query(int l, int r, int p) {
  if (l>r) return 1;
  if (seen[l][r][p]) return dp[l][r][p];
  seen[l][r][p]=true;
  for (int x=l;x<=r;x++) {
    // [l,x] [x+1,r]
    if (g[x][p]>1) {
      if (query(l,x-1,x)&&query(x+1,r,x)) return dp[l][r][p]=true;
    }
  }
  return dp[l][r][p]=false;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  sort(a,a+n);
  for (int x=0;x<n;x++) for (int y=0;y<x;y++) g[y][x]=g[x][y]=__gcd(a[x],a[y]);
  int ok=0; for (int x=0;x<n;x++) {
    if(query(0,n-1,x)) {
      ok=1; break;
    }
  }
  if(ok) printf("Yes\n");
  else printf("No\n");
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