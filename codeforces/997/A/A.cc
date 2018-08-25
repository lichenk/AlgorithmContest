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
const int mn=3e5+4;
char a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,cx,cy; scanf("%d%d%d\n",&n,&cx,&cy);
  scanf("%s\n",a);
  int seg=1;
  for (int i=1;i<n;i++) {
  	if (a[i]!=a[i-1]) seg++;
  }
  ll ans=1LL<<62;
  if (a[0]=='1') {
  	{
  		ll sw=max(0,(seg/2)-1);
  		ll flip=seg==1?0LL:1LL;
  		ll cand=sw*cx+flip*cy;
  		chkmin(ans,cand);
  	}
  	{
  		ll flip=seg/2;
  		ll cand=flip*cy;
  		chkmin(ans,cand);
  	}
  }
  else {
  	{
  		ll sw=max(0,(seg-1)/2);
  		ll flip=1;
  		ll cand=sw*cx+flip*cy;
  		chkmin(ans,cand);
  	}
  	{
  		ll flip=(seg+1)/2;
  		ll cand=flip*cy;
  		chkmin(ans,cand);
  	}
  }
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