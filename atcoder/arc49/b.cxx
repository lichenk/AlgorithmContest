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
int main() {
	ios_base::sync_with_stdio(false);
	string s; cin>>s;
	ll n=s.length();
	ll ans=0;
	for (ll x=0;x<n;x++) {
		ll my=x&1;
		ll e=s[x]=='g'?0:1;
		if (my>e) ans++;
		else if (my<e) ans--;
	}
	printf("%lld\n",ans);
}