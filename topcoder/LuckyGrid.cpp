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
const ll MAXNN=68+2;
const ll MAXF=3*68*68+2;
ll ac[MAXNN], bc[MAXNN];
ll at[MAXNN], bt[MAXNN];
ll ah[MAXNN],bh[MAXNN];
vector<vector<ll> > a,b;
vector<string> ggrid;


/* Mincost maxflow */
typedef long long ll;
typedef pair<int,int> pii;

const ll maxnodes = 68*2+4+2;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
  int to, f, cap, cost, rev, extra_data;
};

vector<Edge> graph[maxnodes];

void add_edge(int s, int t, int cap, int cost, int extra_data) {
  Edge a = {t, 0, cap, cost, graph[t].size(),extra_data};
  Edge b = {s, 0, 0, -cost, graph[s].size(),(int)UNDEF};
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

pii minCostFlow(int s, int t, int maxf) {
// bellmanFord can be safely commented if edges costs are non-negative
  //bellmanFord(s, pot);
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



bool islucky(ll x) {
	while(x>0) {
		ll d=x%10;
		if (d!=4&&d!=7) return false;
		x/=10;
	}
	return true;
}

ll solveeasy(ll n) {
	ll nv = 2*n+2;
	nodes=nv;
	for (ll v = 0; v < nodes; v++) {
		graph[v].clear();
	}
	ll src=2*n;
	ll target=2*n+1;
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<n;y++) {
			if (ggrid[x][y]=='.') {
				add_edge(x,y+n,1,0,UNDEF);
			}
		}
	}
	for (ll x=0;x<n;x++) {
		add_edge(src,x,a[x][0],0,a[x][0]);
		if (a[x].size()>1) {
			assert(a[x].size()==2);
			assert(a[x][1]-a[x][0]==1);
			add_edge(src,x,a[x][1]-a[x][0],1,UNDEF);
		}
	}
	for (ll y=0;y<n;y++) {
		add_edge(y+n,target,b[y][0],0,b[y][0]);
		if (b[y].size()>1) {
			assert(b[y].size()==2);
			assert(b[y][1]-b[y][0]==1);
			add_edge(y+n,target,b[y][1]-b[y][0],1,UNDEF);
		}
	}
	pii ret = minCostFlow(src, target, INT_MAX);
	for (ll v=0;v<nodes;v++) {
		for (auto e: graph[v]) {
			if (e.extra_data!=UNDEF&&e.extra_data != e.f) {
				return UNDEF;
			}
		}
	}
	return ret.first;
}

ll solvehard(ll n, ll amask, ll bmask) {
	ll nv = 2*n+2;
	nodes=nv;
	for (ll v = 0; v < nodes; v++) {
		graph[v].clear();
	}
	ll src=2*n;
	ll target=2*n+1;
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<n;y++) {
			if (ggrid[x][y]=='.') {
				add_edge(x,y+n,1,0,UNDEF);
			}
		}
	}
	for (ll x=0;x<n;x++) {
		ll idx=0;
		if ((amask>>x)&1) {
			while(idx<a[x].size()-1) {
				idx++;
				if (a[x][idx]-a[x][idx-1]==9) break;
			}
			assert(a[x][idx]-a[x][idx-1]==9);
		}
		add_edge(src,x,a[x][idx],0,a[x][idx]);
		if (idx<a[x].size()-1 && a[x][idx+1]-a[x][idx]==1) {
			assert(a[x][idx+1]-a[x][idx]==1);
			add_edge(src,x,a[x][idx+1]-a[x][idx],1,UNDEF);
		}
	}
	for (ll y=0;y<n;y++) {
		ll idx=0;
		if ((bmask>>y)&1) {
			while(idx<b[y].size()-1) {
				idx++;
				if (b[y][idx]-b[y][idx-1]==9) break;
			}
			assert(b[y][idx]-b[y][idx-1]==9);
		}
		add_edge(y+n,target,b[y][idx],0,b[y][idx]);
		if (idx<b[y].size()-1 && b[y][idx+1]-b[y][idx]==1) {
			assert(b[y][idx+1]-b[y][idx]==1);
			add_edge(y+n,target,b[y][idx+1]-b[y][idx],1,UNDEF);
		}
	}
	pii ret = minCostFlow(src, target,INT_MAX);
	for (ll v=0;v<nodes;v++) {
		for (auto e: graph[v]) {
			if (e.extra_data!=UNDEF&&e.extra_data != e.f) {
				return UNDEF;
			}
		}
	}
	return ret.first;
}


