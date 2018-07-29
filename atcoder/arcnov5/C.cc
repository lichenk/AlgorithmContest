#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll INF=1e9;
const ll UNDEF = INF;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=1e5+4;
vector<ll> g[mn];
ll vp[mn];
ll vl[mn],vr[mn],odd[mn];
bool seen[mn];
bool fail=false;

bool iscentroid[mn];
ll getCentroid(ll u,ll p,ll n) {
    ll cnt = 1;
    bool goodCenter = true;
    for (auto w : g[u]) {
    	ll v=w;
      if (v == p||iscentroid[v]) continue;
      ll res = getCentroid(v, u, n);
      if (res >= 0)
        return res;
      ll size = -res;
      goodCenter &= size <= n / 2;
      cnt += size;
    }
    goodCenter &= n - cnt <= n / 2;
    return goodCenter ? u : -cnt;
  }
ll getSubtreeSize(ll x,ll p) {
	ll selfSubtreeSize=1;
	for (auto &w:g[x]) {
		ll y=w;
		if (y==p||iscentroid[y]) continue;
		ll childSubtreeSize=getSubtreeSize(y,x);
		selfSubtreeSize+=childSubtreeSize;
	}
	return selfSubtreeSize;
}

void dfs(ll x, ll par) {
	if (vp[x]!=UNDEF) return;
	//if (seen[x]) return;
	//seen[x]=true;
	for (auto &y:g[x]) {
		if (y==par) continue;
		dfs(y,x);
		chkmax(vl[x],vl[y]-1);
		chkmin(vr[x],vr[y]+1);
		//printf("x:%lld y:%lld odd:%lld\n",x,y,odd[y]);
		if (odd[y]!=UNDEF) {
			ll need=odd[y]^1;
			if (odd[x]==UNDEF) odd[x]=need;
			else if (odd[x]!=need) {
				fail=true; break;
			}
		}
	}
}

ll final=0;
void fullCentroidDecomposition(ll initv,ll p,ll n) {
	ll centroid=getCentroid(initv,p,n);
	vector<pll> subtreeRootsWithSizes;
	for (auto &w:g[centroid]) {
		ll y=w;
		if (y!=p&&(!iscentroid[y])) {
			ll sz=getSubtreeSize(y,centroid);
			subtreeRootsWithSizes.PB(MP(y,sz));
		}
	}
	/* Custom code starts here */
	dfs(centroid,-1);
	for (ll y=max(vl[centroid],-mn);y<=vr[centroid];y++) {
		ll parity=((y%2)+2)%2;
		if (parity==odd[centroid]||odd[centroid]==UNDEF) {
			//printf("%lld getting %lld. %lld %lld %lld\n",centroid+1,y,vl[centroid],vr[centroid],odd[centroid]);
			vp[centroid]=y;
			vl[centroid]=y;
			vr[centroid]=y;
			odd[centroid]=parity;
			break;
		}
	}
	if (vp[centroid]==UNDEF) {
		fail=true;
		return;
	}
	/* Custom code ends here. Continue decomposing subtree.*/
	iscentroid[centroid]=true;
	for (auto &got:subtreeRootsWithSizes) {
		fullCentroidDecomposition(got.first,centroid,got.second);
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(iscentroid,0,sizeof iscentroid);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%lld%lld",&x,&y);
		--x;--y;
		g[x].PB(y); g[y].PB(x);
	}
	ll k; scanf("%lld",&k);
	for (ll x=0;x<n;x++) {
		vp[x]=UNDEF;
		vl[x]=-INF,vr[x]=INF,odd[x]=UNDEF;
	}
	for (ll i=0;i<k;i++) {
		ll x,px; scanf("%lld%lld",&x,&px);
		--x;
		vp[x]=px;
		vl[x]=px;
		vr[x]=px;
		ll parity=((px%2)+2)%2;
		odd[x]=parity;
	}
	fullCentroidDecomposition(0,-1,n);
	bool cfail=false;
	for (ll x=0;x<n;x++) {
		for (auto &y:g[x]) {
			if (abs(vp[x]-vp[y])!=1) cfail=true;
		}
	}
	//assert(fail==cfail);
	if (cfail) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
		for (ll x=0;x<n;x++) {
			printf("%lld\n",vp[x]);
		}
	}
}

