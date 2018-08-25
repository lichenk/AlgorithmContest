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

const int mn=2e5+4;
int* parl;
int INF = 1 << 29;
int n;
int m;
int len;
int** up;
int* tin;
int* tout;
int time;

void init(vvi &g, int root) {
    int n = tree.length;
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) up[i]=new int[n];
    tin = new int[n];
    tout = new int[n];
    parl = new int[n];
    dfs(tree, root, root);
}

void dfs(vvi &tree, int u, int p) {
    tin[u] = time++;
    up[0][u] = p;
    for (int i = 1; i < len; i++)
        up[i][u] = up[i - 1][up[i - 1][u]];
    for (long d : tree[u]) {
        int v = (int) (d / n);
        if (v != p) {
            parl[v] = (int) (d % n);
            dfs(tree, v, u);
        }
    }
    tout[u] = time++;
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

vvi g;
vvi h;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); g.resize(n);
  for (int i=1;i<n;i++) {
    int x=i,y=rint();
    --x;--y;
    g[x].PB(y); g[y].PB(x);
  }
  init(g, 0);
  int m=rint();
  h.resize(SEGOFFSET+m*2*ceil(log2(n)+1));
  int OFF=m;
  int SEGOFFSET=3*m;
  for (int i=0;i<m;i++) {
    ae(h,i,i+2*m,1);
    ae(h,i+m,i+2*m,1);
  }
  for (int i = 0; i < m; i++) {
    int a=rint()-1,b=rint()-1;
    int r=lca(a, b);
    for (int j = len - 1; j >= 0; j--) {
        if (!isParent(up[j][a], r)) {
          ae(h,i,SEGOFFSET + a * len + j,0);
          a = up[j][a];
        }
        if (!isParent(up[j][b], r)) {
          ae(h,OFF+i,SEGOFFSET + b * len + j,0);
          b = up[j][b];
        }
    }
    if (a != r) {
        ae(h,i,SEGOFFSET+a*len+0,0);
    }
    if (b != r) {
        ae(h,OFF+i,SEGOFFSET+b*len+0,0);
    }
  }
  for (int i = 1; i < n; i++) {
      for (int j = 1; j < len; j++) {
          ae(h, SEGOFFSET + i * len + j, SEGOFFSET + i * len + j - 1, 0);
          if (up[j - 1][i] != 0)
              ae(h, SEGOFFSET + i * len + j, SEGOFFSET + up[j - 1][i] * len + j - 1, 0);
      }
  }
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
    qx[qi]=rint();
    qy[qi]=rint();
  }
  queue<int> q[2];
  //for (int )
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