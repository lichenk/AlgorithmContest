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

void solve(long long N, long long M, long long K, vector<long long> A, vector<long long> B, vector<long long> C){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long K;
	long long M;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&M);
	scanf("%lld",&K);
	vector<long long> A(K-1+1);
	vector<long long> C(K-1+1);
	vector<long long> B(K-1+1);
	for(int i = 0 ; i <= K-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		scanf("%lld",&C[i]);
	}
	solve(N, M, K, A, B, C);
	return 0;
}

