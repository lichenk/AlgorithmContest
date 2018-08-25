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
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=(1e5)+2;
int px[mn],py[mn];
bitset<mn> b;
const ll LIM=2250000000000;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {px[i]=rint(); py[i]=rint();}
  while(1) {
    mt19937 rng(clock());
    int got;
    ll sx=0,sy=0;
    for (int i=0;i<n;i++) {
      if ((i&31)==0) got=rng();
      b[i]=(got&1);
      if (got&1) {
        sx+=px[i]; sy+=py[i];
      }
      else {
        sx-=px[i]; sy-=py[i];
      }
      got>>=1;
    }
    ll s2=sx*sx+sy*sy;
    if (s2<=LIM) {
      for (int i=0;i<n;i++) {
        if (b[i]) printf("1 ");
        else printf("-1 ");
      }
      exit(0);
    }
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