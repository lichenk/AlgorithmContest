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


int rint()
{
  int x; scanf("%d",&x); return x;
}
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b; scanf("%lld%lld",&a,&b);
  ll inv2=mod_pow(2,MOD-2,MOD);
  ll lhs=mul(mul(b,b-1),inv2);
  ll rhs=mul(mul(mul(a+1,a),inv2),b)+a;
  ll ans=mul(lhs,rhs);
  printf("%lld\n",ans);
}

