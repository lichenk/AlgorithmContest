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
const ll maxn=1e5+4;
ll f[2][3];
const ll EQ=0,LS=1,GR=2;
void solve(long long N, vector<long long> A){
	ll cur=0,nxt=1;
	for (ll state=0;state<3;state++) f[cur][state]=1;
	for (ll x=1;x<N;x++) {
		for (ll state=0;state<3;state++) {
			f[nxt][state]=INF;
		}
		for (ll s=0;s<3;s++) {
			ll a=A[x-1],b=A[x];
			if (s==EQ&&!(a==b)) continue;
			if (s==LS&&!(a<=b)) continue;
			if (s==GR&&!(a>=b)) continue;
			chkmin(f[nxt][s],f[cur][s]);
			chkmin(f[nxt][s],f[cur][EQ]);
		}
		for (ll t=0;t<3;t++) chkmin(f[nxt][EQ],f[cur][t]+1);
		swap(cur,nxt);
	}
	ll ans=INF;
	for (ll s=0;s<3;s++) chkmin(ans,f[cur][s]);
	printf("%lld\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, A);
	return 0;
}

