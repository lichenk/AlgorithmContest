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
bitset<mn> seen;
vector<int> g[mn];
void dfs(int x) {
	if (seen[x]) return;
	seen[x]=true;
	for (auto &y:g[x]) {
		dfs(y);
	}
}
void solve(long long N, long long M, vector<long long> A){
	sort(A.begin(),A.end());
	if (A.size()==1) {
		printf("%lld\n",A[0]);
		vector<int> vans;
		if (A[0]%2) {
			for (int i = 0; i < A[0] / 2; i++) {
				vans.PB(2);
			}
			vans.PB(1);
		}
		else {
			int g=A[0]/2;
			if (g%2) {
				for (int k=0;k<2;k++) {
					for (int i = 0; i < g / 2; i++) {
						vans.PB(2);
					}
					vans.PB(1);
				}
			}
			else {
				for (int i = 0; i < g / 2; i++) {
					vans.PB(2);
				}
				vans.PB(1);
				for (int i = 0; i < (g / 2)-1; i++) {
					vans.PB(2);
				}
				vans.PB(1);
			}
		}
		printf("%d\n",(int)vans.size());
		int sum=0;
		for (auto &w:vans) {
			printf("%d ",w);
			sum+=w;
		}
		assert(sum==N);
		printf("\n");
	}
	else {
		int base=0;
		for (auto &w:A) {
			for (int x=base;x<base+w;x++) {
				int y=base+w-1-(x-base);
				if (x<y) {
					g[x].PB(y);
					g[y].PB(x);
				}
			}
		}
		for (int x=0;x<N;x++) {
			int y=N-1-x;
			if (x<y) {
				g[x].PB(y);
				g[y].PB(x);
			}
		}
		dfs(0);
		if (seen.count()==N) {
			for (auto &w:A) printf("%lld ",w);
			printf("\n1\n%lld\n",N);
		}
		else {
			printf("Impossible\n");
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long M;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> A(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, M, A);
	return 0;
}

