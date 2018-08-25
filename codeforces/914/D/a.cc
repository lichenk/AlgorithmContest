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

typedef struct _S {
  int g;
  vi v;
} S;
inline void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
inline int gcd(int x, int y) {
  if(x==-1) return y;
  if(y==-1) return x;
  return __gcd(x,y);
}
template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  S t[2 * SEGSZ];
  S identity;
  S combine(const S& l, const S& r) {
    if (l.g==-123) return r;
    if (r.g==-123) return l;
    S ans;
    ans.g=__gcd(l.g,r.g);
    for (auto &x:l.v) {
      ans.v.PB(gcd(x,r.g));
    }
    for (auto &x:r.v) {
      ans.v.PB(gcd(x,l.g));
    }
    makeunique(ans.v);
    return ans;
  }
  void init(int n) {segn=n;
    identity.g=-123;
  }
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

bool bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin<vx.size() && vx[imin]==x;
}

const int mn=500000;
SegTree<mn> seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  seg.init(n);
  for (int i=0;i<n;i++) {
    seg.t[n+i].g=rint();
    seg.t[n+i].v.PB(-1);
  }
  seg.build();
  int q=rint();
  for (int qi=0;qi<q;qi++) {
    int t=rint();
    if (t==1) {
      int l=rint()-1,r=rint()-1,x=rint();
      S got=seg.query(l,r);
      bool ans=(l==r||(got.g%x==0));
      if (!ans) {
        for (auto &y:got.v) {
          if (y%x==0) {ans=true; break;}
        }
      }
      if (ans) {
        printf("YES\n");
      }
      else printf("NO\n");
    }
    else {
      int idx=rint()-1,y=rint();
      S put; put.g=y; put.v.PB(-1);
      seg.sset(idx,put);
    }
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