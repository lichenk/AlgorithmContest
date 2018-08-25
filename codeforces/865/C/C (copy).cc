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
const int mt=100*50+100+4;
typedef pair<ld,ld> pld;
pld dp[mn][mt];
pld g(int l, int t) {
  if (t>r) return MP(0.0L,1.0L);
  if (dp[l][t]>-2) return dp[l][t];
  pld a=g(l+1,t+f[l]); a.fst+=f[l]; a.fst*=p[i]; a.snd*=p[i];
  pld b=g(l+1,t+s[l]); b.fst+=s[l]; b.fst*=(1-p[i]); b.snd*=(1-p[i]);
  pld ans1=MP(a.fst+b.fst,a.snd+b.snd);
  pld ans2=

}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),r=rint();
  for (int l=0;l<n;l++) {
    f[i]=rint(),s[i]=rint(),p[i]=rint()/100.0L;
  }
  for (int l=0;l<mn;l++) {
    for (int t=0;t<mt;t++) {
      dp[l][t]=-2;
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