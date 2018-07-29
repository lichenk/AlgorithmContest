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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=2e5+2;
  // Hopcroft Karp Bipartite Matching
	const int MAX_N = mn, MAX_M = mn;
	int karp_n, karp_m;
	vector<int> graph[MAX_N];
	int match[MAX_N];

	int matched[MAX_M], depth[MAX_N], q[MAX_N];
	int v[MAX_N], vcnt;
	bool BFS(){
		int t = 0;
		for(int i = 0; i < karp_n; i++)
			if (match[i] == -1) depth[i] = 0, q[t++] = i;
			else depth[i] = -1;
		for(int h = 0; h < t; h++) {
			int cur = q[h];
			int curDepth = depth[cur];
			for(int i = 0; i < graph[cur].size(); i++) {
				int adj = graph[cur][i];
				if (matched[adj] == -1)
					return true;
				int next = matched[adj];
				if (depth[next] != -1) continue;
				depth[next] = curDepth + 1, q[t++] = next;
			}
		}
		return false;
	}

	bool DFS(int nod) {
		v[nod] = vcnt;
		for(int i = 0; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
				continue;
			if (next == -1 || DFS(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return true;
			}
		}
		return false;
	}

	int Match()
	{
		memset(match, -1, sizeof(match));
		memset(matched, -1, sizeof(matched));
		int ans = 0;
		while(BFS()) {
			++vcnt;
			for(int i = 0; i < karp_n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}

bool vans[mn];
bool done[mn];
bool sat[mn];
vector<int> orig[mn];
vector<int> vout[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int numv,numc; scanf("%d%d",&numc,&numv);
	for (int c=1;c<=numc;c++) {
		int k; scanf("%d",&k);
		for (int j=0;j<k;j++) {
			int v; scanf("%d",&v);
			orig[c].PB(v);
			vout[abs(v)].PB((v>0)?c:-c);
		}
	}
	for (int v=1;v<=numv;v++) {
		if (vout[v].size()==1) {
			int c=vout[v][0];
			sat[abs(c)]=1;
			vans[v]=(c>0);
			done[v]=1;
		}
		else if (vout[v].size()==2) {
			int cx=vout[v][0],cy=vout[v][1];
			if (cx>0&&cy>0) {
				sat[cx]=1; sat[cy]=1;
				vans[v]=1;
				done[v]=1;
			}
			else if (cx<0&&cy<0) {
				sat[cx]=1; sat[cy]=1;
				vans[v]=0;
				done[v]=1;
			}
		}
	}
	for (int c=1;c<=numc;c++) {
		bool ok=false;
		for (auto &v:orig[c]) {
			if (!done[abs(v)]) continue;
			if (v<0&&!vans[abs(v)]) {
				ok=true;
			}
			if (v>0&&vans[abs(v)]) {
				ok=true;
			}
		}
		if (ok) sat[c]=true;
	}
	for (int v=1;v<=numv;v++) {
		if (vout[v].size()==2) {
			int cx=vout[v][0],cy=vout[v][1];
			if (cx>0&&cy>0) {
			}
			else if (cx<0&&cy<0) {
			}
			else {
				if (!sat[abs(cx)]) {
					graph[v].PB(abs(cx));
					//printf("v:%d cx:%d\n",v,abs(cx));
				}
				if (!sat[abs(cy)]) {
					graph[v].PB(abs(cy));
					//printf("v:%d cy:%d\n",v,abs(cy));
				}
			}
		}
	}
	int needflow=0;
	karp_n=numv+1; karp_m=numc+1;
	for (int c=1;c<=numc;c++) if (!sat[c]) needflow++;
	int flow=Match();
	//printf("need:%d flow:%d\n",needflow,flow);
	if (flow==needflow) {
		printf("YES\n");
		for (int v=1;v<=numv;v++) {
			int got=match[v];
			if (got==-1) continue;
			for (auto &w:vout[v]) {
				if (got==w) vans[v]=1;
			}
		}
		for (int c=1;c<=numc;c++) {
			bool ok=false;
			for (auto &v:orig[c]) {
				if (v<0&&!vans[abs(v)]) {
					ok=true;
				}
				if (v>0&&vans[abs(v)]) {
					ok=true;
				}
			}
			if (!ok) assert(0);
		}
		for (int v=1;v<=numv;v++) {
			printf("%d",vans[v]?1:0);
		}
		printf("\n");
	}
	else {
		printf("NO\n");
	}

}