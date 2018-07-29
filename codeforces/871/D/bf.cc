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
const int INF=1e9;
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

const int mn=1e2+1;
vector<int> g[mn];
int vdist[mn];
int n;
void bfs(int initx) {
  for (int x=1;x<=n;x++) {
    vdist[x]=INF;
  }
  queue<int> q;
  q.push(initx);
  vdist[initx]=0;
  while(!q.empty()) {
    int x=q.front();
    q.pop();
    int distx=vdist[x]+1;
    for (auto &y:g[x]) {
      if (vdist[y]>distx) {
        vdist[y]=distx;
        q.push(y);
      }
    }
  }
}
int f[5];
int main() 
{
  scanf("%d",&n);
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=n;y++) {
      if (__gcd(x,y)!=1) {
        g[x].PB(y);
      }
    }
  }
  int special=0;
  ll final=0;
  for (int x=1;x<=n;x++) {
    bfs(x);
    for (int y=1;y<=n;y++) {
      if (x==1||y==1||x==y) {
        special++; continue;
      }
      int dist=vdist[y];
      assert(dist!=0);
      if (dist>=INF) {
        f[0]++;
      }
      else {
        assert(dist<=3);
        f[dist]++;
        if (x<y) final+=dist;
      }
      if (dist==2) {
        //printf("%d %d\n",x,y);
      }
    }
  }
  //printf("f0:%d f1:%d f2:%d f3:%d s:%d\n",f[0],f[1],f[2],f[3],special);
  printf("%lld\n",final);
}
