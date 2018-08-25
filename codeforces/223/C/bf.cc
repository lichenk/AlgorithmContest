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

const int mn=2004;
ll a[mn];
ll b[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(),k=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  for (int kk=0;kk<k;kk++) {
    for (int i=1;i<=n;i++) {
      ll ans=0;
      for (int j=1;j<=i;j++) {
        ans+=a[j]; ans%=MOD;
      }
      b[i]=ans;
    }
    for (int i=1;i<=n;i++) a[i]=b[i];
  }
  for (int i=1;i<=n;i++) printf("%lld ",a[i]);
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