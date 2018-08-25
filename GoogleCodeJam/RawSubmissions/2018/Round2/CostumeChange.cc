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
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
const int mn=102;
const int MAXN=mn;
bitset<MAXN> g[MAXN];
const int MAX_N = MAXN, MAX_M = MAXN;
int karp_n, karp_m;
int match[MAX_N];

int matched[MAX_M], depth[MAX_N], q[MAX_N];
int v[MAX_N], vcnt;
// matched is y to x
// match is x to y
  bool BFS(){
    int t = 0;
    for(int i = 0; i < karp_n; i++)
      if (match[i] == -1) depth[i] = 0, q[t++] = i;
      else depth[i] = -1;
    for(int h = 0; h < t; h++) {
      int cur = q[h];
      int curDepth = depth[cur];
      for(int i = 0; i < karp_m; i++) {
        if (g[cur][i]) {
          int adj=i;
          if (matched[adj] == -1)
            return true;
          int next = matched[adj];
          if (depth[next] != -1) continue;
          depth[next] = curDepth + 1, q[t++] = next;
        }
      }
    }
    return false;
  }

  bool DFS(int nod) {
    v[nod] = vcnt;
    for(int i = 0; i < karp_m; i++) {
      if (g[nod][i]) {
        int adj = i;
        int next = matched[adj];
        if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
          continue;
        if (next == -1 || DFS(next)) {
          match[nod] = adj;
          matched[adj] = nod;
          return true;
        }
      }
    }
    return false;
  }
	int Match(int leftPartiteSize, int rightPartiteSize)
	{
		// If you filled in g[x][y], leftPartite is for x, rightPartite is for y
		vcnt=0;
		karp_n=leftPartiteSize;
    karp_m=rightPartiteSize;
		memset(match, -1, sizeof(match[0])*karp_n);
		memset(matched, -1, sizeof(matched[0])*karp_m);
		memset(q,0,(sizeof q[0])*karp_n);
		memset(v,0,(sizeof v[0])*karp_m);
		memset(depth,0,sizeof depth);
		int ans = 0;
		while(BFS()) {
			++vcnt;
			for(int i = 0; i < karp_n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}

vector<pii> v2xy[2*mn];
void solve(int casenum) {
	int n; cin>>n;
	for (int x=0;x<2*mn;x++) v2xy[x].clear();
	for (int x=0;x<n;x++) {
		for (int y=0;y<n;y++) {
			int t; cin>>t;
			v2xy[t+mn].PB(MP(x,y));
		}
	}
	int can=0;
	for (int t=0;t<2*mn;t++) {
		if (v2xy[t].size()==0) continue;
		for (int x=0;x<n;x++) g[x].reset();
		for (auto &w:v2xy[t]) {
			g[w.fst][w.snd]=true;
		}
		int got=Match(n,n);
		//printf("t:%d got:%d\n",t-mn,got);
		can+=got;
	}
	int ans=n*n-can;
	printf("Case #%d: %d\n",casenum,ans);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
