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


const int mn=1002;
const int MAXSEG = mn;  // limit for array size
int segn;  // array size
typedef int S;
S t[2 * MAXSEG];
S identity = INT_MIN;
S combine(const S& lefts, const S& rights) {
  return max(lefts,rights);
}
void build(S *t) {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(int l, int r, const S& value) {
  r++;
  int n=segn;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      t[l] = combine(t[l], value);
      l++;
    }
    if (r&1) {
      --r;
      t[r] = combine(t[r], value);
    }
  }
}

S query(S *t, int p) {
  int n=segn;
  S res = identity;
  for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
  return res;
}



vector<pii> vp;
vector<pii> vb;
void makeunique(vector<ll> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<ll> &vx, ll x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
bool activex[mn];
vector<int> x2line[mn];
vector<int> vx,vy;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  int x=0,y=0;
  vp.PB(MP(x,y));
  for (int j=0;j<n;j++) {
    char c=rch(); int d=rint();
    if (c=='L') x-=d;
    if (c=='R') x+=d;
    if (c=='U') u+=d;
    if (c=='D') u-=d;
    vp.PB(MP(x,y));
  }
  for (auto &w:vp) {vx.PB(w.fst); vy.PB(w.snd);}
  makeunique(vx);makeunique(vy);
  for (auto &w:vp) {
    vb.PB(MP(bins(vx,w.fst),bins(vy.w.snd)));
  }
  int vpsz=vp.size();
  for (int i=1;i<vpsz;i++) {
    int pxb=vb[i-1].fst,pyb=vb[i-1].snd; if(t) swap(pxb,pyb);
    int xb=vb[i].fst,yb=vb[i].snd; if(t) swap(xb,yb);
    if (yb!=pyb) {
      assert(xb==pxb);
      int lyb=min(yb,pyb),hyb=max(yb,pyb);
      x2yline[xb].PB(MP(lyb,hyb));
    }
    else if (xb!=pxb) {
      int lxb=min(xb,pxb),hxb=max(xb,pxb);
      y2xline[yb].PB(MP(lxb,hxb));
    }
  }
  {
    for (int xb=0;xb<vx.size();xb++) {
      for (auto &line:vx) {
        int lyb=line.fst,hyb=line.snd;
        modify(lyb,hyb,xb);
      }
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