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
const ll mn=1004;
ll vp[mn],vb[mn];
ll prepos[mn];
ll custc[mn];
ll posc[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; scanf("%lld",&numtests);
	for (ll testnum=1;testnum<=numtests;testnum++) {
		ll n,c,m; scanf("%lld%lld%lld",&n,&c,&m);
		for (ll i=0;i<m;i++) {
			scanf("%lld%lld",&vp[i],&vb[i]);
		}
		memset(prepos,0,sizeof prepos);
		memset(custc,0,sizeof custc);
		memset(posc,0,sizeof posc);
		for (ll i=0;i<m;i++) {
			prepos[vp[i]]++;
			posc[vp[i]]++;
			custc[vb[i]]++;
		}
		for (ll x=1;x<mn;x++) prepos[x]+=prepos[x-1];
		ll rides=0;
		for (ll c=0;c<mn;c++) chkmax(rides,custc[c]);
		for (ll x=1;x<mn;x++) chkmax(rides,(prepos[x]+x-1)/x);
		ll promote=0;
		for (ll x=1;x<mn;x++) {
			promote+=max(0ll, posc[x]-rides);
		}
		assert(rides!=0);
		printf("Case #%lld: %lld %lld\n",testnum,rides,promote);
	}
}

