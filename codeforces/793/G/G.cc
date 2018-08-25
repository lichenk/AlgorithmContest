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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int MAXN=10000;
bitset<MAXN> g[MAXN];
  // Hopcroft Karp Bipartite Matching
  const int MAX_N = MAXN, MAX_M = MAXN;
  int karp_n, karp_m;
  int match[MAX_N];

  int matched[MAX_M], depth[MAX_N], q[MAX_N];
  int v[MAX_N], vcnt;
  bool BFS(){
    int t = 0;
    for(int i = 0; i < karp_n; i++)
      if (match[i] == -1) depth[i] = 0, q[t++] = i;
      else depth[i] = -1;
    for(int h = 0; h < t; h++) {
      int cur = q[h];
      int curDepth = depth[cur];
      for(int i = 0; i < karp_n; i++) {
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
    for(int i = 0; i < karp_n; i++) {
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
  int finalans;
  void init(int leftPartiteSize, int rightPartiteSize) {
    karp_n=leftPartiteSize;
    karp_m=rightPartiteSize;
    memset(match, -1, sizeof(match));
    memset(matched, -1, sizeof(matched));
    vcnt=0;
    finalans = 0;
  }

  int Match()
  {
    while(BFS()) {
      ++vcnt;
      for(int i = 0;i<karp_n;i++) if (depth[i] == 0 && DFS(i)) finalans++;
    }
    return finalans;
  }

//short vx1[MAXN],vy1[MAXN],vx2[MAXN],vy2[MAXN];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),qn=rint();
  for (int x=0;x<n;x++) g[x].set();
  init(n,n);
  for (int i=0;i<qn;i++) {
    int y1=rint(),x1=rint(),y2=rint(),x2=rint();
    --x1;--y1;--x2;--y2;
    //vx1[i]=x1;
    //vy1[i]=y1;
    //vx2[i]=x2;
    //vy2[i]=y2;
    for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) g[x][y]=false;
  }
  int ans=Match();
  printf("%d\n",ans);
  /*for (int i=q-1;i>=0;i--) {

    if (i==0) return 0;
    int x1=vx1[i];
    int y1=vy1[i];
    int x2=vx2[i];
    int y2=vy2[i];
    for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) g[x][y]=true;
  }*/
}

