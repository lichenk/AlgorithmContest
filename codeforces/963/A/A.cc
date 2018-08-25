#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000009;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,a,b,k;
  cin>>n>>a>>b>>k;
  string s;cin>>s;
  ll an=mod_pow(a,n,MOD);
  ll c=mul(mod_pow(a,MOD-2,MOD),b);
  ll sum=0;
  ll ci=1;
  for (int i=0;i<k;i++) {
  	ll sgn=1; if (s[i]=='-') sgn=MOD-1;
  	sum=(sum+sgn*ci)%MOD;
  	ci=mul(ci,c);
  }
  ll e=((n+1)/k)-1;
  ll ck=mod_pow(c,k,MOD);
  ll geom=mul(mod_pow(ck,e+1,MOD)+MOD-1,mod_pow(ck+MOD-1,MOD-2,MOD));
  if (ck==1) geom=e+1;
  //printf("sum:%lld ck:%lld e:%lld geom:%lld\n",mul(sum,an),ck,e,geom);
  ll got=mul(sum,geom);
  ll final=mul(got,an);
  if (final<0) final+=MOD;
  printf("%lld\n",final);
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