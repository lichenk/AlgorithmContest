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

int mul(int x, int y) {
  return (x*(ll)y)%MOD;
}

const int mn=2*100000+4;
vector<int> g[mn];
vector<int> rg[mn];

bool reachescycle[mn];
int mark[mn];
int markid=1;
bool goseen[mn];
int numcyc=0;
bool go(int x) {
  if (mark[x]==markid) {
    numcyc++;
    return reachescycle[x]=true;
  }
  if (goseen[x]) return reachescycle[x];
  mark[x]=markid;
  goseen[x]=true;
  bool ans=false;
  for (auto &y:g[x]) {
    ans=ans||go(y);
  }
  reachescycle[x]=ans;
  return ans;
}
bool dfsed[mn];
bool haseng[mn];
int dfs(int x) {
  dfsed[x]=true;
  int ans=1;
  for (auto &y:rg[x]) {
    assert(!dfsed[y]);
    int cand=dfs(y);
    ans+=cand;
    if (ans>=MOD) ans-=MOD;
  }
  assert(ans>=0&&ans<MOD);
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    haseng[x]=true;
    if (x!=y) {
      g[x].PB(y);
      rg[y].PB(x);
    }
  }
  for (int x=1;x<=2*n;x++) {
    markid++;
    if (0==mark[x]) go(x);
  }
  int res=1;
  for (int x=1;x<=2*n;x++) {
    if (reachescycle[x]||dfsed[x]||haseng[x]) continue;
    if (rg[x].size()==0) continue;
    int cand=dfs(x);
    res=mul(res,cand);
    assert(res>=0&&res<MOD);
    //printf("x:%d cand:%d\n",x,cand);
  }
  for (int i=0;i<numcyc;i++) {
    res=mul(res,2);
    assert(res>=0&&res<MOD);
  }
  assert(res>=0&&res<MOD);
  printf("%d\n",res);
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