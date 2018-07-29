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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=1e5+4;
int vc[mn];
int f[mn][11];
vector<pll> ve;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int x,y; scanf("%d%d",&x,&y); ve.PB(MP(x,y)); ve.PB(MP(y,x));
	}
	int qn; scanf("%d",&qn);
	for (int i=1;i<=qn;i++) {
		int v,d;
		scanf("%d%d%d",&v,&d,&vc[i]);
		chkmax(f[v][d],i);
	}
	for (ll d=9;d>=0;d--) {
		for (auto &e:ve) {
			ll x=e.fst,y=e.snd;
			chkmax(f[y][d],f[x][d+1]);
		}
	}
	for (ll x=1;x<=n;x++) {
		ll ans=0;
		for (ll d=0;d<=10;d++) {
			chkmax(ans,f[x][d]);
		}
		printf("%d\n",vc[ans]);
	}
}

