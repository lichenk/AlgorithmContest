#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
//const int MOD=1000000007;
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
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q; scanf("%d",&q);
  for (int qi=0;qi<q;qi++) {
    int d; ll l,r;
    scanf("%d%lld%lld",&d,&l,&r);
    ll ans=0;
    for (ll x=l;x<=r;x++) {
      ll y=x;
      int z=0;
      while(y>0) {
        int r=y%d;
        z^=(1<<r);
        y/=d;
      }
      if (z==0) {
        //printf("x:%lld\n",x);
        ans++;
      }
    }
    printf("%lld\n",ans);
  }
}
