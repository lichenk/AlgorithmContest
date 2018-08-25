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
bitset<88> b;
vector<ll> fib;
const ll LIM=1e18+4;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  fib.PB(1); fib.PB(2);
  while(1) {
    int sz=fib.size();
    ll x=fib[sz-1]+fib[sz-2];
    if (x>LIM) break;
    fib.PB(x);
  }
  int numt=rint();
  for (int tt=0;tt<numt;tt++) {
    ll n=rlong();
    int fsz=fib.size();
    b.reset();
    for (int i=fsz-1;i>=0;i--) {
      if (n>=fib[i]) {
        n-=fib[i];
        b[i]=true;
      }
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