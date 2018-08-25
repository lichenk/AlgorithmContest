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
pii query(int x, int y) {
  printf("%d %d\n",x,y); fflush(stdout);
  int a,b; scanf("%d %d",&a,&b);
  return MP(a,b);
}
const int mn=1002;
bitset<mn> b[mn];
void solve(int blah) {
  for (int x=0;x<mn;x++) b[x].reset();
  int A=rint();
  int xlim=A/5;
  set<int> needx;
  for (int sx=1;sx+2<=xlim;sx+=3) needx.insert(sx);
  needx.insert(xlim-2);
  for (auto &sx:needx) {
    for (int sy=1;sy<=3;sy+=2) {
      set<pii> need;
      while(need.size()<9) {
        pii got=query(sx+1,sy+1);
        if (got==MP(0,0)) {
          return;
        }
        need.insert(got);
      }
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T=rint();
  for (int casenum=1;casenum<=T;casenum++) {
    solve(casenum);
  }
}
