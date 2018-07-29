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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x*y)%MOD;}

const ll MAXN=1e5+4;
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
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	for (auto &p:gpv) {
		if (p*p>x) break;
		if ((x%p)==0) {
			ll cnt=0;
			while(x%p==0) {
				x/=p;
				cnt++;
			}
			h[p]+=cnt;
			if (x<MAXP) break;
		}
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
}
ll totient(ll p, ll k) {
	if (k==0) return 1;
	return (mod_pow(p,k-1,MOD)*(p-1))%MOD;
}
const ll mp=63;
ll f[2][mp];
ll solve(ll ke, ll qe, ll n,ll p) {
	memset(f[0],0,sizeof f[0]);
	f[0][0]=1;
	ll cur=0,nxt=1;
	for (ll i=0;i<n;i++) {
		memset(f[nxt],0,sizeof f[nxt]);
		for (ll x=0;x<=ke;x++) {
			for (ll y=0;y<=ke;y++) {
				ll z=min(x+y,ke);
				f[nxt][z]+=mul(f[cur][x],totient(p,ke-y));
				f[nxt][z]%=MOD;
			}
		}
		swap(cur,nxt);
	}
	ll inv=mod_pow(totient(p,ke-qe),MOD-2,MOD);
	return mul(inv,f[cur][qe]);
}
class ModEquation {
	public:
	vector <int> count(int _n, int K, vector <int> query) {
		ll n=_n;
		vector<int> vans;
		sieve();
		map<ll,ll> kf=factorize(K);
		for (auto &q:query) {
			ll ans=1;
			for (auto &w:kf) {
				ll p=w.first,ke=w.second;
				ll qe;
				{
					ll tp=1;
					for (ll x=0;x<=ke;x++) {
						if (q%tp==0) qe=x;
						else break;
						tp*=p;
					}
				}
				ll now=solve(ke,qe,n,p);
				//printf("ke:%lld qe:%lld n:%lld p:%lld now:%lld\n",ke,qe,n,p,now);
				ans=(ans*now)%MOD;
			}
			vans.PB(ans);
		}
		return vans;
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
		cout << "Testing ModEquation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483066039;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ModEquation _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int K = 2;
				int query[] = {0,1};
				int __expected[] = {3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int K = 4;
				int query[] = {0,1,2,3};
				int __expected[] = {8, 2, 4, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 6;
				int K = 6;
				int query[] = {4};
				int __expected[] = {2016 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int K = 2;
				int query[] = {0,0,0,1,1,1};
				int __expected[] = {1, 1, 1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
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
