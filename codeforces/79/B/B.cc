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

vector<pii> vp;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),k=rint(),t=rint();
  for (int i=0;i<k;i++) {
    int a=rint(),b=rint();
    vp.PB(MP(a,b));
  }
  sort(vp.begin(),vp.end());
  for (int i=0;i<t;i++) {
    int x=rint(),y=rint();
    int imin=0,imax=vp.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (vp[imid]<MP(x,y)) imin=imid+1;
      else imax=imid;
    }
    if (imin<vp.size()&&vp[imin]==MP(x,y)) {
        printf("Waste\n");
    }
    else {
      ll ans=((x-1LL)*m+(y-1LL)-imin)%3;
      if (ans==0)printf("Carrots\n");
      else if (ans==1)printf("Kiwis\n");
      else printf("Grapes\n");
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