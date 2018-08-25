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
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1002;
int v[mn];
//set<int> g[mn];
//ll vcost[mn];
//bitset<mn> seen;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	for (int x=1;x<=n;x++) {
		v[x]=rint();
		//printf("x:%d v:%d\n",x,v[x]);
	}
	ll final=0;
	for (int i=1;i<=m;i++) {
		int x=rint(),y=rint();
		final+=min(v[x],v[y]);
	}
	//final/=2;
	printf("%lld\n",final);
}

