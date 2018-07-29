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

void solve(long long n, vector<long long> a, vector<long long> b){
	ll lo=0;
	for (auto &w:b) chkmax(lo,w);
	lo++;
	
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	vector<long long> b(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&b[i]);
	}
	solve(N, a, b);
	return 0;
}

