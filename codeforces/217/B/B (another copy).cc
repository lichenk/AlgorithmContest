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

pair<int,ll> f(int n, ll z) {
  ll oz=z;
  ll t=1,b=1;
  int prev=-1;
  ll last;
  int rep=0;
  for (int i=n-1;i>=0;i--) {
    int k=(z>>i)&1;
    if (prev==k) {
      rep++;
    }
    //if (oz==0) printf("prev:%d k:%d rep:%d\n",prev,k,rep);
    prev=k;
    if (k) {
      t+=b;
      last=t;
    }
    else {
      b+=t;
      last=b;
    }
  }
  return MP(rep,last);
}
const int k=28;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n; int r; cin>>r;
  pair<int,int> ans; ans.fst=1e9;
  for (int z=0;z<(1<<min(k,n));z++) {
    auto got=f(n,z);
    //if (z==0) printf("got.fst:%d\n",got.fst);
    //if (h.find(got.snd)==h.end()) h[got.snd]=MP(got.fst,z);
    if (got.snd==r) chkmin(ans,MP(got.fst,z));
  }
  if (ans.fst>5e8) {
    printf("IMPOSSIBLE\n");
  }
  else {
    printf("%d\n",ans.fst);
    for (int i=0;i<n-min(n,k);i++) printf("B");
    for (int i=min(n,k)-1;i>=0;i--) {
      if (ans.snd&(1<<i)) printf("T");
      else printf("B");
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