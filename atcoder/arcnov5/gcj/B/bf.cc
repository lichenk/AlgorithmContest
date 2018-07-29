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
const ll mn=8;
ll vp[mn],vb[mn];
ll a[mn][mn];
ll fail[2];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; scanf("%lld",&numtests);
	for (ll testnum=1;testnum<=numtests;testnum++) {
		ll n,c,m; scanf("%lld%lld%lld",&n,&c,&m);
		if (n>7||c>7||m>7) continue;
		for (ll i=0;i<m;i++) {
			scanf("%lld%lld",&vp[i],&vb[i]);
			vp[i]--;
		}
		ll prom=INF;
		ll ridez=INF;
		for (ll rides=1;rides<mn;rides++) {
			for (ll k=0;k<100000;k++) {
				ll promotes=0;
				memset(a,-1,sizeof a);
				bool ok=1;
				for (ll i=0;i<m;i++) {
					ll ridepos=rand()%rides;
					ll pos=vp[i];
					ll promote=rand()%2;
					if (vp[i]>0&&promote) {
						pos=rand()%vp[i];
						promotes+=promote;
					}
					if (a[ridepos][pos]!=-1) {ok=0; break;}
					a[ridepos][pos]=i;
				}
				if (!ok) continue;
				for (ll rp=0;rp<rides;rp++) {
					bitset<mn> b; b.reset();
					for (ll pos=0;pos<mn;pos++) {
						ll i=a[rp][pos];
						if (i==-1) continue;
						ll cust=vb[i];
						if (b[cust]) {ok=0; break;}
						b[cust]=true;
					}
				}
				if (ok) {
					chkmin(prom,promotes);
				}
			}
			if (prom<INF) {ridez=rides; break;}
		}
		printf("Case #%lld: %lld %lld\n",testnum,ridez,prom);
		//printf("%lld %lld\n",fail[0],fail[1]);
	}
}

