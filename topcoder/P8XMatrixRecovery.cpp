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
	//printf("%lld->%lld:%lld\n",a,b,cap);
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
 
ll dinic(ll src, ll dest, ll numnodes) {
	dinic_src = src;
	dinic_dest = dest;
	dinic_numnodes = numnodes;
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
		while (ll pushed = dfs (dinic_src, INF))
			flow += pushed;
	}
	return flow;
}
void dinic_clear(ll numnodes) {
	dinic_edge.clear();
	for (ll v=0;v<numnodes;v++) dinic_graph[v].clear();	
}
ll rlim,clim;
bool f(vector <string> &rows, vector <string> &columns) {
			ll src = 2*clim;
			ll dest = 2*clim+1;
			ll numnodes=dest+1;
			dinic_clear(numnodes);
			//printf("src:%lld dest:%lld\n",dinic_src,dinic_dest);
			for (ll a=0;a<clim;a++) {
				add_edge(src,a,1);
				add_edge(a+clim,dest,1);
			}
			for (ll a=0;a<clim;a++) {
				for (ll b=0;b<clim;b++) {
					bool match=true;
					for (ll r=0;r<rlim;r++) if (columns[a][r]!=rows[r][b]&&rows[r][b]!='?'&&columns[a][r]!='?') {
						match=false;
					}
					if (match) add_edge(a,b+clim,1);
				}
			}
			ll flow=dinic(src,dest,numnodes);
			//printf("flow:%lld want:%lld\n",flow,clim);
			return (flow==clim);
}
class P8XMatrixRecovery {
	public:
	vector <string> solve(vector <string> rows, vector <string> columns) {
		rlim=rows.size(),clim=columns.size();
		for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
			if (rows[r][c]=='?') {
				//printf("? at %lld,%lld\n",r,c);
				rows[r][c]='0';
				if (!f(rows,columns)) rows[r][c]='1';
			}
		}
		return rows;
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
		cout << "Testing P8XMatrixRecovery (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472620959;
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
		P8XMatrixRecovery _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rows[] = {"10?"
				                ,"?11"};
				string columns[] = {"01"
				                   ,"10"
				                   ,"1?"};
				string __expected[] = {"101", "011" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 1:
			{
				string rows[] = {"0"
				                ,"?"
				                ,"1"};
				string columns[] = {"0?1"};
				string __expected[] = {"0", "0", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 2:
			{
				string rows[] = {"10"
				                ,"01"};
				string columns[] = {"10"
				                   ,"01"};
				string __expected[] = {"10", "01" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 3:
			{
				string rows[] = {"??0"
				                ,"11?"
				                ,"?01"
				                ,"1?1"};
				string columns[] = {"1???"
				                   ,"?111"
				                   ,"0?1?"};
				string __expected[] = {"010", "110", "101", "101" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			/*case 4:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
