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

void solve(long long A, long long B, long long C, long long X, long long Y){
	ll final=LLONG_MAX;
	{
		ll xy=min(X,Y);
		ll xl=X-xy;
		ll yl=Y-xy;
		ll ans=xy*2*C+xl*A+yl*B;
		chkmin(final,ans);
	}
	{
		chkmin(final,X*A+Y*B);
	}
	{
		chkmin(final,max(X,Y)*2*C);
	}
	printf("%lld\n",final);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long A;
	long long B;
	long long Y;
	long long C;
	long long X;
	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);
	scanf("%lld",&X);
	scanf("%lld",&Y);
	solve(A, B, C, X, Y);
	return 0;
}

