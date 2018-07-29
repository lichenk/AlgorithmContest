#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
#define MP make_pair
#define INF MP(9223372036854775807LL,-3LL)
#define NEGINF MP(-9223372036854775807LL,-3LL)
#define MIN false
#define MAX true

std::ifstream ifs("range.in",std::ifstream::in);
ofstream ofs("range.out", std::ofstream::out);
typedef pair<ll,ll> rt;

rt cmp(bool minmax, rt x, rt y) {
	return (minmax == MIN)? min(x,y) : max(x,y);
}

void ins(bool minmax, rt *a, rt v, ll bot, ll top, ll x, ll ind) {
	if (bot == x && top == x) {
		a[ind] = v;
		return;
	}
	ll mid = (bot+top-1)/2;
	if (x <= mid) {
		ins(minmax,a,v,bot,mid,x, ind*2);
	}
	else {
		ins(minmax,a,v,mid+1,top,x,ind*2+1);
	}
	a[ind] = cmp(minmax,a[2*ind],a[2*ind+1]);
}

rt lookup(bool minmax,rt *a,ll bot, ll top, ll l, ll r, ll ind) {
	if (l > r) return (minmax == MIN)? INF : NEGINF;
	if (bot == l && top == r) {
		return a[ind];
	}
	ll mid = (bot+top-1)/2;
	rt ans = ((minmax == MIN)? INF : NEGINF);
	if (l <= mid) {
		rt cand = lookup(minmax,a,bot,mid,l,min(mid,r),ind*2);
		ans = cmp(minmax,ans, cand);
	}
	if (r >= mid+1) {
		rt cand = lookup(minmax,a,mid+1,top,max(mid+1,l),r,ind*2+1);
		ans = cmp(minmax,ans, cand);
	}
	return ans;
}

int main() {
	ll n,p,q,minmaxi;
	ifs >> n;
	ifs >> p;
	ifs >> q;
	ifs >> minmaxi;
	bool minmax = (minmaxi == 1)? MAX : MIN;
	ll range = pow(2,ceil(log(n+1)/log(2)))-1;
	ll tsize = pow(2,1+ceil(log(n+1)/log(2)));
	rt *a = new rt[tsize+10];
	for (ll i = 0; i < tsize+10; i++) {
		a[i] = ((minmax == MIN)? INF : NEGINF);
	}
	for (ll i = 0; i < p; i++) {
		ll x; rt v;
		ifs >> x; ifs >> v.first; ifs >> v.second;
		ins(minmax,a,v,  0,range, x, 1);
	}
	for (ll i = 0; i < q; i++) {
		ll l,r;
		ifs >> l; ifs >> r;
		rt ans = lookup(minmax,a,0,range, l,r, 1);
		ofs << ans.first << " " << ans.second << endl;
	}
	return 0;
}
