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

void solve(long long n, vector<long long> a){
	sort(a.begin(),a.end());
	pll ans=MP(INF,INF);
	ll b=a[n-1];
	for (int i=0;i<n-1;i++) {
		chkmin(ans,MP(abs(b-2*a[i]),a[i]));
	}
	printf("%lld %lld\n",b,ans.snd);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long n;
	scanf("%lld",&n);
	vector<long long> a(n-1+1);
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(n, a);
	return 0;
}

