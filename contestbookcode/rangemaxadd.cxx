#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
#define INF -9223372036854775807LL
#define UNDEF 0
//#define ifs cin
//#define ofs cout
std::ifstream ifs("range.in",std::ifstream::in);
ofstream ofs("range.out", std::ofstream::out);
ll *a,*c;

void addrange(ll v, ll bot, ll top, ll l, ll r, ll ind) {
	if (l > r) return;
	if (bot == l && top == r) {
		//cout << l << "," << r << ":" << v << endl;
		c[ind] += v;
		a[ind] += v;
		return;
	}
	ll mid = (bot+top-1)/2;
	ll oldc = c[ind];
	c[ind] = UNDEF;
	if (l <= mid) {
		addrange(v,bot,mid,l,min(r,mid), ind*2);
	}
	if (r >= mid+1) {
		addrange(v,mid+1,top,max(l,mid+1),r,ind*2+1);
	}
	if (oldc != UNDEF) {
		c[ind*2] += oldc;
		a[ind*2] += oldc;
		c[(ind*2) + 1] += oldc;
		a[(ind*2) + 1] += oldc;
	}
	a[ind] = max(a[2*ind],a[2*ind+1]);
}



ll lookup(ll bot, ll top, ll l, ll r, ll ind) {
	if (l > r) return INF;
	if (bot == l && top == r) {
		return a[ind];
	}
	ll mid = (bot+top-1)/2;
	ll ans = INF;
	if (l <= mid) {
		ll cand = lookup(bot,mid,l,min(mid,r),ind*2);
		ans = max(ans, cand);
	}
	if (r >= mid+1) {
		ll cand = lookup(mid+1,top,max(mid+1,l),r,ind*2+1);
		ans = max(ans, cand);
	}
	return ans+c[ind];
}

int main() {
	ll n,p,q;
	ifs >> n;
	ifs >> p;
	ifs >> q;
	/*
	ll n = 4000007; ll p = n; ll q = n;
	ll x1 = 15612311; ll x2 = 1263711; ll x3 = 71429; ll x4 = 165289; ll x5 = 421897;
	ll y1 = 147289; ll y2 = 571829l; ll y3 = 47128; ll y4 = 237189; ll y5 = 214789;
	*/
	ll range = pow(2,ceil(log(n+1)/log(2)))-1;
	ll tsize = pow(2,1+ceil(log(n+1)/log(2)));
	a = new ll[tsize+10];
	c = new ll[tsize+10];
	for (ll i = 0; i < tsize+10; i++) {
		a[i] = 0;
		c[i] = UNDEF;
	}
	/*
	for (ll i = 0; i < p; i++) {
		ll l = ((x1*i)+y1)%n;
		ll r = ((x2*i)+y2)%n;
		ll v = ((x5*i)+y5)%n;
		addrange(v,  0,range, min(l,r), max(l,r), 1);
	}
	ll final = 0;
	for (ll i = 0; i < q; i++) {
		ll l = ((x3*i)+y3)%n;
		ll r = ((x4*i)+y4)%n;
		ll ans = lookup(0,range, min(l,r), max(l,r), 1);
		final = (final + ans)%1000007;
	}
	ofs << final << endl;
	*/
	
	for (ll i = 0; i < p; i++) {
		ll l,r,v;
		ifs >> l; ifs >> r; ifs >> v;
		addrange(v,  0,range, min(l,r), max(l,r), 1);
	}
	for (ll i = 0; i < q; i++) {
		ll l,r;
		ifs >> l; ifs >> r;
		ll ans = lookup(0,range, min(l,r), max(l,r), 1);
		ofs << ans << endl;
	}
	
	return 0;
}
