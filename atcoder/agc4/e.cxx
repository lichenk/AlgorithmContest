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
const ll INF=1e8;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=104;
char a[mn][mn];
ll b[mn][mn];
ll f[2][mn][mn][mn];
ll gr[mn][mn][mn];
ll gc[mn][mn][mn];
inline bool validleft(ll s,ll t,ll e) {
	return (s+1)>(t-e);
	////printf("Leftans: %lld %lld %lld: %lld\n",s,t,e,ans);
}
inline bool validright(ll s,ll t,ll e, ll n) {
	return (n-t)>(e-s);
	////printf("Rightans: %lld %lld %lld %lld: %lld\n",s,t,e,n,ans);
}
inline pair<ll,ll> getpair(ll s,ll t,ll e,ll n) {
	ll lo=max(s,t-e);
	ll hi=min(t,n-1-(e-s));
	return MP(lo,hi);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll rlim,clim; cin>>rlim>>clim;
	for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) cin>>a[r][c];
	ll er,ec;
	for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) if(a[r][c]=='E') {er=r,ec=c;}
	for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) b[r][c]=(a[r][c]=='o')?1:0;
	for (ll r=0;r<rlim;r++) for (ll sc=0;sc<clim;sc++) {
		ll sum=0;
		for (ll tc=sc;tc<clim;tc++) {
			sum+=b[r][tc];
			gr[r][sc][tc]=sum;
		}
	}
	for (ll c=0;c<clim;c++) for (ll sr=0;sr<rlim;sr++) {
		ll sum=0;
		for (ll tr=sr;tr<rlim;tr++) {
			sum+=b[tr][c];
			gc[c][sr][tr]=sum;
		}
	}
	for (ll sr=0;sr<=rlim;sr++)for (ll tr=0;tr<=rlim;tr++) for (ll sc=0;sc<=clim;sc++) f[0][sr][tr][sc]=-INF;
	f[0][er][er][ec]=0;
	ll ans=0;
	ll sumlim=rlim+clim-2;
	for (ll lsum=1;lsum<=sumlim;lsum++) {
	ll now=lsum&1,prev=now^1;
	for (ll sr=0;sr<=rlim;sr++)for (ll tr=0;tr<=rlim;tr++) for (ll sc=0;sc<=clim;sc++) f[now][sr][tr][sc]=-INF;
	for (ll lr=0;lr<rlim;lr++) for (ll sr=0;sr<rlim-lr;sr++) {
		ll tr=sr+lr;
		ll lc=lsum-lr;
		if (lc>=clim||lc<0) continue;
		for (ll sc=0;sc<clim-lc;sc++) {
			ll tc=sc+lc;
			//if (tc>=clim) continue;
			ll cand=-INF;
			if (validleft(sr,tr,er)) {
				ll v=f[prev][sr+1][tr][sc];
				if (v>=0) {
					pair<ll,ll> p=getpair(sc,tc,ec,clim);
					ll add=gr[sr][p.first][p.second];
					chkmax(cand,v+add);
					//printf("sr+1. %lld %lld %lld %lld: %lld+%lld\n",sr,tr,sc,tc,v,add);
				}
			}
			if (validright(sr,tr,er,rlim)) {
				ll v=f[prev][sr][tr-1][sc];
				if (v>=0) {
					pair<ll,ll> p=getpair(sc,tc,ec,clim);
					ll add=gr[tr][p.first][p.second];
					chkmax(cand,v+add);
					//printf("trm1. %lld %lld %lld %lld: %lld+%lld\n",sr,tr,sc,tc,v,add);
				}
			}
			if (validleft(sc,tc,ec)) {
				ll v=f[prev][sr][tr][sc+1];
				if (v>=0) {
					pair<ll,ll> p=getpair(sr,tr,er,rlim);
					ll add=gc[sc][p.first][p.second];
					chkmax(cand,v+add);
					//printf("sc+1. %lld %lld %lld %lld: %lld+%lld\n",sr,tr,sc,tc,v,add);
				}
			}
			if (validright(sc,tc,ec,clim)) {
				ll v=f[prev][sr][tr][sc];
				if (v>=0) {
					pair<ll,ll> p=getpair(sr,tr,er,rlim);
					ll add=gc[tc][p.first][p.second];
					chkmax(cand,v+add);
					//printf("tcm1. %lld %lld %lld %lld: %lld+%lld. p:%lld %lld\n",sr,tr,sc,tc,v,add,p.first,p.second);
				}
			}
			chkmax(ans,cand);
			f[now][sr][tr][sc]=cand;
		}
	}}
	cout<<ans<<endl;
}