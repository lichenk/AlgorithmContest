#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
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

const ll lim = 1000LL*1000LL*1000LL*1000LL*1000LL*1000LL;
vector<ll> go(ll N, ll negbias) {
	vector<ll> vans;
	for (ll i=0;i<N;i++) vans.PB(1);
	for (ll k=0;k<gpv.size();k++) {
		bool ok=true;
		ll p=gpv[k];
		if (!ok) break;
		ll b=(k/2)+1;
		ll neg=(k&1)^negbias;
		for (ll x=0;x<N;x++) {
			if ((((x+1)>>b)&1)^neg) {
				printf("k:%lld x+1:%lld\n",k,x+1);
				ll res;
				if (__builtin_smulll_overflow(vans[x],p,&res)) return vans;
				if (res>lim) return vans;
				vans[x]=res;
			}
		}
	}
	return vans;
}
bool check(vector<ll> &v) {
	ll n=v.size();
	for (ll i=0;i<n-1;i++) {
		if (__gcd(v[i],v[i+1])>1) return false;
	}
	for (ll i=0;i<n;i++) {
		for (ll j=i+2;j<n;j++) {
			if (__gcd(v[i],v[j])==1) return false;
		}
	}
	return true;
}
class CoprimeNeighbors {
	public:
	vector<long long> findAny(int N) {
		sieve();
		for (ll negbias=0;negbias<=1;negbias++) {
			vector<ll> vans=go(N,negbias);
			for (auto &w:vans) printf("%lld ",w);
			printf("\n");
			if (check(vans)) return vans;
		}
		assert(0);
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
		cout << "Testing CoprimeNeighbors (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486848847;
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
		CoprimeNeighbors _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				long long __expected[] = {14, 25 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			case 1:
			{
				int N = 3;
				long long __expected[] = {1000000000000000000, 1, 1000000000000000000 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			case 2:
			{
				int N = 6;
				long long __expected[] = {14, 39, 80, 63, 26, 105 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}
			/*case 3:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.findAny(N); break;
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
