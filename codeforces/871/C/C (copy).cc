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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
int mod_pow(int a, int n) {
  const int mod=MOD;
  int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
const int mn=2e5+4;
void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

bool iscyc;
bool seen[mn];
vector<int> g[mn];
int dfs(int x, int p) {
  if (seen[x]) {
    iscyc=true;
    return 0;
  }
  int ans=1;
  seen[x]=true;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=dfs(y,x);
  }
  return ans;
}
int dp[mn][2][2];
int f(int x, int p, int c, int e) {
  int dpval=dp[x][c][e]; if (dpval!=-1) return dpval;
  int h[2][2];
  int cur=0,nxt=1;
  h[0][1]=1;
  h[0][0]=0;
  bool isleaf=true;
  for (auto &y:g[x]) {
    if (y==p) continue;
    isleaf=false;
    h[nxt][0]=h[nxt][1]=0;
    for (int pc=0;pc<=1;pc++) {
      int now=h[cur][pc];
      for (int nc=0;nc<=pc;nc++) {
        int ne=e; if (nc) ne=1;
        int got=f(y,x,nc, ne);
        h[nxt][pc-nc]=(h[nxt][pc-nc]+now*(ll)got)%MOD;
        printf("x:%d c:%d y:%d pc:%d nc:%d now:%d got:%d h:%d\n",x,c,y,pc,nc,now,got,h[nxt][pc-nc]);
      }
    }
    swap(cur,nxt);
  }
  int ans=0;
  if (isleaf) {
    if (c==0) {
      if (e) ans=1;
      else ans=1;
    }
    else {
      if (e) ans=1;
      else ans=2;
    }
  }
  else {
    if (c == 0) {
      if (e) {
        ans += h[cur][0];
        ans += h[cur][1];
        if (ans >= MOD) ans -= MOD;
      } else {
        ans += h[cur][0];
        ans += h[cur][1];
        if (ans >= MOD) ans -= MOD;
        ans += h[cur][1];
        if (ans >= MOD) ans -= MOD;
      }
    } else {
      if (e) {
        ans += h[cur][0];
        if (ans >= MOD) ans -= MOD;
      } else {
        ans += h[cur][0];
        ans += h[cur][1];
        if (ans >= MOD) ans -= MOD;
      }
    }
  }
  printf("x:%d c:%d e:%d ans:%d hc0:%d hc1:%d\n",x,c,e,ans,h[cur][0],h[cur][1]);
  return dp[x][c][e]=ans;
}



int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  int n=rint();
  vector<int> vx,vy; vector<pii> vp;
  vx.reserve(n);vy.reserve(n);vp.reserve(n);
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    vp.PB(MP(x,y));
    vx.PB(x); vy.PB(y);
  }
  makeunique(vx);makeunique(vy);
  for (int i=0;i<n;i++) {
    int x=vp[i].fst,y=vp[i].snd;
    int bx=bins(vx,x);
    int by=bins(vy,y)+vx.size();
    g[bx].PB(by);
    g[by].PB(bx);
  }
  int k=vx.size()+vy.size();
  int final=1;
  for (int x=0;x<k;x++) {
    if (seen[x]) continue;
    iscyc=0;
    int sz=dfs(x,-1);
    if (iscyc) {
      final=mul(final,mod_pow(2,sz));
    }
    else {
      int got=f(x,-1,0,0);
      final=mul(final,got);
    }
  }
  printf("%d\n",final);
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