#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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

template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef pair<pair<ld,ld>,ld> S;
  S t[2 * SEGSZ];
  S identity = MP(MP((ld)1e18,(ld)-1e18),0.0);
  S combine(const S& a, const S& b) {
    return MP(MP(min(a.fst.fst,b.fst.fst),max(a.fst.snd,b.fst.snd)),
      max(max(a.snd,b.snd),b.fst.snd-a.fst.fst));
  }
  void init(int n) {segn=n;}
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


const int mn=150000+4;
int vx[mn],vc[mn];
ld vp[mn];
ld a[mn];
SegTree<mn> seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),cfine=rint();
  for (int i=0;i<n;i++) vx[i]=rint();
  for (int i=0;i<n-1;i++) vp[i]=rint()/100.0;
  for (int i=0;i<n-1;i++) {
    ld gain=fabs(vx[i+1]-vx[i])/2.0;
    ld loss=cfine*vp[i];
    a[i+1]=gain-loss;
  }
  for (int i=1;i<n;i++) a[i]+=a[i-1];
  seg.init(n);
  for (int i=0;i<n;i++) {
    ld val=a[i];
    seg.t[i+seg.segn]=MP(MP(val,val),0);
  }
  seg.build();
  ld ans=0;
  for (int i=0;i<m;i++) {
    int l=rint()-1,r=rint()-1;
    ans+=seg.query(l,r).snd;
  }
  printf("%.16f\n",ans);
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