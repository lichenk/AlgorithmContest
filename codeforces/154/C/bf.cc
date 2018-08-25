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

const int mn=1000000+4;
vi g[mn];
map<vi,int> h1[mn];
map<vi,int> h2[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int x=1;x<=n;x++) {
    sort(g[x].begin(),g[x].end());
    ++h1[g[x].size()][g[x]];
  }
  ll ans=0;
  for (int s=0;s<mn;s++) {
    for (auto &w:h1[s]) {
      ll x=w.snd;
      ans+=x*(x-1);
    }
  }
  for (int x=1;x<=n;x++) {
    g[x].PB(x); sort(g[x].begin(),g[x].end());
    ++h2[g[x].size()][g[x]];
  }
  for (int s=0;s<mn;s++) {
    for (auto &w:h2[s]) {
      ll x=w.snd;
      ans+=x*(x-1);
    }
  }
  ans/=2;
  printf("%lld\n",ans);
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