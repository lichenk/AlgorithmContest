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
vector<int> h[mn];
set<pii> g[mn];
int deg[mn];
priority_queue<pii,vector<pii>,greater<pii> > pq;
void rm(int x, int y) {;
  g[x].erase(MP(deg[y],y));
  g[y].erase(MP(deg[x],x));
  for (auto &w:g[x]) {
    int z=w.snd;
    g[z].erase(MP(deg[x],x));
    g[z].insert(MP(deg[x]-1,x));
  }
  for (auto &w:g[y]) {
    int z=w.snd;
    g[z].erase(MP(deg[y],y));
    g[z].insert(MP(deg[y]-1,y));
  }
  deg[x]--;
  deg[y]--;
  if (deg[x]>0) pq.push(MP(deg[x],x));
  if (deg[y]>0) pq.push(MP(deg[y],y));
}
bool done[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  if (m&1) {
    printf("No solution\n"); return 0;
  }
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    h[x].PB(y);
    h[y].PB(x);
  }
  for (int x=1;x<=n;x++) {
    deg[x]=h[x].size();
    pq.push(MP(deg[x],x));
  }
  for (int x=1;x<=n;x++) {
    for (auto &y:h[x]) g[x].insert(MP(deg[y],y));
  }
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    int x=got.snd;
    if (done[x]) continue;
    done[x]=1;
    if (deg[x]==0) continue;
    if (deg[x]==1) {
      int y=(g[x].begin())->snd;
      auto it=g[y].begin();
      while(it->snd==x) ++it;
      int z=it->snd;
      rm(x,y); rm(y,z);
      printf("%d %d %d\n",x,y,z);
    }
    else {
      auto it=g[x].begin();
      int y=it->snd;
      ++it;
      int z=it->snd;
      rm(x,y); rm(x,z);
      printf("%d %d %d\n",y,x,z);
    }
  }
}
