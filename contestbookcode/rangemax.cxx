#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
#define ZERO 0
#define UNDEF -1

std::ifstream ifs("range.in",std::ifstream::in);
ofstream ofs("range.out", std::ofstream::out);
ll *a,*b;
// a is max(left,right)
// b is true value of node
void ins(ll v, ll bot, ll top, ll l, ll r, ll ind, bool bchange) {
	//ofs << "Setting " << v << " on range:" << l << " to " << r << ":" << v << " on ind " << ind << " on bot " << bot << " top " << top << endl;
	if (l > r) return;
	if (bot == l && top == r) {
		//ofs << "Setting Brange:" << l << " to " << r << ":" << v << " on ind " << ind << endl;
		b[ind] = v;
		a[ind] = v;
		return;
	}
	ll mid = (bot+top-1)/2;
	bool newbchange = bchange;
	ll oldb = b[ind];
	if (oldb != UNDEF) {
		b[ind] = UNDEF;
		newbchange = false;
	}
	if (l <= mid) {
		ins(v,bot,mid,l,min(r,mid), ind*2, newbchange);
	}
	if (r >= mid+1) {
		ins(v,mid+1,top,max(l,mid+1),r,ind*2+1, newbchange);
	}
	if (bchange && oldb != UNDEF) {
		ins(oldb,bot,top,bot,l-1,ind,false);
		ins(oldb,bot,top,r+1,top,ind,false);
	}
	a[ind] = max(a[2*ind],a[2*ind+1]);
}

ll lookup(ll bot, ll top, ll l, ll r, ll ind) {
	if (l > r) return UNDEF;
	if (b[ind] != UNDEF) {
		return b[ind];
	}
	if (bot == l && top == r) {
		return a[ind];
	}
	ll mid = (bot+top-1)/2;
	ll ans = ZERO;
	if (l <= mid) {
		ll cand = lookup(bot,mid,l,min(mid,r),ind*2);
		//ofs << l << "," << mid << ":" << cand << endl;
		ans = max(ans, cand);
	}
	if (r >= mid+1) {
		ll cand = lookup(mid+1,top,max(mid+1,l),r,ind*2+1);
		//ofs << mid+1 << "," << r << ":" << cand << endl;
		ans = max(ans, cand);
	}
	return ans;
}

int main() {
	ll n,p,q;
	ll x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;
	ifs >> n;
	ifs >> p;
	ifs >> q;
	ifs >> x1;
	ifs >> y1;
	ifs >> x2;
	ifs >> y2;
	ifs >> x3;
	ifs >> y3;
	ifs >> x4;
	ifs >> y4;
	ifs >> x5;
	ifs >> y5;
	ll range = pow(2,ceil(log(n+1)/log(2)))-1;
	ll tsize = pow(2,1+ceil(log(n+1)/log(2)));
	a = new ll[tsize+10];
	b = new ll[tsize+10];
	for (ll i = 0; i < tsize+10; i++) {
		a[i] = ZERO;
		b[i] = UNDEF;
	}
	for (ll i = 0; i < p; i++) {
		ll l = ((x1*i)+y1)%n;
		ll r = ((x2*i)+y2)%n;
		ll v = ((x5*i)+y5)%n;
		ins(v,  0,range, min(l,r), max(l,r), 1, true);
	}
	ll final = 0;
	for (ll i = 0; i < q; i++) {
		ll l = ((x3*i)+y3)%n;
		ll r = ((x4*i)+y4)%n;
		ll ans = lookup(0,range, min(l,r), max(l,r), 1);
		final = (final + ans)%1000007;
	}
	ofs << final << endl;
	/*
	for (ll i = 0; i < p; i++) {
		ll l,r,v;
		ifs >> l; ifs >> r; ifs >> v;
		ins(v,  0,range, l, r, 1, true);
	}
	for (ll i = 0; i < q; i++) {
		ll l,r;
		ifs >> l; ifs >> r;
		ll ans = lookup(0,range, l,r, 1);
		ofs << ans << endl;
	}
	*/
	return 0;
}
