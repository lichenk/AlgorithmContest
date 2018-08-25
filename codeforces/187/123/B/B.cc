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

ll px[2],py[2],dx[2],dy[2];

ll lodiv(ll quo, ll den) {
  assert(den>0);
  if (quo>=0) {
    return quo/den;
  }
  else {
    return -((-quo)/den)-1;
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll a=rint(),b=rint();
  for (int t=0;t<2;t++) {
    ll x=rint(),y=rint();
    dx[t]=lodiv(x+y,2*a);
    dy[t]=lodiv(x-y,2*b);
    //printf("x+y:%lld x-y:%lld\n",dx[t],dy[t]);
  }
  ll cx=abs(dx[0]-dx[1]),cy=abs(dy[0]-dy[1]);
  ll ans=max(cx,cy);
  printf("%lld\n",ans);
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