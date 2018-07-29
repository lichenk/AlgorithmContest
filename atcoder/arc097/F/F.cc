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
//int rint();char rch();long long rlong();
const int mn=1e5+4;
vector<int> inp[mn];
bitset<mn> b;
bitset<mn> predp;
bool pre(int x, int p) {
  bool ans=b[x];
  int id=0;
  for (auto &y:inp[x]) {
    if (y==p) continue;
    //printf("p:%d id:%d x:%d y:%d\n",p,id,x,y);
    ans=pre(y,x)||ans;
    ++id;
  }
  //printf("p:%d x:%d ans:%d\n",p,x,ans);
  return predp[x]=ans;
}
vi g[mn];
int nume=0;
void makeg(int x, int p) {
  if (predp[x]==0) return;
  for (auto &y:inp[x]) {
    if (y==p) continue;
    if (predp[y]==0) continue;
    g[x].PB(y); g[y].PB(x);
    nume++;
    makeg(y,x);
  }
}
bitset<mn> c;
int dpe[mn],dpi[mn];
int dfs1(int x, int p) { // end MUST exclude bottom vertex
	int bonus=(c[x]?1:-1);
	int ans=1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		int cand=dfs1(y,x)+bonus+1;
		chkmax(ans,cand);
	}
	//printf("x:%d dpe:%d\n",x,ans);
	return dpe[x]=ans;
}
int dfs2(int x, int p) { // start MUST include bottom vertex
	int bonus=(c[x]?1:-1);
	int ans=bonus+1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		int cand=dfs2(y,x)+bonus+1;
		chkmax(ans,cand);
	}
	//printf("x:%d dpi:%d\n",x,ans);
	return dpi[x]=ans;
}
int final=0;
void peek(int x, int p) {
	int bonus=c[x]?1:-1;
	int be=-INF,bi=-INF;
	int ans=0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		chkmax(ans,dpe[y]+bi+bonus);
		chkmax(ans,dpi[y]+be+bonus);
		chkmax(be,dpe[y]);
		chkmax(bi,dpi[y]);
	}
	chkmax(ans,bi);
	chkmax(ans,be+bonus);
	chkmax(final,ans);
	for (auto &y:g[x]) if (y!=p) peek(y,x);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<n;i++) {
    int x,y; cin>>x>>y;
    //printf("x:%d y:%d\n",x,y);
    inp[x].PB(y); inp[y].PB(x);
  }
  string s; cin>>s;
  for (int x=1;x<=n;x++) {
    b[x]=(s[x-1]=='W');
    //printf("x:%d %d\n",x,(int)b[x]);
  }
  int initx=-1;
  for (int x=1;x<=n;x++) {
    if (b[x]) {initx=x; break;}
  }
  if (initx==-1) {
    printf("0\n"); return 0;
  }
  pre(initx,-1);
  makeg(initx,-1);
  for (int x=1;x<=n;x++) c[x]=(g[x].size()&1)^b[x];
  dfs1(initx,-1); dfs2(initx,-1);
  peek(initx,-1);
  int ans=nume*2+c.count()-(final);
  printf("%d\n",ans);
}
