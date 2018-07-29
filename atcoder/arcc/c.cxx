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
map<ll, vector<ll> > g[mn];
set<ll> cset[mn];
map<ll,ll> dist[mn];
bool vsn[mn];
typedef pair<ll,ll> pll;
const ll UNK=2e6;
inline ll MK(ll x,ll y) {return (x<<32)|y;}
inline ll getdist(ll u, ll c) {
	auto it=dist[u].find(c);
	if (it==dist[u].end()) return INF;
	else return it->second;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<m;i++) {
		ll x,y,c;
		cin>>x>>y>>c;
		p[i]=x; q[i]=y; cc[i]=c;
		g[x][c].PB(y); g[y][c].PB(x);
		cset[x].insert(c); cset[y].insert(c);
	}
	for (ll x=1;x<=n;x++) vsn[x]=false;
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	vsn[1]=true;
	for (auto &c:cset[1]) {
		dist[1][c]=1;
		pq.push(MP(1,MK(1,c)));
	}
	while(!pq.empty()) {
		pll top=pq.top(); pq.pop();
		ll u=top.second>>32;
		ll c=top.second&0xffffffff;
		ll du=top.first;
		//printf("u:%lld c:%lld du:%lld\n",u,c,du);
		if (du>getdist(u,c)) continue;
		if (!vsn[u]) {
			vsn[u]=true;
			for (auto &wc:cset[u]) {
				ll alt=du+1;
				if (alt<getdist(u,wc)) {
					dist[u][wc]=alt;
					pq.push(MP(alt,MK(u,wc)));
				}
			}
		}
		for (auto &v:g[u][c]) {
			ll alt=du;
			if (alt<getdist(v,c)) {
				dist[v][c]=alt;
				pq.push(MP(alt,MK(v,c)));
			}
		}
	}
	ll ans=INF;
	for (auto &cand:dist[n]) {
		chkmin(ans,cand.second);
	}
	if (ans>=INF) ans=-1;
	cout<<ans<<endl;
}