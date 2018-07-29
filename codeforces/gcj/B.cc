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
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
inline int rint() {
  int x; scanf("%d",&x);
  return x;
}
int solve(int casenum) {
  int n=rint();
  vector<int> a[2];
  a[0].reserve((n+1/2));
  a[1].reserve((n+1/2));
  for (int i=0;i<n;i++) {
    a[i&1].PB(rint());
  }
  for (int t=0;t<2;t++) sort(a[t].begin(),a[t].end());
  int c[2]; c[0]=c[1]=0;
  vector<int> b; b.reserve(n);
  for (int i=0;i<n;i++) {
    int t=i&1;
    b.PB(a[t][c[t]]);
    c[t]++;
  }
  //for (int x=0;x<n;x++) printf("%d ",b[x]); printf("\n\n");
  for (int x=0;x<n-1;x++) {
    if (b[x]>b[x+1]) return x;
  }
  return -1;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T=rint();
  for (int casenum=1;casenum<=T;casenum++) {
    int got=solve(casenum);
    if (got!=-1) printf("Case #%d: %d\n",casenum,got);
    else printf("Case #%d: OK\n",casenum);
  }
}
