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
const int mn=1e6+4;
ll g[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(),m=rint();
  //ve.reserve(m);
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x]++;
    g[y]++;
  }
  ll sum=0;
  for (int x=1;x<=n;x++) {
    ll d=g[x];
    sum+=(d*(d-1))/2;
  }
  ll ans= (n*(n-1)*(n-2))/6 - m*(n-2) + sum;
  printf("%lld\n",ans);
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