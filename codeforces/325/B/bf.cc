#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 lld;
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

lld quadratic(lld a, lld b, lld c) {
  lld det=b*b-4*a*c;
  if (det<0) return -2;
  lld ans=(-b+sqrt((ld)det))/(2*a);
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rlong();
  set<ll> vans;
  for (int k=0;k<=60;k++) {
    ll a = 1;
    ll b = (1LL << (k + 1)) - 3;
    ll c = -2 * n;
    lld ans=quadratic(a,b,c);
    if (ans>=0&&ans<=LLONG_MAX) {
      ll got=round((ld)ans);
      if (got&1) {
        ld error = ans - got;
        if (-1e-9 < error && error < 1e-9) {
          ll prod;
          bool ovf=__builtin_smulll_overflow(got,1LL<<k,&prod);
          if (!ovf) vans.insert(prod);
        }
      }
    }
  }
  //sort(vans.begin(),vans.end());
  if (vans.size()==0) {
    printf("-1\n"); return 0;
  }
  for (auto &w:vans) {
    printf("%lld\n",w);
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