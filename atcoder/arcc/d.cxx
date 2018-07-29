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
const ll mn=1e3+4;
ll f[2][mn][mn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m,k; cin>>n>>m>>k;
	ll sumlim=n+m+k;
	for (ll sum=1;sum<=sumlim;sum++) {
		ll cur=sum&1,prev=cur&1;
		ll xlim=min(n,sum);
		for (ll x=1;x<=xlim;x++) {
			ll ymin=max(0ll,sum-x-k);
			ll ylim=min(m,sum-x);
			for (ll y=ymin;y<=ylim;y++) {
				ll ans=f[prev][x+1][y+1]+f[prev][x][y+1]+f[prev][x+1][y];
				ll z=sum-x-y;
				f[cur][x+1][y+1]=ans%MOD;
			}
		}
	}
	cout<<f[sumlim&1][n+1][m+1]<<endl;
}