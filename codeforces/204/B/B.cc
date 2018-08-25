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
const int mn=1e5+4;
int f[mn],b[mn];
map<int,int> h,g;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  vector<pii> v;
  for (int i=0;i<n;i++) {
    f[i]=rint(),b[i]=rint();
    h[f[i]]++;
    if (f[i]!=b[i]) h[b[i]]++;
    g[f[i]]++;
  }
  for (auto &w:h) v.PB(MP(w.snd,w.fst));
  sort(v.begin(),v.end(),greater<pii>());
  int ans=1e9;
  for (auto &w:v) {
    int allcnt=w.fst,color=w.snd;
    if (allcnt< (n+1)/2) break;
    int ff=g[color];
    int pay=max(0,((n+1)/2) - ff);
    //printf("allcnt:%d color:%d pay:%d\n",allcnt,color,pay);
    chkmin(ans,pay);
  }
  if (ans>1e8) ans=-1;
  printf("%d\n",ans);

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