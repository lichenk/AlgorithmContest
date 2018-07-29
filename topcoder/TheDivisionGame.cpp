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
const ll MAXP=sqrt(1e9+1e6)+10;
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
const ll MAXN=1e6+4;
ll f[MAXN];
ll g[MAXN];
unordered_map<ll,ll> h;
class TheDivisionGame {
	public:
	long long countWinningIntervals(int L, int R) {
		sieve();
		for (ll x=L;x<=R;x++) {
			f[x-L]=0; g[x-L]=x;
		}
		for (auto &p: pv) {
			for (ll d=p;;d*=p) {
				ll s=((L+d-1)/d)*d;
				if (s>R) break;
				for (ll x=s; x<=R; x+=d) {
					f[x-L]++;
					assert((g[x-L]%p)==0);
					g[x-L]/=p;
				}
			}
		}
		for (ll x=L;x<=R;x++) {
			if (g[x-L] > 1) f[x-L]++;
		}
		//for (ll x=L;x<=R;x++) {
		//	printf("%lld: %lld\n",x,f[x-L]);
		//}
		ll xlim=R-L;
		for (ll x=1;x<=xlim;x++) {
			f[x]^=f[x-1];
		}
		h[0]=1;
		ll final=0;
		for (ll x=0;x<=xlim;x++) {
			ll nim=f[x];
			final+=h[nim];
			h[nim]++;
		}
		ll total=((xlim+2)*(xlim+1))/2;
		return total-final;

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
		cout << "Testing TheDivisionGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462250024;
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
		TheDivisionGame _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 9;
				int R = 10;
				_expected = 2LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			case 1:
			{
				int L = 2;
				int R = 5;
				_expected = 9LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			case 2:
			{
				int L = 2;
				int R = 6;
				_expected = 13LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			case 3:
			{
				int L = 2;
				int R = 100;
				_expected = 4345LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			case 4:
			{
				int L = 12566125;
				int R = 12567777;
				_expected = 1313432LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			case 5:
			{
				int L = 1;
				int R = 10;
				_expected = -1LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}
			/*case 6:
			{
				int L = ;
				int R = ;
				_expected = LL;
				_received = _obj.countWinningIntervals(L, R); break;
			}*/
			/*case 7:
			{
				int L = ;
				int R = ;
				_expected = LL;
				_received = _obj.countWinningIntervals(L, R); break;
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
