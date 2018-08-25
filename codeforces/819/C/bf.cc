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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint();char rch();long long rlong();
int va[3],vb[3],vs[3];
ll solve() {
  //af.clear(); bf.clear(); sf.clear();
  vs[0]*=2;
  ll alim=va[0]*(ll)va[1]*(ll)va[2];
  ll blim=vb[0]*(ll)vb[1]*(ll)vb[2];
  ll slim=vs[0]*(ll)vs[1]*(ll)vs[2];
  ll ans1=0,ans2=0;
  for (ll b=blim;b>=1;b--) {
    if (0==(slim%__gcd(alim,b))) ans1++;
  }
  for (ll a=alim;a>=1;a--) {
    if (slim%a==0) ans2++;
  }
  //printf("ans1:%lld ans2:%lld\n",ans1,ans2);
  ll final=ans1+ans2;
  return final;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //sieve();
  int t=rint();
  for (int ti=0;ti<t;ti++) {
    
    for (int i=0;i<3;i++) va[i]=rint();
    for (int i=0;i<3;i++) vb[i]=rint();
    for (int i=0;i<3;i++) vs[i]=rint();
    ll ans=solve();
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