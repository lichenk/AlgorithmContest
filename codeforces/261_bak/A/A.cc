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
int q[mn],a[mn];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m=rint();
  for (int i=0;i<m;i++) q[i]=rint();
  sort(q,q+m);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  sort(a,a+n);
  int x=n-1;
  ll ans=0;
  while(x>=0) {
    int qi=q[0]+2;
    while(qi>0&&x>=0) {
      if (qi>2) ans+=a[x];
      x--;
      qi--;
    }
  }
  printf("%lld\n",ans);
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