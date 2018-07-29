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

void solve(long long Q, vector<long long> A, vector<long long> B){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long Q;
	scanf("%lld",&Q);
	vector<long long> A(Q-1+1);
	vector<long long> B(Q-1+1);
	for(int i = 0 ; i <= Q-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
	}
	solve(Q, A, B);
	return 0;
}

