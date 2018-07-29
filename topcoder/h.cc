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
const int MAXN=104;

ll mod_pow(ll a, ll n) { ll ret = 1; ll p = a % MOD; while (n) { if (n & 1) ret = ret * p % MOD; p = p * p % MOD; n >>= 1; } return ret; }
const ll MAXFACT=104;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
ll fbinom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
ll binom[MAXFACT];
ll prodbinom[MAXFACT][MAXFACT];
int k;
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
  for (ll x=0;x<MAXFACT;x++) binom[x]=fbinom(x,k);
  for (ll x=0;x<MAXFACT;x++) for (ll y=0;y<MAXFACT;y++) {
  	prodbinom[x][y]=mul(binom[x],binom[y]);
  }
}

int n,m;
bitset<MAXN> A[MAXN];
int cntByCareMaskAndSig[1<<18];
int elem2sig[MAXN];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) {
		A[i].reset();
		int Ai_size;
		scanf("%d",&Ai_size);
		for (int j=0;j<Ai_size;j++) {
			int Aij; scanf("%d",&Aij);
			A[i][Aij-1]=true;
		}
	}
	init();
	for (int elem=0;elem<n;elem++) {
		int fullsig=0;
		for (int Ai=0;Ai<m;Ai++) {
			if (A[Ai][elem]) fullsig|=1<<Ai;
		}
		elem2sig[elem]=fullsig;
	}
	ll final_ans=0;
	int max_mask=1<<m;
	for (int care_mask=1;care_mask<max_mask;care_mask++) {
		int inner_size=__builtin_popcount(care_mask);
		set<int> active;
		for (int elem=0;elem<n;elem++) {
			int fullsig=elem2sig[elem];
			int res=fullsig&care_mask;
			cntByCareMaskAndSig[res]++;
			active.insert(res);
		}
		ll this_ans=0;
		for (auto &sig: active) {
			int xnum=cntByCareMaskAndSig[sig];
			int ynum=cntByCareMaskAndSig[sig^care_mask];
			ll choice=prodbinom[xnum][ynum];
			this_ans+=choice;
		}
		for (auto &sig: active) cntByCareMaskAndSig[sig]=0;
		if ((__builtin_popcount(care_mask)%2)==0) this_ans=MOD-this_ans;
		final_ans+=this_ans;
		final_ans%=MOD;
	}
	printf("%lld\n",final_ans);
}
