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
const int mn=2e5+4;
const int mx=mn;
typedef int UFTYPE;
class UnionFind {
public:
// Custom
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x|y;
}
/*inline UFTYPE getInitialValue(int x) {
}*/

int ufParent[mx];
UFTYPE ufData[mx];
void init(int n) {
  for (int x=1;x<=n;x++) {
    ufParent[x]=x;
  }
}
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
void funion(int _x, int _y) {
  int xr = ffind(_x);
  int yr = ffind(_y);
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
void funionFast(int xr, int yr) {
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
int getData(int x) {
  return ufData[ffind(x)];
}
int getDataFast(int x) {
  return ufData[x];
}
};
UnionFind uf;

int n,m,k;
int vdist[mn];
bitset<mn> seen;
vector<int> g[mn];
void ae(int x, int y) {
  printf("x:%d y:%d\n",x,y);
  g[x].PB(y); g[y].PB(x);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int on=rint();m=rint();k=rint();
  for (int i=0;i<k;i++) {
    seen[rint()]=true;
  }
  for (int i=1;i<=m;i++) {
    int x=rint(),y=rint();
    ae(x,on+i);
    ae(on+i,y);
  }
  n=on+m;
  int src=rint(),dest=rint();
  srand(clock());
  seen[dest]=true;
  uf.init(n);
  for (int x=1;x<=n;x++) vdist[x]=INF;
  queue<int> q;
  for (int x=1;x<=n;x++) {
    if (seen[x]) {
      q.push(x);
      printf("push: %d\n",x);
      vdist[x]=0;
    }
  }
  uf.ufData[src]=1;
  uf.ufData[dest]=2;
  while(!q.empty()) {
    int x=q.front(); q.pop();
    int distx=vdist[x];
    int ndist=distx+1;
    //printf("ndist:%d\n",ndist);
    for (auto &y:g[x]) {
      if (!seen[y]) {
        seen[y]=true;
        vdist[y]=ndist;
        printf("unite %d %d\n",x,y);
        uf.funion(x,y);
        int data=uf.getData(x);
        if (data==3) {
          printf("%d\n",ndist);
          return 0;
        }
        printf("push: %d\n",y);
        q.push(y);
      }
    }
  }
  printf("-1\n");
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