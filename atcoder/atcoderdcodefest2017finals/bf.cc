#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const ll mn=5002;
pll a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; scanf("%lld",&n);
  for (ll i=0;i<n;i++) {
    ll h,p; scanf("%lld%lld",&h,&p);
    a[i]=MP(h,p);
  }
  vector<ll> perm;
  for (ll i=0;i<n;i++) perm.PB(i);
  ll final=0;
  do {
    ll sh=0,ans=0;
    for (ll i=0;i<n;i++) {
      ll j=perm[i];
      ll h=a[j].fst,p=a[j].snd;
      if (sh<=h) {
        sh+=p;
        ans++;
      }
    }
    chkmax(final,ans);
  } while(next_permutation(perm.begin(),perm.end()));
  printf("%lld\n",final);
}
