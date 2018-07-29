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
bool seen[55];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	vector<ll> v;
	for (ll x=0;x<n;x++) v.PB(x);
	do {
		memset(seen,0,sizeof seen);
		vector<vll> all;
		for (ll x=0;x<n;x++) {
			if (seen[x]) continue;
			vll cyc;
			seen[x]=true;
			cyc.PB(x);
			ll y=v[x];
			if (y!=x) {
				while(y!=x) {
					cyc.PB(y);
					seen[y]=true;
					y=v[y];
				}
			}
			pll best=MP(-1ll,-1ll);
			for (ll i=0;i<cyc.size();i++) chkmax(best,MP(cyc[i],i));
			//for (auto &w:cyc) printf("%lld ",w);
			//printf(" end partial (%lld). ",best.snd);
			vll cyc2;
			ll csz=cyc.size();
			for (ll i=0;i<cyc.size();i++) {
				cyc2.PB(cyc[(i+best.snd)%csz]);
			}
			all.PB(cyc2);
		}
		sort(all.begin(),all.end());
		vll final;
		for (auto &x:all) for (auto &y:x) final.PB(y);
		if (final==v) {
			for (auto &w:final) printf("%lld ",w+1);
			printf("\n");
		}
	} while(next_permutation(v.begin(),v.end()));
}

