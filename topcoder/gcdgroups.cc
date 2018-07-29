#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
 
const ll MAXN=5e5+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
			chkmin(sp[i],i);
		}
	}
}
/*
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			if ((x%p)==0) {
				x/=p;
				h[p]++;
				found=true;
				break;
			}
		}
		if (!found) break;
	}
	if (x<MAXP) {
		while(x>1) {
		ll p=sp[x];
		x/=p;
		h[p]++;
		}
	}
	if (x>1) h[x]++;
	return h;
}*/
vector<ll> getprimefactors(ll x) {
	vector<ll> ans;
	while(x>1) {
		ll p=sp[x];
		x/=p;
		while(x%p==0) x/=p;
		ans.PB(p);
	}
	if (x>1) ans.PB(x);
	return ans;
}
const ll mn=MAXN;
ll a[mn];
ll cnt[mn];
ll light[mn];
int main()
{
	sieve();
	ll tt; scanf("%lld",&tt);
	for (ll jj=0;jj<tt;jj++) {
		ll n; scanf("%lld",&n);
		memset(cnt,0,sizeof cnt);
		for (ll i=0;i<n;i++) {
			ll x; scanf("%lld",&x);
			a[i]=x;
			vector<ll> pfac=getprimefactors(x);
			for (auto &w:pfac) {
				cnt[w]++;
			}
		}
		vector<ll> gp;
		for (ll x=2;x<mn;x++) {
			if (cnt[x]>=n/2) {
				gp.PB(x);
				//printf("gp:%lld %lld\n",x,cnt[x]);
			}
		}
		ll k=gp.size();
		for (ll x=0;x<n;x++) {
			ll got=0;
			for (ll i=0;i<k;i++) {
				if (a[x]%gp[i]==0) got|=(1LL<<i);
			}
			light[x]=got;
		}
		bool good=false;
		for (ll i=0;i<k;i++) {
			ll msk=1LL<<i;
			ll all=(1LL<<k)-1LL;
			for (ll x=0;x<n;x++) {
				ll y=light[x];
				if ((y&msk)==0) {
					all&=y;
				}
			}
			if (all) {
				//printf("p:%lld all:%lld\n",gp[i],all);
				good=true; break;
			}
		}
		if (good) printf("YES\n");
		else printf("NO\n");
	}
}

