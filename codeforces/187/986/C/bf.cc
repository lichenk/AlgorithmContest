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
const int mn=22;
const int mz=1<<mn;

const int mx=mz;
class UnionFind {
public:
  int ufParent[mx];
  int rank[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    if (_x==-1 || _y==-1) return;
    //printf("funion: %d %d\n",_x,_y);
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
  }
};
UnionFind uf;

bitset<mz> a;
bitset<mz> f;
int g[mz];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int k=rint(),m=rint(); int zlim=1<<k;
  uf.init(1<<k);
  for (int i=0;i<m;i++) {int x=rint();a[x]=true;}
  for (int x=0;x<zlim;x++) for (int y=0;y<zlim;y++) {
    if ((x&y)==0&&a[x]&&a[y]) {
      uf.funion(x,y);
    }
  }
  int ans=0;
  for (int z=0;z<zlim;z++) {
    if (a[z] && uf.ffind(z)==z) ans++;
  }
  printf("%d\n",ans);
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