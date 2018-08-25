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


int rint()
{
  int x; scanf("%d",&x); return x;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,k; scanf("%lld %lld",&n,&k);
  vector<ll> v;
  for (int i=0;i<n;i++) {
    ll x; scanf("%lld",&x);
    v.PB(x);
  }  
  ll least=INF;
  for (int i=0;i<n;i++) {
    chkmin(least,v[i]);
  }
  ll ans=0;
  for (int i=0;i<n;i++) {
    ll left=v[i]-least;
    if (0!=(left%k)) {
      printf("-1\n");
      return 0;
    }
    ans+=left/k;
  }
  printf("%lld\n",ans);
}

