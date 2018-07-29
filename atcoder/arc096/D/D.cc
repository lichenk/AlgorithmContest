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
const int mn=1e5+4;
ll a[mn],b[mn];
void solve(long long n, long long C, vector<long long> x, vector<long long> v){
	ll final=0;
	ll best1=0;
	{
		ll sum=0;
		for (ll i=0;i<n;i++) {
			sum+=v[i];
			chkmax(best1,sum-x[i]);
			a[i]=best1;
		}
	}
	ll best2=0;
	{
		ll sum=0;
		for (ll i=n-1;i>=0;i--) {
			sum+=v[i];
			chkmax(best2,sum-(C-x[i]));
			b[i]=best2;
		}
	}
	chkmax(final,max(best1,best2));
	{
		ll sum=0;
		for (ll i=0;i<n-1;i++) {
			sum+=v[i];
			chkmax(final,b[i+1]+sum-2*x[i]);
		}
	}
	{
		ll sum=0;
		for (ll i=n-1;i>=1;i--) {
			sum+=v[i];
			chkmax(final,a[i-1]+sum-2*(C-x[i]));
		}
	}
	printf("%lld\n",final);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long C;
	scanf("%lld",&N);
	vector<long long> v(N-1+1);
	vector<long long> x(N-1+1);
	scanf("%lld",&C);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
		scanf("%lld",&v[i]);
	}
	solve(N, C, x, v);
	return 0;
}

