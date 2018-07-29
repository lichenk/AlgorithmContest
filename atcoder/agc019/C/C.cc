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

void solve(vector<long long> x, vector<long long> y, long long N, vector<long long> X, vector<long long> Y){
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<long long> y(2-1+1);
	long long N;
	vector<long long> x(2-1+1);
	for(int i = 0 ; i <= 2-1 ; i++){
		scanf("%lld",&x[i]);
		scanf("%lld",&y[i]);
	}
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	vector<long long> Y(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
		scanf("%lld",&Y[i]);
	}
	solve(x, y, N, X, Y);
	return 0;
}

