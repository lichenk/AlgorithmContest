#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef __int128 ll;
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

struct rational_t { __int128 nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    nu = n; de = d;
    if (de < 0) { nu = -nu; de = -de; } }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator== (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const rational_t& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const rational_t& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const rational_t& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const rational_t& b) const { return nu * b.de >= b.nu * de; }
};

typedef rational_t rat;
const ll lim=1e16+2;
void solve(){
	int K; cin>>K;
	vector<pair<rat,ll> > g;
	/*for (ll d=1;;d++) {
		ll lft=d;
		vector<ll> v;
		while(lft>0) {
			ll take=min(lft,(ll)9LL);
			v.PB(take);
			lft-=take;
		}
		sort(v.begin(),v.end());
		ll nu=0;
		for (auto &w:v) {
			nu*=10;
			nu+=w;
		}
		//printf("nu:%lld\n",nu);
		if (nu>lim) {
			break;
		}
		g.PB(MP(rat(nu,d),nu));
	}*/
	for (ll nu=1;nu<=100;nu++) {
			ll x=nu;
			ll den=0;
			while(x>0) {
				den+=x%10; x/=10;
			}
			g.PB(MP(rat(nu,den),nu));
	}
	ll pten=1;
	for (ll d=0;d<=16;d++) {
		for (ll p=1;p<1000;p++) {
			ll nu=pten*p-1;
			if (nu>lim) continue;
			ll x=nu;
			ll den=0;
			while(x>0) {
				den+=x%10; x/=10;
			}
			g.PB(MP(rat(nu,den),nu));
		}
		pten*=10;
	}
	sort(g.begin(),g.end());
	ll prev=0;
	for (auto &w:g) {
		//printf("wnu:%lld\n",w.nu);
		ll nu=w.snd;
		if (nu<=prev) continue;
		printf("%lld\n",(long long)nu);
		prev=nu;
		--K; if (K==0) break;
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}

