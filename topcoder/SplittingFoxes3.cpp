#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
typedef pair<ll,ll> pll;
#define sz(c) ((ll)(c).size())
#define FOR(i,n) for(ll i = 0; i < (n); i++)
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll add(ll x,ll y) {return (x+y)%MOD;}
inline ll sub(ll x,ll y) {return (x-y+MOD)%MOD;}
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
/* Discrete log */
ll alpha=5; // Generator modulo MOD
vector<ll> factorsphimod = {2,(MOD-1)/2}; // Relatively prime factors of phi(MOD)
ll garner(vector<pll> mr, ll mod){
  mr.emplace_back(mod, 0);

  vector<ll> coffs(sz(mr), 1);
  vector<ll> constants(sz(mr), 0);
  FOR(i, sz(mr) - 1){
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)
    ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
    if (v < 0) v += mr[i].first;

    for (ll j = i + 1; j < sz(mr); j++) {
      (constants[j] += coffs[j] * v) %= mr[j].first;
      (coffs[j] *= mr[i].first) %= mr[j].first;
    }
  }

  return constants[sz(mr) - 1];
}


ll alpha_mm;
ll babysteps_m;
map<ll,ll> babysteps_h;
void babysteps_init() {
	babysteps_m=ceil(sqrt(MOD)+1);
	ll m=babysteps_m;
	alpha_mm=mod_pow(mod_inv(alpha,MOD),m,MOD);
	ll alphaj=1;
	for (ll j=0;j<=m;j++) {
		babysteps_h[alphaj]=j;
		alphaj=mul(alphaj,alpha);
	}
}
ll get_discrete_log(ll x) {
	/*ll y=1;
	for (ll i=0;i<MOD;i++) {
		if (y==x) return i;
		y=mul(y,alpha);
	}
	assert(false);
	return -1;*/
	ll y=x;
	ll m=babysteps_m;
	for (ll i=0;i<babysteps_m;i++) {
		auto it=babysteps_h.find(y);
		if (it!=babysteps_h.end()) {
			ll j=it->second;
			return i*babysteps_m+j;
		}
		y=mul(y,alpha_mm);
	}
	return -1;
}
ll getroot2(ll x, ll k) {
	for (ll a=0;a<MOD;a++) {
		if (mod_pow(a,k,MOD)==x) return a;
	}
	return -1;
}
ll getroot(ll x, ll k) {
	if (x==0) return 0;
	ll dlog=get_discrete_log(x);
	if (dlog==-1) return -1;
	ll phimod=MOD-1;
	vector<pll> togarner;
	for (auto &p:factorsphimod) {
		// Solve k*u=dlog mod p
		ll umodp=(dlog*mod_inv(k,p))%p;
		togarner.PB(MP(p,umodp));
	}
	ll u=garner(togarner, phimod);
	//printf("x:%lld Solving %lld*x=%lld. Got u:%lld\n",x,k,dlog,u);
	if (u<0) {
		//printf("FAILED\n");
		return -1;
	}
	ll ans=mod_pow(alpha,u,MOD);
	if (mod_pow(ans,k,MOD)==x) {
		//printf("Returning:%lld\n",ans);
		return ans;
	}
	else {
		//printf("FAILED\n");
		return -1;
	}
}
ll n,k;
vector<ll> a,b,xx;
vector<ll> vans;
const ll mn=304;
vector<ll> g[mn];
bool has[mn];
set<ll> anc[mn];
ll countt_helper(ll x) {
	if (has[x]) return 0;
	has[x]=true;
	ll ans=vans[x];
	for (auto &y:g[x]) {
		ans=add(ans,countt_helper(y));
	}
	return ans;
}
ll countt(ll x) {
	memset(has,0,sizeof has);
	return countt_helper(x);
}
/*ll countupattractions(ll x) {
	return countt(x)-vans[x];
}*/
ll dp[mn];
ll gocount(ll x) {
	if (dp[x]!=UNDEF) return dp[x];
	ll allt=countt(x);
	ll all=mod_pow(allt,k,MOD);
	ll s=0;
	for (auto &y:anc[x]) {
		ll gcy=gocount(y);
		//printf("x:%lld y:%lld gcy:%lld\n",x,y,gcy);
		s=add(s,gcy);
	}
	//printf("x:%lld all:%lld s:%lld\n",x,all,s);
	return dp[x]=sub(all,s);
	/*ll ans=0;
	if (counted[x]) return 0;
	counted[x]=true;
	for (auto &y:g[x]) {
		ans=add(ans,gocount(y));
	}
	
	ll toadd=sub(mod_pow(upnodes+vans[x],k,MOD),mod_pow(upnodes,k,MOD));
	printf("Count x:%lld upnodes:%lld vans:%lld toadd:%lld\n",x,upnodes,vans[x],toadd);
	ans=add(ans,toadd);
	return ans;*/
}
void init_anc(ll x, ll p) {
	for (auto &y:g[x]) {
		anc[p].insert(y);
		init_anc(y,p);
	}
}
bool fail=false;
bool solved[mn];
void solve(ll x) {
	if (solved[x]) return;
	solved[x]=true;
	for (auto &y:g[x]) {
		solve(y);
	}
	ll S=0;
	for (auto &y:anc[x]) {
		ll gcy=gocount(y);
		//printf("x:%lld y:%lld gcy:%lld\n",x,y,gcy);
		S=add(S,gcy);
	}
	ll upnodes=countt(x);
	ll udk=(xx[x]+S)%MOD;
	//printf("x:%lld upnodes:%lld udk:%lld=%lld+%lld\n",x,upnodes,udk,xx[x],S);
	ll ud=getroot(udk,k);
	if (ud==-1) {
		//printf("udk:%lld ud:%lld check:%lld\n",udk,ud,getroot2(udk,k));
		fail=true;
	}
	ll d=sub(ud,upnodes);
	vans[x]=d;
	//printf("x:%lld ud:%lld vans:%lld\n",x,ud,vans[x]);
}
class SplittingFoxes3 {
	public:
	vector <int> restore(int _n, int _k, vector <int> _a, vector <int> _b, vector <int> _xx) {
		babysteps_init();
		n=_n,k=_k;
		for (ll x=0;x<n;x++) dp[x]=UNDEF;
		vans.resize(n);
		for (auto &w:_a) a.PB(w);
		for (auto &w:_b) b.PB(w);
		for (auto &w:_xx) xx.PB(w);
		ll m=a.size();
		for (ll i=0;i<m;i++) {
			ll x=a[i],y=b[i];
			g[y].PB(x);
		}
		for (ll x=0;x<n;x++) {
			init_anc(x,x);
		}
		memset(solved,0,sizeof solved);
		for (ll x=0;x<n;x++) {
			solve(x);
			if (fail) break;
		}
		vector<int> vfinal;
    if (fail) return vfinal;
		for (auto &w:vans) vfinal.PB(w);
		return vfinal;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing SplittingFoxes3 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1478459336;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SplittingFoxes3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int k = 2;
				int a[] = {0,2};
				int b[] = {1,1};
				int x[] = {1,2,1};
				int __expected[] = {1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int k = 3;
				int a[] = {1,1,0,3};
				int b[] = {0,3,2,2};
				int x[] = {7,1,49,7};
				int __expected[] = {1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 1;
				int k = 2;
				int a[] = {};
				int b[] = {};
				int x[] = {5};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int k = 2;
				int a[] = {};
				int b[] = {};
				int x[] = {4};
				int __expected[] = {1000000005 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				int k = 2;
				int a[] = {0,2,2,4,4,6,1,3,5};
				int b[] = {1,1,3,3,5,5,7,7,7};
				int x[] = {1,4,4,12,9,24,16,30};
				int __expected[] = {1, 0, 2, 0, 3, 0, 4, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 10;
				int k = 1000000000;
				int a[] = {1,2,3,4,5,6,7,8,9};
				int b[] = {0,0,2,3,3,2,5,4,7};
				int x[] = {0,0,1,0,0,0,0,0,0,0};
				int __expected[] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int k = ;
				int a[] = ;
				int b[] = ;
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				int a[] = ;
				int b[] = ;
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				int a[] = ;
				int b[] = ;
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restore(n, k, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
