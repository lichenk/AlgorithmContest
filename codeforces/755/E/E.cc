#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll mn=1e3+2;
int g[mn][mn];

bool seen[mn];
ll dist[mn];
ll n;
void bfs(ll initx) {
	for (ll x=1;x<=n;x++) dist[x]=INF;
	queue<ll> q;
	dist[initx]=0;
	q.push(initx);
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		for (ll y=1;y<=n;y++) {
			if (x==y||!g[x][y]) continue;
			ll cand=dist[x]+1;
			if (cand<dist[y]) {
				dist[y]=cand;
				q.push(y);
			}
		}
	}
}
ll getdiam() {
	dist[1]=0; bfs(1);
	pair<ll,ll> best=MP(-1ll,-1ll);
	for (ll x=1;x<=n;x++) chkmax(best,MP(dist[x],x));
	dist[best.second]=0;bfs(best.second);
	ll diam=0;
	for (ll x=1;x<=n;x++) {
		chkmax(diam,dist[x]);
		if (dist[x]==INF) return -1;
	}
	//for (ll x=1;x<=n;x++) printf("x:%lld %lld\n",x,dist[x]);
	return diam;
}

void ae(ll x,ll y) {
	g[x][y]=1; g[y][x]=1;
}
bool solve() {
	ll k; scanf("%lld %lld",&n,&k);
	memset(g,0,sizeof g);
	if (k==1) {
		for (ll x=2;x<n;x++) {
			ae(1,x);
		}
	}
	else if (k==2) {
		for (ll x=1;x<n;x++) {
			ae(x,x+1);
		}
	}
	else if (k==3) {
		ae(1,2);ae(2,3);ae(3,4);
		ae(5,2); ae(5,4);
		for (ll x=6;x<=n;x++) ae(5,x);
	}
	else return false;
	ll d1=getdiam();
	for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
		if (x!=y) g[x][y]^=1;
	}
	//for (ll x=1;x<=n;x++) for (ll y=x+1;y<=n;y++) if(g[x][y])printf("%lld %lld\n",x,y);
	ll d2=getdiam();
	for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
		if (x!=y) g[x][y]^=1;
	}
	//printf("d:%lld %lld\n",d1,d2);
	if (min(d1,d2)==k) {
		return true;
	}
	else return false;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool ans=solve();
	if (!ans) {
		printf("-1\n"); return 0;
	}
	else {
		ll m=0;
		for (ll x=1;x<=n;x++) for (ll y=x+1;y<=n;y++) m+=g[x][y];
		printf("%lld\n",m);
		for (ll x=1;x<=n;x++) for (ll y=x+1;y<=n;y++) if(g[x][y])printf("%lld %lld\n",x,y);
	}
}

