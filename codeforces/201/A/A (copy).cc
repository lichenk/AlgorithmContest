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
//int rint();char rch();long long rlong();


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll w;cin>>w;
  for (ll x=1;;x+=2) {
    {
      ll a=1;
      ll b=((x/2)-1)*2; chkmax(b,0ll); assert(b%2==0); b/=2;
      ll c=((x+1)/2)*((x+1)/2)+((x)/2)*((x)/2)-a-b*2;
      if (c%4) {printf("x:%lld a:%lld b:%lld c:%lld\n",x,a,b,c); exit(0);}
      assert(c%4==0); c/=4;
      for (ll aa=0;aa<=a;aa++) {
        for (ll bb=0;bb<=b;bb++) {
          for (ll cc=0;cc<=c;cc++) {
            ll tot=aa+bb*2+cc*4;
            if (tot==w) {
              printf("%lld\n",x);
              return 0;
            }
          }
        }
      }
    }
    {
      ll a=0;
      ll b=(x/2)*2; assert(b%2==0); b/=2;
      ll c=((x+1)/2)*((x)/2)+((x+1)/2)*((x)/2)-a-b*2;
      if (c%4) {printf("x:%lld a:%lld b:%lld c:%lld\n",x,a,b,c); exit(0);}
      assert(c%4==0); c/=4;
      for (ll aa=0;aa<=a;aa++) {
        for (ll bb=0;bb<=b;bb++) {
          for (ll cc=0;cc<=c;cc++) {
            ll tot=aa+bb*2+cc*4;
            if (tot==w) {
              printf("%lld\n",x);
              return 0;
            }
          }
        }
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