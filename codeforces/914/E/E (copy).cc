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
const int mk=20;
const int mz=1<<mk;
//int col2numvtx[mn];
int st[mn],ft[mn],ver[mn],big[mn],sz[mn];
ll vfinal[mn];
int intermsk2cnt[mz];
int msk2cnt[mz];
int allmsk2cnt[mz];
int v2msk[mn];
int inp[mn];
vector<int> g[mn];
vector<int> vwant;
ll final=0;

ll interchild=0;
ll finterchild;
vector<int> interpending;
void handlequery(int v, int par) {
  printf("v:%d final:%lld finterchild:%lld\n",v,final,finterchild);
  vfinal[v]=final+finterchild;
}

void flushpending() {
  for (auto &msk:interpending) {
    intermsk2cnt[msk]++;
  }
  interpending.clear();
}

void add(int v, int toadd, int center) {
  int msk=v2msk[v];
  //printf("v:%d toadd:%d msk:%d\n",v,toadd,msk);
  if (toadd==1) {
    for (auto &want:vwant) {
      int omsk=want^msk;
      final-=toadd*msk2cnt[omsk];
    }
    msk2cnt[msk]+=toadd;
    {
      for (auto &want:vwant) {
        int omsk=want^msk^inp[center];
        interchild+=intermsk2cnt[omsk];
        if (intermsk2cnt[omsk]) {
          //printf("v:%d msk:%d want:%d omsk:%d cnt:%d\n",v,msk,want,omsk,intermsk2cnt[omsk]);
        }
      }
      printf("Pending:%d\n",msk);
      interpending.PB(msk);
    }
    for (auto &want:vwant) {
      int omsk=want^msk;
      final+=toadd*(allmsk2cnt[omsk]-msk2cnt[omsk]);
      //if (toadd*(allmsk2cnt[omsk]-msk2cnt[omsk])) printf("want:%d omsk:%d Add: %d\n",want,omsk,toadd*(allmsk2cnt[omsk]-msk2cnt[omsk]));
    }
  }
  else {
    for (auto &want:vwant) {
      int omsk=want^msk;
      final-=(allmsk2cnt[omsk]-msk2cnt[omsk]);
      //if (toadd*msk2cnt[omsk]) printf("want:%d omsk:%d Sub: %d\n",want, omsk, toadd*msk2cnt[omsk]);
    }
    msk2cnt[msk]+=toadd;
    intermsk2cnt[msk]+=toadd;
    for (auto &want:vwant) {
      int omsk=want^msk;
      final+=(msk2cnt[omsk]);
    }
  }
}


void dfs(int v, int par, bool keep){
  int bigChild=big[v];
  for(auto u : g[v]) {
    if(u != par && u != bigChild) {
      dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    }
  }
  if(bigChild != -1) {
    dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
  }
  interchild=0;
  //printf("Reset interchild v:%d\n",v);
  for(auto u : g[v]) {
    if(u != par && u != bigChild) {
      for(int p = st[u]; p < ft[u]; p++) add(ver[p],1,v);
      flushpending();
    }
  }
  finterchild=interchild;
  add(v,1,v);
  flushpending();
  //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
  handlequery(v,par);
  if(keep == 0) {
    for(int p = st[v]; p < ft[v]; p++) add(ver[p],-1,v);
  }
}
int dfs_time=0;
void pre_dfs(int v, int p){
  st[v] = dfs_time++;
  ver[ st[v] ] = v;
  sz[v] = 1, big[v] = -1;
  for(auto u : g[v]){
    if (u==p) continue;
    pre_dfs(u,v);
    sz[v] += sz[u];
    if(big[v] == -1 || sz[u] > sz[ big[v] ])
        big[v] = u;
  }
  ft[v] = dfs_time;
}
void init(int x, int p, int msk) {
  msk^=inp[x];
  v2msk[x]=msk;
  allmsk2cnt[msk]++;
  for (auto &y:g[x]) {
    if (y==p) continue;
    init(y,x,msk);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  allmsk2cnt[0]++; // For root
  vwant.PB(0);
  for (int i=0;i<mk;i++) vwant.PB(1<<i);
  int n=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int i=1;i<=n;i++) inp[i]=1<<(rch()-'a');
  init(1,-1,0);
  pre_dfs(1,-1);
  dfs(1,-1,true);
  for (int x=1;x<=n;x++) printf("%lld ",vfinal[x]);
  printf("\n");
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