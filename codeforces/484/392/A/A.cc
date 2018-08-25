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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  if (n==0) {
    printf("1\n");
    return 0;
  }
  ll py=n;
  ll ans=0;
  for (ll x=0;x<=n;x++) {
    ll sq=n*n-x*x;
    ll y=floor(sqrt((ld)(n*n-x*x))+1e-12);
    if (y*y>sq) y--;
    if ((y+1)*(y+1)<=sq) y++;
    assert(y*y<=sq&&(y+1)*(y+1)>sq);
    ll add=max(py-y-1,0ll)+1;
    //printf("x:%lld y:%lld add:%lld\n",x,y,add);
    ans+=add;
    py=y;
  }
  //printf("ans:%lld\n",ans);
  ans--;
  ans*=4;
  printf("%lld\n",ans);
}

