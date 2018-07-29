#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
//template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
//template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
//ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll mn=404;
ll f[mn][mn];
ll a[mn],b[mn],s[mn][mn];
ll p[mn][mn];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,c;
	scanf("%lld %lld",&n,&c);
	for (ll x=0;x<mn;x++) {
		ll z=1;
		for (ll y=0;y<mn;y++) {
			p[x][y]=z;
			z=mul(z,x);
		}
	}
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);
	for (ll i=0;i<n;i++) scanf("%lld",&b[i]);
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<=c;y++) {
			ll sum=0;
			for (ll d=a[x];d<=b[x];d++) {
				sum+=p[d][y];
				sum%=MOD;
			}
			s[x][y]=sum;
		}
	}
	for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) {
		f[x][y]=0;
	}
	f[0][0]=1;
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<=c;y++) {
			for (ll z=y;z<=c;z++) {
				ll diff=z-y;
				f[x+1][z]+=mul(f[x][y],s[x][diff]);
				f[x+1][z]%=MOD;
			}
		}
	}
	printf("%lld\n",f[n][c]);
}