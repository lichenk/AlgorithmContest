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
const ll MAXP=474747+8;
bool sieve_array[MAXP+1];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
	for (ll i=2;i<=MAXP;i++) {
		if (sieve_array[i]) pv.PB(i);
	}
}
inline bool iscomposite(ll x) {
	return (!sieve_array[x])&&(x!=1);
}
inline bool isprime(ll x) {
	return sieve_array[x];
}
const ll mn=MAXP;
ll f[mn][2];
bool isok[mn][2];
class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
		sieve();
		ll n=N,k=K;
		if (n>1000 && k > sqrt(n)) {
			set<ll> h;
			for (auto &w:pv) h.insert(w);
			ll ans=0;
			while(1) {
				n=*(h.lower_bound(n-k));
				ans++;
				n--;
				if (!iscomposite(n)) break;
				ans++;
			}
			return ans;
		}
		for (ll x=0;x<mn;x++) isok[x][0]=isprime(x);
		for (ll x=0;x<mn;x++) isok[x][1]=iscomposite(x);
		for (ll x=1;x<=n;x++) {
			for (ll t=0;t<2;t++) {
				ll bestwin=INF;
				ll bestlose=-INF;
				ll sublim=min(k,x-1);
				for (ll sub=1;sub<=sublim;sub++) {
					ll y=x-sub;
					if (isok[y][t]) {
						ll v=f[y][t^1];
						//printf("%d %d look at %d %d\n",x,t,y,t^1);
						if (v<=0) {
							chkmin(bestwin,-v+1);
						}
						else if(v>0){
							chkmax(bestlose,v+1);
						}
						else assert(false);
					}
				}
				//printf("x:%lld t:%lld got %lld %lld\n",x,t,bestwin,bestlose);
				if (bestwin!=INF) {
					f[x][t]=bestwin;
				}
				else if (bestlose!=-INF) {
					f[x][t]=-bestlose;
				}
				else f[x][t]=0;
			}
		}
		return f[n][0];
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
		cout << "Testing PrimeCompositeGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472658393;
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
		PrimeCompositeGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				_expected = 1;
				_received = _obj.theOutcome(N, K); break;
			}
			case 1:
			{
				int N = 58;
				int K = 1;
				_expected = 0;
				_received = _obj.theOutcome(N, K); break;
			}
			case 2:
			{
				int N = 30;
				int K = 3;
				_expected = -2;
				_received = _obj.theOutcome(N, K); break;
			}
			case 3:
			{
				int N = 6;
				int K = 3;
				_expected = 1;
				_received = _obj.theOutcome(N, K); break;
			}
			case 4:
			{
				int N = 526;
				int K = 58;
				_expected = 19;
				_received = _obj.theOutcome(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.theOutcome(N, K); break;
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
