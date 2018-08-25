#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
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
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s,t;
  int n; cin>>n>>s>>t;
  ld numer=0;
  ld denom=0;
  for (ll len=1;len<=n;len++) {
    ll poss=n-len+1;
    denom+=poss*poss;
  }
  //printf("Change C to Z\n");
  for (char c='A';c<='Z';c++) {
    //printf("c:%c\n",c);
    ll sl=0,sr=0; __float128 prod=0;
    int cnt=0;
    for (int x=0;x<n;x++) {
      if (s[x]==c) {
        cnt++;
        int l=1;
        int r=n-x;
        sr+=r;
        prod+=l*r;
      }
    }
    for (int x=0;x<n;x++) {
      int a=x+1,b=n-x;
      //printf("x:%d sl:%lld sr:%lld prod:%lld a:%d b:%d\n",x,sl,sr,prod);
      if (t[x]==c) {
        numer+=prod;
      }
      if (x==n-1) break;
      if (s[x]==c) sr-=b;
      prod+=sr;
      //printf("add sr:%lld\n",sr);
      if (s[x]==c) sl+=a;
      prod-=sl;
      //printf("sub sl:%lld\n",sl);
    }
  }
  ld final=numer/denom;
  //printf("numer:%f denom:%f\n",numer,denom);
  printf("%.16f\n",(double)final);
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