class LuckyGrid {
	public:
	int findMinimumSum(vector <string> grid) {
		ggrid=grid;
		ll n=grid.size();
		for (ll x=0;x<n;x++) {ac[x]=0;bc[x]=0;at[x]=0;bt[x]=0;}
		ll base=0,dots=0;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				if (grid[x][y]=='4') {
					ac[x]+=4;
					bc[y]+=4;
					base+=4;
				}
				else {
					ac[x]+=7;
					bc[y]+=7;
					base+=7;
				}
				if (grid[x][y]=='.') {
					at[x]++;
					bt[y]++;
					dots++;
				}
			}
		}
		bool hard=false;
		for (ll x=0;x<n;x++) {
			ll v=ac[x];
			vector<ll> tmp;
			for (ll k=0;k<=at[x];k++) {
				if (islucky(v)) {
					tmp.PB(k);
				}
				v-=3;
			}
			a.PB(tmp);
			if(tmp.size()==0) return -1;
		}
		for (ll x=0;x<n;x++) {
			ll v=bc[x];
			vector<ll> tmp;
			for (ll k=0;k<=bt[x];k++) {
				if (islucky(v)) {
					tmp.PB(k);
				}
				v-=3;
			}
			b.PB(tmp);
			if(tmp.size()==0) return -1;
		}

		for (ll x=0;x<n;x++) {
			ah[x]=false;bh[x]=false;
			for (ll i=0;i<a[x].size()-1;i++) {
				if (a[x][i+1]-a[x][i]==9) {ah[x]=true;hard=true;}
			}
			for (ll i=0;i<b[x].size()-1;i++) {
				//if(x==8) printf("DBG:%lld %lld\n",b[x][i+1],b[x][i]);
				if (b[x][i+1]-b[x][i]==9) {bh[x]=true;hard=true;}
			}
		}
		if (!hard) {
			ll flow = solveeasy(n);
			if (flow==UNDEF) return -1;
			return base-flow*3;
		}
		else {
			ll lim=1ULL<<n;
			vector<ll> am,bm;
			for (ll z=0;z<lim;z++) {
				{
					bool good=true;
					for (ll x=0;x<n;x++) {
						if (((z>>x)&1)&&!ah[x]) {
							good=false;break;
						}
					}
					if(good)am.PB(z);
				}
				{
					bool good=true;
					for (ll x=0;x<n;x++) {
						if (((z>>x)&1)&&!bh[x]) {
							good=false;break;
						}
					}
					if(good)bm.PB(z);
				}
			}
			ll ans=INF;
			for (auto&amask:am) {
				for (auto&bmask:bm) {
					ll flow = solvehard(n,amask,bmask);
					if (flow!=UNDEF) ans=min(ans,base-flow*3);
				}
			}
			if (ans>=INF) return -1;
			return ans;
		}
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
		cout << "Testing LuckyGrid (700.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456464108;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 700.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LuckyGrid _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"."};
				_expected = 4;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"7"};
				_expected = 7;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"........",
				                 "........",
				                 "........",
				                 "........",
				                 "........",
				                 "........",
				                 "........",
				                 "........"};
				_expected = 352;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".4.",
				                 "7.7",
				                 "4.."};
				_expected = -1;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"774777..",
				                 "..4.....",
				                 "..7774..",
				                 "..7..7..",
				                 "..7..7..",
				                 "..7..74.",
				                 "..4..4..",
				                 "........"};
				_expected = 355;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 5:
			{
				string grid[] = {".44.....7..",
				                 ".44........",
				                 "...........",
				                 "...........",
				                 ".7.........",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "..........."};
				_expected = 490;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 6:
			{
				string grid[] = {".4......7..",
				                 "...........",
				                 ".....7.....",
				                 "...........",
				                 ".7......7..",
				                 "...........",
				                 ".....4.....",
				                 "...........",
				                 "........4..",
				                 "...........",
				                 "..........."};
				_expected = 814;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 7:
			{
				string grid[] = {"..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 ".............477747774....77777.....477774........................",
				                 ".................4.......4.........4......4.......................",
				                 ".................4......4.........4........4......................",
				                 ".................7......7.........7........7......................",
				                 ".................4......4.........4........4......................",
				                 ".................4.......4.........4......4.......................",
				                 ".................7........77777.....777777........................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................", 
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 "..................................................................",
				                 ".................................................................."};
				_expected = 29304;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 8:
			{
				string grid[] = {"4"};
				_expected = 4;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 9:
			{
				string grid[] = {"..",".."};
				_expected = -1;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 10:
			{
				string grid[] = {
					"47....4....",
					"4...4......",
					"...4.74....",
					"....744.4..",
					"...........",
					"4.....7....",
					"...4.......",
					".......7...",
					"...4.......",
					"...7..44...",
					".7........."};
				_expected = -1;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 9:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.findMinimumSum(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
