#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

typedef long long ll;
typedef pair<ll,ll> pll;

const ll maxnodes = 200000;

ll nodes = maxnodes;
ll prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
	ll to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(ll s, ll t, ll cap, ll cost) {
	Edge a = {t, 0, cap, cost, graph[t].size()};
	Edge b = {s, 0, 0, -cost, graph[s].size()};
	graph[s].push_back(a);
	graph[t].push_back(b);
}

void bellmanFord(ll s, ll dist[]) {
	fill(dist, dist + nodes, INT_MAX);
	dist[s] = 0;
	ll qt = 0;
	q[qt++] = s;
	for (ll qh = 0; (qh - qt) % nodes != 0; qh++) {
		ll u = q[qh % nodes];
		inqueue[u] = false;
		for (ll i = 0; i < (ll) graph[u].size(); i++) {
			Edge &e = graph[u][i];
			if (e.cap <= e.f) continue;
			ll v = e.to;
			ll ndist = dist[u] + e.cost;
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

pll minCostFlow(ll s, ll t, ll maxf) {
	// bellmanFord can be safely commented if edges costs are non-negative
	bellmanFord(s, pot);
	ll flow = 0;
	ll flowCost = 0;
	while (flow < maxf) {
		priority_queue<pll, vector<pll>, greater<pll> > q;
		q.push(MP(0LL,s));
		fill(prio, prio + nodes, INT_MAX);
		prio[s] = 0;
		curflow[s] = INT_MAX;
		while (!q.empty()) {
			pll cur = q.top();
			ll d = cur.first;
			ll u = cur.second;
			q.pop();
			if (d != prio[u])
				continue;
			for (ll i = 0; i < (ll) graph[u].size(); i++) {
				Edge &e = graph[u][i];
				ll v = e.to;
				if (e.cap <= e.f) continue;
				ll nprio = prio[u] + e.cost + pot[u] - pot[v];
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.push(MP(nprio,v));
					prevnode[v] = u;
					prevedge[v] = i;
					curflow[v] = min(curflow[u], e.cap - e.f);
				}
			}
		}
		if (prio[t] == INT_MAX)
			break;
		for (ll i = 0; i < nodes; i++)
			pot[i] += prio[i];
		ll df = min(curflow[t], maxf - flow);
		flow += df;
		for (ll v = t; v != s; v = prevnode[v]) {
			Edge &e = graph[prevnode[v]][prevedge[v]];
			e.f += df;
			graph[v][e.rev].f -= df;
			flowCost += df * e.cost;
		}
	}
	return make_pair(flow, flowCost);
}


#define MAXN 160
#define TREE 0
#define DAY 1
#define DEVICE 2
inline ll getvtx(ll type, ll n) {
	return 2+type*MAXN + n;
}

class TaroCutting {
	public:
	int getNumber(vector <int> height, vector <int> add, vector <int> device, int time) {
		ll src = 0; ll target = 1;
		ll n = height.size();
		ll dsz = device.size();
		for (ll t = 0; t < n; t++) {
			addEdge(src, getvtx(TREE,t), 1, 0);
		}
		for (ll tree = 0; tree < n; tree++) {
			for (ll day = 1; day <= time; day++) {
				addEdge(getvtx(TREE,tree), getvtx(DAY, day), 1, (time-day)*add[tree]);
			}
			addEdge(getvtx(TREE,tree), target, 1, height[tree]+add[tree]*time);
		}
		for (ll day = 1; day <= time; day++) {
			for (ll dev = 0; dev < dsz; dev++) {
				addEdge(getvtx(DAY,day), getvtx(DEVICE,dev), 1, device[dev]);
			}
		}
		for (ll dev = 0; dev < dsz; dev++) {
			addEdge(getvtx(DEVICE,dev), target, INT_MAX, 0);
		}
		pll res = minCostFlow(src, target, INT_MAX);
		ll flow = res.first;
		assert(flow==n);
		ll flowCost = res.second;
		return flowCost;
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
		cout << "Testing TaroCutting (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453596513;
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
		TaroCutting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {4, 7};
				int add[] = {7, 1};
				int device[] = {7};
				int time = 1;
				_expected = 15;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			case 1:
			{
				int height[] = {3, 1, 2};
				int add[] = {1, 1, 1};
				int device[] = {7, 7, 7};
				int time = 2;
				_expected = 12;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			case 2:
			{
				int height[] = {100, 50};
				int add[] = {75, 30};
				int device[] = {200, 100, 50};
				int time = 2;
				_expected = 130;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			case 3:
			{
				int height[] = {7, 10, 1, 7, 5, 4, 11, 5, 7, 9, 10, 8};
				int add[] = {1, 3, 4, 10, 2, 1, 6, 4, 8, 7, 5, 10};
				int device[] = {7, 1, 5, 10};
				int time = 3;
				_expected = 96;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			case 4:
			{
				int height[] = {35, 45, 32, 8};
				int add[] = {2, 25, 31, 5};
				int device[] = {29, 28, 3, 11, 28, 37};
				int time = 8;
				_expected = 29;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			case 5:
			{
				int height[] = {614, 649, 977, 808, 821, 356, 801, 493, 669, 650, 652, 627, 129, 261, 883, 513, 62, 698, 83, 772, 
				               779, 719, 83, 105, 774, 867, 412, 892, 142, 851, 743, 66, 221, 494, 125, 905, 638, 342, 723, 680, 
				               407, 197, 111, 368, 676, 694, 765, 482, 712, 188, 325, 535, 6, 49, 655, 595, 958, 805, 659, 893, 
				               370, 904, 276, 156, 29, 458, 757, 632, 731, 289, 582, 207, 843, 365, 387, 521, 69, 269, 459, 428, 
				               423, 885, 744, 199, 998, 968, 296, 473, 50, 752, 492, 919, 473, 981, 380, 896, 769, 991, 269, 93, 
				               108, 184, 762, 312, 511, 256, 374, 600, 643, 445, 908, 250, 384, 518, 119, 464, 499, 124, 82, 999, 
				               881, 767, 177, 796, 2, 620, 759, 380, 901, 221, 407, 622, 260, 622, 729, 264, 768, 79, 236, 524, 
				               437, 215, 108, 518, 820, 725, 490, 796, 986, 318};
				int add[] = {391, 938, 772, 630, 54, 775, 379, 613, 647, 8, 946, 885, 604, 822, 663, 559, 452, 565, 637, 695, 24, 
				            515, 92, 956, 194, 551, 813, 362, 190, 268, 440, 781, 450, 789, 566, 372, 402, 860, 531, 608, 434, 
				            761, 754, 26, 504, 873, 132, 756, 206, 93, 284, 807, 642, 637, 936, 954, 205, 303, 582, 822, 134, 
				            269, 967, 147, 589, 549, 24, 670, 403, 105, 40, 531, 486, 695, 898, 287, 443, 542, 599, 151, 45, 
				            567, 548, 945, 912, 764, 451, 404, 700, 522, 227, 954, 84, 347, 625, 278, 377, 730, 635, 604, 959, 
				            845, 41, 193, 459, 532, 429, 216, 473, 415, 85, 933, 90, 643, 94, 927, 692, 99, 771, 594, 318, 627, 
				            89, 340, 110, 488, 909, 253, 20, 114, 179, 177, 116, 42, 676, 91, 787, 437, 551, 51, 880, 336, 759, 
				            795, 243, 727, 279, 620, 488, 607};
				int device[] = {942, 79, 387, 184, 104, 981, 766, 678, 715, 998, 161, 125, 439, 532, 550, 415, 4, 467, 211, 852, 781, 
				               577, 728, 592, 40, 971, 852, 592, 338, 555, 662, 636, 823, 122, 728, 69, 701, 476, 346, 190, 36, 
				               535, 826, 739, 517, 551, 257, 36, 906, 171, 629, 292, 49, 29, 109, 151, 299, 180, 193, 731, 655, 
				               877, 174, 688, 866, 957, 57, 89, 513, 765, 68, 245, 454, 968, 224, 417, 657, 383, 769, 809, 13, 51, 
				               813, 970, 632, 357, 787, 717, 254, 645, 352, 636, 370, 950, 917, 959, 364, 453, 890, 43, 98, 438, 
				               748, 277, 115, 298, 431, 709, 312, 49, 553, 395, 798, 58, 419, 355, 770, 818, 460, 89, 880, 515, 
				               952, 219, 608, 284, 532, 254, 361, 524, 199, 265, 407, 782, 737, 928, 977, 729, 510, 175, 609, 81, 
				               155, 24, 425, 186, 999, 839, 896, 721};
				int time = 150;
				_expected = 43325;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}
			/*case 6:
			{
				int height[] = ;
				int add[] = ;
				int device[] = ;
				int time = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}*/
			/*case 7:
			{
				int height[] = ;
				int add[] = ;
				int device[] = ;
				int time = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
			}*/
			/*case 8:
			{
				int height[] = ;
				int add[] = ;
				int device[] = ;
				int time = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int)), vector <int>(device, device+sizeof(device)/sizeof(int)), time); break;
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
