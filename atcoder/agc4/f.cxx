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
vector<ll> g[mn];
ll dp[mn][2];
void f(ll x,ll p) {
	ll h[2][2];
	h[0][0]=0,h[0][1]=INF;
	h[1][0]=0,h[1][1]=INF;
	ll nh[2][2];
	for (auto &y:g[x]) {
		if (y==p) continue;
		f(y,x);
		for (ll k=0;k<2;k++) {
			nh[k][0]=h[k][0]+dp[y][1];
			if (k==1) {
				chkmin(nh[k][0], h[k-1][1]+dp[y][0]+1);
			}
			nh[k][1]=min(h[k][0]+dp[y][0]+1, h[k][1]+dp[y][1]);
		}
		for (ll k=0;k<2;k++) for (ll c=0;c<2;c++) h[k][c]=nh[k][c];
	}
	dp[x][0]=h[1][0];
	dp[x][1]=h[0][1];
	printf("x:%lld z:%lld one:%lld\n",x,dp[x][0],dp[x][1]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	if (m!=n-1) {
		cout<<-1<<endl;
		return 0;
	}
	for (ll i=0;i<m;i++) {
		ll a,b;cin>>a>>b;
		g[a].PB(b); g[b].PB(a);
	}
	f(1,-1);
	ll ans=dp[1][1];
	if (ans>=INF) ans=-1;
	cout<<ans<<endl;
}