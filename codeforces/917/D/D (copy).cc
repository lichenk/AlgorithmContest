#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
typedef unsigned long long ull;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=101;

int mod_pow(int a, int n) {
  const int mod=MOD;
 int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=mn;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
int binom[mn][mn];
int _binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
  for (int n=0;n<mn;n++) {
    for (int k=0;k<=n;k++) {
      binom[n][k]=_binom(n,k);
    }
  }
}

vector<int> tree[mn];
int vsz[mn];
bool cmp(const int &x, const int &y) {
  return vsz[x]<vsz[y];
}
int getsz(int x, int p) {
  int ans=1;
  for (auto &y:tree[x]) {
    if (y==p) continue;
    ans+=getsz(y,x);
  }
  return vsz[x]=ans;
}
const ull LLIM=ULLONG_MAX-((MOD-1)*(ll)(MOD-1));
typedef unsigned long long ull;
int dpf[mn][2][mn][mn]; // dp[vertex][live][allEdgesExceptLive]
bitset<mn> seen;
int gn;
void dfs(int x, int p) {
  int n=gn;
  if (seen[x]) return;
  seen[x]=true;
  int cur=0;
  for (auto &y:tree[x]) {
    if (y==p) continue;
    dfs(y,x);
    cur^=1;
  }
  auto &f=dpf[x];
  f[cur][1][0]=1;
  int nodes=1;
  int rlim=0;
  for (auto &ch:tree[x]) {
    if (ch==p) continue;
    int nxt=cur^1;
    int chnodes=vsz[ch];
    for (int live=0;live<=nodes+chnodes;live++) {
      memset(f[nxt][live],0,sizeof(int)*(nodes+chnodes+1));
    }
    
    for (int rlive=1;rlive<=nodes;rlive++) {
      for (int rall=0;rall<=nodes;rall++) {
        for (int clive=0;clive<=chnodes;clive++) {
          for (int call=0;call<=chnodes;call++) {
            // Root connects to ch
            int prev=f[cur][rlive][rall];
            int child=dpf[ch][0][clive][call];
            f[nxt][rlive+clive][rall+call]+=prev*(ll)child;
            f[nxt][rlive+clive][rall+call]%=MOD;
          }
        }
      }
    }
    nodes+=chnodes;
    /*
    for (int tlive=1;tlive<=nodes;tlive++) {
      for (int tall=0;tall<=nodes;tall++) {
        for (int clive=0;clive<=min(tlive,chnodes);clive++) {
          for (int call=0;call<=min(tall,chnodes);call++) {
            // Root connects to ch
            int rlive=tlive-clive; int rall=tall-call;
            int prev=f[cur][rlive][rall];
            int child=dpf[ch][0][clive][call];
            f[nxt][tlive][tall]+=prev*(ll)child;
            f[nxt][tlive][tall]%=MOD;
          }
        }
      }
    }*/
    cur^=1;
  }
  assert(cur==0);
  //memcpy(dpf[x], f[cur], sizeof f[cur]);
  for (int rlive=1;rlive<=n;rlive++) {
    for (int rall=0;rall<=n;rall++) {
      f[0][0][rall+rlive-1]=(f[0][0][rall+rlive-1]+n*(rlive)*(ll)f[0][rlive][rall])%MOD;
    }
  }
}

int vans[mn];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int n=rint();
  gn=n;
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint(); --x; --y;
    tree[x].PB(y);
    tree[y].PB(x);
  }
  getsz(0,-1);
  for (int x=0;x<n;x++) sort(tree[x].begin(),tree[x].end(),cmp);
  dfs(0,-1);
  int invn2=mod_pow(n*n,MOD-2);
  for (int rall=n-1;rall>=0;rall--) {
    int seed=dpf[0][0][0][rall];
    int sones=rall;
    for (int o=rall+1;o<n;o++) {
      int ozeros=n-1-o;
      int C=binom[n-1-ozeros][sones];
      seed=(seed-C*(ll)vans[o])%MOD;
      if (seed<0) seed+=MOD;
    }
    vans[rall]=seed;
  }
  for (int rall=0;rall<n;rall++) {
    int ans=(vans[rall]*(ll)invn2)%MOD;
    printf("%d ",ans);
  }
  printf("\n");
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