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
ll cdiv(ll x,ll y) {
	return (x+y-1)/y;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%lld",&n);
	ll x=1,y=1;
	for (ll i=0;i<n;i++) {
		ll t,a; scanf("%lld%lld",&t,&a);
		ll g=max(cdiv(x,t),cdiv(y,a));
		x=g*t,y=g*a;
	}
	printf("%lld\n",x+y);
}