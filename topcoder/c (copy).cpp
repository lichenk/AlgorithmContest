#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXN=100000+4;
pair<ll,pair<ll,ll> > pt[MAXN];
ll d[MAXN];
const ll MAXX=2e18;
const ll INF=9e18;
const ll BASE=1e18;
ll n;
ll lpt[MAXN];
ll rpt[MAXN];
ll fy(ll y, ll z) {
	for (ll i=0;i<n;i++) {
		d[i]=abs(pt[i].second.first-y)+abs(pt[i].second.second-z);
	}
	for (ll i=0;i<n;i++) {
		lpt[i]=d[i]-pt[i].first;
		if (i>0) chkmax(lpt[i],lpt[i-1]);
	}
	for (ll i=n-1;i>=0;i--) {
		rpt[i]=d[i]+pt[i].first;
		if (i<n-1) chkmax(rpt[i],rpt[i+1]);
	}
	ll best=INF;
	for (ll i=0;i<n-1;i++) {
		ll lc=lpt[i],rc=rpt[i+1];
		ll lx=pt[i].first, rx=pt[i+1].first;
		if (lx==rx) continue;
		ll intx[2];
		intx[0]=(rc-lc)/2;
		intx[1]=(rc-lc+1)/2;
		chkmin(best,max(lc+lx,rc-lx));
		chkmin(best,max(lc+rx,rc-rx));
		for (ll j=0;j<2;j++) {
			if (lx<=intx[j]&&intx[j]<=rx) {
				chkmin(best,max(lc+intx[j],rc-intx[j]));
			}
		}
	}
	if (best>=INF) return 0;
	return best;
}
ll fz(ll z) {
	//printf("fz:%lld\n",z);
	ll ymin=0,ymax=MAXX+1;
	while(ymin<ymax) {
		//printf("Binsearchy: %lld %lld\n",ymin,ymax);
		ll ymid=(ymin+ymax)/2;
		if (fy(ymid,z)>fy(ymid+1,z)) {
			ymin=ymid+1;
		}
		else ymax=ymid;
	}
	return fy(ymin,z);
}
int main() {
	ll t; scanf("%lld",&t);
	for (ll tt=0;tt<t;tt++) {
		scanf("%lld",&n);
		for (ll i=0;i<n;i++) {
			ll x,y,z;
			scanf("%lld %lld %lld", &x,&y,&z);
			pt[i]=MP(x+BASE,MP(y+BASE,z+BASE));
		}
		sort(pt,pt+n);
		ll zmin=0,zmax=MAXX+1;
		while(zmin<zmax) {
			ll zmid=(zmin+zmax)/2;
			if (fz(zmid)>fz(zmid+1)) {
				zmin=zmid+1;
			}
			else {
				zmax=zmid;
			}
		}
		ll ans=fz(zmin);
		printf("%lld\n",ans);
	}
}