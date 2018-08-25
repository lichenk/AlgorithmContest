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


const int mk=7;
const int mn=(1<<mk)+1;
int vl[mn],vr[mn];
ld vp[mn][mn];
ld dp[mn][mn];
int k,n;
ld f(int node, int player) {
  if (node>=n) return 1.0L;
  if (dp[node][player]>=-1) return dp[node][player];
  int ln=node*2; int rn=ln+1;
  if (player>vr[ln]) swap(ln,rn);
    ld A=f(ln,player);
    ld B=0;
    for (int q=vl[rn];q<=vr[rn];q++) {
      ld cand=f(rn,q);
      chkmax(B,cand);
    }
  ld ans=A+B;
  return dp[node][player]=ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  k = rint();
  n = 1 << k;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int p = rint();
      vp[x][y] = p / 100.0L;
    }
  }
  for (int node=n;node<2*n;node++) {
    vl[node]=vr[node]=node-n;
  }
  for (int node=n-1;node>=1;node--) {
    vl[node]=vl[node*2];
    vr[node]=vr[(node*2)+1];
  }
  for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) dp[x][y]=-2;
  ld final=0;
  for (int player=0;player<n;player++) {
    ld got=f(node,player);
    chkmax(final,got);
  }
  printf("%.15f\n",(double)final);
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