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

void solve(long long N, long long K, long long Q, vector<long long> A){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long Q;
	long long K;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	scanf("%lld",&K);
	scanf("%lld",&Q);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, K, Q, A);
	return 0;
}
