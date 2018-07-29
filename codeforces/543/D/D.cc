#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll mod=1000000007LL;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll mod_pow(ll a, ll n) {
	long long ret = 1; long long p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret;
}
ll mod_inv(ll a) {assert(a!=0); return mod_pow(a,mod-2);}
inline ll mul(ll x,ll y) {
	return (((long long)x)*y)%mod;
}
const ll mn=2e5+4;
const int MAX_NODES=mn;
const int MAX_EDGES=mn;
const int FAKENODE=mn-1;
typedef struct graph_t {
	ll gid=0;
	ll from[2*MAX_EDGES];
	ll to[2*MAX_EDGES];
	ll gprev[2*MAX_EDGES];
	ll gnext[2*MAX_EDGES];
	ll head[2*MAX_EDGES];
	void init() { // MUST CALL INIT!!!!
		memset(head,-1,sizeof head);
		gid=0;
	}
	int add_edge_helper(ll x, ll y) {
		from[gid]=x; to[gid]=y;
		gnext[gid]=head[x];
		head[x]=gid;
		return gid++;
	}
	void add_edge(ll x, ll y) {
		add_edge_helper(x,y);
		add_edge_helper(y,x);
	}
	void rm_edge_by_id(ll id) {
		ll x=from[id];
		if (head[x]==id) {
			head[x]=gnext[id];
		}
		else {
			gnext[gprev[id]]=gnext[id];
			gprev[gnext[id]]=gprev[id];
		}
	}
	int get_first_edge(ll x) {
		return head[x];
	}
	int get_next_edge_by_id(ll id) {
		return gnext[id];
	}
	int get_src(ll id) {
		return from[id];
	}
	int get_dest(ll id) {
		return to[id];
	}
	int get_opposite_edge(ll id) {
		return id^1;
	}
} graph;
graph_t g;

ll dpedge[2*MAX_EDGES];
ll dpvtx[MAX_NODES];

void initdfs() {
	memset(dpedge,-1,sizeof dpedge);
	memset(dpvtx,-1,sizeof dpvtx);
}

ll dfsdown(ll e) {
	ll dpval=dpedge[e];
	if (dpval!=-1) return dpval;
	ll p=g.get_src(e);
	ll x=g.get_dest(e);
	ll ansdown=1;
	for (ll id=g.get_first_edge(x); id!=-1; id=g.get_next_edge_by_id(id)) {
		ll y=g.get_dest(id);
		if (y!=p) {
			ll yans= 1 + dfsdown(id);
			ansdown=mul(ansdown, yans);
		}
	}
	//if (p==1&&x==2) printf("A1->2:%d\n",ansdown);
	if (p==FAKENODE) return dpvtx[x]=ansdown;
	else return dpedge[e]=ansdown;
}

ll vtxValue(ll x) {
	ll dpval=dpvtx[x];
	assert(dpval!=-1);
	return dpval;
}

ll edgeValue(ll e) {
	ll dpval=dpedge[e];
	if(dpval!=-1) {
		return dpval;
	}
	ll p=g.get_src(e);
	ll x=g.get_dest(e);
	ll xVal=vtxValue(x);
	ll reverseEdgeValue= 1 + edgeValue(g.get_opposite_edge(e));
	ll ans= mul(xVal,mod_inv(reverseEdgeValue));
	return dpedge[e]=ans;
}

void dfsup(ll e) {
	ll p=g.get_src(e);
	ll x=g.get_dest(e);
	//printf("Process p:%d x:%d\n",p,x);
	if (p!=FAKENODE) {
		dpvtx[x]=mul(edgeValue(e), 1 + edgeValue(g.get_opposite_edge(e)));
	}
	for (ll id=g.get_first_edge(x); id!=-1; id=g.get_next_edge_by_id(id)) {
		ll y=g.get_dest(id);
		if (y!=p) {
			dfsup(id);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	g.init();
	for (ll i=2;i<=n;i++) {
		ll p; scanf("%d",&p);
		g.add_edge(i,p);
	}
	ll laste=g.add_edge_helper(FAKENODE,1);
	initdfs();
	dfsdown(laste);
	dfsup(laste);
	for (ll x=1;x<=n;x++) {
		printf("%d ",vtxValue(x));
	}
	printf("\n");
}

