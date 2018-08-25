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

ll a[100];
const ll mk=31;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(); ll L=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=n;i<mk;i++) a[i]=a[i-1]*2;
  for (int i=1;i<mk;i++) {
    chkmin(a[i],a[i-1]*2);
  }
  for (int i=mk-2;i>=0;i--) {
    chkmin(a[i],a[i+1]);
  }
  ll final;
  {
    ll q=L;
    ll ans=0;
    for (int i=0;i<mk;i++) {
      if ((1LL<<i)&q) ans+=a[i];
    }
    final=ans;
  }
  for (int k=0;k<mk;k++) {
    ll msk=1LL<<k;
    ll q=((L+msk-1)/msk)*msk;
    ll ans=0;
    for (int i=0;i<mk;i++) {
      if ((1LL<<i)&q) ans+=a[i];
    }
    chkmin(final,ans);
  }
  printf("%lld\n",final);
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