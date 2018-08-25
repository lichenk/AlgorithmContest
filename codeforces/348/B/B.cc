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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e5+4;
int a[mn];
vector<int> g[mn];
inline ll llcm(ll x, ll y) {
  if (x==-2||y==-2) return -2;
  if (x==-1) return y;
  if (y==-1) return x;
  return (x/__gcd(x,y))*y;
}
pll dfs(int x, int p) {
  ll lcm=-1;
  ll lo=INF;
  int child=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    pll got=dfs(y,x);
    lcm=llcm(lcm,got.fst);
    chkmin(lo,got.snd);
    child++;
  }
  if (child==0) return MP(1,a[x]);
  ll lim=(lo/lcm)*lcm;
  if (lim==0) {
    return MP(-2ll,0ll);
  }
  lcm*=child;
  lim*=child;
  //printf("x:%d lcm:%lld lim:%lld lo:%lld\n",x,lcm,lim,lo);
  return MP(lcm,lim);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  pll res=dfs(1,-1);
  ll sum=0; for (int x=1;x<=n;x++) sum+=a[x];
  ll ans=sum-res.snd;
  //printf("res:%lld\n",res.snd);
  printf("%lld\n",ans);
}

