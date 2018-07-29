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
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int readInt()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}


const ll MAXN = 404;
struct edge {
  ll a, b, cap, flow;
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
 
void add_edge (ll a, ll b, ll cap) {
  //printf("%lld->%lld:%lld\n",a,b,cap);
  edge e1 = { a, b, cap, 0 };
  edge e2 = { b, a, 0, 0 };
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
  for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
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

int n,m;
int getnode(int x, int y) {
  return x*m+y;
}
bool valid(int x, int y) {
  return (x<n&&y<m&&a[x][y]!='#');
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
  for (int x=0;x<n;x++) cin>>a[x];
  int tlim=0;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    char c=a[x][y];
    if ('1'<=c&&c<='8') tlim++;
  }
  for (int i=0;i<tlim;i++) {cin>>t2val[i];}
  int src=n*m;
  int target=src+1;
  for (int z=0;z<(1<<tlim);z++) {
    int ans=0;
    for (int t=0;t<tlim;t++) if(z&(1<<t)) ans+=t2val[t];
    for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
      {
        {
          int ny=y;
          int nx=x+1;
          if (valid[nx][ny]) add_edge(getnode(x,y),getnode(nx,ny),1);
        }
        {
          int ny=y+1;
          int nx=x;
          if (valid[nx][ny]) add_edge(getnode(x,y),getnode(nx,ny),1);
        }
      }
      if (x==0||x==n-1||y==0||y==m-1) {
        add_edge(getnode(x,y), target, INF);
      }
    }
    dinic_clear(target+1);
  }
}

