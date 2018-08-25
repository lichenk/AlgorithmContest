#include <bits/stdc++.h>
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
const int INF=INT_MAX;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int MAXN = 200004;
struct edge {
  ll a, b, cap, flow, id;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[MAXN];

/*void add_edge_bidir (ll a, ll b, ll cap, ll id) {
  //prllf("%lld->%lld:%lld\n",a,b,cap);
  edge e1 = { a, b, cap, 0, id};
  edge e2 = { b, a, cap, 0, -id};
  assert(a>=0);
  dinic_graph[a].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e2);
}*/

void add_edge (ll a, ll b, ll cap, ll id) {
  //prllf("%lld->%lld:%lld\n",a,b,cap);
  edge e1 = { a, b, cap, 0, id};
  edge e2 = { b, a, 0, 0, 0};
  dinic_graph[a].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((ll) dinic_edge.size());
  dinic_edge.push_back (e2);
}

bool bfs() {
  ll qh=0, qt=0;
  q[qt++] = dinic_src;
  memset (d, -1, dinic_numnodes * sizeof d[0]);
  d[dinic_src] = 0;
  while (qh < qt && d[dinic_dest] == -1) {
    ll v = q[qh++];
    for (size_t i=0; i<dinic_graph[v].size(); ++i) {
      ll id = dinic_graph[v][i],
        to = dinic_edge[id].b;
      if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[dinic_dest] != -1;
}
 
ll dfs (ll v, ll flow) {
  if (!flow)  return 0;
  if (v == dinic_dest)  return flow;
  for (; ptr[v]<dinic_graph[v].size(); ++ptr[v]) {
    ll id = dinic_graph[v][ptr[v]],
      to = dinic_edge[id].b;
    if (d[to] != d[v] + 1)  continue;
    ll pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
    if (pushed) {
      dinic_edge[id].flow += pushed;
      dinic_edge[id^1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
ll dinic(ll src, ll dest, ll numnodes) {
  if (src==dest) return INF;
  dinic_src = src;
  dinic_dest = dest;
  dinic_numnodes = numnodes;
  ll flow = 0;
  for (;;) {
    if (!bfs())  break;
    memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
    while (ll pushed = dfs (dinic_src, INF))
      flow += pushed;
  }
  return flow;
}
void dinic_clear(ll numnodes) {
  dinic_edge.clear();
  for (ll v=0;v<numnodes;v++) dinic_graph[v].clear(); 
}
const int mn=2e5+4;
int vfinal[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int id=1;id<=m;id++) {
    int a=rint()-1,b=rint()-1,c=rint();
    add_edge(a,b,c,id);
    add_edge(b,a,c,-id);
  }
  dinic(0,n-1,n);
  for (auto &e:dinic_edge) {
    int id=e.id;
    if (id>0) {
      if (e.flow==0) vfinal[id]=1;
    }
    if (id<0) {
      if (e.flow>0) vfinal[-id]=1;
    }
  }
  for (int id=1;id<=m;id++) {
    printf("%d\n",vfinal[id]);
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