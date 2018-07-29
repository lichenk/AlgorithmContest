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
ll a[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	ll extra=0;
	ll ans=0;
	for (ll i=0;i<n;i++) {
		ll sum=extra+a[i];
		ll take=sum/2;
		ans+=take;
		sum-=take*2;
		if (sum>0&&a[i]>0) extra=1;
		else extra=0;
		//printf("i:%lld sum:%lld take:%lld extra:%lld\n",i,sum,take,extra);
	}
	printf("%lld\n",ans);
}