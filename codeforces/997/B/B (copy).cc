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
int tab[4]={0,4,9,49};
const ll dd=50;
bitset<dd*49+1> b[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  int dlim=min(n,dd);
  ll lo=LLONG_MAX,hi=LLONG_MIN;
  if (n>dd) {
    lo=dlim*tab[2];
    hi=dlim*tab[0]+(n-dlim)*tab[3];
    if (lo>hi) lo=LLONG_MAX,hi=LLONG_MIN;
  }
  if (lo>hi) {
    int cur=0,nxt=1;
    b[cur][0]=true;
    for (int d=0;d<n;d++) {
      b[nxt].reset();
      for (int x=0;x<4;x++) {
        b[nxt]|=b[cur]<<tab[x];
      }
    }
    ll ans=b.count();
    printf("%lld\n",ans);
  }
  else {
    int cur=0,nxt=1;
    b[cur][0]=true;
    for (int d=0;d<dd;d++) {
      b[nxt].reset();
      for (int x=0;x<4;x++) {
        b[nxt]|=b[cur]<<tab[x];
      }
    }
    ll ans=b.count();
    printf("%lld\n",ans);
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