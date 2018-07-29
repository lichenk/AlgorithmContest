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
const int mn=5000;
bool bf(ll a, ll b, ll c, ll d) {
	bitset<mn> q;
	q[a]=true;
	while(1) {
		a-=b; if (a<0) return false;
		if (a<=c) a+=d;
		if (q[a]) return true;
		if (a>=mn) return true;
		q[a]=true;
		if (q.count()==mn) return true;
	}
}

bool go(ll a,ll b,ll c,ll d) {
	if (d<b) return false;
	if (a<b) return false;
	if (!(c+1<=b-1)) return true;
	if (a>c) {
		ll reduce=(a-c+b-1)/b; assert(reduce>0);
		a-=reduce*b; assert(a<=c&&a+b>c);
	}
	else {
		a-=b;
	}
	if (a<0) return false;
	if (b==d) return true;
	assert(0<=a&&a<=c&&a+b>c);
	ll g=__gcd(b,d-b);
	vector<pll> v;
	{
		ll x=a;
		ll l=c+1-x; if (l<0) l+=b;
		ll r=b-1-x; if (r<0) r+=b;
		if (l<=r) v.PB(MP(l,r));
		else {
			v.PB(MP(l,b-1));
			v.PB(MP(0,r));
		}
	}
	for (auto &w:v) {
		ll l=w.fst,r=w.snd;
		ll got=(r/g)*g;
		//printf("x:%lld g:%lld l:%lld r:%lld\n",a,g,l,r);
		if (l<=got&&got<=r) return false;
	}
	return true;
}

void solve(long long T, vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D){
	for (ll i=0;i<T;i++) {
		bool ans=go(A[i],B[i],C[i],D[i]);
		//bool bff=bf(A[i],B[i],C[i],D[i]);
		//assert(ans==bff);
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long T;
	scanf("%lld",&T);
	vector<long long> D(T-1+1);
	vector<long long> C(T-1+1);
	vector<long long> B(T-1+1);
	vector<long long> A(T-1+1);
	for(int i = 0 ; i <= T-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		scanf("%lld",&C[i]);
		scanf("%lld",&D[i]);
	}
	solve(T, A, B, C, D);
	return 0;
}

