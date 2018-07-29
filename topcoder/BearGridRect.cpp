#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> pii;

const int maxnodes = 2000;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
	int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void add_edge(int s, int t, int cap, int cost) {
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

bool inr(ll x, ll r) {
	return r<=x&&x<r+50;
}
bool fr[50][50];
class BearGridRect {
	public:
	vector <int> findPermutation(int N, vector <int> r1, vector <int> r2, vector <int> c1, vector <int> c2, vector <int> cnt) {
		vector<int> fail={-1};
		ll numb= r1.size();
		for (ll i=0;i<N;i++) {
			for (ll j=0;j<N;j++) {
				fr[i][j]=true;
			}
		}
		for (ll b=0;b<numb;b++) {
			for (ll r=r1[b];r<=r2[b];r++) {
				for (ll c=c1[b];c<=c2[b];c++) {
					fr[r][c]=false;
				}
			}
		}
			const ll src=201;
			const ll dest=202;
			const ll ROFF=0;
			const ll COLOFF=50;
			const ll BS=100;
			const ll BE=150;
			for (ll r=0;r<N;r++) {
				add_edge(src,r+ROFF,1,0);
			}
			for (ll c=0;c<N;c++) {
				add_edge(c+COLOFF,dest,1,0);
			}
			for (ll b=0;b<numb;b++) {
				for (ll r=r1[b];r<=r2[b];r++) {
					add_edge(r+ROFF,b+BS,1,0);
				}
				for (ll c=c1[b];c<=c2[b];c++) {
					add_edge(b+BE,c+COLOFF,1,0);
				}
				add_edge(b+BS,b+BE,cnt[b],0);
			}
			for (ll r=0;r<N;r++) {
				for (ll c=0;c<N;c++) {
					if (fr[r][c]) {
						add_edge(r+ROFF,c+COLOFF,1,1);
					}
				}
			}
			pii res = minCostFlow(src, dest, INT_MAX);
			ll left=N;
			for (ll b=0;b<numb;b++) {
				left-=cnt[b];
			}
			//printf("Flow: %d Cost:%d\n",res.first,res.second);
			if (res.first<N||res.second>left) return fail;
			vector<int> ans(N,-1);
			vector<ll> br[50],bc[50];
			for (ll a=0;a<maxnodes;a++) {
				for (auto &w:graph[a]) {
					if (w.f==1) {
						ll b=w.to;
						//printf("%d to %d\n",a,b);
						if (inr(a,ROFF)&&inr(b,COLOFF)) {
							ans[a-ROFF]=b-COLOFF;
						}
						else if (inr(a,ROFF)&&inr(b,BS)) {
							br[b-BS].PB(a-ROFF);
						}
						else if (inr(a,BE)&&inr(b,COLOFF)) {
							bc[a-BE].PB(b-COLOFF);
						}
					}
				}
			}
			for (ll b=0;b<numb;b++) {
				assert (bc[b].size()==br[b].size());
				ll need=cnt[b];
				assert(bc[b].size()==need);
				for (ll i=0;i<need;i++) {
					ans[br[b][i]]=bc[b][i];
				}
			}
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
		cout << "Testing BearGridRect (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466270656;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearGridRect _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int r1[] = {4, 0};
				int r2[] = {4, 1};
				int c1[] = {2, 1};
				int c2[] = {4, 2};
				int cnt[] = {0, 2};
				int __expected[] = {1, 2, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int r1[] = {4, 0, 2};
				int r2[] = {4, 1, 2};
				int c1[] = {2, 1, 2};
				int c2[] = {4, 2, 2};
				int cnt[] = {0, 2, 1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int r1[] = {0};
				int r2[] = {2};
				int c1[] = {0};
				int c2[] = {2};
				int cnt[] = {0};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 4;
				int r1[] = {0};
				int r2[] = {0};
				int c1[] = {0};
				int c2[] = {0};
				int cnt[] = {0};
				int __expected[] = {1, 0, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 2;
				int r1[] = {0, 0, 1, 1};
				int r2[] = {0, 0, 1, 1};
				int c1[] = {0, 1, 0, 1};
				int c2[] = {0, 1, 0, 1};
				int cnt[] = {0, 1, 1, 0};
				int __expected[] = {1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 2;
				int r1[] = {0, 0, 1, 1};
				int r2[] = {0, 0, 1, 1};
				int c1[] = {0, 1, 0, 1};
				int c2[] = {0, 1, 0, 1};
				int cnt[] = {0, 1, 0, 1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 2;
				int r1[] = {0, 0, 1, 1};
				int r2[] = {0, 0, 1, 1};
				int c1[] = {0, 1, 0, 1};
				int c2[] = {0, 1, 0, 1};
				int cnt[] = {1, 1, 1, 1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 7:
			{
				int N = 6;
				int r1[] = {0, 0, 4};
				int r2[] = {2, 3, 5};
				int c1[] = {0, 5, 1};
				int c2[] = {4, 5, 5};
				int cnt[] = {3, 1, 1};
				int __expected[] = {1, 2, 4, 5, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 8:
			{
				int N = 3;
				int r1[] = {0};
				int r2[] = {0};
				int c1[] = {0};
				int c2[] = {0};
				int cnt[] = {2};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 9:
			{
				int N = 42;
				int r1[] = {25, 13, 23, 31, 4, 7, 18, 2, 1, 20};
				int r2[] = {30, 19, 24, 40, 12, 12, 19, 10, 18, 22};
				int c1[] = {7, 19, 1, 5, 32, 1, 3, 21, 13, 3};
				int c2[] = {35, 25, 24, 38, 40, 11, 12, 31, 17, 32};
				int cnt[] = {3, 0, 1, 8, 1, 0, 1, 2, 2, 3};
				int __expected[] = {34, 16, 35, 21, 32, 17, 2, 20, 0, 41, 22, 23, 24, 26, 27, 28, 29, 30, 3, 31, 4, 18, 19, 1, 25, 7, 8, 9, 36, 37, 38, 5, 6, 10, 11, 12, 13, 14, 15, 39, 40, 33};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			/*case 10:
			{
				int N = ;
				int r1[] = ;
				int r2[] = ;
				int c1[] = ;
				int c2[] = ;
				int cnt[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}*/
			/*case 11:
			{
				int N = ;
				int r1[] = ;
				int r2[] = ;
				int c1[] = ;
				int c2[] = ;
				int cnt[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findPermutation(N, vector <int>(r1, r1+sizeof(r1)/sizeof(int)), vector <int>(r2, r2+sizeof(r2)/sizeof(int)), vector <int>(c1, c1+sizeof(c1)/sizeof(int)), vector <int>(c2, c2+sizeof(c2)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
