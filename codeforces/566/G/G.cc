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

typedef pair<long long, long long> point;

long long cross(const point &a, const point &b, const point &c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

vector<point> convexHullAllowStraightEdges(vector<point> points) {
	if (points.size() <= 1)
		return points;
	sort(points.begin(), points.end());
	vector<point> h;
	for (auto p: points) {
		while (h.size() >= 2 && cross(h.end()[-2], h.back(), p) > 0)
			h.pop_back();
		h.push_back(p);
	}
	reverse(points.begin(), points.end());
	int upper = h.size();
	for (auto p: points) {
		while (h.size() > upper && cross(h.end()[-2], h.back(), p) > 0)
			h.pop_back();
		h.push_back(p);
	}
	h.resize(h.size() - 1 - (h[0] == h[1]));
	return h;
}


long long rint()
{
  long long x; scanf("%lld",&x); return x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n=rint(),m=rint();
	ll ox=rint(),oy=rint();
	set<point> vmin,vmax;
	for (ll i=0;i<n;i++) {
		ll x=rint(),y=rint();
		vmax.insert(MP(x,y));
	}
	ll xhi=0,yhi=0;
	for (ll i=0;i<m;i++) {
		ll x=rint(),y=rint();
		vmin.insert(MP(x,y));
		chkmax(xhi,x); chkmax(yhi,y);
	}
	set<point> toch;
	for (auto &w:vmin) toch.insert(w);
	for (auto &w:vmax) toch.insert(w);
	toch.insert(MP(0,0));
	toch.insert(MP(xhi,0));
	toch.insert(MP(0,yhi));
	vector<point> vtoch; for (auto &w:toch) vtoch.PB(w);
	vector<point> ch=convexHullAllowStraightEdges(vtoch);
	for (auto &w:ch) {
		if (vmax.find(w)!=vmax.end()) {
			printf("Max\n");
			return 0;
		}
	}
	printf("Min\n");
}