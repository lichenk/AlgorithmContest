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
ll p[mn],q[mn],cc[mn];
map<ll, vector<ll> > h[mn];
set<ll> cset[mn];
vector<pll> g[mn];
map<pll,ll> pairtoid;
pll idtopair[mn];
typedef pair<ll,ll> pll;
const ll UNK=2e6;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<m;i++) {
		ll x,y,c;
		cin>>x>>y>>c;
		p[i]=x; q[i]=y; cc[i]=c;
		h[x][c].PB(i); h[y][c].PB(i);
		cset[x].insert(c);
	}
	{
		ll id=0;
		for (ll x=1;x<=n;x++) {
			for (auto &c:cset[x]) {
				pll pr=MP(x,c);
				pairtoid[pr]=id;
				idtopair[id]=pr;
				id++;
			}
		}
	}
	{
		for (ll x=1;x<=n;x++) {
			
		}
	}


	priority_queue<pll,vector<pll>,greater<pll> > pq;
	dist[1][UNK]=0;
	pq.push(MP(0,MK(1,UNK)));
	while(!pq.empty()) {
		pll top=pq.top(); pq.pop();
		ll u=top.second>>32;
		ll c=top.second&0xffffffff;
		if (top.first>dist[u]) continue;
		for (auto &w:cset[u]) {
			ll alt=dist[u][c]+1;
			if (alt<dist)
		}
	}
	ll ans=INF;
	if (ans>=INF) ans=-1;
	cout<<ans<<endl;
}