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
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll MAXFACT=1e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}


class OrderedProduct {
	public:
	int count(vector <int> a) {
		ll asz=a.size();
		init();
		ll final=0;
		for (ll n=1;n<=50*50+5;n++) {
			ll ans=0;
			ll sign=1;
			for (ll x=n;x>=0;x--) {
				ll now=1;
				for (ll i=0;i<asz;i++) now=mul(now,starbar(a[i],x));
				ans+=(sign*binom(n,x)*now)%MOD;
				ans%=MOD;
				if (ans<0) ans+=MOD;
				sign*=-1;
			}
			final+=ans;
		}
		return final%MOD;
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
		cout << "Testing OrderedProduct (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490500535;
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
		OrderedProduct _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1, 1};
				_expected = 3;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {2};
				_expected = 2;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1, 1, 1, 1, 1};
				_expected = 541;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {23, 49, 12};
				_expected = 316396073;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2, 5, 4, 2, 3, 1, 3, 1, 4, 6};
				_expected = 225466557;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
