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
// Strict subset increasing
#define FORSSI(sub, full) for(int sub = 0 ;sub!=(full)  ; sub = (sub - (full)) & (full))
// Nonempty subset increasing
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
// Nonempty subset decreasing
#define FORNESD(sub, full) for(int sub = (full) ; sub > 0 ; sub = (sub-1) & (full))
inline int next_bit_perm(int v) {
  int t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}
void iterate_over_n_choose_k(int n, int k) {
  if (k==0) {
    // Handle k==0 separately
  }
  for (int w = (1 << k) - 1; w < (1 << n); w = next_bit_perm(w)) {
    // do whatever you want with w
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int seen=5;

  FORSSI(now, seen) {
    printf("now:%d\n",now);
  }
  printf("\n");
  FORNESI(now, seen) {
    printf("now:%d\n",now);
  }
  printf("\n");
  FORNESD(now, seen) {
    printf("now:%d\n",now);
  }
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