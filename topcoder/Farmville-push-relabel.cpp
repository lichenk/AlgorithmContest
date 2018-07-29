#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
//#define INF 9223372036854775807LL
#define INF 1000000001
#define MAXT 1251LL
#define BASET 25LL
#define RMAXT (MAXT + BASET)
#define START 0LL
#define MID 1LL
#define END 2LL
#define CLASSNUM 3LL
ll global_num_nodes = -1;
ll global_num_plants = -1;
void printvtx(ll v) {
	ll t = (v%RMAXT) - BASET;
	ll k = v/RMAXT;
	if (k/CLASSNUM >= global_num_plants) {
		printf(" src or target ");
	}
	else if (k%CLASSNUM == START)
		printf(" Plant %lld t %lld start ",k/CLASSNUM,t);
	else if (k%CLASSNUM == MID)
		printf(" Plant %lld t %lld mid ",k/CLASSNUM,t);
	else
		printf(" Plant %lld t %lld end ",k/CLASSNUM,t);
}

ll getvtx(ll plant, ll t, ll cls) {
	assert(BASET + t >= 0 && (BASET + t) < RMAXT);
	return (plant*CLASSNUM + cls)*RMAXT + (BASET + t);
}


typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void resetFlow() {
  	for (int i = 0; i < N; i++) {
  		excess[i] = 0; dist[i] = 0; active[i] = 0;
  	}
  	for (int i = 0; i < 2*N; i++) {
  		count[i] = 0;
  	}
  	for (int i = 0; i < N; i++) {
  		for (auto& e: G[i]) {
  			e.flow = 0;
  		}
  	}
  }

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};


