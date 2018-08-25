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
int d[8];
int n,k;
int seen;
inline int isseen(int x) {
  return (seen&(1<<x));
}
void dfs(int x) {
  if (isseen(x)) return;
  seen|=(1<<x);
  for (int y=0;y<k;y++) {
    if (d[y]==x) dfs(y);
  }
}
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>k;
  int zlim=1;
  for (int i=0;i<k;i++) zlim*=k;
  int ans=0;
  for (int z=0;z<zlim;z++) {
    seen=0;
    dfs(0);
    if (seen==(1<<k)-1) ans++;
    for (int i=0;i<k;i++) {
      d[i]++;
      if (d[i]<k) break;
      else d[i]=0;
    }
  }
  int l=n-k;
  int other=mod_pow(l,l,MOD);
  //printf("ans:%d other:%d\n",ans,other);
  ll final=1ll*ans*other; final%=MOD;
  printf("%lld\n",final);
}

