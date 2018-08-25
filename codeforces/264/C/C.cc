#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

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
const int mn=1e5+4;
ll f[mn];
int v[mn],c[mn];
pair<ll,int> best[3];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),q=rint();
  for (int i=0;i<n;i++) v[i]=rint();
  for (int i=0;i<n;i++) c[i]=rint();
  for (int qi=0;qi<q;qi++) {
    int a=rint(),b=rint();
    for (int i=1;i<=n;i++) f[i]=-INF;
    memset(best,0,sizeof best);
    ll final=0;
    for (int i=0;i<n;i++) {
      int col=c[i]; ll val=v[i];
      ll same=f[col]+val*(ll)a;
      ll diff;
      if (best[2].snd!=col) {
        diff=best[2].fst;
      }
      else {
        diff=best[1].fst;
      }
      diff+=val*(ll)b;
      //printf("i:%d %lld %lld\n",i,same,diff);
      ll res=max(same,diff);
      chkmax(final,res);
      chkmax(f[col],res);
      bool done=0;
      for (int k=2;k>=1;k--) {
        if (col==best[k].snd) {
          chkmax(best[k].fst,res);
          done=1;
          break;
        }
      }
      if (!done) {
        best[0]=MP(res,col);
      }
      sort(best,best+3);
    }
    printf("%lld\n",final);
  }
}