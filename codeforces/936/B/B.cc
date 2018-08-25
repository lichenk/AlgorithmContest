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
const int N=1e5+4;
vector<int> g[N];
int scc[N], nsc, low[N], num[N], mn, st[N], sz;
void dfs(int p) { low[p] = num[p] = mn++; st[sz++] = p;
  for (int i : g[p]) if (scc[i] == -1) {
    if (num[i] == -1) dfs(i);
    low[p] = min(low[p], low[i]); }
  if (low[p] == num[p]) { while(scc[p] != nsc) scc[st[--sz]] = nsc; ++nsc; } }
// Set up adj and n first; memset num and scc to -1
// then after get_scc() you can read scc array and nsc variable
int vcnt[N];
void get_scc(int n) {
  memset(num,-1,sizeof num); memset(scc,-1,sizeof scc);
  nsc=mn=sz=0; for(int i=1; i<=n; ++i) if (num[i] == -1) dfs(i);
  //for (int x=1;x<=n;x++) printf("x:%d scc:%d\n",x,scc[x]);
  for (int x=1;x<=n;x++) vcnt[scc[x]]++;
  for (int x=1;x<=n;x++) if (vcnt[scc[x]]<=1) scc[x]=-1;
}

bool hasdraw=0;
bool sn[N];
void dfsdraw(int x) {
  if (sn[x]) return;
  sn[x]=true;
  if (scc[x]!=-1) hasdraw=true;
  for (auto &y:g[x]) dfsdraw(y);
}
int hi[N][2];
int dp[N][2];
vi vans;
int f(int x, int d) {
  if (dp[x][d]!=-1) return dp[x][d];
  if (hi[x][d]>=4) return 0;
  hi[x][d]++;
  if (g[x].size()==0) {
    return dp[x][d]=(d&1);
  }
  int ans=0;
  for (auto &y:g[x]) {
    if (f(y,d^1)) {
      vans.PB(y);
      return dp[x][d]=1;
    }
  }
  return dp[x][d]=0;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int x=1;x<=n;x++) {
    int c=rint();
    for (int i=0;i<c;i++) {
      int y=rint();
      g[x].PB(y);
    }
  }
  int s=rint();
  get_scc(n);
  dfsdraw(s);
  memset(dp,-1,sizeof dp);
  int ans=f(s,0);
  if (ans) {
    reverse(vans.begin(),vans.end());
    printf("Win\n%d ",s);
    for (auto &w:vans) printf("%d ",w);
    printf("\n");
  }
  else if (hasdraw) {
    printf("Draw\n");
  }
  else {
    printf("Lose\n");
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