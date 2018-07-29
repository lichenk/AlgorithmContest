#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<int, int> pii;

const int maxnodes = 64;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
  Edge a = {t, 0, cap, cost, graph[t].size()};
  Edge b = {s, 0, 0, -cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
  fill(dist, dist + nodes, INT_MAX);
  dist[s] = 0;
  int qt = 0;
  q[qt++] = s;
  for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
    int u = q[qh % nodes];
    inqueue[u] = false;
    for (int i = 0; i < (int) graph[u].size(); i++) {
      Edge &e = graph[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      int ndist = dist[u] + e.cost;
      if (dist[v] > ndist) {
        dist[v] = ndist;
        if (!inqueue[v]) {
          inqueue[v] = true;
          q[qt++ % nodes] = v;
        }
      }
    }
  }
}

pii minCostFlow(int s, int t, int maxf) {
// bellmanFord can be safely commented if edges costs are non-negative
  bellmanFord(s, pot);
  int flow = 0;
  int flowCost = 0;
  while (flow < maxf) {
    priority_queue<ll, vector<ll>, greater<ll> > q;
    q.push(s);
    fill(prio, prio + nodes, INT_MAX);
    prio[s] = 0;
    curflow[s] = INT_MAX;
    while (!q.empty()) {
      ll cur = q.top();
      int d = cur >> 32;
      int u = cur;
      q.pop();
      if (d != prio[u])
        continue;
      for (int i = 0; i < (int) graph[u].size(); i++) {
        Edge &e = graph[u][i];
        int v = e.to;
        if (e.cap <= e.f) continue;
        int nprio = prio[u] + e.cost + pot[u] - pot[v];
        if (prio[v] > nprio) {
          prio[v] = nprio;
          q.push(((ll) nprio << 32) + v);
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
        }
      }
    }
    if (prio[t] == INT_MAX)
      break;
    for (int i = 0; i < nodes; i++)
      pot[i] += prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for (int v = t; v != s; v = prevnode[v]) {
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}



const ll MAXN = 204;
struct edge {
	ll a, b, cap, flow;
};

ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], qq[MAXN];
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
	qq[qt++] = dinic_src;
	memset (d, -1, dinic_numnodes * sizeof d[0]);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		ll v = qq[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			ll id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				qq[qt++] = to;
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

#define fst first
#define snd second
class AngelDemonGame {
	public:
	string winner(vector <string> G, int A, int D) {
		int n=G.size();
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				int cost=(G[x][y]=='Y')?0:1;
				if (x!=y) addEdge(x, y, 1, cost);
			}
		}
		addEdge(n,0,D+1,0);
		pii got=minCostFlow(n, n-1, D+1);
		if (got.fst==D+1 && got.snd<=A) return "Angel";
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				if (x!=y&&G[x][y]=='Y') add_edge(x,y,1);
			}
		}
		int flow=dinic(0, n-1, n);
		if (A==0) {
			if (flow<=D) return "Demon";
			else return "Unknown";
		}
		else if (A==1) {
			int c=1;
			for (int z=1;z<n-1;z++) {
				dinic_clear(n);
				for (int x=0;x<n;x++) {
					for (int y=0;y<n;y++) {
						if (x!=y&&G[x][y]=='Y') add_edge(x,y,1);
					}
				}
				int flow=dinic(z, n-1, n);
				if (flow>0) c++;
			}
			if (D<c) return "Unknown";
			return "Demon";
		}
		else {
			int block=n-1;
			//printf("D:%d block:%d n:%d\n",D,block,n);
			if (D>=block) return "Demon";
			else return "Unknown";
		}
		return "Unknown";
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
		cout << "Testing AngelDemonGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1500740635;
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
		AngelDemonGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string G[] = {"NYNY",
				              "YNYY",
				              "NYNN",
				              "YYNN"};
				int A = 2;
				int D = 2;
				_expected = "Angel";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 1:
			{
				string G[] = {"NYNY",
				              "YNYY",
				              "NYNN",
				              "YYNN"};
				int A = 6;
				int D = 6;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 2:
			{
				string G[] = {"NNNN",
				              "NNNN",
				              "NNNN",
				              "NNNN"};
				int A = 2;
				int D = 2;
				_expected = "Unknown";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 3:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 4;
				int D = 4;
				_expected = "Unknown";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 4:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 8;
				int D = 4;
				_expected = "Angel";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 5:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 4;
				int D = 8;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 6:
			{
				vector<string> G;
				for (int x=0;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="N";
					G.PB(s);
				}
				int A = 0;
				int D = 0;
				_expected = "Demon";
				_received = _obj.winner(G, A, D); break;
			}
			case 7:
			{
				vector<string> G;
				for (int x=0;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 0;
				int D = 0;
				_expected = "Angel";
				_received = _obj.winner(G, A, D); break;
			}
			case 8:
			{
				vector<string> G;
				for (int x=0;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 0;
				int D = 49;
				_expected = "Demon";
				_received = _obj.winner(G, A, D); break;
			}
			case 9:
			{
				vector<string> G;
				for (int x=0;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 0;
				int D = 50;
				_expected = "Demon";
				_received = _obj.winner(G, A, D); break;
			}
			case 10:
			{
				vector<string> G;
				for (int x=0;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 0;
				int D = 48;
				_expected = "Angel";
				_received = _obj.winner(G, A, D); break;
			}
			case 11:
			{
				vector<string> G;
				{
					string s; for (int y=0;y<50;y++) s+="N";
					G.PB(s);
				}
				for (int x=1;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 1;
				int D = 48;
				_expected = "Unknown";
				_received = _obj.winner(G, A, D); break;
			}
			case 12:
			{
				vector<string> G;
				{
					string s; for (int y=0;y<50;y++) s+="N";
					G.PB(s);
				}
				for (int x=1;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+="Y";
					G.PB(s);
				}
				int A = 1;
				int D = 49;
				_expected = "Demon";
				_received = _obj.winner(G, A, D); break;
			}
			case 13:
			{
				vector<string> G;
				{
					string s; for (int y=0;y<50;y++) s+="N";
					G.PB(s);
				}
				for (int x=1;x<50;x++) {
					string s; for (int y=0;y<50;y++) s+=(y==x)?"N":"Y";
					G.PB(s);
				}
				int A = 1;
				int D = 47;
				_expected = "Unknown";
				_received = _obj.winner(G, A, D); break;
			}
			case 14:
			{
				string G[] = {"NYNNNNN",
"YNYNNNN",
"NYNYNNN",
"NNYNNNY",
"NNNNNNN",
"NNNNNNN",
"NNNYNNN"};
				int A = 1;
				int D = 4;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 15:
			{
				string G[] = {"NYNNNNN",
"YNYNNNN",
"NYNYNNN",
"NNYNNNY",
"NNNNNNN",
"NNNNNNN",
"NNNYNNN"};
				int A = 1;
				int D = 3;
				_expected = "Unknown";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