class Farmville {
	public:
	int minTime(vector <string> s, vector <int> tim, vector <int> cost, int budget) {
		ll numplants = s.size();
		global_num_plants = numplants;
		ll numnodes = numplants*CLASSNUM*RMAXT;
		ll target = numnodes; numnodes++;
		ll src[MAXT];
		for (ll t = 0; t < MAXT; t++) {
			src[t] = numnodes; numnodes++;
		}
		auto push_relabel = PushRelabel(numnodes);
		global_num_nodes = numnodes;
		// Make graph
		for (ll plant = 0; plant < numplants; plant++) {
			for (ll t = -BASET; t < 0; t++) {
				push_relabel.AddEdge(getvtx(plant, t, MID), target, cost[plant]);
			}
			for (ll t = 0; t < MAXT; t++) {
				push_relabel.AddEdge(src[t], getvtx(plant, t, END), INF);
			}
			for (ll t = 0; t < MAXT; t++) {
				for (ll dt = 1; dt <= tim[plant]; dt++) {
					ll start_time = t - dt;
					push_relabel.AddEdge(getvtx(plant, t, END), getvtx(plant, start_time, MID), INF);
				}
				push_relabel.AddEdge(getvtx(plant, t, MID), getvtx(plant, t, START), cost[plant]);
				push_relabel.AddEdge(getvtx(plant, t, END), getvtx(plant, t, START), INF);
			}
			for (ll depend = 0; depend < numplants; depend++) {
				if (s[plant][depend] == '1') {
					for (ll t = 0; t < MAXT; t++) {
						push_relabel.AddEdge(getvtx(plant, t, START), getvtx(depend, t, END), INF);
					}
				}
			}
		}
		//ll maxflow = maxFlow(graph, src[1], target);
		//printf("maxflow: %lld\n", maxflow);
		//return 0;
		ll imin = 0; ll imax = MAXT;
		while (imin < imax) {
			ll imid = (imin+imax)/2;
			//ll maxflow = maxFlow(graph, src[imid], target);
			ll maxflow = push_relabel.GetMaxFlow(src[imid], target);
			printf("%lld %lld\n", imid, maxflow);
			push_relabel.resetFlow();
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
				string s[] = {"00000000000000000000000000000001000000000000000000", "00000000000000000000000000000000000000000000100000", "00000000000000000000000001000000000000000000000000", "00000000010000000000000000000000000000000000000000", "00000000000000000000000000100000000000000000000000", "00000000000000000000010000000000000000000000000000", "00000001000000000000000000000000000000000000000000", "00000000000000000000000000001000000000000000000000", "00000000000000000000000100000000000000000000000000", "00000100000000000000000000000000000000000000000000", "00000000000000000000000000000010000000000000000000", "00000000000000000000000000000000000000010000000000", "00000000000000000000000000000000000000000010000000", "00000000000000000000000000000000010000000000000000", "00000000000000000100000000000000000000000000000000", "00001000000000000000000000000000000000000000000000", "00000000000000000000000000000000001000000000000000", "00100000000000000000000000000000000000000000000000", "01000000000000000000000000000000000000000000000000", "00000000000000000010000000000000000000000000000000", "00000000000000000000000000000000000000000001000000", "00000000000000000000000000000000000000000000000000", "00000000000000100000000000000000000000000000000000", "00000000000010000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000100", "00000000000000000000000000000000000100000000000000", "00000000000001000000000000000000000000010000000000", "00000000000100000000000000000000000000000000000000", "00000000000000000000100000000000000000000000000000", "00000010000000000000000000000000000000000000000000", "00010000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000010000", "10000000000000000000000000000000000000000000000000", "00000000000000000000000000010000000000000000000000", "00000000000000000000000000000000000000000000000010", "00000000000000000000000000000000000010000000000000", "00000000000000000000000000000000000001000000000000", "00000000000000000000000000000100000000000000000000", "00000000000000000000000000000000000000000000000001", "00000000000000000000000010000000000000000000000000", "00000000000000000000001000000000000000000000000000", "00000000001000000000000000000000000000000000000000", "00000000000000000000000000000000100000000000000000", "00000000000000001000000000000000000000000000000000", "00000000000000000000000000000000000000000100000000", "00000000000000000001000000000000000000000000000000", "00000000000000010000000000000000000000000000000000", "00000000000000000000000000000000000000001000000000", "00000000000000000000000000000000000000100000000000", "00000000100000000000000000000000000000000000000000"};
				int time[] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25};
				int cost[] = {51280586, 899851662, 472625543, 894707090, 88641596, 515979593, 753051794, 14044412, 549260898, 746667153, 46018657, 144812105, 596221244, 110241316, 577537421, 344820359, 349297656, 989180747, 864226715, 388441890, 612267473, 349009127, 501190896, 900111660, 587301085, 26918077, 279828760, 752090820, 853197017, 165956183, 238996770, 851647236, 139108334, 633315447, 335958264, 658625673, 586539803, 680192054, 912808915, 646450754, 259778059, 675893562, 29575429, 447926293, 638550236, 480309893, 36943233, 611764798, 706588631, 906560892};
				int budget = 0;
				_expected = 1250;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 8:
			{
				string s[] = {"000000000000000000000001000000000000000", "000000010000000000000000000000000000000", "000000000000000000000000000000000001001", "000000000000010000000000010000000000000", "000000000000001000000000000000000000000", "000000000000000000000000000000000001000", "000000000100000000000000000000000000000", "000000000000000001000000000000000000000", "010000000000000000000000000000000000000", "000000000000000000000000100000000000000", "000000000000000000000000000001000000000", "000000100000000000000000000000000000000", "000000000000000000000000001000000000000", "000000001000000000000000000000000000000", "000000000000000000000000000100000000000", "000000000000000000000000000010000000000", "000000000000000000000000000000000000010", "000001000000000000000000000000000000000", "000000000000000000000000000000000000000", "000000000000100000000000000000000000000", "100000000000000000000000000000000000000", "000000000000000000100000000000000000000", "000100000000000001000000000000000000000", "000000000000000000000000000000000100000", "000000000000000000000000010000000000000", "000000000000000000010000000000000000000", "000000000000000000000100000000000000000", "000000000010000000000000000000000000000", "000000000000000000000010000000000000000", "000000000000000000000000000000100000000", "000000000000000100000000000000000000000", "000000000000000000000000000000000010000", "000000000000000000000000000000010000100", "000000000000000000000000000000000000100", "001000000000000000000000000000000000000", "000000000100000010000000000000000000000", "000010000000000000000000100000000000000", "000000000001000000000000000000000000000", "000000000000000010001001000000000000000"};
				int time[] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25};
				int cost[] = {223564918, 913735994, 715918620, 386722062, 801323762, 374691744, 888131215, 422159244, 739218234, 208774638, 767117134, 752598959, 744609402, 297498815, 912319225, 173416803, 519669871, 36610530, 200269520, 833464220, 387256103, 723860780, 176359234, 139178144, 680564546, 429685296, 354550294, 923534719, 941889529, 124870309, 383882497, 625116335, 74434951, 695727422, 427387805, 532132910, 596013250, 489997062, 932031091};
				int budget = 806346858;
				_expected = 953;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), budget); break;
			}
			case 9:
			{
				string s[] = {"00000000000000100", "00000110000000000", "00000000001000000", "00000000000100100", "00000000000000000", "00000000000000000", "00101000000000000", "00101010000100001", "00010000010000000", "10001000000100000", "00001000000010000", "00000000000000000", "00000000000000000", "10000000010000101", "00000000000010010", "00000000000000000", "00000000000000100"};
				int time[] = {12, 13, 20, 13, 7, 22, 13, 8, 23, 4, 6, 14, 18, 7, 19, 2, 25};
				int cost[] = {7529341, 6199, 49, 395279, 3, 151082035, 3, 729, 8649, 4548522, 596345, 5, 1118332, 587, 420, 4771206, 175424};
				int budget = 806152;
				_expected = 40;
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
