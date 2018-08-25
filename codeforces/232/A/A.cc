#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
//const ll MOD=maxn0000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
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
ll rint();char rch();long long rlong();
const ll maxn=100;
bool a[maxn][maxn];
void go(ll oldk) {
  ll k=oldk;
  vector<int> vans;
  ll left=maxn;
  ll v=0;
  for (ll x=maxn;x>=1;x--) {
    if (x==2) continue;
    ll x3=(x*(x-1)*(x-2))/6;
    while(x3<=k&&left>=x) {
     // printf("x:%d\n",x);
      ll lo=v,hi=v+x;
      for (ll i=lo;i<hi;i++) {
        for (ll j=lo;j<hi;j++) {
          if (i!=j) {
            //printf("i:%d j:%d\n",i,j);
            a[i][j]=1;
          }
        }
      }
      v=hi;
      k-=x3;
      vans.PB(x);
      left-=x;
      x=2;
      break;
    }
  }
  assert(left==0);
  ll x=vans[0];
  ll rem=maxn-x;
  v=x;
  for (ll c=x;c>=2;c--) {
    ll c2=(c*(c-1))/2;
    ll take=min(rem,k/c2);
    ll lo=v,hi=v+take;
    //printf("c:%d take:%d\n",c,take);
    for (ll i=0;i<c;i++) {
      for (ll j=lo;j<hi;j++) {
        //printf("i:%d j:%d\n",i,j);
        a[i][j]=1;
        a[j][i]=1;
      }
    }
    v=hi;
    k-=take*c2;
    rem-=take;
  }
  assert(k==0);
  //return;
  printf("%d\n",maxn);
  for (ll x=0;x<maxn;x++) {
    for (ll y=0;y<maxn;y++) {
      printf("%c",a[x][y]?'1':'0');
    }
    printf("\n");
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll k; cin>>k;
  go(k);
  /*for (ll k=maxn*maxn0;k>=1;k--) {
    go(k);
  }*/


}





long long rint()
{
  long long x; scanf("%lld",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}