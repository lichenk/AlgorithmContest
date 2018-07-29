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
const ll mn=104;
const ll mp=4;
int df[mn][mn][mn][mn][mp];
ll vcnt[mp];
ll g[mn];
ll n,p;
ll f(ll a, ll b, ll c, ll d, ll l) {
	ll dpval=df[a][b][c][d][l];
	if (a+b+c+d==0) return 0;
	if (dpval!=-1) return dpval;
	ll ans=0;
	if (a>0) chkmax(ans, f(a-1,b,c,d,(l+p-0)%p));
	if (b>0) chkmax(ans, f(a,b-1,c,d,(l+p-1)%p));
	if (c>0) chkmax(ans, f(a,b,c-1,d,(l+p-2)%p));
	if (d>0) chkmax(ans, f(a,b,c,d-1,(l+p-3)%p));
	if (l==0) ans++;
	return df[a][b][c][d][l]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; scanf("%lld",&numtests);
	for (ll testnum=1;testnum<=numtests;testnum++) {
		scanf("%lld%lld",&n,&p);
		for (ll i=0;i<n;i++) scanf("%lld",&g[i]);
		memset(df,-1,sizeof df);
		memset(vcnt,0,sizeof vcnt);
		for (ll i=0;i<n;i++) {
			vcnt[g[i]%p]++;
		}
		ll finalans=f(vcnt[0],vcnt[1],vcnt[2],vcnt[3],0);
		printf("Case #%lld: %lld\n",testnum,finalans);
	}
}

