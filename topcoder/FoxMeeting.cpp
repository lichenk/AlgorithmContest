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

const ll MAXN=50+50+2;

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

vector<pair<ll,ll> > g[50];
pair<ll,ll> gr[50][50];
void makegr(ll x, ll p, ll k) {
	for (auto &vv:g[x]) {
		ll w=vv.first,c=vv.second;
		if(w==p) continue;
		gr[k][w]=MP(x,c);
		makegr(w,x,k);
	}
}
vector<ll> reachans;
void reach(ll x, ll p, ll cost) {
	if (cost>=0) reachans.PB(x);
	for (auto &vv:g[x]) {
		ll w=vv.first,c=vv.second;
		if(w==p) continue;
		reach(w,x,cost-c);
	}
}
bool need[50];
class FoxMeeting {
	public:
	int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes) {
		ll n=A.size()+1;
		for (ll i=0;i<n-1;i++) {
			A[i]--;B[i]--;
		}
		for (ll i=0;i<foxes.size();i++) {foxes[i]--;}
		for (ll i=0;i<n-1;i++) {
			ll x=A[i],y=B[i],c=L[i];
			g[x].PB(MP(y,c));
			g[y].PB(MP(x,c));
		}
		for (ll r=0;r<n;r++) {
			makegr(r,-1,r);
		}
		ll imin=0,imax=50*100000+1;
		while(imin<imax) {
			ll imid=(imin+imax)/2;
			bool ok=false;
			for (ll r=0;r<n;r++) {
				//printf("r: %lld imid:%lld\n",r,imid);
				for (ll v=0;v<n;v++) need[v]=false;
				for (auto fox:foxes) {
					ll sum=0;
					ll v=fox;
					while(v!=r) {
						sum+=gr[r][v].second;
						if (sum>imid) break;
						v=gr[r][v].first;
					}
					//printf("fox: %lld needing: %lld\n",fox,v);
					need[v]=true;
					while (v!=r) {
						v=gr[r][v].first;
						//printf("fox: %lld needing: %lld\n",fox,v);
						need[v]=true;
					}
				}
				ll src=100,target=101;
				for (auto fox:foxes) {
					reachans.clear();
					reach(fox,-1,imid);
					for (auto &w:reachans) {
						add_edge(fox,50+w,1);
					}
					add_edge(src,fox,1);
				}
				ll needcnt=0;
				for (ll v=0;v<n;v++) {
					if (need[v]) {add_edge(50+v,target,1); needcnt++;}
				}
				dinic_numnodes=102;
				dinic_src=src;
				dinic_dest=target;
				ll flow=dinic();
				dinic_reclear();
				if (flow==needcnt) {
					ok=true; break;
				}
			}
			if (!ok) {
				imin=imid+1;
			}
			else imax=imid;
		}
		return imin;
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
		cout << "Testing FoxMeeting (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463334590;
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
		FoxMeeting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int B[] = {2};
				int L[] = {5};
				int foxes[] = {1, 2};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1, 2};
				int B[] = {2, 3};
				int L[] = {1, 1};
				int foxes[] = {1, 3};
				_expected = 1;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1, 2};
				int B[] = {2, 3};
				int L[] = {1, 1};
				int foxes[] = {1, 2, 3};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {10,8,3,7,2,6,9,1,4};
				int B[] = {5,5,8,10,5,5,6,10,3};
				int L[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216};
				int foxes[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23};
				int B[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25};
				int L[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838};
				int foxes[] = {3,5,7,9,10,14,17,19,20,21,24,25,28};
				_expected = 107013;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41};
				int B[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6};
				int L[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
				          90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
				          40718,2115,79278,88841,40966,42023};
				int foxes[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50};
				_expected = 89342;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
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
