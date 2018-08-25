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
const ll INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int MAXN=81;
vector<int> g[MAXN];
const int MAXE=2002;
int vdest[MAXE],vc[MAXE];
int dp[MAXN][MAXN][MAXN][MAXN];
int f(int x, int lo, int hi, int need) {
  int dpval=dp[need][lo][hi][x];
  if (dpval!=-1) return dpval;
  int ans;
  if (!(lo<=hi)) ans=INF;
  else if (need==0) ans=0;
  else {
    ans=INF;
    for (auto &eid:g[x]) {
      int y=vdest[eid];
      if (!(lo<=y&&y<=hi)) continue;
      if (x==y) continue;
      int cost=vc[eid];
      int got;
      if (y<x) {
        got=f(y,lo,x-1,need-1);
      }
      else {
        got=f(y,x+1,hi,need-1);
      }
      if (got<INF) {
        chkmin(ans,got+cost);
      }
    }
  }
  return dp[need][lo][hi][x]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),k=rint();
  int m=rint();
  for (int i=0;i<m;i++) {
    int u=rint(),v=rint(),c=rint();
    --u; --v;
    vdest[i]=v;
    vc[i]=c;
    g[u].PB(i);
  }
  memset(dp,-1,sizeof dp);
  int ans=INF;
  for (int x=0;x<n;x++) {
    int got=f(x,0,n-1,k-1);
    chkmin(ans,got);
  }
  if (ans<INF) printf("%d\n",ans);
  else printf("-1\n");
}

