#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

const ll MAXN = 50*50*9+2+1;
struct edge {
	ll a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[MAXN];
 
void add_edge (ll a, ll b, ll cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	dinic_graph[a].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = dinic_src;
	memset (d, -1, dinic_numnodes * sizeof d[0]);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			ll id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[dinic_dest] != -1;
}
 
ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == dinic_dest)  return flow;
	for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
		ll id = dinic_graph[v][ptr[v]],
			to = dinic_edge[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
		if (pushed) {
			dinic_edge[id].flow += pushed;
			dinic_edge[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
		while (ll pushed = dfs (dinic_src, INF))
			flow += pushed;
	}
	return flow;
}




ll idtoval[MAXN], idtotype[MAXN];
const ll MAXB = 51;
unordered_set<ll> st[MAXB][MAXB][2];
unordered_set<ll> h[MAXN];

ll getnum(char c) {
	if ('0'<=c&&c<='9') return c-'0';
	return -1;
}
bool isdir(char c) {
	return c=='<'||c=='>'||c=='A'||c=='V';
}

class LaserTowersDiv1 {
	public:
	int countMaxEnemies(vector <string> board) {
		ll n=board.size(), m=board[0].length();
		ll id=0;
		ll sum=0;
		for (ll initx=0;initx<n;initx++) {
			for (ll inity=0;inity<m;inity++) {
				if (isdir(board[initx][inity])) {
					ll dx,dy;
					if (board[initx][inity]=='A') {dx=-1;dy=0;}
					if (board[initx][inity]=='V') {dx=1;dy=0;}
					if (board[initx][inity]=='>') {dx=0;dy=1;}
					if (board[initx][inity]=='<') {dx=0;dy=-1;}
					ll type=(dx==0)?0:1;
					ll x=initx,y=inity;
					ll prev=0;
					x+=dx;y+=dy;
					while(0<=x&&x<n&&0<=y&&y<m) {
						ll num=getnum(board[x][y]);
						if (num>prev){
							ll diff=num-prev;
							prev=num;
							idtoval[id]=diff;
							sum+=diff;
							//printf("init:%lld %lld. bare:%lld %lld. diff:%lld num:%lld prev:%lld\n",initx,inity,x,y,diff,num,prev);
							idtotype[id]=type;
							ll i=initx,j=inity;
							i+=dx;j+=dy;
							while(1) {
								////printf("st:%d %d %d. i: %d %d. xy: %d %d\n",i,j,type,initx,inity,x,y);
								st[i][j][type].insert(id);
								if (i==x&&j==y) break;
								i+=dx;j+=dy;
							}
							//printf("id:%lld (%lld,%lld)->(%lld,%lld):%lld\n",id,initx,inity,x,y,diff);
							id++;
						}
						x+=dx;y+=dy;
					}
				}
			}
		}
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				for (auto &v1:st[x][y][0]) {
					for (auto &v2:st[x][y][1]) {
						h[v1].insert(v2);
					}
				}
			}
		}
		ll _src=id; ll target=id+1;
		ll nodes=id+2;
		assert(nodes<MAXN);
		for (ll x=0;x<id;x++) {
			ll type = idtotype[x];
			ll val=idtoval[x];
			if (type==0) {
				add_edge(_src, x, val);
			}
			else {
				add_edge(x, target, val);
			}
		}
		for (ll x=0;x<id;x++) {
			for (auto &y:h[x]) {
				add_edge(x,y,INF);
			}
		}
		dinic_src=_src;dinic_dest=target;dinic_numnodes=nodes;
		ll flow = dinic();
		ll ans=sum-flow;
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
		cout << "Testing LaserTowersDiv1 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457501878;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LaserTowersDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {
				                 ".9",
				                 ">3",
				                 ".A"
				                 };
				_expected = 9;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {
				                 "..V..",
				                 ">.54.",
				                 ".>3.6",
				                 "9..A."
				                 };
				_expected = 12;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {
				                 ".9V.",
				                 ">..7",
				                 ".A1."
				                 };
				_expected = 10;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {
				                 "........7..7......4...<...V9.5.",
				                 ">.........2.........5..46......",
				                 ".6...........9..<..>...5.......",
				                 ".6...................<..A>...5.",
				                 ".V>....................6.......",
				                 ".....57.............<...>....7.",
				                 "..............6.........<V....7",
				                 "V..V7..V..AA>..............61..",
				                 "..V.......V..A.....>.....5.....",
				                 "......7....V....>.........7....",
				                 "1...........<>..............6..",
				                 "............5...........<......",
				                 ".........6..V.......V...V..A...",
				                 ".2...........<....A..>....7....",
				                 "5..........................<...",
				                 ".............V...5...>.....6...",
				                 "........5.......V.V....A...>.8.",
				                 ".....A.........7.....>......5..",
				                 "96.........................<...",
				                 "....AV..............7V.....VA.A",
				                 "..............5....6........<.V",
				                 "..6................<........V..",
				                 "....V..............>.......5..6",
				                 "8.6................<...>....6..",
				                 ".........A.............V.....A.",
				                 ".....6A........A.A.>.....6.....",
				                 "69....<.A>.............3.......",
				                 "...2.....<....A.......>...2.6..",
				                 "...76..5.....7..7..5........7<.",
				                 "...8.......6..<..V5>.....9..7..",
				                 "....7.....5.5.<>.4...7.556.4..."};
				_expected = 328;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {">9"};
				_expected = 9;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {">8",
				                  "9A"};
				_expected = 8;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {">2.1",
													"99A9"};
				_expected = 2;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"...8.",
													"...7.",
													"1<>69",
													".....",
													"...A."};
				_expected = 10;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {".V.6.",
													">...9",
													"...A.",
													"1...<",
													".5..."};
				_expected = 11;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 9:
			{
				string board[] = {"V...V.",
												  "5....<",
												  ".V>.67",
												  "67.>.6"};
				_expected = 26;
				_received = _obj.countMaxEnemies(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
