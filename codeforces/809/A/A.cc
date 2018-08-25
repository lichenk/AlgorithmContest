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
const ll INF=1e18;
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
const int mn=3e5+4;
ll pt[mn];
ll a[mn];
ll norm(ll x) {
  x%=MOD;
  if (x<0) x+=MOD;
  return x;
}
ll mul(ll x, ll y) {
  x=norm(x); y=norm(y);
  return (x*y)%MOD;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  pt[0]=1;
  for (int i=1;i<mn;i++) {
    pt[i]=mul(pt[i-1],2);
  }
	int n=rint();
  for (int i=1;i<=n;i++) {
    a[i]=rint();
  }
  sort(a+1,a+n+1);
  ll final=0;
  for (int t=1;t<=n;t++) {
    final+=mul(pt[t-1]-1, a[t]);
    final+=MOD-mul(pt[n-t]-1, a[t]);
    //printf("Add:%lld Sub:%lld a[t]:%lld\n",pt[t-1]-1, pt[n-t]-1,a[t]);
    final=norm(final);
  }
  printf("%lld\n",final);
}

