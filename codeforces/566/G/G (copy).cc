#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

typedef pair<int, int> point;

long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}

vector<point> convexHull(vector<point> dat) {
	vector<point> upper, lower;
	sort(dat.begin(), dat.end());
	for(int i = 0; i < dat.size(); i++) {
		while(upper.size() >= 2 && ccw(*++upper.rbegin(),*upper.rbegin(),dat[i]) >= 0) upper.pop_back();
		while(lower.size() >= 2 && ccw(*++lower.rbegin(),*lower.rbegin(),dat[i]) <= 0) lower.pop_back();
		upper.emplace_back(dat[i]);
		lower.emplace_back(dat[i]);
	}
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;
}


int rint()
{
  int x; scanf("%d",&x); return x;
}
map<ll,ll> h;
void ins(ll x, ll y) {
	chkmax(h[x],y);
	auto it=h.find(x);
	if (it==h.begin()||it==h.end()) return;
	auto lit=it,rit=it;
	--lit; ++rit;
	if (rit==h.end()) return;
	if (ccw(*lit, *it, *rit)>=0) h.erase(it);
	else {
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	int ox=rint(),oy=rint();
	for (int i=0;i<n;i++) {
		int x=rint(),y=rint();
		vmax.insert(MP(x,y));
	}
	for (int i=0;i<m;i++) {
		int x=rint(),y=rint();
		vmin.insert(MP(x,y));
	}
	printf("Max\n");
}

