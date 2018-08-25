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


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll inp; cin>>inp;
  ll n=inp;
  vector<ll> v;
  ll lim=min(n,(ll)sqrt(n)+2);
  for (ll x=2;x<=lim;x++) {
  	while (n%x==0) {
  		n/=x;
  		v.PB(x);
  	}
  }
  if (n!=1) v.PB(n);
  //for (auto &w:v) printf("%d\n",w);
  ll p=v.size();
  pair<ll,ll> ans;
  if (p==0) ans=MP(1,0);
  else if (p==1) ans=MP(1,0);
  else if (p==2) ans=MP(2,-1);
  else {
  	ans=MP(1,(v[0]*v[1]));
  }
  printf("%lld\n",ans.fst);
  if (ans.fst==1) printf("%lld\n",ans.snd);
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