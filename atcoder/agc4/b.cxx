#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MK make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=2e3+4;
ll a[mn];
inline ll MK(ll x, ll y) {
	return (x<<32)|y;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,rot; cin>>n>>rot;
	for (ll i=0;i<n;i++) cin>>a[i];
	ll final=INF;
	for (ll k=0;k<n;k++) {
		set<ll> s;
		for (ll x=0;x>=-k;x--) {
			ll y=(n+x)%n;
			s.insert(MK(a[y],y));
			//printf("Ins (%lld,%lld)\n",a[y],y);
		}
		ll ans=0;
		for (ll x=0;x<n;x++) {
			ll cand=(*(s.begin()))>>32;
			//printf("x:%lld cand:%lld\n",x,cand);
			ans+=cand;
			ll y=(x-k+n)%n;
			s.erase(MK(a[y],y));
			//printf("Er (%lld,%lld)\n",a[y],y);
			s.insert(MK(a[x+1],x+1));
			//printf("Ins (%lld,%lld)\n",a[x+1],x+1);
		}
		ans+=k*rot;
		//printf("ANS:%lld\n",ans);
		chkmin(final,ans);
	}
	cout<<final<<endl;
}
