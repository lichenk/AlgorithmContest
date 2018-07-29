#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=504;
const ll logm=62;
long long a[2][mn][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%d%d",&n,&m);
	memset(a,-1,sizeof a);
	for (ll i=0;i<m;i++) {
		ll v,u,t;
		scanf("%d%d%d",&v,&u,&t);
		a[t][v][u]=1;
	}	
	long long ans=0;
	for (ll y=1;y<=n;y++) {
		chkmax(ans,a[0][1][y]);
	}
	for (ll k=0;k<logm;k++) {
		for (ll flip=0;flip<2;flip++) {
			for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
				long long best=a[flip][x][y];
				for (ll z=1;z<=n;z++) {
					long long XZ=min(1LL<<k,a[flip][x][z]);
					long long ZY=min(1LL<<k,a[flip^1][z][y]);
					if (XZ==1LL<<k && ZY!=-1) {
						chkmax(best, XZ+ZY);
					}
				}
				a[flip][x][y]=best;
			}
		}
		for (ll y=1;y<=n;y++) {
			chkmax(ans,a[0][1][y]);
		}
	}
	long long lim=1000000000000000000LL;
	if (ans>lim) ans=-1;
	printf("%lld\n",ans);
}

