#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


struct Dinic {
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
	ll dinic_numnodes, dinic_src, dinic_dest;
	ll *d, *ptr, *q;
	vector<edge> dinic_edge;
	vector<vector<ll> > dinic_graph;
	
	Dinic(int n) {
		dinic_graph.resize(n);
		d = new ll[n];
		ptr = new ll[n];
		q = new ll[n];
	}

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
	 
	ll flow(ll src, ll dest, ll numnodes) {
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
	void reset(ll numnodes) {
		dinic_edge.clear();
		for (ll v=0;v<numnodes;v++) dinic_graph[v].clear();	
	}
};
vector<string> str;
ll clim,rlim,m;
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
const ll mn=102;
ll dist1[mn][mn][mn];
bitset<mn> c2tid[mn][mn];
Dinic dinic=Dinic(2*100*100+2);
void dfs(ll ir, ll ic, ll dir, ll tid) {
	int r=ir,c=ic;
	if (!(0<=r&&r<rlim&&0<=c&&c<clim)||str[r][c]=='#') return;
	c2tid[ir][ic][tid]=true;
	dfs(ir+dx[dir],ic+dy[dir],dir,tid);
}
ll tidlim,sidlim;
void bfs(ll ir, ll ic, ll sid) {
	memset(dist1[sid],-1,sizeof dist1[sid]);
	queue<pll> q;
	q.push(MP(ir,ic));
	dist1[sid][ir][ic]=0;
	bitset<mn> bit;
	while(!q.empty()) {
		auto got=q.front(); q.pop();
		ll r=got.fst,c=got.snd;
		if (!(0<=r&&r<rlim&&0<=c&&c<clim)||str[r][c]=='#') continue;
		//printf("BFS: sid:%lld %lld %lld. dist:%lld\n",sid,r,c,dist[r][c]);
		bit|=c2tid[r][c];
		if (dist1[sid][r][c]<m) {
			for (ll k=0;k<4;k++) {
				ll nr=r+dx[k],nc=c+dy[k];
				if (dist[nr][nc]==-1) {
					dist1[sid][nr][nc]=dist1[sid][r][c]+1;
					q.push(MP(nr,nc));
				}
			}
		}
	}
	for (ll tid=0;tid<tidlim;tid++) {
		if (bit[tid]) {
			//printf("sid:%lld tid:%lld\n",sid,tid);
			dinic.add_edge(sid,tid,1);
		}
	}
}
bitset<mn> seen2[mn][mn];
ll sid2tid[mn],tid2sid[mn];
queue<ll> q[mn];
void init2(ll r, ll c, ll sid) {
	memset(dist2,-1,sizeof dist2);
	q[sid].push(MP(r,c));
	seen[sid][r][c]=true;
}
void bfs2(ll sid) {
	while(!q[sid].empty()) {
		auto got=q[sid].front(); q[sid].pop();
		for (ll k=0;k<4;k++) {
			ll nr=r+dx[k],nc=c+dy[k];
			if (dist[nr][nc]!=-1&&!seen2[sid][nr][nc]) {
				seen2[sid][nr][nc]=true;
				q[sid].push(MP(nr,nc));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		cin>>clim>>rlim>>m;
		str.clear();
		str.resize(rlim);
		for (ll r=0;r<rlim;r++) {
			cin>>str[r];
		}
		ll src=2*mn;
		ll dest=2*mn+1;
		ll nodes=dest+1;
		ll tid=0;
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				c2tid[r][c].reset();
			}
		}
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				if (str[r][c]=='T') {
					dinic.add_edge(tid,dest,1);
					for (ll dir=0;dir<4;dir++) dfs(r,c,dir,tid);
					tid++;
				}
			}
		}
		tidlim=tid;
		ll sid=tid;
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				char a=str[r][c];
				if (a=='S') {
					dinic.add_edge(src,sid,1);
					bfs(r,c,sid);
					sid++;
				}
			}
		}
		sidlim=sid-tid;
		ll fl=dinic.flow(src,dest,nodes);
		for (auto &edge: dinic.dinic_edge) {
			if (edge.a<sid&&edge.b<tid&&edge.flow==1) {
				//printf("a:%lld\n",edge.a);
				tid2sid[edge.a-tid]=edge.b;
				sid2tid[edge.b]=edge.a-tid;
			}
		}
		ll finalans=fl;
		printf("Case #%lld: %lld\n",testnum,finalans);
		dinic.reset(nodes);
	}
}

