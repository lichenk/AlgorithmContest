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

int a[100];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),t=rint();
  for (int i=0;i<t;i++) a[i]=rint();
  vector<int> v;
  for (int z=1;z<(1<<t);z++) {
    bool ok=true;
    for (int y=0;y<(1<<t);y++) {
      ll sum = 0;
      for (int i = 0; i < t; i++) {
        if (z & (1 << i)) {
          if (y & (1 << i)) sum += a[t - 1 - i];
          else sum -= a[t - 1 - i];
        }
      }
      //sum%=m; if (sum<0) sum+=m;
      if (sum%m == 0) {
        //printf("z:%lld sum:%lld\n",z,sum);
        ok = 0;
        break;
      }
    }
    if (!ok) v.PB(z);
  }
  int ans=0;
  for (int z=0;z<(1<<t);z++) {
    int ok=1;
    for (auto &w:v) {
      if ((w&z)==w) {
        ok=0; break;
      }
    }
    if (ok) cout<<bitset<5>(z)<<endl;
    ans+=ok;
  }
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