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

const int mk=31;
ll a[mk];
ll b[mk];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  ll future=0;
  for (int i=0;i<n;i++) {
    int x=rint();
    future+=x;
    for (int k=0;k<mk;k++) {
      if (x&(1<<k)) a[k]++;
    }
  }
  for (int i=0;i<m;i++) {
    int k=rint();
    b[k]++;
  }
  ll ans=0;
  ll borrowed=0;
  for (ll k=0;k<mk;k++) {
    borrowed=((borrowed+(1LL<<k)-1)>>k)<<k;
    ll origak=a[k];
    ll need=borrowed>>k;
    ll grab=min(need,a[k]);
    a[k]-=grab;
    ll cantake=(future-borrowed)>>k;
    borrowed-=grab<<k;
    //if (k<4) printf("k:%lld cantake:%lld b[k]:%lld future:%lld borrowed:%lld grab:%lld\n",k,cantake,b[k],future,borrowed,grab);
    ll take=max(0ll,min(cantake,b[k]));
    borrowed+=max(0ll,take-a[k])<<k;
    ans+=take;
    future-= origak<<k;
  }
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