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
const int mn=1e6+4;
bool seen[mn];
vector<int> g[mn];
bool care[mn];
void dfs(int x) {
	if (seen[x]) return;
	seen[x]=true;
	for (auto &y:g[x]) {
		if (!seen[y]) dfs(y);
	}
}


int rint()
{
  int x; scanf("%d",&x); return x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	memset(care,0,sizeof care);
	int cared=-1;
	ll self=0;
	for (int i=1;i<=m;i++) {
		int u=rint(),v=rint();
		care[u]=true; care[v]=true;
		cared=u;
		if (u!=v) {
			g[u].PB(v); g[v].PB(u);
		}
		else self++;
	}
	memset(seen,0,sizeof seen);
	dfs(cared);
	bool ok=true;
	for (int x=1;x<=n;x++) if(care[x]&&(!seen[x])) ok=false;
	if (!ok) {
		printf("0\n"); return 0;
	}
	ll ans=0;
	for (int x=1;x<=n;x++) {
		if (care[x]) {
			ll s=g[x].size();
			ans+=(s*(s-1))/2;
		}
	}
	ans+=(m-self)*self;
	ans+=(self*(self-1))/2;
	printf("%lld\n",ans);
}

