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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=2002;
int a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  int ans=INF;
  int ones=0;
  for (int l=0;l<n;l++) {
    if (a[l]==1) ones++;
  }
  if (ones>0) chkmin(ans, n-ones);
  else {
  for (int l=0;l<n;l++) {
    int x=a[l];
    int need=INF;
    if (x==1) need=0;
    else {
      for (int r=l+1;r<n;r++) {
        x=__gcd(x,a[r]);
        if (x==1) {
          need=r-l;
          break;
        }
      }
    }
    chkmin(ans,need+n-1);
  }}
  if (ans>=INF) ans=-1;
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