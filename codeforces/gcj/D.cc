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
const ld s2=sqrt((ld)(2.0L));
int solve(int casenum) {
  ld A; cin>>A;
  ld ang=asin(A/s2) - M_PI/4;
  //printf("%Lf\n",cos(ang)+sin(ang));
  printf("Case #%d:\n",casenum);
  printf("%.12f %.12f 0\n",
  	(double)(0.5*cos(ang)),
  	(double)(-0.5*sin(ang))
  	);
  printf("%.12f %.12f 0\n",
  	(double)(-0.5*sin(ang)),
  	(double)(-0.5*cos(ang))
  	);
  printf("0 0 0.5\n");
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int casenum=1;casenum<=T;casenum++) {
    solve(casenum);
  }
}
