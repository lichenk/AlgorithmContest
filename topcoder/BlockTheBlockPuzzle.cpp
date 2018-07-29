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

struct edge {
	ll a, b, cap, flow;
};



const ll ONE=0;
const ll DOWN=1;
const ll RIGHT=2;
const ll UP=3;
const ll LEFT=4;
const ll MAXTYPE=3;
ll ddx[]={0,1,0,-1,0};
ll ddy[]={0,0,1,0,-1};
const ll MAXB=54;
ll dollarx=-1,dollary=-1;
ll n,m;
const ll MAXN = 2+(MAXTYPE*2)*MAXB*MAXB;
string decode(ll v) {
	if(v==0) return "src";
	if (v==1) return "target";
	v-=2;
	string ans="";
	if (v>=MAXTYPE*MAXB*MAXB) {
		ans+="out-"; v-=MAXTYPE*MAXB*MAXB;
	}
	else ans+="in-";
	ll type=v/(MAXB*MAXB);
	if (type==ONE) ans+="one";
	if (type==DOWN) ans+="down";
	if (type==RIGHT) ans+="right";
	v-=type*MAXB*MAXB;
	ll x=v/MAXB;
	ll y=v%MAXB;
	ans+="("+to_string(x)+","+to_string(y)+")";
	return ans;
}


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
	if (a==-1||b==-1) return;
	/*if (cap>0) {
		printf("AE: %s->%s:%lld\n",decode(a).c_str(),decode(b).c_str(),cap);
	}*/
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

ll vin(ll type, ll x, ll y) {
	if (!(0<=x&&x<n&&0<=y&&y<m)) return -1;

	if (type==UP) {x--;type=DOWN;}
	if (type==LEFT) {y--;type=RIGHT;}
	return 2+type*MAXB*MAXB+x*MAXB+y;
}
ll vout(ll type, ll x, ll y) {
	if (!(0<=x&&x<n&&0<=y&&y<m)) return -1;
	if (type==UP) {x--;type=DOWN;}
	if (type==LEFT) {y--;type=RIGHT;}
	return 2+(MAXTYPE+type)*MAXB*MAXB+x*MAXB+y;
}

ll getf(char c) {
	if (c=='.') return 1;
	else if (c=='H') return 0;
	else return INF;
}

char b[MAXB][MAXB];
class BlockTheBlockPuzzle {
	public:
	int minimumHoles(vector <string> board) {
		n=board.size();
		m=board[0].length();
		for (ll x=0;x<MAXB;x++) {
			for (ll y=0;y<MAXB;y++) {
				b[x][y]='H';
			}
		}
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				b[x][y]=board[x][y];
			}
		}
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				if (b[x][y]=='$') {
					dollarx=x;dollary=y;
					break;
				}
			}
		}
		ll src=0; ll target=1;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				if (((x-dollarx)%3==0)&&((y-dollary)%3==0)) {
					char c=b[x][y];
					if (c=='$') {
						add_edge(vin(ONE,x,y),target,INF);
					}
					else if (c=='b') {
						add_edge(src,vout(ONE,x,y),INF);
					}
					else if (c=='.') {
						add_edge(vin(ONE,x,y),vout(ONE,x,y),1);
					}
					for (ll t=DOWN;t<=LEFT;t++) {
						ll dx=ddx[t],dy=ddy[t];
						add_edge(vout(ONE,x,y),vin(t,x+dx,y+dy),INF);
						add_edge(vout(t,x+dx,y+dy),vin(ONE,x,y),INF);
					}
				}
				for (ll t=DOWN;t<=RIGHT;t++) {
					ll dx=ddx[t],dy=ddy[t];
					if (((x-dx-dollarx)%3==0)&&((y-dy-dollary)%3==0)) {
						ll F=getf(b[x][y])+getf(b[x+dx][y+dy]);
						add_edge(vin(t,x,y),vout(t,x,y),F);
					}
				}
			}
		}
		dinic_src=src;dinic_dest=target;dinic_numnodes=MAXN;
		ll flow = dinic();
		/*for (auto &e:dinic_edge) {
			if (e.flow>0) {
				printf("%s->%s:%lld\n",decode(e.a).c_str(),decode(e.b).c_str(),e.flow);
			}
		}*/
		if (flow>=INF) return -1;
		return flow;
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
		cout << "Testing BlockTheBlockPuzzle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457544956;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BlockTheBlockPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"b..$",
				                  "....",
				                  "HHHH",
				                  "HHHH"};
				_expected = 2;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"............H..",
				                  "...............",
				                  "...............",
				                  "HHH$HHH.....H..",
				                  "HHHHHHH........",
				                  "HHHHHHHH.......",
				                  "......b..H.....",
				                  "...............",
				                  "...............",
				                  "...H..H..H.....",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "..............."};
				_expected = 0;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"............H..",
				                  "...............",
				                  "...............",
				                  "HHH$HHH........",
				                  "HHHHHHH........",
				                  "HHHHHHHH.......",
				                  "......b..H.....",
				                  "...............",
				                  "...............",
				                  "...H..H..H.....",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "..............."};
				_expected = 1;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"b..$...",
				                  "...H...",
				                  ".......",
				                  "b..b..b",
				                  "...H...",
				                  ".......",
				                  "b..b..b"};
				_expected = 4;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"b..b..b",
				                  "..b..b.",
				                  ".......",
				                  "b..$bbb",
				                  ".b.....",
				                  "....b..",
				                  "b..b..b"};
				_expected = -1;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"b..$",
													"....",
												  "....",
												  "...."};
				_expected = 3;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = "bHH$";
				_expected = 0;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"bHH$",
													".HH.",
												  "....",
												  "H..H"};
				_expected = 0;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
