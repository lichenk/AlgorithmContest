#include "bits/stdc++.h"
#include <assert.h>
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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int mn=50+2;
set<int> orig[mn];
set<int> g[mn];
class MatchTree {
public:
	static const int maxn=mn;
	bitset<maxn> match;
	bool ok;
	void rst() {ok=1; match.reset();}
	bool doMatch(int x, int p) { // True iff x is matched with a child
		bool matched=false;
		for (auto &y:g[x]) {
			if (y==p) continue;
			if (!doMatch(y,x)) {
				if (matched) {ok=0;}
				matched=true;
				match[x]=true; match[y]=true;
			}
		}
		return matched;
	}
	bool hasMatch(int n) {
		return match.count()==n && ok;
	}
};

MatchTree mt;

void ae(int x, int y) {
	g[x].insert(y); g[y].insert(x);
}
void re(int x, int y) {
	g[x].erase(y); g[y].erase(x);
}
class DfsCycle {
	bitset<mn> seen;
public:
	bool cyc=false;
	void rst() {cyc=false; seen.reset();}
	void dfs(int x, int p) {
		//printf("p:%d -> x:%d\n",p,x);
		if (seen[x]) {
			//printf("CYC\n");
			cyc=true; return;
		}
		seen[x]=true;
		for (auto &y:g[x]) {
			if (y==p) continue;
			dfs(y,x);
		}
	}
	bool isTree(int n) {
		bool ret=(!cyc)&&(seen.count()==n);
		//printf("cyc:%d seen.count():%d n:%d ret:%d\n",cyc,seen.count(),n,ret);
		return ret;
	}
};
DfsCycle dc;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<n;i++) {
  	int x=rint(),y=rint(); orig[x].insert(y); orig[y].insert(x);
  }
  int ans=0;
  for (int a=1;a<=n;a++) for (int b=1;b<a;b++) {
  	if (1!=orig[a].count(b)) continue;
  	for (int c=1;c<=n;c++) for (int d=1;d<c;d++) {
  		if (!(a==c&&b==d)) {
  			if (0!=orig[c].count(d)) continue;
  		}
  		for (int x=1;x<=n;x++) g[x]=orig[x];
  		re(a,b);
  		ae(c,d);
  		dc.rst();
  		dc.dfs(1,-1);
  		//if (dc.isTree(n)) printf("FUCKa:%d b:%d c:%d d:%d\n",a,b,c,d);
  		if (!dc.isTree(n)) continue;
  		mt.rst();
  		mt.doMatch(1,-1);
  		if (mt.hasMatch(n)) {
  			ans++;
  			dbg("%d-%d  %d-%d\n",a,b,c,d);
  		}
  	}
	}
	printf("%d\n",ans);
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}