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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
//#ifdef DEBUG_CAT

//#define dbg(...)   prllf( __VA_ARGS__ )
//#else 
//#define dbg(...)   /****nothing****/
//#endif
map<ll, vector<ll> > g[10];
ll dig[10];
ll fact[20];

ll conv(ll xx, ll L) {
	memset(dig,0,sizeof dig);
	ll x=xx;
	for (ll d=L;d>=1;d--) {
		ll r=x%10;
		dig[r]++;
		x/=10;
	}
	ll y=0;
	for (ll d=1;d<=L;d++) {
		y*=10;
		y+=dig[d];
	}
	return y;
}

void init(ll L) {
	ll pten=1; for (ll i=0;i<L;i++) pten*=10;
	for (ll xx=0;xx<pten;xx++) {
		ll sum=0;
		bool ok=1;
		ll x=xx;
		for (ll d=L;d>=1;d--) {
			ll r=x%10;
			sum+=r;
			if (sum>L) {ok=0; break;}
			x/=10;
		}
		if (ok) {
			memset(dig,0,sizeof dig);
			ll y=conv(xx, L);
			//prllf("L:%lld y:%lld xx:%lld\n",L,y,xx);
			if (y!=xx) g[L][y].PB(xx);
		}
	}
}
map<ll,ll> dp[10];
ll gL;
ll f(ll x) {
	ll L=gL;
	auto kt=dp[L].find(x);
	if (kt!=dp[L].end()) return kt->snd;
	ll tmp=x;
	memset(dig,0,sizeof dig);
	ll stars=0;
	for (ll d=L;d>=1;d--) {
		ll r=tmp%10;
		stars+=r;
		dig[d]=r;
		tmp/=10;
	}
	dig[0]=max(0ll,L-stars);
	stars+=dig[0];
	ll all=0;
	if (stars<=L) {
		all=fact[stars];
		for (ll d=0;d<=L;d++) {
			all/=fact[dig[d]];
			//if (x==3)prllf("stars:%lld dig[d]:%lld all:%lld\n",stars,dig[d],all);
			/*for (ll v=0;v<dig[d];v++) {
				if (x==1) prllf("stars:%lld d:%lld\n",stars,d);
				
			}*/
		}
	}
	//prllf("x:%lld ball:%lld\n",x,all);
	if (conv(x,L)!=x) all++;
	//prllf("x:%lld fall:%lld\n",x,all);
	auto it=g[L].find(x);
	if (it!=g[L].end()) {
		for (auto &y:it->snd) {
			ll got=f(y);
			//prllf("x:%lld y:%lld got:%lld\n",x,y,got);
			all+=got-1;
		}
	}
	//prllf("x:%lld all:%lld\n",x,all);
	return dp[L][x]=all;
}

ll brute(ll target) {
	ll L=gL;
	ll pten=1; for (ll i=0;i<L;i++) pten*=10;
	ll ans=0;
	for (ll xx=0;xx<pten;xx++) {
		ll x=xx;
		bool ok=1;
		for (ll y=0;y<L;y++) {
			if (x%10>L) {ok=0; break;}
			x/=10;
		}
		if (!ok) continue;
		x=xx;
		if (x==target) ans++;
		else {
			while(1) {
				ll y=conv(x,L);
				if (y==target) {
					//prllf("xx:%d\n",xx);
					ans++; break;
				}
				if (x==y) break;
				x=y;
			}
		}
	}
	return ans;
}

void test() {
	srand(clock()+time(0)+rand());
	for (ll k=0;k<10000;k++) {
		ll L=(rand()%5)+1;
		ll x=0;
		for (ll i=0;i<L;i++) {
			x*=10;
			x+=rand()%(L+1);
		}
		if (x==0) continue;
		//L=3; x=1;
		gL=L;
		ll fx=f(x),bx=brute(x);
		//if(fx!=bx) {
		//	prllf("L:%lld x:%lld f:%lld bx:%lld\n",L,x,fx,bx);
		//}
	}
}

int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	for (ll L=1;L<=9;L++) init(L);
	fact[0]=1;
	for (ll x=1;x<=10;x++) fact[x]=fact[x-1]*x;
	//test();
	//return 0;
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		string s; cin>>s;
		gL=s.length();
		stringstream stream1(s);
		ll x; stream1>>x;
		ll ans=f(x);
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
