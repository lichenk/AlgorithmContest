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
const ll MAXN=1e6+4;
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
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			if ((x%p)==0) {
				x/=p;
				h[p]++;
				found=true;
				if (x<MAXP) break;
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
}
class FoxAndGCDLCM {
	public:
	long long get(long long G, long long L) {
		sieve();
		map<ll,ll> g=factorize(G);
		map<ll,ll> l=factorize(L);
		set<ll> s;
		for (auto &w:g) s.insert(w.first);
		for (auto &w:l) s.insert(w.first);
		vector<ll> pv;
		for (auto &w:s) {
			pv.PB(w);
		}
		ll psz=pv.size();
		for (auto &p:pv) {
			if (l[p]<g[p]) return -1;
		}
		ll zlim=1LL<<psz;
		ll ans=INF;
		for (ll z=0;z<zlim;z++) {
			ll x=1,y=1;
			for (ll k=0;k<psz;k++) {
				ll p=pv[k];
				if (z&(1LL<<k)) {
					for (ll i=0;i<g[p];i++) x*=p;
					for (ll i=0;i<l[p];i++) y*=p;
				}
				else {
						for (ll i=0;i<g[p];i++) y*=p;
						for (ll i=0;i<l[p];i++) x*=p;
				}
			}
			chkmin(ans,x+y);
		}
		return ans;
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
		cout << "Testing FoxAndGCDLCM (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471622004;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxAndGCDLCM _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long G = 2LL;
				long long L = 20LL;
				_expected = 14LL;
				_received = _obj.get(G, L); break;
			}
			case 1:
			{
				long long G = 5LL;
				long long L = 8LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 2:
			{
				long long G = 1000LL;
				long long L = 100LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 3:
			{
				long long G = 100LL;
				long long L = 1000LL;
				_expected = 700LL;
				_received = _obj.get(G, L); break;
			}
			case 4:
			{
				long long G = 10LL;
				long long L = 950863963000LL;
				_expected = 6298430LL;
				_received = _obj.get(G, L); break;
			}
			case 5:
			{
				long long G = 1LL;
				long long L = 999999999989LL;
				_expected = 999999999990LL;
				_received = _obj.get(G, L); break;
			}
			/*case 6:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
			}*/
			/*case 7:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
