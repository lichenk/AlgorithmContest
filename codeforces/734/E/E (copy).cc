#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=2e5+4;
ll n;
ll c[mn],oc[mn];
vector<ll> g[mn];
bool seen[mn];
ll wc;
void dfs(ll x) {
	if (seen[x]) return;
	seen[x]=true;
	c[x]=wc;
	for (auto &y:g[x]) {
		if (c[y]!=wc&&!seen[y]) {
			dfs(y);
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld",&oc[i]);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%lld%lld",&x,&y);
		g[x].PB(y);
		g[y].PB(x);
	}
	ll final=INF;
	for (ll gc=0;gc<2;gc++) {
		wc=gc;
		for (ll i=1;i<=n;i++) c[i]=oc[i];
		memset(seen,0,sizeof seen);
		ll ans=0;
		for (ll x=1;x<=n;x++) {
			if (c[x]!=gc&&(!seen[x])) {
				dfs(x);
				ans++;
			}
		}
		chkmin(final,ans);
	}
	printf("%lld\n",final);
}

