#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
const ll mn=2e5+2;
ll vx[mn];
ll n,m;
ll get_geq(ll x) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (vx[imid]<x) imin=imid+1;
		else imax=imid;
	}
	if (0<=imin&&imin<n&&vx[imin]>=x) return imin;
	return -1;
}
ll get_leq(ll x) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (vx[imid]<=x) imin=imid+1;
		else imax=imid;
	}
	--imin;
	if (0<=imin&&imin<n&&vx[imin]<=x) return imin;
	return -1;
}
vll vdir,va,vl;
const ll RIGHT=1;
ll f(ll dir, ll a, ll l) {
	//printf("dir:%lld a:%lld l:%lld\n",dir,a,l);
	if (l==0) return a;
	ll vsz=vdir.size();
	if (vsz>=2&&vdir[vsz-2]==dir&&va[vsz-2]==a) {
		ll diff=vl[vsz-2]-l;
		ll need=min(
			get_leq(vx[a]+diff-1),
			get_geq(vx[a]-diff+1)
			);
		ll toadd=(l-need)%diff;
		if (toadd<0) toadd+=diff;
		ll otherl=toadd+need;


	}
	vdir.PB(dir);va.PB(a);vl.PB(l);
	ll newa;
	if (dir==RIGHT) {
		newa=get_leq(vx[a]+l);
	}
	else {
		newa=get_geq(vx[a]-l);
	}
	if (newa==-1||newa==a) {
		dir^=1;
		if (dir==RIGHT) {
			newa=get_leq(vx[a]+l);
		}
		else {
			newa=get_geq(vx[a]-l);
		}
	}
	if (newa==-1||newa==a) return a;
	ll newl=l-abs(vx[newa]-vx[a]);
	ll newdir=dir^1;
	return f(newdir,newa,newl);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&n,&m);
	for (ll i=0;i<n;i++) scanf("%lld",&vx[i]);
	sort(vx,vx+n);
	for (ll i=0;i<m;i++) {
		vdir.clear(),va.clear(),vl.clear();
		ll a,l;
		scanf("%lld%lld",&a,&l);
		--a;
		for (ll d=0;d<2;d++) h[d].clear();
		ll ans=f(RIGHT,a,l);
		ans++;
		printf("%lld\n",ans);
	}
}

