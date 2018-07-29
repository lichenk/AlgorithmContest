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
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef vector<vi> vvi;
class GaussianElimination {
public:
    const bool UNIQUE=false; // Need a unique basis. We do this by eliminating the upper triagle in
    // addition to the lower triangle
    const bool NEEDSOL=true; // Need a linear combination that sums to the solution
    vvi a;
    int sgn=1;
    int xlim,ylim,mod;
    inline int mull(int x, int y) {return (x*(ll)y)%mod;}
    int gauss(vvi inp, int _mod) {
      a=inp;
      // Returns the rank
      int rank=0;
      xlim=a.size(),ylim=a[0].size(),mod=_mod;
      int xlo=0;
      for (int yelim=0;yelim<ylim;yelim++) {
        for (int xs=xlo;xs<xlim;xs++) {
          if (a[xs][yelim]!=0) {
            if (xs!=xlo) {
              sgn=-sgn;
              for (int y=0;y<ylim;y++) swap(a[xs][y], a[xlo][y]);
            }
            int inv=mod_pow(a[xlo][yelim], mod-2, mod);
            for (int y=yelim;y<ylim;y++) {
              a[xlo][y]=mull(a[xlo][y], inv);
            }
            for (int x=xlo+1;x<xlim;x++) {
              if (x==xlo) continue;
              int sub=a[x][yelim];
              if (sub) {
                for (int y=yelim;y<ylim;y++) {
                  a[x][y]=(a[x][y]-sub*(ll)a[xlo][y])%mod;
                  if (a[x][y]<0) a[x][y]+=mod;
                }
              }
            }
            xlo++; rank++;
            break;
          }
        }
      }
      return rank;
    }
    int getdet() {
      assert(xlim==ylim);
      int det=1;
      for (int x=0;x<xlim;x++) {
        det=mull(det,a[x][x]);
      }
      return sgn*det;
    }
};
GaussianElimination G;


const int MAXN = 608;
struct edge {
  int a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
int dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<int> dinic_graph[MAXN];
 
void add_edge (int a, int b, int cap) {
  //printf("%lld->%lld:%lld\n",a,b,cap);
  edge e1 = { a, b, cap, 0 };
  edge e2 = { b, a, 0, 0 };
  dinic_graph[a].push_back ((int) dinic_edge.size());
  dinic_edge.push_back (e1);
  dinic_graph[b].push_back ((int) dinic_edge.size());
  dinic_edge.push_back (e2);
}

bool dinic_bfs() {
  int qh=0, qt=0;
  q[qt++] = dinic_src;
  memset (d, -1, dinic_numnodes * sizeof d[0]);
  d[dinic_src] = 0;
  while (qh < qt && d[dinic_dest] == -1) {
    int v = q[qh++];
    for (size_t i=0; i<dinic_graph[v].size(); ++i) {
      int id = dinic_graph[v][i],
        to = dinic_edge[id].b;
      if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[dinic_dest] != -1;
}
 
int dinic_dfs (int v, int flow) {
  if (!flow)  return 0;
  if (v == dinic_dest)  return flow;
  for (; ptr[v]<(int)dinic_graph[v].size(); ++ptr[v]) {
    int id = dinic_graph[v][ptr[v]],
      to = dinic_edge[id].b;
    if (d[to] != d[v] + 1)  continue;
    int pushed = dinic_dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
    if (pushed) {
      dinic_edge[id].flow += pushed;
      dinic_edge[id^1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
int dinic(int src, int dest, int numnodes) {
  if (src==dest) return INF;
  dinic_src = src;
  dinic_dest = dest;
  dinic_numnodes = numnodes;
  int flow = 0;
  for (;;) {
    if (!dinic_bfs())  break;
    memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
    while (int pushed = dinic_dfs (dinic_src, INF))
      flow += pushed;
  }
  return flow;
}
void dinic_clear(int numnodes) {
  dinic_edge.clear();
  for (int v=0;v<numnodes;v++) dinic_graph[v].clear();  
}


const int mn=608;
bool hasin[mn],hasout[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),p=rint();
  vvi a(n); for (int i=0;i<n;i++) a[i].resize(n);
  int src=n,dest=n+1;
  for (int i=0;i<m;i++) {
    int x=rint()-1,y=rint()-1;
    hasin[y]=true; hasout[x]=true;
    add_edge(x,y,1);
    if (x<y) {
      a[x][y]=1;
    }
    else a[x][y]=p-1;
  }
  int need=0;
  for (int x=0;x<n;x++) {
    if (!hasin[x]) {add_edge(src,x,1); need++;}
    if (!hasout[x]) add_edge(x,dest,1);
  }
  dinic_numnodes=n+2;
  dinic_src=src;
  dinic_dest=dest;
  int flow=dinic(src,dest,n+2);
  if (flow<need) {
    printf("0\n"); exit(0);
  }

//  dinic_numnodes: number of nodes
//dinic_src: Source vertex
//dinic_dest: Target vertex
  int det=G.gauss(a,p);
  int ans=(det*(ll)mod_pow(2,p-2,p))%p;
  printf("%d\n",ans);
}




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

int rint()
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
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
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