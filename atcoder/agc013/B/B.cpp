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
const ll maxn=1e5+4;
vector<ll> g[maxn];
bool seen[maxn];

vector<ll> gres;
void dfs(ll x) {
	if (seen[x]) return;
	gres.PB(x);
	seen[x]=true;
	for (auto &y:g[x]) {
		if (!seen[y]) {
			dfs(y);
			break;
		}
	}
}

void solve(long long N, long long M, vector<long long> A, vector<long long> B){
	for (ll i=0;i<A.size();i++) {
		ll x=A[i],y=B[i];
		g[x].PB(y); g[y].PB(x);
	}
	memset(seen,0,sizeof seen);
	vector<ll> gans;
	ll x=1;
	{
		seen[x]=true;
		gres.clear();
		dfs(g[x][0]);
		reverse(gres.begin(),gres.end());
		for (auto &w:gres) gans.PB(w);
		gans.PB(x);
		gres.clear();
		for (auto &y:g[x]) {
			if (!seen[y]) {
				dfs(y);
				break;
			}
		}
		for (auto &w:gres) gans.PB(w);
	}
	printf("%lld\n",(ll)gans.size());
	for (auto &y:gans) {
		printf("%lld ",y);
	}
	printf("\n");
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long M;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> A(M-1+1);
	vector<long long> B(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
	}
	solve(N, M, A, B);
	return 0;
}

