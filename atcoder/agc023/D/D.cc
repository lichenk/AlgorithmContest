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

void solve(long long N, long long S, vector<long long> X, vector<long long> P){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long S;
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	vector<long long> P(N-1+1);
	scanf("%lld",&S);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
		scanf("%lld",&P[i]);
	}
	solve(N, S, X, P);
	return 0;
}

