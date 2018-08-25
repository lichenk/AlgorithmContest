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
int v[mn],c[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),q=rint();
  for (int i=0;i<n;i++) v[i]=rint();
  for (int i=0;i<n;i++) c[i]=rint();
  for (int qi=0;qi<q;qi++) {
    int a=rint(),b=rint();
    ll final=0;
    int zlim=1<<n;
    for (int z=0;z<zlim;z++) {
      ll ans=0;
      int last=-1;
      for (int i=0;i<n;i++) {
        if (z&(1<<i)) {
          int col=c[i],val=v[i];
          if (col==last) ans+=val*(ll)a;
          else ans+=val*(ll)b;
          last=col;
        }
      }
      chkmax(final,ans);
    }
    printf("%lld\n",final);
  }
}