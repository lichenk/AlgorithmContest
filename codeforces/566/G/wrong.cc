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

typedef pair<long long, long long> point;

long long cross(const point &a, const point &b, const point &c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

vector<point> convexHull(vector<point> points) {
	if (points.size() <= 1)
		return points;
	sort(points.begin(), points.end());
	vector<point> h;
	for (auto p: points) {
		while (h.size() >= 2 && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.push_back(p);
	}
	reverse(points.begin(), points.end());
	int upper = h.size();
	for (auto p: points) {
		while (h.size() > upper && cross(h.end()[-2], h.back(), p) >= 0)
			h.pop_back();
		h.push_back(p);
	}
	h.resize(h.size() - 1 - (h[0] == h[1]));
	return h;
}

static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int readInt()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
	int ox=readInt(),oy=readInt();
	set<point> vmin,vmax;
	vmax.insert(MP(0,0));
	int xhi=0,yhi=0;
	for (int i=0;i<n;i++) {
		int x=readInt(),y=readInt();
		vmax.insert(MP(x,y));
		chkmax(xhi,x);
		chkmax(yhi,y);
	}
	vmax.insert(MP(xhi,0));
	vmax.insert(MP(0,yhi));
	for (int i=0;i<m;i++) {
		int x=readInt(),y=readInt();
		vmin.insert(MP(x,y));
	}
	set<point> toch=vmax;
	for (auto &w:vmin) toch.insert(w);
	vector<point> tochv;
	for (auto &w:toch) tochv.PB(w);
	vector<point> ch=convexHull(tochv);
	set<point> smin;
	for (auto &w:vmin) smin.insert(w);
	for (auto &w:vmax) smin.erase(w);
	//for (auto &w:ch) printf("%d %d\n",w.fst,w.snd);
	for (auto &w:ch) {
		if (smin.find(w)!=smin.end()) {
			printf("Min\n");
			return 0;
		}
	}
	printf("Max\n");
}
