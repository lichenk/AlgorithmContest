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
const ll mn=1e5+4;
ll a[mn];
ll pqs=0;
priority_queue<int,vector<int>, greater<int> > pq;
ll rint() {
  ll x; scanf("%lld",&x); return x;
}
ll rlong() {
  ll x; scanf("%lld",&x); return x;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(),k=rint();
  ll b=rlong();
  for (ll x=1;x<=n;x++) a[x]=rint();
  ll final=n;
  for (ll x=n-1;x>=1;x--) {
    ll need=a[x];
    vector<int> v;
    for (int y=x+1;y<=n-1;y++) {
      v.PB(a[y]);
    }
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0;i<min(k-1,(ll)v.size());i++) need+=v[i];
    if (need>b) chkmin(final,x);
  }
  printf("%lld\n",final);
}

