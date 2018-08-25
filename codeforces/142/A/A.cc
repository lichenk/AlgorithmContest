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
  int n=rint();
  int lim=ceil(sqrt(n))+2;
  chkmin(lim,n);
  vector<int> v;
  for (int d=1;d<=lim;d++) {
    if (n%d==0) {v.PB(d); v.PB(n/d);}
  }
  sort(v.begin(),v.end());
  auto it=unique(v.begin(),v.end());
  v.resize(distance(v.begin(),it));
  ll lo=LLONG_MAX,hi=LLONG_MIN;
  for (auto &x:v) {
    for (auto &y:v) {
      ll xy=x*(ll)y;
      if (xy>n) continue;
      if (n%xy!=0) continue;
      ll z=n/xy;
      ll got=(x+1LL)*(y+2LL)*(z+2LL);
      //if (got==42+n) printf("%d %d %lld\n",x,y,z);
      chkmin(lo,got);
      chkmax(hi,got);
    }
  }
  lo-=n; hi-=n;
  printf("%lld %lld\n",lo,hi);
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