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
typedef pair<ll,ll> pll;

int main() {
	ll n=100000,x=1000000;
	printf("%lld\n",n);
	for (ll i=1;i<=n;i++) {
		if (i!=n) printf("%lld ",x);
		else printf("%lld\n",x);
	}
	for (ll i=0;i<n-1;i++) {
		printf("%lld %lld\n",i+1,i+2);
	}
}
