#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
ll n,m,k;
bitset<mn> isfort;
set<ll> oldg[mn];
ll alldeg[mn];
ll old_good_deg[mn];
ll gooddeg[mn];
set<ll> g[mn];
inline ld rat(ll x) {
	return (ld)gooddeg[x]/(ld)alldeg[x];
}
bitset<mn> isrm;
bool f(ld r) {
	for (ll x=1;x<=n;x++) g[x]=oldg[x];
	memcpy(gooddeg,old_good_deg,sizeof gooddeg);
	isrm=isfort;
	queue<ll> q;
	for (ll x=1;x<=n;x++) {
		if (!isfort[x]&&rat(x)<r) {
			isrm[x]=true;
			//printf("init rm:%d\n",x);
			q.push(x);
		}
	}
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		for (auto &y:g[x]) {
			g[y].erase(x);
			gooddeg[y]--;
			if ((!isrm[y])&&rat(y)<r) {
				//printf("%d rm:%d\n",x,y);
				isrm[y]=true;
				q.push(y);
			}
		}
		g[x].clear();
	}
	return (isrm.count()<n);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d%d",&n,&m,&k);
	isfort.reset();
	for (ll i=0;i<k;i++) {
		ll fort; scanf("%d",&fort); isfort[fort]=true;
	}
	for (ll i=0;i<m;i++) {
		ll a,b; scanf("%d%d",&a,&b);
		oldg[a].insert(b);oldg[b].insert(a);
	}
	for (ll x=1;x<=n;x++) {
		alldeg[x]=oldg[x].size();
		ll good=0;
		for (auto &y:oldg[x]) {
			if (!isfort[y]) good++;
		}
		old_good_deg[x]=good;
	}
	for (ll x=1;x<=n;x++) {
		if (isfort[x]) {
			for (auto &y:g[x]) oldg[y].erase(x);
			g[x].clear();
		}
	}
	//assert(!f(0.999));
	ld imin=0,imax=1;
	for (ll k=0;k<43;k++) {
		ld imid=(imin+imax)/2;
		if (f(imid)) imin=imid;
		else imax=imid;
	}
	printf("%.4f\n",imin);
	/*f(imin);
	ll cnt=0;
	for (ll x=1;x<=n;x++) if(!isrm[x]) cnt++;
	if (cnt==0) {
		isrm=isfort;
		for (ll x=1;x<=n;x++) if(!isrm[x]) cnt++;
	}
	printf("%d\n",cnt);
	for (ll x=1;x<=n;x++) if(!isrm[x]) {printf("%d ",x);}
	printf("\n");*/
}