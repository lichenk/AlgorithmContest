#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const int INF = 1<<28;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<short,short> pss;
typedef vector<pss> vpss;
const int mn=1000;
vpss g[mn][mn];
int vdist[mn][mn];
void bfs(pss init) {
	queue<pss> q; q.push(init);
	for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) vdist[x][y]=INF;
	vdist[init.fst][init.snd]=0;
	while(!q.empty()) {
		pss x=q.front(); q.pop();
		int dd=vdist[x.fst][x.snd]+1;
		for (auto &y:g[x.fst][x.snd]) {
			//printf("%d %d->%d %d\n",x.fst,x.snd,y.fst,y.snd);
			if (dd<vdist[y.fst][y.snd]) {
				vdist[y.fst][y.snd]=dd;
				q.push(y);
			}
		}
	}
}
bitset<mn> b[mn];
void go(int n, int d, int sx, int sy) {
	b[sx][sy]=true;
	int d2=d*d;
	for (int x=0;x<n;x++) {
		int dx=abs(sx-x);
		int dy2=d2-dx*dx;
		if (dy2>=0) {
			int dy=0;
			if (dy2>0) dy=round(sqrt(dy2));
			if(dy*dy<dy2) dy++;
			if (0<=sy+dy&&sy+dy<n) b[x][sy+dy]=true;
			if (0<=sy-dy&&sy-dy<n) b[x][sy-dy]=true;
		}
	}
}
class FrogSquare {
	public:
	int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
		go(n,d,sx,sy);
		go(n,d,tx,ty);
		set<int> t={0,(n-1)/2,n-1};
		for (auto &x:t) {
			for (auto &y:t) {
				if (x==y&&x==(n-1)/2) continue;
				go(n,d,x,y);
			}
		}
		vpss v;
		for (int x=0;x<n;x++) for (int y=0;y<n;y++) if (b[x][y]) v.PB(MP(x,y));
		int d2=d*d;
		for (auto &x:v) {
			//printf("%d %d\n",x.fst,x.snd);
			for (auto &y:v) {
				if (y==x) continue;
				int dx=x.fst-y.fst;int dy=x.snd-y.snd;
				int dd=dx*dx+dy*dy;
				if (dd>=d2) {
					g[x.fst][x.snd].PB(y);
				}
			}
		}
		bfs(MP(sx,sy));
		int ans=vdist[tx][ty];
		if (ans>=INF) return -1;
		return ans;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing FrogSquare (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1518718214;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FrogSquare _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 100;
				int d = 10;
				int sx = 0;
				int sy = 0;
				int tx = 3;
				int ty = 4;
				_expected = 2;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 1:
			{
				int n = 100;
				int d = 5;
				int sx = 0;
				int sy = 0;
				int tx = 3;
				int ty = 4;
				_expected = 1;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 2:
			{
				int n = 100;
				int d = 200;
				int sx = 0;
				int sy = 0;
				int tx = 3;
				int ty = 4;
				_expected = -1;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 3:
			{
				int n = 10;
				int d = 7;
				int sx = 4;
				int sy = 4;
				int tx = 5;
				int ty = 5;
				_expected = 3;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 4:
			{
				int n = 1;
				int d = 1;
				int sx = 0;
				int sy = 0;
				int tx = 0;
				int ty = 0;
				_expected = 0;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 5:
			{
				int n = 689;
				int d = 731;
				int sx = 249;
				int sy = 97;
				int tx = 599;
				int ty = 237;
				_expected = 4;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 6:
			{
				int n = 899;
				int d = 415;
				int sx = 537;
				int sy = 112;
				int tx = 294;
				int ty = 128;
				_expected = 2;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			case 7:
			{
				int n = 718;
				int d = 359;
				int sx = 412;
				int sy = 471;
				int tx = 335;
				int ty = 635;
				_expected = 2;
				_received = _obj.minimalJumps(n, d, sx, sy, tx, ty); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
