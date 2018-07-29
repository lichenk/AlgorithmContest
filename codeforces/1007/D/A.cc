#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000003;
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

class TwoSat {
  static const int MAXN=5e6;
  vector<vector<int> > graph, rev_graph;
  vi used, comp, order, res;
  int twosat_cnt = 0;

  void dfs1(int u) { used[u] = true;
    for (auto i = 0u; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!used[v]) dfs1(v); }
    order[twosat_cnt++] = u; }
  void dfs2(int u, int color) { comp[u] = color;
    for (auto i = 0u; i < rev_graph[u].size(); i++) {
      int v = rev_graph[u][i];
      if (comp[v] == -1) dfs2(v, color); } }
  bool twosat() { int n = graph.size();
    for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
    for (int i = 0; i < n; i++) for (auto j = 0u; j < graph[i].size(); j++)
      rev_graph[graph[i][j]].push_back(i);
    for (int i = 0, color = 0; i < n; i++) {
      int u = order[n-i-1];
      if (comp[u] == -1) dfs2(u, color++); }
    for (int i = 0; i < n; i++) if (comp[i] == comp[i^1]) return false;
    for (int i = 0; i < n; i+=2) res[i/2] = (comp[i] > comp[i^1]);
    return true; }
  //if type = 0, we add the edge x -> y, if type = 1, we add the edge ~x -> y
  //if type = 2, we add the edge x -> ~y, if type = 3, we add the edge ~x -> ~y
  //NOTE: each implication and its dual implication is also added, so NO need to
  //add twice for each implication.
  void add(int x, int y) { graph[x].push_back(y); };
  void add_edge(int x, int y, int type) {
    int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
    switch (type) {
      case 0: add(a,b); add(nb, na); break;
      case 1: add(na, b); add(nb, a); break;
      case 2: add(a, nb); add(b, na); break;
      case 3: add(na, nb); add(b,a); break; } }

  void ae(bool tx, int x, bool ty, int y) {
    // tx is True if x is True
    // ty is True if y is True
    //printf("x:%d tx:%d y:%d ty:%d\n",x,tx,y,ty);
    int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
    if (!tx) swap(a,na);
    if (!ty) swap(b,nb);
    add(a,b); add(nb, na);
  }

  void inittwosat(int n) {
      graph.clear(); rev_graph.clear();
      graph.resize(2*n);
      rev_graph.resize(2*n);
      used.resize(2*n); fill(used.begin(),used.end(),0);
      comp.resize(2*n); fill(comp.begin(),comp.end(),-1);
      order.resize(2*n); fill(order.begin(),order.end(),0);
      res.resize(2*n);
      twosat_cnt=0;
  }
};


class IdAllocator {
public:
  int n=0;
  int getid() {
    return n++;
  }
  int size() {
    return n;
  }
  void clear() {
    n=0;
  }
};

template <typename LST> struct LimitedVec  {
  vector<LST> a;
  int n=0;
  void init(int needsize) {
    a.resize(needsize);
  }
  void push_back(LST val) {
    a[n++]=val;
  }
  LST * begin()
  {
    return a.begin();
  }
  LST * end()
  {
    return a.end();
  }
  void clear() {
    n=0;
  }
  int size() {
    return n;
  }
};

const int mn=100000;
const int ma=10000;
const int logmn=ceil(log(mn)/log(2))+1.5;

const int ANT=0;
const int UPLINK=ma;
const int DOWNLINK=ma+mn*logmn;
const int LIST=ma+2*mn*logmn;

class LCAEdgeDecomposition {
public:
  int timestamp = 0;
  int **up; // up[k][v] = v's ancestor k levels up.
  int *tin;
  int *tout;
  int len;
  int n;
  LimitedVec ret;
  void dfs(vvi &tree, int u, int p) {
    tin[u] = timestamp++;
    up[0][u] = p;
    for (int i = 1; i < len; i++)
      up[i][u] = up[i - 1][up[i - 1][u]];
    for (auto v : tree[u]) {
      if (v != p) {
        dfs(tree, v, u);
      }
    }
    tout[u] = timestamp++;
  }

  bool isParent(int parent, int child) {
    return tin[parent] <= tin[child] && tout[child] <= tout[parent];
  }

  int lca(int a, int b) {
    if (isParent(a, b))
      return a;
    if (isParent(b, a))
      return b;
    for (int i = len - 1; i >= 0; i--)
      if (!isParent(up[i][a], b))
        a = up[i][a];
    return up[0][a];
  }

  void processEdge(int a, int b, int data) {
    ret.clear();
    int r = lca(a, b);
    for (int j = len - 1; j >= 0; j--) {
      if (!isParent(up[j][a], r)) {
        ret.PB(a * len + j);
        a = up[j][a];
      }
      if (!isParent(up[j][b], r)) {
        ret.PB(b * len + j);
        b = up[j][b];
      }
    }
    if (a != r) {
      ret.PB(a * len + 0);
    }
    if (b != r) {
      ret.PB(b * len + 0);
    }
  }

  void linkParentChild(int parent, int child) { /* Custom code goes here */
    // Uplink
    sat.ae(true, UPLINK+child, true, UPLINK+parent);
    // Downlink
    sat.ae(true, DOWNLINK+parent, true, DOWNLINK+child);
  }

  void linkAllParentChild() {
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < len; j++) {
        linkParentChild(i * len + j, i * len + j - 1);
        if (up[j - 1][i] != -1) {
          linkParentChild(i * len + j, up[j - 1][i] * len + j - 1);
        }
      }
    }
  }

  int getIdParent(int x) {
    int i=x/len; int j=x-q*len;
    if (j==len-1) return -1;
    return i*len+j+1;
  }

  int getIdChild(int x) {
    int i=x/len; int j=x-q*len;
    if (j==0) return -1;
    return i*len+j-1;
  }

  void init(vvi &tree, int root) {
    n = tree.size();
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) {up[i]= new int[n]; memset(up[i],-1,sizeof(int)*n);}
    tin = new int[n];
    tout = new int[n];
    dfs(tree, root, root);
    ret.init(n);
    linkAllParentChild();
  }
};

LCAEdgeDecomposition lcd;
vvi g;
vvi id2vtx;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); g.resize(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1,y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  lcd.init(g,0);
  id2vtx.resize(2*n*lcd.len);
  int m=rint();
  for (int s=0;s<m;s++) {
    sat.ae(false, ANT+(s<<1),false,ANT+((s<<1)|1)); // Ant must have at least one colored path.
    for (int t=0;t<2;t++) {
      int st=(s<<1)|t;
      int a=rint(),b=rint();
      hl.query(a,b);
      for (auto &w:h.ret) {
        id2vtx[w].PB(st);
        sat.ae(true, DOWNLINK+w, false, ANT+st); // Another ant prevents ant s from using path t.
        sat.ae(true, UPLINK+w, false, ANT+st); // Another ant prevents ant s from using path t.
        int pw=hl.getIdParent(w);
        if (pw!=-1) {
          sat.ae(true, ANT+st, true, UPLINK+pw); // Ant s uses up this edge.
        }
        int cw=hl.getIdChild(w);
        if (cw!=-1) {
          sat.ae(true, ANT+st, true, DOWNLINK+cw); // Ant s uses up this edge. Propagate to LCA child.
        }
      }
    }
  }
  for (int id=0;id<2*n*lcd.len;id++) {
    
  }

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