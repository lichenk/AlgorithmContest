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
const int mn=1e5+4;
set<int> te[2*mn];
int segEdgeN;
void addedge(set<int> &s, int val, bool toadd) {
	if (toadd) s.insert(val);
	else s.erase(val);
}

void segModifyEdge(int l, int r, int value, bool toadd) {
  for (l += segEdgeN, r += segEdgeN; l < r; l >>= 1, r >>= 1) {
    if (l&1) addedge(te[l++], value, toadd);
    if (r&1) addedge(te[--r], value, toadd);
  }
}

set<int> segQueryEdge(int p) {
  set<int> res;
  for (p += segEdgeN; p > 0; p >>= 1) {
  	for (auto &w:te[p]) res.insert(w);
  }
  return res;
}

typedef struct STT {
	ll val;
	bool done;
	bool operator== (const STT &c1) {
   return (val == c1.val);
  }
	bool operator!= (const STT &c1) {
   return !(val == c1.val);
  }
} ST;
class SegmentTreeFast {
public:
	// Modify the following 5 methods to implement your custom operations on the tree.
	// This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
	ST modifyOperation(ST x, ST y) {
		ST ans;
		ans.done=x.done||y.done;
		if (!ans.done) ans.val=min(x.val, y.val);
		else ans.val=INF;
		return ans;
	}

	// query (or combine) operation
	ST queryOperation(ST leftValue, ST rightValue) {
		ST ans;
		ans.val=min(leftValue.val, rightValue.val);
		return ans;
	}

	ST deltaEffectOnSegment(ST delta, int segmentLength) {
		if (delta == getNeutralDelta()) return getNeutralDelta();
		// Here you must write a fast equivalent of following slow code:
		// int result = delta;
		// for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
		// return result;
		ST ans;
		ans.done=delta.done;
		if (!ans.done) ans.val=delta.val;
		else ans.val=INF;
		return ans;
	}

	ST getNeutralDelta() {
		ST ans;
		ans.val=INF;
		ans.done=false;
		return ans;
	}

	ST getInitValue(int i) {
		ST ans;
		ans.val=INF;
		ans.done=false;
		return ans;
	}

	ST getNeutralValue() {
		ST ans;
		ans.val=INF;
		ans.done=false;
		return ans;
	}

	// generic code
	ST *value;
	ST *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
	int gn;

	ST joinValueWithDelta(ST value, ST delta) {
		if (delta == getNeutralDelta()) return value;
		return modifyOperation(value, delta);
	}

	ST joinDeltas(ST delta1, ST delta2) {
		if (delta1 == getNeutralDelta()) return delta2;
		if (delta2 == getNeutralDelta()) return delta1;
		return modifyOperation(delta1, delta2);
	}

	void pushDelta(int i) {
		int d = 0;
		for (; (i >> d) > 0; d++) {
		}
		for (d -= 2; d >= 0; d--) {
			int x = i >> d;
			value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
			delta[x] = joinDeltas(delta[x], delta[x >> 1]);
			delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
			delta[x >> 1] = getNeutralDelta();
		}
	}

	SegmentTreeFast(int n) {
		gn=n;
		value = new ST[2 * n];
		for (int i = 0; i < n; i++) {
			value[i + n] = getInitValue(i);
		}
		for (int i = 2 * n - 1; i > 1; i -= 2) {
			value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
		}
		delta = new ST[2 * n];
		fill(delta, delta + (2*n), getNeutralDelta());
	}

	ST joinNodeValueWithDelta(int i, int len) {
		return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
	}

	ST query(int from, int to) {
		from += gn;
		to += gn;
		pushDelta(from);
		pushDelta(to);
		ST res = getNeutralValue();
		bool found = false;
		for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
			if ((from & 1) != 0) {
				res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
				found = true;
			}
			if ((to & 1) == 0) {
				res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
				found = true;
			}
		}
		if (!found) assert(0);
		return res;
	}

	void modify(int from, int to, ST delta) {
		from += gn;
		to += gn;
		pushDelta(from);
		pushDelta(to);
		int a = from;
		int b = to;
		for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
			if ((from & 1) != 0) {
				this->delta[from] = joinDeltas(this->delta[from], delta);
			}
			if ((to & 1) == 0) {
				this->delta[to] = joinDeltas(this->delta[to], delta);
			}
		}
		for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
			value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
		}
		for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
			value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
		}
	}
};

typedef struct edget {
	int sl,sr,tl,tr,w;
} edge;


vector<edge> ve;
int n;
ll vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q,s; scanf("%d%d%d",&n,&q,&s);
	segEdgeN=q;
	for (int i=0;i<q;i++) {
		int t; scanf("%d",&t);
		int sl,sr,tl,tr,w;
		if (t==1) {
			int v,u;
			scanf("%d%d%d",&v,&u,&w);
			sl=v,sr=v,tl=u,tr=u;
		}
		else {
			int v,l,r;
			scanf("%d%d%d%d",&v,&l,&r,&w);
			if (t==2) sl=v,sr=v,tl=l,tr=r;
			else sl=l,sr=r,tl=v,tr=v;
		}
		edge e={sl,sr,tl,tr,w};
		ve.PB(e);
		segModifyEdge(v,v,ve.size()-1,true);
	}
	memset(vans,-1,sizeof vans);
	SegmentTreeFast t = SegmentTreeFast(n+1);
	t.modify(s,s,{0ll,false});
	while(1) {
		ST get=t.query(1,n);
		ll dist=get.val.fst;
		int vtx=get.val.snd;
		if (dist==INF) break;
		t.modify(vtx,vtx,{INF,true});
		vans[vtx]=dist;
		set<int> &edgeIdxSet=segQueryEdge(vtx);
		for (auto &ei: edgeIdxSet) {
			edge e=ve[ei];
			segModifyEdge(e.sl,e.sr,ei,false);
			ll newdist=dist+e.w;
			t.modify(e.tl,e.tr,{newdist,false});
		}
	}


}

