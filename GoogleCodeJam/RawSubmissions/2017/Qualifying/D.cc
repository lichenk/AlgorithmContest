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


const ll MAXN = 808;
struct edge {
	ll a, b, cap, flow;
};
/*
Dinic's max flow algorithm adapted from http://e-maxx.ru/algo/dinic
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

const ll BASE=402;

const ll mn=404;
int g[2][2*mn][2*mn];
int line[2][2][2*mn];
int vans[mn][mn];
int orig[mn][mn];
const int STR=0,DIAG=1;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		ll n,m; cin>>n>>m;
		memset(g,0,sizeof g);
		memset(line,0,sizeof line);
		memset(vans,0,sizeof vans);
		memset(orig,0,sizeof orig);
		ll ans=0;
		for (ll i=0;i<m;i++) {
			char type; ll r,c;
			cin>>type>>r>>c;
			--r; --c;
			if (type=='o'||type=='x') {
				g[STR][r][c]=1;
				line[STR][0][r]=1;
				line[STR][1][c]=1;
				vans[r][c]|=1<<STR;
				ans++;
			}
			if (type=='o'||type=='+') {
				ll x=r+c,y=r-c+n-1;
				g[DIAG][x][y]=1;
				line[DIAG][0][x]=1;
				line[DIAG][1][y]=1;
				vans[r][c]|=1<<DIAG;
				ans++;
			}
			orig[r][c]=vans[r][c];
		}
		for (ll sd=0;sd<2;sd++) {
			dinic_clear(MAXN);
			ll lim;
			if (sd==STR) lim=n;
			else lim=2*n-1;
			for (ll r=0;r<n;r++) {
				for (ll c=0;c<n;c++) {
					ll x,y;
					if (sd==STR) {
						x=r; y=c;
					}
					else {
						x=r+c;
						y=r-c+n-1;
					}
					if (!line[sd][0][x]&&!line[sd][1][y]) {
						//if(sd==STR) printf("x:%d y:%d\n",x,y);
						add_edge(x,BASE+y,1);
					}
				}
			}
			ll src=MAXN-2,dest=MAXN-1;
			for (ll x=0;x<lim;x++) add_edge(src,x,1);
			for (ll y=0;y<lim;y++) add_edge(y+BASE,dest,1);
			ans+=dinic(src,dest,MAXN);
			for (auto &e:dinic_edge) {
				if (e.flow==1&&e.a!=src&&e.b!=dest) {
					ll x=e.a;
					ll y=e.b-BASE;
					ll r,c;
					if (sd==STR) {
						r=x; c=y;
					}
					else {
						r=(x+y-(n-1))/2;
						c=x-r;
					}
					vans[r][c]|=1<<sd;
				}
			}
		}
		vector<pair<pll,char> > vf;
		for (ll r=0;r<n;r++) for (ll c=0;c<n;c++) {
			ll got=vans[r][c];
			if (got!=0&&got!=orig[r][c]) {
				char ch;
				if (got==3) ch='o';
				else if (got==1<<STR) ch='x';
				else if (got==1<<DIAG) ch='+';
				else assert(0);
				vf.PB(MP(MP(r+1,c+1),ch));
			}
		}
		cout<<"Case #"<<testnum<<": "<<ans<<" "<<(ll)vf.size()<<endl;
		for (auto &w:vf) {
			cout<<w.snd<<" "<<w.fst.fst<<" "<<w.fst.snd<<endl;
		}
	}
}

