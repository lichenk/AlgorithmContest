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
ll ax,ay,az;
ll fy(ll y, ll z, bool need) {
	for (ll i=0;i<n;i++) {
		d[i]=abs(pt[i].second.first-y)+abs(pt[i].second.second-z);
	}
	rpt[n-1]=d[n-1]+pt[n-1].first;
	for (ll i=n-2;i>=0;i--) {
		rpt[i]=d[i]+pt[i].first;
		chkmax(rpt[i],rpt[i+1]);
	}
	if (need) {
		pair<ll,ll> best=MP(INF,INF);
		ll lc=d[0]-pt[0].first;
		for (ll i=0;i<n-1;i++) {
			chkmax(lc,d[i]-pt[i].first);
			ll rc=rpt[i+1];
			ll lx=pt[i].first, rx=pt[i+1].first;
			if (lx==rx) continue;
			ll intx[2];
			intx[0]=(rc-lc)/2;
			intx[1]=(rc-lc+1)/2;
			chkmin(best,MP(max(lc+lx,rc-lx),lx));
			chkmin(best,MP(max(lc+rx,rc-rx),rx));
			for (ll j=0;j<2;j++) {
				if (lx<=intx[j]&&intx[j]<=rx) {
					chkmin(best,MP(max(lc+intx[j],rc-intx[j]),intx[j]));
				}
			}
		}
		ax=best.second;
		return best.first;
	}
		ll best=INF;
		ll lc=d[0]-pt[0].first;
		for (ll i=0;i<n-1;i++) {
			chkmax(lc,d[i]-pt[i].first);
			ll rc=rpt[i+1];
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
		return best;
}
ll fz(ll z) {
	//printf("fz:%I64d\n",z);
	ll ymin=0,ymax=MAXX+1;
	while(ymin<ymax) {
		//printf("Binsearchy: %I64d %I64d\n",ymin,ymax);
		ll ymid=(ymin+ymax)/2;
		if (fy(ymid,z,false)>fy(ymid+1,z,false)) {
			ymin=ymid+1;
		}
		else ymax=ymid;
	}
	ay=ymin;
	return fy(ymin,z,true);
}
int main() {
	ll t; scanf("%I64d",&t);
	for (ll tt=0;tt<t;tt++) {
		scanf("%I64d",&n);
		bool same=true;
		for (ll i=0;i<n;i++) {
			ll x,y,z;
			scanf("%I64d %I64d %I64d", &x,&y,&z);
			pt[i]=MP(x+BASE,MP(y+BASE,z+BASE));
			if (pt[i]!=pt[0]) same=false;
		}
		if (same) {
			printf("%I64d %I64d %I64d\n",pt[0].first-BASE,pt[0].second.first-BASE,pt[0].second.second-BASE);
			continue;
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
		fz(zmin);
		az=zmin;
		printf("%I64d %I64d %I64d\n",ax-BASE,ay-BASE,az-BASE);
	}
}