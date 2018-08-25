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
const int mk=62;
ll bf(ll l, ll r) {
	pll ans=MP((ll)__builtin_popcountll(r),-r);
	for (ll x=l;x<=r;x++) {
		chkmax(ans,MP((ll)__builtin_popcountll(x),-x));
	}
	return -ans.snd;
}
ll solve(ll l, ll r) {
		pll ans=MP((ll)__builtin_popcountll(r),-r);
		for (int k=0;k<mk;k++) {
			ll pt=1LL<<k;
			if (r&pt) {
				ll sub=(r&(pt-1))+1;
				ll x=r-sub;
				if (x>=l) {
					chkmax(ans,MP((ll)__builtin_popcountll(x),-x));
				}
			}
		}
		return -ans.snd;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) {
		ll l,r; scanf("%lld%lld",&l,&r);
		ll ans=solve(l,r);
		printf("%lld\n",ans);
	}
}

