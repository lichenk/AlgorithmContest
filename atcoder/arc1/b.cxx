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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=200000+4;
ll fact[MAXN];
ll invfact[MAXN];
ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	return ans;
}
ll inv(ll x) {
	return modexp(x, MOD-2);
}
ll binom(ll n, ll k) {
	ll denom = (invfact[n-k]*invfact[k])%MOD;
	return (fact[n]*denom)%MOD;
}
ll grid(ll a, ll b) {
	return binom(a+b,b);
}
int main() {
	ios_base::sync_with_stdio(false);
	fact[0] = 1;
	for (ll x = 1; x < MAXN; x++) {
		fact[x] = (fact[x-1]*x)%MOD;
	}
	for (ll x = 0; x < MAXN; x++) {
		invfact[x] = inv(fact[x]);
	}
	ll h,w,a,b; scanf("%lld %lld %lld %lld",&h,&w,&a,&b);
	ll c=w-b-1;
	ll ans=0;
	for (ll x=0;x<h-a;x++) {
		ll m1=grid(b,x);
		ll m2=grid(h-1-x,c-1);
		//printf("%lld * %lld. %lld %lld. %lld %lld.\n",m1,m2,b,x,h-1-x,c-1);
		ans+=(m1*m2)%MOD;
		ans%=MOD;
	}
	{
		ll m1=grid(b,h-a-1);
		ll m2=grid(a-1,w-b-1);
		//printf("%lld * %lld. %lld %lld. %lld %lld.\n",m1,m2,b,h-a-1,a-1,w-b-1);
		ans+=(m1*m2)%MOD;
		ans%=MOD;
	}
	printf("%lld\n",ans);
}