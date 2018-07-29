#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int MAX_EDGES=mn;
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
	void add_edge_helper(ll x, ll y) {
		from[gid]=x; to[gid]=y;
		gnext[gid]=head[x];
		head[x]=gid;
		gid++;
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

ll dfsdown(ll e, ll possiblyHasBad) {
	ll dpval=dpedge[e][possiblyHasBad];
	if (dpval!=-1) return dpval;
	ll p=get_src(e);
	ll x=get_dest(e);
	ll ansdown=1;
	ll id=get_first_edge(x);
	while(id!=-1) {
		ll y=get_dest(id);
		if (y!=p) {
			ll yans=0;
			if (!possiblyHasBad) {
				yans+=dfsdown(id,0);
			}
			else {
				yans+=dfsdown(id,0) + dfsdown(id,1);
			}
			ansdown=mul(ansdown, yans);
		}
		id=get_next_edge_by_id(id);
	}
	return dpedge[e][possiblyHasBad]=ansdown;
}

ll vtxValue(ll x) {
	assert(dpvtx[x]!=-1);
	return dpvtx[x];
}

ll edgeValue(ll e, ll possiblyHasBad) {
	ll dpval=dpedge[e][possiblyHasBad];
	if(dpval!=-1) return dpval;
	ll p=get_src(e);
	ll x=get_dest(e);
	ll xVal=vtxValue(x);
	ll reverseEdgeValue=edgeValue(g.get_opposite_edge(e));
	ll ans=mul(xVal,mod_inv(reverseEdgeValue));
	return dpedge[e][possiblyHasBad]=ans;
}

void dfsup(ll e) {
	ll p=get_src(e);
	ll x=get_dest(e);
	for (ll possiblyHasBad=0;possiblyHasBad<2;possiblyHasBad++) {
		if (possiblyHasBad==0) {
			dpvtx[x][0]=mul(edgeValue(e, 0), edgeValue(g.get_opposite_edge(e), 0));
		}
		else {
			dpvtx[x][1]
		}
	}
	ll id=get_first_edge(x);
	while(id!=-1) {
		dfsup(id);
		id=get_next_edge_by_id(id);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	g.init();
	for (ll i=2;i<=n;i++) {
		scanf("%d",&p);
		g.add_edge(i,p[i]);
	}

}

