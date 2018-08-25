#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
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
int id=1;
int getid() {
  return ++id;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k; scanf("%d%d",&n,&k);
  if (k==2) {
    printf("%d\n",n-1);
    for (int x=1;x<n;x++) printf("%d %d\n",x,x+1);
    return 0;
  }
  int sumchain=n-1;
  int chainlolen=(sumchain)/k;
  int chainhi=sumchain%k;
  int chainlo=k-chainhi;
  int chainhilen=chainlolen+1;
  int ans;
  if (chainhi>=2) ans=chainhilen*2;
  else if (chainhi==1) ans=chainhilen+chainlolen;
  else ans=2*chainlolen;
  printf("%d\n",ans);
  for (int chain=0;chain<k;chain++) {
    int prev=1;
    int chainlen=chain<chainhi?chainhilen:chainlolen;
    for (int i=0;i<chainlen;i++) {
      int x=getid();
      printf("%d %d\n",prev,x);
      prev=x;
    }
  }
}

