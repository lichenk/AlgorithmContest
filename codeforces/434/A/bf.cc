#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=9e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const ll mn=1e5+4;
ll a[mn];
vector<int> g[mn];
ll m;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint();
  m=rint();
  for (ll i=0;i<m;i++) {
    ll x=rint();
    a[i]=x;
    g[x].PB(i);
  }
  ll final=INF;
  for (ll x=0;x<=n;x++) for (ll y=0;y<=n;y++) {
    ll cand=0;
    for (ll i=0;i<m-1;i++) {
      ll l=a[i],r=a[i+1];
      if (l==x) l=y;
      if (r==x) r=y;
      cand+=abs(l-r);
    }
    chkmin(final,cand);
  }
  printf("%lld\n",final);
}
