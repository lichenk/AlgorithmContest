#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
#include <immintrin.h>
#include <emmintrin.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int mn=701;
bitset<mn> g[mn];
int a[mn];
queue<int> q[2];
void fail() {
	printf("-1\n"); exit(0);
}
int c[2];
void psh(int x, int t) {
	//printf("x:%d assigned t:%d\n",x,t);
	if (a[x]!=-1) {
		if (a[x]!=t) fail();
		return;
	}
	a[x]=t;
	c[t]++;
	q[t].push(x);
}
ll c2(ll x) {
	return (x*(x-1))/2;
}
bitset<mn> knap[2];
int main()
{
  int n,m; scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++) {
  	int x,y; scanf("%d%d",&x,&y); --x;--y;
  	g[x][y]=true; g[y][x]=true;
  }
  memset(a,-1,sizeof a);
  int cur=0,nxt=1;
  knap[cur][0]=true;
  for (int init=0;init<n;init++) {
  	if (a[init]!=-1) continue;
  	memset(c,0,sizeof c);
	  psh(init,0);
	  while(!(q[0].empty()&&q[1].empty())) {
	  	for (int t=0;t<2;t++) {
		  	if (!q[t].empty()) {
		  		int x=q[t].front(); q[t].pop();
		  		for (int y=0;y<n;y++) {
		  			if (y!=x&&!g[x][y]) {
		  				psh(y,t^1);
		  			}
		  		}
		  	}
		  }
	  }
	  knap[nxt]=knap[cur]<<c[0];
	  knap[nxt]|=knap[cur]<<c[1];
	  swap(cur,nxt);
	}
	ll ans=1e9;
	for (int x=0;x<=n;x++) {
		if (knap[cur][x]) {
			ll cand=c2(x)+c2(n-x);
			chkmin(ans,cand);
		}
	}
  printf("%lld\n",ans);
}