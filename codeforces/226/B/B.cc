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
int a[mn];
ll b[mn];
ll vans[mn];
ll query(int l, int r) {
  return b[r]-b[l-1];
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  sort(a+1,a+n+1,greater<int>());
  for (int i=1;i<=n;i++) {
    b[i]=b[i-1]+a[i];
  }
  for (int k=1;k<=100000;k++) {
    int x=1;
    int t=1;
    ll ans=0;
    ll sz=k;
    while(1) {
      int l=x+1;
      int r=min(x+sz,(ll)n);
      if (l>r) break;
      ll cnt=query(l,r);
      //if (k==1) printf("%d %d %lld\n",k,l,r,cnt);
      ans+=cnt*t;
      t++;
      x=r;
      sz*=k;
    }
    vans[k]=ans;
  }
  int q=rint();
  for (int i=0;i<q;i++) {
    int x=rint();
    printf("%lld ",vans[x]);
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