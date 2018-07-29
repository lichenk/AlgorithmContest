#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const int mx=22*22+8;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x+y;
}
inline UFTYPE getInitialValue(int x) {
  return 1;
}


int ufParent[mx];
UFTYPE ufData[mx];
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
}
void init(int n) {
  for (int x=0;x<n;x++) {
    ufreset(x);
  }
}
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
void funion(int _x, int _y) {
  int xr = ffind(_x);
  int yr = ffind(_y);
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
void funionFast(int xr, int yr) {
  if (xr==yr) return;
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
  ufData[yr]=combine(ufData[xr],ufData[yr]);
}
int getData(int x) {
  return ufData[ffind(x)];
}
int getDataFast(int x) {
  return ufData[x];
}
};
UnionFind uf;


int getid(int x, int y) {
	return 21*x+y;
}
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char t[mx];
set<int> g[mx];
int vdist[mx];
int bfs(int initx, char want) {
	bitset<mx> seen; seen.reset();
	for (int x=0;x<mx;x++) vdist[x]=INF;
	queue<int> q;
	q.push(initx);
	vdist[initx]=0; seen[initx]=true;
	int final=0;
	while(!q.empty()) {
		int x=q.front(); q.pop();
		int distx=vdist[x];
		int cand=distx+1;
		for (auto &y:g[x]) {
			if (!seen[y]) {
				seen[y]=true;
				vdist[y]=cand;
				chkmax(final,cand);
				q.push(y);
			}
		}
	}
	if (((final%2)==0) != (t[initx]==want)) final++;
	return final;
}
bitset<mx> seen;
vector<int> getcomp(int initx) {
	vector<int> v;
	for (int x=0;x<mx;x++) vdist[x]=INF;
	queue<int> q;
	q.push(initx);
	vdist[initx]=0; seen[initx]=true; v.PB(initx);
	int final=0;
	while(!q.empty()) {
		int x=q.front(); q.pop();
		int distx=vdist[x];
		int cand=distx+1;
		for (auto &y:g[x]) {
			if (!seen[y]) {
				seen[y]=true; v.PB(y);
				vdist[y]=cand;
				chkmax(final,cand);
				q.push(y);
			}
		}
	}
	return v;
}
class TileFlippingGame {
	public:
	int HowManyMoves(int n, int m, vector <string> a) {
		assert(n==a.size()); assert(m==a[0].length());
		uf.init(mx);		
		for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
			for (int k=0;k<4;k++) {
				int nx=x+dx[k],ny=y+dy[k];
				if (0<=nx&&nx<n&&0<=ny&&ny<m) {
					if (a[x][y]==a[nx][ny]&&a[x][y]!='e'&&a[nx][ny]!='e') {
						uf.funion(getid(x,y),getid(nx,ny));
					}
				}
			}
		}
		memset(t,-1,sizeof t);
		for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
			int p=uf.ffind(getid(x,y));
			if (a[x][y]!='e') t[p]=a[x][y];
		}
		for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
			for (int k=0;k<4;k++) {
				int nx=x+dx[k],ny=y+dy[k];
				if (0<=nx&&nx<n&&0<=ny&&ny<m) {
					if (a[x][y]!=a[nx][ny]&&a[x][y]!='e'&&a[nx][ny]!='e') {
						int p=uf.ffind(getid(x,y));
						int q=uf.ffind(getid(nx,ny));
						g[p].insert(q); g[q].insert(p);
					}
				}
			}
		}
		vector<vector<int> > comps;
		for (int x=0;x<mx;x++) if (t[x]!=-1&&!seen[x]) {
			comps.PB(getcomp(x));
		}
		vector<char> cc={'w','b'};
		ll final=INF;
		for (auto &want:cc) {
			ll need=0;
			for (auto &com:comps) {
				int comneed=INF;
				for (auto &x:com) {
					int got=bfs(x,want);
					chkmin(comneed,got);
				}
				need+=comneed;
			}
			chkmin(final,need);
		}
		return final;
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
		cout << "Testing TileFlippingGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 50; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1522371602;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TileFlippingGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int m = 3;
				string X[] = {"bbb","eee","www"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 1:
			{
				int n = 3;
				int m = 3;
				string X[] = {"bwe","wbw","ewb"};
				_expected = 2;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 2:
			{
				int n = 4;
				int m = 4;
				string X[] = {"beww","beww","beww","wewe"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 3:
			{
				int n = 2;
				int m = 8;
				string X[] = {"ewewbbbb","bwebewww"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 4:
			{
				int n = 5;
				int m = 5;
				string X[] = {"bwebw","wbebb","eeeee","bbebb","bbebb"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 7;
				string X[] = {"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 6:
			{
				int n = 6;
				int m = 7;
				string X[] = {"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 7:
			{
				int n = 20;
				int m = 20;
				vector<string> X;
				for (int i=0;i<n;i++) {
					string s; s.resize(m); for (int i=0;i<m;i++) s[i]='b'; X.PB(s);
				}
				_expected = 0;
				_received = _obj.HowManyMoves(n, m, X); break;
			}
			case 8:
			{
				int n = 20;
				int m = 20;
				vector<string> X;
				for (int i=0;i<n;i++) {
					string s; s.resize(m); for (int i=0;i<m;i++) s[i]='w'; X.PB(s);
				}
				_expected = 0;
				_received = _obj.HowManyMoves(n, m, X); break;
			}
			case 9:
			{
				int n = 6;
				int m = 5;
				string X[] = {
					"wwbww",
					"wewew",
					"wewew",
					"bebeb",
					"wewew",
					"wwbww",
				};
				_expected = 4;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 10:
			{
				int n = 13;
				int m = 5;
				string X[] = {
					"wwbww",
					"wewew",
					"wewew",
					"bebeb",
					"wewew",
					"wwbww",
					"eeeee",
					"bbwbb",
					"bebeb",
					"bebeb",
					"wewew",
					"bebeb",
					"bbwbb",
				};
				_expected = 8;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 11:
			{
				int n = 13;
				int m = 5;
				string X[] = {
					"wwbww",
					"wewew",
					"wewew",
					"bebeb",
					"wewew",
					"wwbww",
					"eeeee",
					"wwwww",
					"wewew",
					"wewew",
					"bebeb",
					"wewew",
					"wwbww",
				};
				_expected = 7;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 12:
			{
				int n = 13;
				int m = 5;
				string X[] = {
					"wwwww",
					"wewew",
					"wewew",
					"bebeb",
					"wewew",
					"wwbww",
					"eeeee",
					"bbbbb",
					"bebeb",
					"bebeb",
					"wewew",
					"bebeb",
					"bbwbb",
				};
				_expected = 6;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 13:
			{
				int n = 3;
				int m = 3;
				string X[] = {
					"wbw",
					"eee",
					"bwb"
				};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 14:
			{
				int n = 3;
				int m = 3;
				string X[] = {
					"wbw",
					"eee",
					"wbw"
				};
				_expected = 2;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 15:
			{
				int n = 3;
				int m = 3;
				string X[] = {
					"bwb",
					"eee",
					"bwb"
				};
				_expected = 2;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 16:
			{
				int n = 1;
				int m = 3;
				string X[] = {
					"bew"
				};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 17:
			{
				int n = 1;
				int m = 3;
				string X[] = {
					"bwe"
				};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 18:
			{
				int n = 1;
				int m = 10;
				string X[] = {
					"bbwwewwwbb"
				};
				_expected = 2;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 19:
			{
				int n = 3;
				int m = 3;
				string X[] = {
					"ewe",
					"wbw",
					"ewe",
				};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 20:
			{
				int n = 3;
				int m = 3;
				string X[] = {
					"ebe",
					"wwb",
					"ebe",
				};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 21:
			{
				int n = 7;
				int m = 3;
				string X[] = {
					"ebe",
					"bwb",
					"ebe",
					"eee",
					"ewe",
					"wbw",
					"ewe",
				};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 22:
			{
				int n = 20;
				int m = 20;
				string X[] = {
"wbwwwwbebbebeebebeeb",
"bbewwewwbebwbwweeeee",
"wbbewbwwbebeebeweeee",
"ebewwbwbebeewbbebbwe",
"wbwwwbbewebbbebeweew",
"wewbwwbbbwwebweewwwe",
"wwweebeewwwewwbbewbe",
"bebbbwwebbeebeebwwwb",
"wbwwwebewbwbeeebeebw",
"webebewewbwbewwbbwwe",
"bwweewebbweewwbbbwwb",
"ebbbbwweweewewwweeew",
"ewwbebebweweewewwbwe",
"wbebwweewewwewwebwwb",
"ebweewbeweebbbbewwww",
"bbweewbwwwwewebwewbw",
"bbwebbwbbbweeeeebbbw",
"wbeweebweewbbwewebbb",
"bwebbwwebbbeebewwwbe",
"ewbewweeebwwbwbbwwee"
				};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
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
