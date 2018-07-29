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
bool f(ll n, ll a, ll b, ll c, ll d) {
	if (d==0) {
		if (a==b) return true;
		return false;
	}
	ll k=n-1;
	for (ll pos=0;pos<=k;pos++) {
		ll neg=k-pos;
		ll delta=b-a+(neg-pos)*c;
		ll s=d-c;
		ll hi=s*pos;
		ll lo=-s*neg;
		//printf("pos:%lld neg:%lld hi:%lld lo:%lld delta:%lld\n",pos,neg,hi,lo,delta);
		if (lo<=delta&&delta<=hi) return true;
	}
	return false;
}
void solve(long long N, long long A, long long B, long long C, long long D){
	if (f(N,A,B,C,D)) {
		printf("YES\n"); return;
	}
	printf("NO\n");
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long D;
	long long C;
	long long B;
	long long A;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);
	scanf("%lld",&D);
	solve(N, A, B, C, D);
	return 0;
}

