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

const int mx=26;
class UnionFind {
  typedef int UFTYPE;
public:
  //UFTYPE ufIdentity = -1;
  //inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  //  return max(x,y);
  //}
  //inline UFTYPE getInitialValue(int x) {
  //  return x;
  //}
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    //ufData[x]=getInitialValue(x);
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
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    //ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  /*int getDataForPos(int x) {
    return ufData[x];
  }*/
};
UnionFind uf;
int n;
const int mn=1e5+4;
char a[mn],b[mn];
vector<pair<char,char> > v;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d\n%s\n%s\n",&n,a,b);
  int ans=0;
  uf.init(26);
  for (int i=0;i<n;i++) {
    int x=a[i],y=b[i];
    int xr=uf.ffind(x-'a'),yr=uf.ffind(y-'a');
    if (xr!=yr) {
      uf.funion(xr,yr);
      ans++;
      v.PB(MP(x,y));
    }
  }
  printf("%d\n",ans);
  for (auto &w:v) {
    printf("%c %c\n",w.fst,w.snd);
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