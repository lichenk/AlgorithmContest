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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }



const ll MAXN = 200;
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
	//pr("%lld->%lld %lld\n",a,b,cap);
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
const ll mn=55;
ll di[mn][mn];
class SafeReturn {
	public:
	int minRisk(int N, vector <string> streets) {
		ll t=streets.size();
		for (ll x=0;x<t;x++) for (ll y=0;y<t;y++) di[x][y]=INF;
		for (ll s=0;s<t;s++) {
			queue<ll> q;
			q.push(s);
			di[s][s]=0;
			for (ll j=0;j<=t+3;j++)
			for (ll x=0;x<t;x++) for (ll y=0;y<t;y++) {
				char c=streets[x][y];
				if (c=='-') continue;
				ll k=c-'1'+1;
				chkmin(di[s][y],di[s][x]+k);
			}
		}
		ll n=N;
		for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
			if (x==y) continue;
			if (di[0][y]==di[0][x]+di[x][y]) {
				//pr("%lld to %lld\n",x,y);
				add_edge(x,y+n,1);
			}
		}
		ll src=n+n+1;
		ll dest=n+n+2;
		for (ll x=1;x<=n;x++) add_edge(src,x,1);
		for (ll x=1;x<=n;x++) add_edge(x+n,dest,1);
		dinic_numnodes=dest+1;
		dinic_src=src;
		dinic_dest=dest;
		ll flow=dinic();
		//pr("flow:%lld\n",flow);
		ll ans=n-flow;
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
		cout << "Testing SafeReturn (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471537378;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SafeReturn _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string streets[] = {"-234",
				                    "2---",
				                    "3---",
				                    "4---"};
				_expected = 3;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 2;
				string streets[] = {"-12",
				                    "1-1",
				                    "21-"};
				_expected = 1;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 3;
				string streets[] = {"-----7",
				                    "--1---",
				                    "-1-5--",
				                    "--5-1-",
				                    "---1-3",
				                    "7---3-"};
				_expected = 1;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 2;
				string streets[] = {"-11",
				                    "1-1",
				                    "11-"};
				_expected = 2;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string streets[] = ;
				_expected = ;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string streets[] = ;
				_expected = ;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int N = ;
				string streets[] = ;
				_expected = ;
				_received = _obj.minRisk(N, vector <string>(streets, streets+sizeof(streets)/sizeof(string))); break;
			}*/
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
