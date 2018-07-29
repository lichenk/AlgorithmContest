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
const ll mn=504;
const ll logm=62;
ll a[2][mn][mn];
ll b[2][mn][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%lld%lld",&n,&m);
	memset(a,-1,sizeof a);
	for (ll i=0;i<m;i++) {
		ll v,u,t;
		scanf("%lld%lld%lld",&v,&u,&t);
		a[t][v][u]=1;
	}	
	ll ans=0;
	for (ll y=1;y<=n;y++) {
		chkmax(ans,a[0][1][y]);
	}
	for (ll k=0;k<logm;k++) {
		memset(b,-1,sizeof b);
		for (ll flip=0;flip<2;flip++) {
			for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
				ll best=a[flip][x][y];
				for (ll z=0;z<=n;z++) {
					if (a[flip][x][z]==1LL<<k && a[flip^1][z][y]!=-1) {
						chkmax(best, a[flip][x][z]+a[flip^1][z][y]);
					}
				}
				b[flip][x][y]=best;
			}
		}
		for (ll y=1;y<=n;y++) {
			chkmax(ans,b[0][1][y]);
		}
		swap(a,b);
	}
	ll lim=1000000000000000000LL;
	if (ans>lim) ans=-1;
	printf("%lld\n",ans);
}

