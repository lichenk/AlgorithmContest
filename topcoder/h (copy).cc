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
const ll MAXFACT=1e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
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
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}


bitset<MAXN> A[MAXN];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) {
		A[i].reset();
		int Ai_size;
		scanf("%d",&Ai_size);
		for (int j=0;j<Ai_size;j++) {
			int Aij; scanf("%d",&Aij);
			A[i][Aij-1]=true;
		}
	}
	int max_mask=1<<m;
	ll final_ans=0;
	bitset<MAXN> universe;
	universe.reset();
	for (int x=0;x<n;x++) universe[x]=true;
	for (int mask=1; mask<max_mask;mask++) {
		bitset<MAXN> the_intersection, the_union;
		the_intersection=universe;
		the_union.reset();
		for (int i=0;i<m;i++) {
			if (mask&(1<<i)) {
				the_union=the_union | A[i];
				the_intersection= the_intersection & A[i];
			}
		}
		ll choices_X=binom(the_intersection.count(), k);
		ll choices_Y=binom(n-the_union.count(), k);
		ll choices=(choices_X*choices_Y)%MOD;
		int sign = (__builtin_popcount(mask)%2==1)?1:-1;
		final_ans+=choices * sign;
	}
	final_ans = (final_ans*2)%MOD;
	printf("%lld\n",final_ans);
}
