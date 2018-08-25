#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=1e5+4;
vector<int> g[mn];
vector<int> tree[mn];
vector<int> other[mn];
bool seen[mn];
int par[mn];
void dfs1(int x, int p) {
  seen[x]=true;
  par[x]=p;
  for (auto &y:g[x]) {
    if (seen[y]) other[x].PB(y);
    else {tree[x].PB(y); dfs1(y,x);}
  }
}
int dpf[mn][2];
int dpg[mn][2];
bool dfs2(int x, int p, int down) {
  int dpval=dpf[x][down];
  if (dpval!=-1) return dpval;
  int osz=other.size();
  int need=(down+osz)&1;
  bool dp[2][2];
  dp[0][need]=1;
  dp[0][need^1]=0;
  int cur=0,nxt=1;
  for (auto &y:tree[x]) {
    memset(dp[nxt],0,sizeof dp[nxt]);
    for (int k=0;k<2;k++) {
      if (dp[cur][k]==0) continue;
      for (int d=0;d<2;d++) {
        bool got=dfs2(y,x,d);
        if (got) {
          dp[nxt][k^d^1]=1;
        }
      }
    }
    swap(cur,nxt);
  }
  int tsz=tree[x].size();
  for (int i=0;i<tsz;i++) {
    
  }
  return dpf[x][down]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  if (m&1) {
    printf("No solution\n"); return 0;
  }
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y);
    g[y].PB(x);
  }
  parent[1]=-1;
  dfs1(1,-1);
  bool can=dfs2(1,-1,0);
  if (!can) {
    printf("No solution\n"); return 0;
  }

}
