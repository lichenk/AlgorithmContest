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
ll c[mn];
vector<ll> g[mn];
vector<ll> h[mn];
bool seen[mn];
ll dfs(ll x, ll r) {
	seen[x]=true;
	for (auto &y:g[x]) {
		if (seen[y]) continue;
		if (c[y]!=c[x]) {
			h[r].PB(y);
			h[y].PB(r);
			dfs(y,y);
		}
		else {
			dfs(y,r);
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d",&n);
	for (ll i=1;i<=n;i++) scanf("%d",&c[i]);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%d%d",&x,&y);
		g[x].PB(y);
		g[y].PB(x);
	}
	memset(seen,0,sizeof seen);
	dfs(1,1);
	printf("%lld\n",final);
}

