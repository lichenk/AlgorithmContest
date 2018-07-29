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
const ll INF=1e15;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=2e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
}

const ll mn=2e5+4;
ll cheapest[mn];
ll colcnt[mn];
void solve(long long n, long long X, long long Y, vector<long long> c, vector<long long> w){
	for (ll col=1;col<=n;col++) {
		cheapest[col]=INF;
	}
	for (ll i=0;i<n;i++) {
		chkmin(cheapest[c[i]],w[i]);
	}
	pll cheap[3]; cheap[0]=MP(INF,INF); cheap[1]=MP(INF,INF);
	for (ll col=1;col<=n;col++) {
		chkmin(cheap[0],MP(cheapest[col],col));
	}
	for (ll col=1;col<=n;col++) {
		if (col!=cheap[0].snd) chkmin(cheap[1],MP(cheapest[col],col));
	}
	if (cheap[0].fst+cheap[1].fst>Y) {
		cheap[1]=MP(INF,INF);
	}
	ll all=0;
	for (ll i=0;i<n;i++) {
		bool can=false;
		ll col=c[i];
		cheap[2]=MP(cheapest[col],col);
		ll klim=2;
		if (cheap[0].fst+cheap[2].fst<=Y) {
			klim++;
		}
		for (ll k=0;k<klim;k++) {
			ll lim;
			if (c[i]==cheap[k].snd) lim=X;
			else lim=Y;
			if (w[i]+cheap[k].fst<=lim) {
				//printf("i:%d\n",i);
				colcnt[c[i]]++;
				all++;
				break;
			}
		}
	}
	init();
	ll denom=1;
	for (ll col=1;col<=n;col++) {
		denom=(denom*fact[colcnt[col]])%MOD;
	}
	ll numer=fact[all];
	ll final=(numer*mod_inv(denom, MOD))%MOD;
	printf("%lld\n",final);
}

int main(){	
	long long X;
	long long N;
	long long Y;
	scanf("%lld",&N);
	vector<long long> w(N-1+1);
	vector<long long> c(N-1+1);
	scanf("%lld",&X);
	scanf("%lld",&Y);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&c[i]);
		scanf("%lld",&w[i]);
	}
	solve(N, X, Y, c, w);
	return 0;
}

