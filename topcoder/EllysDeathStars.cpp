#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAGIC=5e13;
const ll MAXN = 5000;
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
	////printf("%lld to %lld. flow:%f\n",a,b,cap/(ld)MAGIC);
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


inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
vector<ll> vd[22];
vector<ll> vs[22];

class EllysDeathStars {
	public:
	double getMax(vector <string> stars, vector <string> ships) {
		ll n=stars.size(),m=ships.size();
		for (ll x=0;x<n;x++) vd[x]=load(stars[x]);
		for (ll y=0;y<m;y++) vs[y]=load(ships[y]);
		ll src=n+m;
		ll dest=n+m+1;
		dinic_numnodes=dest+1;
		dinic_src=src;
		dinic_dest=dest;
		for (ll x=0;x<n;x++) {
			set<pair<ld,pair<ll,ll> > > h;
			ll xd=vd[x][0],yd=vd[x][1];
			for (ll y=0;y<m;y++) {
				if (vs[y][0]==vs[y][2]&&vs[y][1]==vs[y][3]) continue;
				ld sx=vs[y][0],sy=vs[y][1],ex=vs[y][2],ey=vs[y][3],s=vs[y][4],r=vs[y][5];
				ld dx=ex-sx,dy=ey-sy;
				ld norm=sqrt(dx*dx+dy*dy);
				ld vx=s*dx/norm;
				ld vy=s*dy/norm;
				////printf("s:%f norm:%f dy:%f vy:%f vx:%f\n",s,norm,dy,vy,vx);
				ld endtime=norm/s;
				ld a=vx;
				ld b=sx-xd;
				ld c=vy;
				ld d=sy-yd;
				ld A=(a*a+c*c);
				ld B=2*(a*b+c*d);
				ld C=b*b+d*d-r*r;
				ld det=B*B-4*A*C;
				////printf("x:%d y:%d det:%d\n",x,y,det);
				if (det<0) continue;
				ld start=(-B-sqrt(det))/(2*A);
				ld end=(-B+sqrt(det))/(2*A);
				ld zero=0;
				start=max(start,zero);
				end=min(end,endtime);
				if (end<start) continue;
				h.insert(MP(start,MP(y,-1)));
				h.insert(MP(end,MP(y,1)));
				//printf("x:%d y:%d start:%f end:%f. duration:%f\n",x,y,start,end,end-start);
			}
			ld prevt=0;
			set<ll> active;
			for (auto &w:h) {
				ld t=w.first;
				ll y=w.second.first;
				ll op=w.second.second;
					ld dt=t-prevt;
					////printf("t:%f y:%d op:%d\n",t,y,op);
					ll vtx=dinic_numnodes;
					dinic_numnodes++;
					ll approx=round(dt*MAGIC);
					//printf("x:%d prevt:%f t:%f dt:%f\n",x,prevt,t,dt);
					add_edge(x,vtx,approx);
					for (auto &got:active) {
						//printf("x:%d to y:%d with dt:%f\n",x,got,dt);
						add_edge(vtx,got+n,INF);
					}
				if (op==-1) active.insert(y);
				else active.erase(y);
				prevt=t;
			}
		}
		for (ll x=0;x<n;x++) {
			add_edge(src,x,INF);
		}
		for (ll y=0;y<m;y++) {
			ll e=vs[y][6];
			ll approx=e*MAGIC;
			add_edge(y+n,dest,approx);
		}
		ll ans=dinic();
		////printf("dinic got:%lld\n",ans);
		long double final=(long double)ans/(long double)MAGIC;
		return final;
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
		cout << "Testing EllysDeathStars (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471232711;
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
		EllysDeathStars _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string stars[] = {"2 2"};
				string ships[] = {"1 1 5 3 2 1 2"};
				_expected = 0.894427190999916;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 1:
			{
				string stars[] = {"12 10", "7 5"};
				string ships[] = {"10 10 12 10 1 1 3", "6 1 8 10 1 2 3", "3 6 8 2 5 3 1", "42 42 42 42 6 6 6"};
				_expected = 4.983770744659944;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 2:
			{
				string stars[] = {"5 77", "60 50", "10 46", "22 97", "87 69"};
				string ships[] = {"42 17 66 11 5 7 13", "10 10 20 20 3 3 3", "13 15 18 9 4 1 2",
				                  "99 71 63 81 19 4 60", "27 34 56 43 11 3 12"};
				_expected = 0.0;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 3:
			{
				string stars[] = {"141 393", "834 847", "568 43", "18 228", "515 794",
				                  "167 283", "849 333", "719 738", "434 261", "613 800",
				                  "127 340", "466 938", "598 601"};
				string ships[] = {"410 951 472 100 337 226 210", "713 352 677 908 731 687 300",
				                  "191 41 337 92 446 716 213", "598 889 446 907 148 650 203",
				                  "168 556 470 924 344 369 198", "300 182 350 936 737 533 45",
				                  "410 871 488 703 746 631 80", "270 777 636 539 172 103 56",
				                  "466 906 522 98 693 77 309", "768 698 846 110 14 643 14",
				                  "755 724 664 465 263 759 120"};
				_expected = 31.965770956316362;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 4:
			{
				string stars[] = {"0 0", "0 0"};
				string ships[] = {"0 0 0 1 1 1 1","0 0 0 1 1 1 1","0 0 0 1 1 1 1"};
				_expected = 2.0;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 5:
			{
				string stars[] = {"42 42"};
				string ships[] = {"40 40 41 41 2 7 42"};
				_expected = 0.7071067811865476;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 6:
			{
				string stars[] = {"8 7", "11 9"};
				string ships[] = {"11 14 8 10 92 3 3", "12 14 12 6 434 4 6"};
				_expected = 0.01583636715715995;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 7:
			{
				string stars[] = {"42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42", "42 42"};
				string ships[] = {"43 43 41 42 3 4 1", "41 42 41 42 4 3 1", "43 43 43 41 3 3 2", "41 41 43 43 2 4 3", "43 41 43 41 2 2 3", "41 43 43 42 4 2 2", "43 42 42 42 3 4 2", "43 41 42 41 3 1 1", "41 43 41 42 4 2 1", "43 42 41 41 5 2 1", "42 43 43 42 5 4 3", "41 41 43 43 1 1 3", "41 41 43 42 3 4 1", "41 42 42 43 1 3 3", "43 42 42 43 5 2 3", "41 41 41 42 1 1 1", "42 43 42 42 3 1 2", "42 42 43 41 5 5 3", "42 41 42 41 2 3 3", "43 41 43 41 5 4 3"};
				_expected = 22.666666666666643;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 8:
			{
				string stars[] = {"42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42"};
				string ships[] = {"43 43 41 42 3 4 1",
 "41 42 41 42 4 3 1",
 "43 43 43 41 3 3 2",
 "41 41 43 43 2 4 3",
 "43 41 43 41 2 2 3",
 "41 43 43 42 4 2 2",
 "43 42 42 42 3 4 2",
 "43 41 42 41 3 1 1",
 "41 43 41 42 4 2 1",
 "43 42 41 41 5 2 1"};
				_expected = 10.453559925;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 9:
			{
				string stars[] = {"42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42"};
				string ships[] = { "41 43 43 42 4 2 2",
 "43 42 42 42 3 4 2",
 "43 41 42 41 3 1 1",
 "41 43 41 42 4 2 1",
 "43 42 41 41 5 2 1"};
				_expected = 2.79508497187;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}
			case 10:
			{
				string stars[] = {"42 42",
 "42 42",
 "42 42",
 "42 42",
 "42 42"};
				string ships[] = {"43 43 41 42 3 4 1",
 "41 42 41 42 4 3 1",
 "43 43 43 41 3 3 2",
 "41 41 43 43 2 4 3",
 "43 41 43 41 2 2 3"};
				_expected = 6.0;
				_received = _obj.getMax(vector <string>(stars, stars+sizeof(stars)/sizeof(string)), vector <string>(ships, ships+sizeof(ships)/sizeof(string))); break;
			}

			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
