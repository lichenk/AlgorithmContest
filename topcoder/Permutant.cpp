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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXM=50000+4;
ll f[4][4*MAXM+4];

inline ll mul(ll x,ll y) {
	return (x*y)%MOD;
}
inline ll add(ll x,ll y) {
	return (x+y)%MOD;
}
ll fact[4*MAXM+4],invfact[4*MAXM+4];

ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	return ans;
}

ll binom(ll n, ll k) {
	return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
class Permutant {
	public:
	int counthis(vector <int> a) {
		{
			fact[0]=1;
			ll tmp=1;
			for (ll i=1;i<MAXM;i++) {
				tmp = mul(tmp,i);
				fact[i]=tmp;
			}
			for (ll i=0;i<MAXM;i++) {
				invfact[i]=modexp(fact[i],MOD-2);
			}
		}

		ll n=a.size();
		ll ans=0;
		for (ll init=0;init<n;init++) {
			vector<ll> b;
			for (ll i=0;i<n;i++) {if(i!=init) b.PB(a[i]);}
			for (ll r=0;r<MAXM;r++) f[0][r]=0;
			f[0][a[init]-1]=fact[a[init]];
			ll sum=a[init]-1;
			for (ll s=0;s<n-1;s++) {
				ll p=s%2; ll c=(s+1)%2;
				for (ll r=0;r<MAXM;r++) f[c][r]=0;
				ll t=b[s];
				for (ll radd=0;radd<t;radd++) {
					ll ladd=t-radd;
					for (ll rorig=0;rorig<MAXM-1-radd;rorig++) {
						ll lorig=sum-rorig;
						if (lorig<0) break;
						ll chl=binom(lorig+ladd,ladd);
						ll chr=binom(rorig+radd,radd);
						ll choose = mul(chl,chr);
						ll inc = mul(f[p][rorig],mul(choose,fact[t-1]));
						f[c][rorig+radd] = add(f[c][rorig+radd],inc);
					}
				}
				sum+=t;
			}
			for (ll r=0;r<MAXM;r++) {
				ans = add(ans,f[(n+1)%2][r]);
			}
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
		cout << "Testing Permutant (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457370308;
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
		Permutant _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,1};
				_expected = 2;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {1,2};
				_expected = 4;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1,2,3};
				_expected = 188;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1,1,1,1,1};
				_expected = 120;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {1,2,2,3,3,3,4,4,4,4};
				_expected = 860993751;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.counthis(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
