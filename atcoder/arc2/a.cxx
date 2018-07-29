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
ll x[200];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		cin>>x[i];
	}
	ll ans=INF;
	for (ll y=-100;y<=100;y++) {
		ll cand=0;
		for (ll i=0;i<n;i++) {
			ll d=(y-x[i]);
			cand+=d*d;
		}
		chkmin(ans,cand);
	}
	cout<<ans<<endl;
}