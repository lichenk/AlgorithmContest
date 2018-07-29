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
typedef pair<int,int> pii;
void solve(int n, vector<long long> inp){
	vector<pii> v; for (int i=0;i<n;i++) v.PB(MP(inp[i],i));
	sort(v.begin(),v.end());
	vector<int> vans; vans.resize(n);
	for (int i=0;i<n/2;i++) {
		vans[v[i].snd]=v[n/2].fst;
	}
	for (int i=n/2;i<n;i++) {
		vans[v[i].snd]=v[n/2-1].fst;
	}
	for (int i=0;i<n;i++) printf("%d\n",vans[i]);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
	}
	solve(N, X);
	return 0;
}

