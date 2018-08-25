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
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
const int mn=52;
int c[mn];
inline int getid(int n, int lft) {
	int r=rand()%lft;
	for (int x=0;x<n;x++) {
		if (c[x]) {
			if (r==0) return x;
			--r;
		}
	}
	assert(0);
}
typedef unsigned int uint;
uint a[2][mn];
vector<vi> gensig(vector<vi> g) {
	int n=g.size();
	set<vector<int> > s;
	vector<vi> vsig;
	for (int init=0;init<n;init++) {
		int cur=0,nxt=1;
		memset(a[cur],0,sizeof a[cur]);
		a[cur][init]=1;
		vector<int> sig(2*n);
		for (int k=0;k<2*n;k++) {
			memset(a[nxt],0,sizeof a[nxt]);
			for (int x=0;x<n;x++) {
				uint now=a[cur][x];
				if (now) for (auto &y:g[x]) {
					a[nxt][y]+=now;
				}
			}
			sig[k]=a[nxt][init];
			swap(cur,nxt);
		}
		if (s.find(sig)!=s.end()) return {};
		s.insert(sig);
		vsig.PB(sig);
	}
	return vsig;
}


vector<vi> g;
bitset<mn> d[mn];
vvi ovsig;
bool go(int n) {
	for (int x=0;x<n;x++) c[x]=4;
	g.resize(n);
	for (int x=0;x<n;x++) {g[x].clear(); d[x].reset();}
	int lft=n;
	int e=0;
	while(lft) {
		int x=getid(n,lft); if(--c[x]==0) --lft;
		int y=getid(n,lft);
		int tries=0;
		while(y==x||d[x][y]) {
			y=getid(n,lft);
			if (++tries>12) return false;
		}
		if(--c[y]==0) --lft;
		g[x].PB(y); g[y].PB(x); d[x][y]=d[y][x]=true;
		++e;
	}
	ovsig=gensig(g);
	if (ovsig.size()==n) {
		return true;
	}
	else return false;
}
int vans[mn];
void solve(int casenum) {
	int L,U; scanf("%d %d",&L,&U);
	int n=L;
	while(1) {
		bool got=go(n);
		if (got) {
			break;
		}
	}
	printf("%d\n",n);
	for (int x=0;x<n;x++) {
		for (auto &y:g[x]) {
			if(x<y) printf("%d %d\n",x+1,y+1);
		}
	}
	fflush(stdout);
	int tmp; scanf("%d",&tmp);
	//assert(tmp==n);
	vvi h; h.resize(n);
	for (int i=0;i<2*n;i++) {
		int x,y; scanf("%d%d",&x,&y);
		--x; --y;
		h[x].PB(y); h[y].PB(x);
	}
	vvi nsig=gensig(h);
	for (int x=0;x<n;x++) {
		for (int y=0;y<n;y++) {
			if (nsig[y]==ovsig[x]) {
				vans[x]=y;
			}
		}
	}
	for (int x=0;x<n;x++) printf("%d ",vans[x]+1);
	printf("\n");
	fflush(stdout);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; scanf("%d",&T);
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
