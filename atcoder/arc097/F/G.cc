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
int dp1[mn],dp2[mn];
int dfs1(int x, int p) { // end
	int bonus=(c[x]?1:-1);
	int ans=max(0,bonus);
	for (auto &y:g[x]) {
		if (y==p) continue;
		int cand=dfs1(y,x)+bonus+1;
		chkmax(ans,cand);
	}
	return dp1[x]=ans;
}
int dfs2(int x, int p) { // start
	int bonus=(c[x]?1:-1)+1;
	int ans=max(0,bonus);
	for (auto &y:g[x]) {
		if (y==p) continue;
		int cand=dfs2(y,x)+bonus;
		chkmax(ans,cand);
	}
	dp2[x]=ans-1;
	return ans;
}
int final=0;
void peek(int x, int p) {
	vector<pii> v1,v2;
	for (auto &y:g[x]) {
		if (y==p) continue;
		v1.PB(MP(dp1[y],y));
		v2.PB(MP(dp2[y],y));
	}
	sort(v1.begin(),v1.end(),greater<pii>());
	sort(v2.begin(),v2.end(),greater<pii>());
	int bonus=c[x]?1:-1;
	int ans=bonus;
	if (v1.size()>=1) {
		chkmax(ans,v1[0].fst+bonus+1);
		chkmax(ans,v2[0].fst+1);
	}
	if (v1.size()>=2) {
		for (int a=0;a<2;a++) for (int b=0;b<2;b++) {
			if (v1[a].snd!=v2[b].snd) {
				int cand=v1[a].fst+v2[b].fst+2+bonus;
				//printf("a:%d b:%d cand:%d\n",a,b,cand);
				chkmax(ans,cand);
			}
		}
	}
	//printf("x:%d ans:%d\n",x,ans);
	chkmax(final,ans);
	for (auto &y:g[x]) {
		if (y==p) continue;
		peek(y,x);
	}
}

char s[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d\n",&n);
  for (int i=1;i<n;i++) {
    int x,y; scanf("%d %d\n",&x,&y);
    //printf("x:%d y:%d\n",x,y);
    inp[x].PB(y); inp[y].PB(x);
  }
  scanf("%s\n",s);
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
  peek(initx,-1);
  int ans=nume*2+c.count()-(final);
  printf("%d\n",ans);
}
