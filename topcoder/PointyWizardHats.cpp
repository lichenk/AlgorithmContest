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

const ll MAXN=50*50+10;

struct edge {
	ll a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
Run dinic_reclear AFTER each run
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[MAXN];
void dinic_reclear() {
	dinic_edge.clear();
	for (ll i=0;i<dinic_numnodes;i++) dinic_graph[i].clear();
}
void add_edge (ll a, ll b, ll cap) {
	//printf("Add edge: %lld %lld\n",a,b);
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
class PointyWizardHats {
	public:
	int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
		ll n=topHeight.size();
		ll m=bottomHeight.size();
		ll src=250+1;
		ll dest=250+2;
		dinic_numnodes=dest+1;
		dinic_src=src;
		dinic_dest=dest;
		for (ll i=0;i<n;i++) add_edge(src,i,1);
		for (ll j=0;j<m;j++) add_edge(j+50,dest,1);
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<m;j++) {
				ll xr=topRadius[i],xh=topHeight[i];
				ll yr=bottomRadius[j],yh=bottomHeight[j];
				if (xr<yr&&(xr*yh)<(yr*xh)) {
					//printf("%lld->%lld\n",i,j);
					add_edge(i, j+50, 1);
				}
			}
		}
		ll fl=dinic();
		return fl;
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
		cout << "Testing PointyWizardHats (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470001658;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PointyWizardHats _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int topHeight[] = {30};
				int topRadius[] = {3};
				int bottomHeight[] = {3};
				int bottomRadius[] = {30};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 1:
			{
				int topHeight[] = {4,4};
				int topRadius[] = {4,3};
				int bottomHeight[] = {5,12};
				int bottomRadius[] = {5,4};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 2:
			{
				int topHeight[] = {3};
				int topRadius[] = {3};
				int bottomHeight[] = {1,1};
				int bottomRadius[] = {2,4};
				_expected = 1;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 3:
			{
				int topHeight[] = {10,10};
				int topRadius[] = {2,5};
				int bottomHeight[] = {2,9};
				int bottomRadius[] = {3,6};
				_expected = 2;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 4:
			{
				int topHeight[] = {3,4,5};
				int topRadius[] = {5,4,3};
				int bottomHeight[] = {3,4,5};
				int bottomRadius[] = {3,8,5};
				_expected = 2;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 5:
			{
				int topHeight[] = {1,2,3,4,5};
				int topRadius[] = {2,3,4,5,6};
				int bottomHeight[] = {2,3,4,5,6};
				int bottomRadius[] = {1,2,3,4,5};
				_expected = 0;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 6:
			{
				int topHeight[] = {123,214,232,323,342,343};
				int topRadius[] = {123,123,232,123,323,434};
				int bottomHeight[] = {545,322,123,545,777,999};
				int bottomRadius[] = {323,443,123,656,767,888};
				_expected = 5;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			case 7:
			{
				int topHeight[] = {999,999,999,10000,10000,10000};
				int topRadius[] = {10000,10000,10000,1,2,3};
				int bottomHeight[] = {2324,2323,234,5454,323,232};
				int bottomRadius[] = {1,2,3222,434,5454,23};
				_expected = 3;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}
			/*case 8:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int topHeight[] = ;
				int topRadius[] = ;
				int bottomHeight[] = ;
				int bottomRadius[] = ;
				_expected = ;
				_received = _obj.getNumHats(vector <int>(topHeight, topHeight+sizeof(topHeight)/sizeof(int)), vector <int>(topRadius, topRadius+sizeof(topRadius)/sizeof(int)), vector <int>(bottomHeight, bottomHeight+sizeof(bottomHeight)/sizeof(int)), vector <int>(bottomRadius, bottomRadius+sizeof(bottomRadius)/sizeof(int))); break;
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
