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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1002;
int vx[mn]; ld vy[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),r=rint();
  ld r2=4*r*r;
  for (int i=0;i<n;i++) {
    int ax=rint();
    vx[i]=ax;
    ld ans=r;
    for (int k=0;k<i;k++) {
      int bx=vx[k];
      int dx=abs(bx-ax);
      if (dx>2*r) continue;
      ld dx2=(bx-ax)*(bx-ax);
      ld rem=r2-dx2;
      ld imin=vy[k],imax=vy[k]+2*r;
      for (int t=0;t<45;t++) {
        ld imid=(imin+imax)/2;
        ld dy2=(imid-vy[k])*(imid-vy[k]);
        if (dy2<rem) imin=imid;
        else imax=imid;
      }
      //printf("i:%d k:%d vxk:%d imin:%.8f\n",i,k,vx[k],imin);
      chkmax(ans,imin);
    }
    vy[i]=ans;
    printf("%.8f ",ans);
  }
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