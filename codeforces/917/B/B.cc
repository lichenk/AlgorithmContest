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
int dp[100][100][26];
int n;
vector<pii> g[100];
int f(int x, int o, int c) {
  //if (c>=26) return 0;
  int dpval=dp[x][o][c];
  if (dpval!=-1) return dpval;
  int win=0;
  for (auto &w:g[x]) {
    int y=w.fst,nc=w.snd;
    if (nc>=c) {
      int cand=f(o,y,nc);
      if (cand==0) {
        //printf("x:%d o:%d c:%d wins at y:%d\n",x,o,c,y);
        win=1; break;
      }
    }
  }
  return dp[x][o][c]=win;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  n=rint(); int m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(); int c=rch()-'a';
    --x; --y;
    g[x].PB(MP(y,c));
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      int ans=f(x,y,0);
      if (ans==0) printf("B");
      else printf("A");
    }
    printf("\n");
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