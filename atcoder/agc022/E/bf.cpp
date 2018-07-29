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
typedef vector<int> vi;
map<vector<int>, int> h;
int g(vi v) {
	auto it=h.find(v);
	if (it!=h.end()) return it->snd;
	int n=v.size();
	if (n==1) return h[v]=v[0];
	for (int x=1;x<n-1;x++) {
		int cnt=0;
		for (int y=x-1;y<=x+1;y++) cnt++;
		vi a;
		for (int i=0;i<x-1;i++) a.PB(v[i]);
		a.PB(cnt>=2?1:0);
		for (int i=x+2;i<n;i++) a.PB(v[i]);
		if (g(a)) return h[v]=1;
	}
	return h[v]=0;
}
int dp[21][1<<20];
int f(int n, int z) {
	if (dp[n][z]!=-1) return dp[n][z];
	assert(n>=1);
	if (n==1) {
		return dp[n][z]=z;
	}
	for (int x=1;x<n-1;x++) {
		int cnt=0;
		for (int y=x-1;y<=x+1;y++) if (z&(1<<y)) cnt++;
		int nz=0,idx=0;
		for (int y=0;y<x-1;y++) {
			if (z&(1<<y)) nz|=1<<idx;
			idx++;
		}
		if (cnt>=2) nz|=1<<idx;
		idx++;
		for (int y=x+2;y<n;y++) {
			if (z&(1<<y)) nz|=1<<idx;
			idx++;
		}
		if (f(n-2,nz)) return dp[n][z]=1;
	}
	return dp[n][z]=0;
}
int smart(int n, int z) {
	if (n==1) return z;
	if ((z&3)==3) return 1;
	if (((z<<(n-2))&3)==3) return 1;
	int cnt=0;
	for (int i=0;i<n;i++) {
		if (((z>>i)&3)==3) cnt++;
		if (cnt>=2) return 1;
	}
	return 0;
}
void go() {
	h.clear();
	//assert( g({1,1,1,0,0}));
	//assert( g({1,1,0,0,0}));
	//assert(!g({1,0,1,0,0}));
	//assert(!g({1,0,0,0,0}));
	//assert( g({1}));
	//assert(!g({0}));
	memset(dp,-1,sizeof dp);
	assert( f(5,0b11100));
	assert( f(5,0b11000));
	assert(!f(5,0b10100));
	assert(!f(5,0b10000));
	assert( f(1,0b1));
	assert(!f(1,0b0));
	for (int k=0;k<5000;k++) {
		int n=2*(rand()%5)+1; assert(n&1);
		int z=rand()&((1<<n)-1);
		vi v; for (int i=0;i<n;i++) v.PB((z>>i)&1);
		if(f(n,z)!=smart(n,z)) {
			printf("f:%d sm:%d n:%d z:%d\n",f(n,z),smart(n,z),n,z);
			for (auto &w:v) printf("%d ",w); printf("\n");
			exit(0);
		}
	}
}
void solve(long long N, long long L, vector<long long> x, vector<long long> t){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	go(); return 0;
	long long N;
	long long L;
	scanf("%lld",&N);
	vector<long long> t(N-1+1);
	vector<long long> x(N-1+1);
	scanf("%lld",&L);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&t[i]);
	}
	solve(N, L, x, t);
	return 0;
}

