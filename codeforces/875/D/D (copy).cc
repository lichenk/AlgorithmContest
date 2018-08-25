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
const ll INF=1e18;
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

const int mn=2e5+2;
const int MAXSEG = mn;  // limit for array size
const int segn=mn;  // array size
typedef int S;
S t[2 * MAXSEG];
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts|rights;
}
void build() {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
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
int v[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(v,-1,sizeof v);
  int n=rint();
  for (int i=0;i<n;i++) {
    t[segn+i]=rint();
  }
  build();
  for (int x=0;x<n;x++) {
    int val=t[segn+x];
    int l,r;
    {
      int imin = x, imax = n;
      while (imin < imax) {
        int imid = (imin + imax) >> 1;
        if (query(x, imid) <= val) imin = imid + 1;
        else imax = imid;
      }
      r=imin-1;
    }
    {
      int imin=0,imax=x;
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (query(imid,x)>val) imin=imid+1;
        else imax=imid;
      }
      l=imin;
    }
    printf("x:%d l:%d r:%d\n",x,l,r);
    chkmax(v[l],r);
  }
  int gr=-1;
  ll final=0;
  for (int l=0;l<n;l++) {
    int r=v[l];
    if (r==-1) continue;
    if (r>gr) {
      int pl=gr-l+1;
      int pr=r-l+1-pl;
      ll g1=pl*(ll)pr;
      ll g2=(pr*((ll)pr-1LL))>>1;
      printf("l:%d r:%d gr:%d g1:%lld g2:%lld\n",l,r,gr,g1,g2);
      final+=g1+g2;
    }
    chkmax(gr,r);
  }
  ll all=(n*((ll)n-1LL))>>1;
  ll fres=all-final;
  printf("%lld\n",fres);
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