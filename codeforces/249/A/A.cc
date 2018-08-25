#include <bits/stdc++.h>
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
/*ld getdist(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2) {
  ll numer=abs((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1);
  ll sdenom=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
  ld denom=sqrt(sdenom);
  return numer/denom;
}*/
bool cmpdist(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2, ll rr) {
  ld numer=abs((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1);
  ld sdenom=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
  ld r=rr;
  return (numer*numer+1e-15)<=(r*r*sdenom);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int y1=rint(),y2=rint(),yw=rint(),xb=rint(),yb=rint(),r=rint();
  if (y2-y1<=2*r) {
    printf("-1\n"); return 0;
  }
  yw-=r;
  y1=yw+(yw-y1);
  y2=yw+(yw-y2);
  ll ydest=y1-r;
  ll dy=ydest-yb;
  ll dx=xb;
  ll dy2=ydest-yw;
  ld dx2=(dy2*dx/(ld)dy);
  {
    ll tx1=0,ty1=ydest;
    ll tx2=xb,ty2=yb;
    ll tx0=0,ty0=y2;
    //cout<<dist<<endl;
    if (cmpdist(tx0,ty0,tx1,ty1,tx2,ty2,r)) {
      printf("-1\n");
      return 0;
    }
  }
  /*ll lhs=1ll*(ydest-y2)*dx;
  ll rhs=1ll*r*dy;
  //printf("ydest:%lld dy:%lld dy2:%lld\n",ydest,dy,dy2);
  if (lhs<=rhs) {
    printf("-1\n"); return 0;
  }*/
  cout<<fixed<<setprecision(20);
  cout<<(long double)dx2<<endl;
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