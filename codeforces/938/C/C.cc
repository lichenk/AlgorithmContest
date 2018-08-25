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

ll f(int x, int m) {
  int s=x/m;
  return (x*(ll)x)-(s*(ll)s);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests=rint();
  for (int tt=0;tt<tests;tt++) {
    int want=rint();
    if (want==0) printf("1 1\n");
    else if (want==1) printf("-1\n");
    else {
      bool done=0;
      for (int x=2;;x++) {
        ll lo=f(x,2);
        if (lo>want) break;
        int imin=2,imax=x;
        while(imin<imax) {
          int imid=(imin+imax)>>1;
          ll got=f(x,imid);
          if (got<want) imin=imid+1;
          else imax=imid;
        }
        if (f(x,imin)==want) {
          printf("%d %d\n",x,imin);
          done=1;
          break;
        }
      }
      if (!done) printf("-1\n");
    }
    fflush(stdout);
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