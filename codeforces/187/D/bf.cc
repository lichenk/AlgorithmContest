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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1e5+4;
int vsummod[mn];
int a[mn];
ll vsum[mn];
int vredl[mn],vredr[mn],vreducedr[mn];
int cyc;
void norm(int &x) {x%=cyc; if (x<0) x+=cyc;}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),green=rint(),red=rint();
  cyc=green+red;
  ll sumall=0;
  for (int i=0;i<=n;i++) {
    a[i]=rint();
    sumall+=a[i];
  }
  int qlim=rint();
  for (int qi=0;qi<qlim;qi++) {
    ll t=rint();
    for (int i=0;i<n;i++) {
      t+=a[i];
      int res=t%cyc;
      if (res>=green) t+=cyc-res;
    }
    t+=a[n];
    printf("%lld\n",t);
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