#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define LL_MAX 9223372036854775807LL
#define MAXT 1251LL
#define BASET 25LL
#define RMAXT (MAXT + BASET)
#define START 0LL
#define END 1LL
typedef struct {
	ll t, rev, cap, f;
} EdgeStruct;
typedef EdgeStruct *Edge;
typedef vector<Edge> *Graph;

ll global_num_nodes = -1;
ll global_num_plants = -1;
void printvtx(ll v) {
	ll t = (v%RMAXT) - BASET;
	ll k = v/RMAXT;
	if (k/2 >= global_num_plants) {
		printf(" src or target ");
	}
	else if (k%2 == START)
		printf(" Plant %lld t %lld start ",k/2,t);
	else
		printf(" Plant %lld t %lld end ",k/2,t);
}

ll getvtx(ll plant, ll t, ll startorend) {
	assert(BASET + t >= 0 && (BASET + t) < RMAXT);
	return (plant*2 + startorend)*RMAXT + (BASET + t);
}


Edge newEdge(ll t, ll rev, ll cap) {
	Edge edge = new EdgeStruct;
	edge->t = t;
	edge->rev = rev;
	edge->cap = cap;
	edge->f = 0;
	return edge;
}

void addEdge(Graph &graph, ll s, ll t, ll cap) {
	graph[s].PB(newEdge(t, graph[t].size(), cap));
	graph[t].PB(newEdge(s, graph[s].size() - 1, 0));
}
void resetFlow(Graph &graph) {
	ll n = global_num_nodes;
	for (ll i = 0; i < n; i++) {
		for (auto& e: graph[i]) {
			e->f = 0;
		}
	}
}
// Level graph
bool dinicBfs(Graph &graph, ll src, ll dest, ll *dist) {
	////printf("Enter BFS\n");
	ll n = global_num_nodes;
	for (ll i = 0; i < n; i++) {dist[i] = -1;}
	queue<ll> q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty()) {
		ll u = q.front();
		////printf("BFS %lld with dist %lld. %lld\n",u,dist[u], q.size());
		q.pop();
		////printf("S %lld\n",q.size());
		for (auto& e: graph[u]) {
			if (dist[e->t] < 0 && e->f < e->cap) {
				dist[e->t] = dist[u] + 1;
				q.push(e->t);
				////printf("BFS push %lld\n", e->t);
			}
		}
		////printf("E %lld\n",q.size());
		////printf("X %d\n",q.empty());
		if (q.empty()) break;
	}
	return dist[dest] >= 0;
}

ll dinicDfs(Graph &graph, ll *ptr, ll *dist, ll dest, ll u, ll f) {
	if (u == dest) {return f;}
	for (; ptr[u] < graph[u].size(); ++ptr[u]) {
		Edge e = graph[u][ptr[u]];
		if (dist[e->t] == dist[u] + 1 && e->f < e->cap) {
			ll df = dinicDfs(graph, ptr, dist, dest, e->t, min(f, e->cap - e->f));
			if (df > 0) {
				/*printf("Flow %lld from", df);
				printvtx(u); printvtx(e->t);
				printf("\n");*/
				e->f += df;
				graph[e->t][e->rev]->f -= df;
				return df;
			}
		}
	}
	return 0;
}

ll maxFlow(Graph &graph, ll src, ll dest) {
	ll flow = 0;
	ll n = global_num_nodes;
	ll *dist = new ll[n];
	ll *ptr = new ll[n];
	while (dinicBfs(graph, src, dest, dist)) {
		for (ll i = 0; i < n; i++) {ptr[i] = 0;}
		while(1) {
			//printf("FLOW\n");
			ll df = dinicDfs(graph, ptr, dist, dest, src, LL_MAX);
			if (df == 0) {break;}
			flow += df;
		}	
	}
	return flow;
}

