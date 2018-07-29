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
typedef unsigned long long ull;
const ll mn=504;
const ll logm=62;
const ll mk=64;
ull a[2][mn][4+((mn+mk-1)/mk)];
ull b[2][mn][4+((mn+mk-1)/mk)];
inline ll one(x) {return x/mk;}
inline ll two(x) {return x%mk;}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%d%d",&n,&m);
	memset(a,0,sizeof a);
	long long ans=0;
	for (ll i=0;i<m;i++) {
		ll v,u,t;
		scanf("%d%d%d",&v,&u,&t);
		a[t][v][one(u)]|=two(u);
		if (v==1&&t==0) ans=1;
	}
	ll ylim=((n+1+mk-1)/mk)+1;
	for (ll k=0;k<logm;k++) {
		memset(b,0,sizeof b);
		for (ll flip=0;flip<2;flip++) {
			for (ll x=1;x<=n;x++) for (ll y=0;y<ylim;y++) {
				long long best=a[flip][x][y];
				for (ll z=0;z<=n;z++) {
					if (a[flip][x][z]==1LL<<k) {
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
	long long lim=1000000000000000000LL;
	if (ans>lim) ans=-1;
	printf("%lld\n",ans);
}