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

void solve(long long N, long long P, vector<long long> A){
	int odd=0,even=0;
	for (auto &w:A) {
		if (w&1) odd++; else even++;
	}
	ll ans;
	if (P==0) {
		ans=1LL<<(max(0,odd-1)+even);
	}
	else {
		if (odd==0) ans=0;
		else ans=1LL<<(max(0,odd-1)+even);
	}
	printf("%lld\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long P;
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	scanf("%lld",&P);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, P, A);
	return 0;
}

