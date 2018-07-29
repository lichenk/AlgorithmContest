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
vector<ll> g[mn];
ll n,k;
ll final=0;
ll dfs(ll x) {
	ll depth=0;
	for (auto &y:g[x]) {
		chkmax(depth, dfs(y));
	}
	if (depth==k-1) {
		if (a[x]!=1) final++;
		return 0;
	}
	else return depth+1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for (ll x=1;x<=n;x++) cin>>a[x];
	if (a[1]!=1) {final++;a[1]=1;}
	for (ll x=1;x<=n;x++) {
		if(a[x]!=x) g[a[x]].PB(x);
	}
	dfs(1);
	cout<<final<<endl;
}