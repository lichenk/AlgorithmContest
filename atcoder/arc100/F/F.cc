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

void solve(long long N, long long K, long long M, vector<long long> A){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long M;
	long long K;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&K);
	scanf("%lld",&M);
	vector<long long> A(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, K, M, A);
	return 0;
}

