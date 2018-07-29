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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll int_pow(ll a, ll n) { ll ret = 1; ll p = a; while (n) { if (n & 1) ret = ret * p; p = p * p; n >>= 1; } return ret; }
typedef unsigned int uint128_t __attribute__((mode(TI)));
bool millerTest(ll d, ll n) {
	ll a=1+rand()%(n-4);
	ll x=mod_pow(a,d,n);
	if (x==1||x==n-1) return true;
	while(d!=n-1) {
		x=(((uint128_t)x)*x)%n;
		d*=2;
		if (x==1) return false;
		if (x==n-1) return true;
	}
	return false;
}
bool isProbablePrime(ll n, ll k) {
	if (n<=1||n==4) return false;
	if (n<=3) return true;
	ll d=n-1;
	while((d%2)==0) d/=2;
	for (ll i=0;i<k;i++) {
		if (millerTest(d,n)==false) return false;
	}
	return true;
}
ld frac[51];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	if (n==1) {cout<<1<<endl; return 0;}
	ll s=(n/2)+1;
	for (ll e=1;e<=50;e++) {
		frac[e]=((ld)1)/e;
	}
	for (ll x=s;x<=n;x++) {
		for (ll e=1;e<=50;e++) {
			ll y=round(pow(x,frac[e]));
			if (e==1) y=x;
			if (int_pow(y,e)==x) {
				if (isProbablePrime(y, 10)) {
					cout<<x<<endl;
					return 0;
				}
			}
		}
	}
}