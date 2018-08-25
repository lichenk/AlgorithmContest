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
pll negdiv(ll x, ll k) {
  ll quo=x/k;
  for (ll q=quo-2;q<=quo+2;q++) {
    ll rem=x-q*k;
    if (0<=rem&&rem<abs(k)) {
      return MP(q,rem);
    }
  }
  assert(0);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll inp,k; cin>>inp>>k;
  vector<ll> vans;
  while(inp!=0) {
    pll got=negdiv(inp,-k);
    ll quo=got.fst,rem=got.snd;
    //printf("inp:%lld quo:%lld rem:%lld\n",inp,quo,rem);
    vans.PB(rem);
    inp=quo;
  }
  printf("%d\n",(int)(vans.size()));
  for (auto &w:vans) printf("%lld ",w);
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