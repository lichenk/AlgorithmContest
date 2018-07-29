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
const ll mn=2e5+4;
const ll mx=1e5+4;
ll p[mn],q[mn],c[mn],dist[mn];
vector<ll> g[mx];
typedef pair<ll,ll> pll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<m;i++) {
		ll x,y;
		cin>>x>>y>>c[i];
		p[i]=x; q[i]=y;
		g[x].PB(i); g[y].PB(i);
	}
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	for (ll x=0;x<m;x++) dist[x]=INF;
	for (auto &w:g[1]) {
		dist[w]=1;
		pq.push(MP(1,w));
	}
	while(!pq.empty()) {
		pll top=pq.top(); pq.pop();
		ll u=top.second;
		ll du=top.first;
		if (du>dist[u]) continue;
		for (auto &v:g[p[u]]) {
			if (v==u) continue;
			ll alt=dist[u];
			if (c[v]!=c[u]) alt++;
			if (alt<dist[v]) {
				dist[v]=alt;
				pq.push(MP(alt,v));
			}
		}
		for (auto &v:g[q[u]]) {
			if (v==u) continue;
			ll alt=dist[u];
			if (c[v]!=c[u]) alt++;
			if (alt<dist[v]) {
				dist[v]=alt;
				pq.push(MP(alt,v));
			}
		}
	}
	ll ans=INF;
	for (ll x=0;x<m;x++) {
		if (p[x]==n||q[x]==n) chkmin(ans,dist[x]);
	}
	if (ans>=INF) ans=-1;
	cout<<ans<<endl;
}