class Farmville {
	public:
	int minTime(vector <string> s, vector <int> tim, vector <int> cost, int budget) {
		ll numplants = s.size();
		global_num_plants = numplants;
		ll numnodes = numplants*2*RMAXT;
		ll target = numnodes; numnodes++;
		ll src[MAXT];
		for (ll t = 0; t < MAXT; t++) {
			src[t] = numnodes; numnodes++;
		}
		Graph graph = new vector<Edge>[numnodes];
		global_num_nodes = numnodes;
		// Make graph
		for (ll plant = 0; plant < numplants; plant++) {
			for (ll t = -BASET; t < 0; t++) {
				addEdge(graph, getvtx(plant, t, START), target, cost[plant]);
			}
			for (ll t = 0; t < MAXT; t++) {
				addEdge(graph, src[t], getvtx(plant, t, END), LL_MAX);
			}
			/* Why do we need this?
			for (ll t = 0; t < MAXT-1; t++) {
				addEdge(graph, getvtx(plant, t, START), getvtx(plant, t+1, START), LL_MAX);
			}
			*/
			for (ll t = 0; t < MAXT; t++) {
				addEdge(graph, getvtx(plant, t, END), getvtx(plant, t, START), LL_MAX);
				for (ll dt = 1; dt <= tim[plant]; dt++) {
					ll start_time = t - dt;
					ll flow = cost[plant];
					addEdge(graph, getvtx(plant, t, END), getvtx(plant, start_time, START), flow);
				}
			}
			for (ll depend = 0; depend < numplants; depend++) {
				if (s[plant][depend] == '1') {
					for (ll t = 0; t < MAXT; t++) {
						addEdge(graph, getvtx(plant, t, START), getvtx(depend, t, END), cost[plant]);
					}
				}
			}
		}
		//ll maxflow = maxFlow(graph, src[2], target);
		//printf("maxflow: %lld\n", maxflow);
		//return 0;
		ll imin = 0; ll imax = MAXT;
		while (imin < imax) {
			ll imid = (imin+imax)/2;
			ll maxflow = maxFlow(graph, src[imid], target);
			//printf("%lld %lld\n", imid, maxflow);
			resetFlow(graph);
			if (maxflow > budget) imin = imid + 1;
			else imax = imid;
		}
		assert(imax == imin);
		return imax;
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
		cout << "Testing Farmville (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450461694;
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
		Farmville _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"000",
				              "000",
				              "000"};
				int time[] = {25,15,10};
				int cost[] = {1,2,3};
				int budget = 50;
				_expected = 6;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 1:
			{
				string s[] = {"0000",
				              "1000",
				              "0100",
				              "0010"};
				int time[] = {25,25,25,25};
				int cost[] = {100,200,300,400};
				int budget = 2800;
				_expected = 74;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 2:
			{
				string s[] = {"01110",
				              "00010",
				              "00000",
				              "00000",
				              "10000"};
				int time[] = {25,10,23,12,5};
				int cost[] = {123,456,789,1011,1213};
				int budget = 1000000000;
				_expected = 0;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 3:
			{
				string s[] = {"00",
				              "00"};
				int time[] = {25,25};
				int cost[] = {1000000000,1000000000}	;
				int budget = 1000000000;
				_expected = 25;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 4:
			{
				string s[] = {"0000000000000000",
				              "1000000000000000",
				              "1000000000000000",
				              "0100000000000000",
				              "0110000000000000",
				              "0010000000000000",
				              "0001000000000000",
				              "0001100000000000",
				              "0000110000000000",
				              "0000010000000000",
				              "0000001100000000",
				              "0000000110000000",
				              "0000000011000000",
				              "0000000000110000",
				              "0000000000011000",
				              "0000000000000110"};
				int time[] = {24,25,23,25,23,24,25,24,23,22,25,24,23,25,23,25};
				int cost[] = {82912,129482,235934,3294812,523942,460492,349281,592384,
				             109248,2305923,340945,2304934,582396,548935,767872,423981};
				int budget = 87654321;
				_expected = 49;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 5:
			{
				string s[] = {"000","100","110"};
				int time[] = {3,18,1};
				int cost[] = {242949,8471,54403957};
				int budget = 53867;
				_expected = 16;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 6:
			{
				string s[] = {"00", "10"};
				int time[] = {2,2};
				int cost[] = {1,1};
				int budget = 1;
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 7:
			{
				string s[] = {"00",
				              "10"};
				int time[] = {2,1};
				int cost[] = {1,2};
				int budget = 2;
				_expected = 1;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 8:
			{
				string s[] = {"000","100","110"};
				int time[] = {1,2,1};
				int cost[] = {100,1,100};
				int budget = 2;
				_expected = 2;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
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
