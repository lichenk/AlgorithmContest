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

void solve(long long N, long long M, vector<long long> A, vector<long long> B, vector<long long> U, vector<long long> V){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long M;
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	vector<long long> B(N-1+1);
	scanf("%lld",&M);
	vector<long long> V(M-1+1);
	vector<long long> U(M-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
	}
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&U[i]);
		scanf("%lld",&V[i]);
	}
	solve(N, M, A, B, U, V);
	return 0;
}

