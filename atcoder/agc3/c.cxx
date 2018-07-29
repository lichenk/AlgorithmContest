#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1e5+4;
pair<ll,ll> a[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) {
		ll x;scanf("%lld",&x);
		a[i]=MP(x,i);
	}
	sort(a,a+n);
	ll need=0;
	for (ll i=0;i<n;i++) {
		if ((a[i].second-i)%2) {
			need++;
		}
	}
	ll ans=need/2;
	printf("%lld\n",ans);
}