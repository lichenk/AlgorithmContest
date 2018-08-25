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
const int mn=100000;
int a[mn];
int main()
{
	int n=rint();
  ll ans=1LL<<62;
  for (int i=0;i<n;i++) a[i]=rint();
  for (int j=1;j<n;j++) {
    ll sum=0;
    for (int i=j-1;i>=0;i--) {
      sum+=a[i];
      ll diff=i-j;
      chkmin(ans,sum*sum+diff*diff);
    }
  }
  printf("%lld\n",ans);
}

