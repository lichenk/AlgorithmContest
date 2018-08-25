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
const int mn=2e5+6;
int e[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),u=rint();
  for (int i=0;i<n;i++) {
    e[i]=rint();
  }
  bool ok=0;
  ld ans=0;
  for (int i=0;i<n-1;i++) {
    int imin=i,imax=n;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (e[imid]-e[i]<=u) imin=imid+1;
      else imax=imid;
    }
    int k=imin-1;
    if (i+1<k) {
      ok=1;
      ld numer=e[k]-e[i+1];
      ld denom=e[k]-e[i];
      ld cand=numer/denom;
      chkmax(ans,cand);
    }
  }
  if (!ok) {printf("-1\n");}
  else {printf("%.16f\n",(double)ans);}
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