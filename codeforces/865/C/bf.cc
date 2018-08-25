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
int rint();char rch();long long rlong();
const int mn=52;
const int mt=100*50+2;
ld dp[mn][mt];
ld g00;
int f[mn],s[mn]; ld p[mn];
int n,r;
ld g(int l, int t) {
  ld res=0;
  if (t>r) return g00;
  if (t<=r&&l==n) return 0;
  //assert(l<=n&&t<=r);
  if (dp[l][t]>-1) {
    //printf("l:%d t:%d %Lf\n",l,t,dp[l][t]);
    return dp[l][t];
  }
  ld a=g(l+1,t+f[l])+f[l];
  ld b=g(l+1,t+s[l])+s[l];
  ld ans1=a*p[l]+b*(1-p[l]);
  ld ans2=g00;
  ld ans=min(ans1,ans2);
  //printf("l:%d t:%d ans:%Lf a:%Lf b:%Lf=%Lf+%d. %d %d\n",l,t,ans,a,b,g(l+1,t+s[l]),s[l],l+1,t+s[l]);
  return dp[l][t]=ans;
}
void reset() {
  for (int l=0;l<=n;l++) {
    for (int t=0;t<=r;t++) {
      dp[l][t]=-2;
    }
  }
}
ld test() {
  reset();
  ld got=g(0,0);
  //printf("%Lf %Lf\n",g00,got);
  return got;
}
int main()
{
  time_t st=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),r=rint();
  ld prod=1;
  int ssum=0;
  for (int i=0;i<n;i++) {
    f[i]=rint(),s[i]=rint(),p[i]=rint()/100.0L;
    prod*=p[i];
    ssum+=s[i];
  }
  g00=304697745*2LL;
  for (int k=0;k<10000;k++) {
    if (clock()-st > 1.5 * CLOCKS_PER_SEC) break;
    g00=test();
  }
  printf("%.10f\n",(double)g00);
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