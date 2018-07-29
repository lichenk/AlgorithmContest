#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=100000+4;
const ll INF=5e9;
vector<pair<ll,pair<ll,ll> > > vp;
vector<ll> vy;
const ll DSZ=300*100000;
int delta[DSZ];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; cin>>n>>k;
	set<ll> sy;
	for (ll i=0;i<n;i++) {
		ll x,y; cin>>x>>y;
		sy.insert(y);
		vp.PB(MP(x,MP(y,1)));
		vp.PB(MP(x+k,MP(y,-1)));
	}
	sort(vp.begin(),vp.end());
	ll ly=-INF;
	for (auto &w:sy) {
		for (ll x=max(ly,w);x<w+k;x++) {
			vy.PB(x);
		}
		ly=w+k;
	}
	ll vysz=vy.size();
	for (ll i=0;i<vysz;i++) delta[i]=0;
	for (ll c=1;c<=n;c++) ans[c]=0;
	ll ex=h.rbegin()->first;
	for (auto &w:v) {
		ll x=w.first;
		ll dx=ex-x;
		ll y=w.second.first;
		ll t=w.second.second;
		ll imin=0,imax=vysz;
		while(imin<imax) {
			ll imid=(imin+imax)/2;
			if (vy[imid]<y) imin=imid+1;
			else imax=imid;
		}
		ll iy=imin;
		for (ll )

	}
	for (ll c=1;c<=k;c++) {
		ans[c]=0; now[c]=0;
	}
	ll px=INF;
	map<ll,ll> g;
	for (auto &w:h) {
		ll x=w.first;
		if (px!=INF) {
			ll dx=x-px;
			for (ll c=1;c<=k;c++) {
				ans[c]+=now[c]*dx;
				now[c]=0;
			}
		}
		for (auto &q:w.second) {
			ll y=q.first,t=q.second;
			g[y]+=t;
			if (g[y]==0) {
				g.erase(y);
			}
			g[y+k]-=t;
			if (g[y+k]==0) {
				g.erase(y+k);
			}
		}
		ll sum=0;
		ll py=INF;
		for (auto &p:g) {
			ll y=p.first;
			if (py!=INF) {
				now[sum]+=y-py;
			}
			sum+=p.second;
		}
	}
	for (ll c=1;c<=k;c++) {
		cout<<ans[c]<<" ";
	}
	cout<<endl;
}