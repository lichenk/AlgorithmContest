#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

bool getpow(ll b, ll e, ll n) {
  ll tmp=1;
  for (int i=0;i<e;i++) {
  	tmp*=b;
  	if (tmp>n) return false;
  }
  return tmp<=n;
}
ll getforx(ll e, ll n) {
  ll ans=pow((ld)n,((ld)1)/(ld)e);
  ll lo=max((ll)0,ans-2);
  ll hi=ans+2;
  for (ll final=hi;final>=lo;final--) {
    if (getpow(final,e,n)) return final;
  }
  return ans;
}
ll solve(ll p, ll q, ll n) {
  ll g=__gcd(p,q);
  p/=g; q/=g;
  ll k1=n/q;
  ll k2=n/p;
  ll k=min(k1,k2);
  return k;
}
const ll maxe=35;

class PowerEquation {
	public:
int count(int _n) {
  ll n=_n;
  vector<ll> tab;
  tab.PB(0);
  for (ll e=1;e<=maxe;e++) {
    tab.PB(getforx(e,n)-1);
  }
  ll finalans=0;
  ll lim=min(maxe,n);
  for (ll x=1;x<=lim;x++) {
    for (ll y=1;y<=lim;y++) {
      if (__gcd(x,y)!=1) continue;
      ll got=solve(x,y,n)%MOD;
      ll me=min(tab[x],tab[y]);
      if (me<0) me+=MOD;
      ll add=(got*me)%MOD;
      finalans+=add;
      finalans%=MOD;
    }
  }
  finalans+=(n*n);
  finalans%=MOD;
  return finalans%MOD;
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
		cout << "Testing PowerEquation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1493254803;
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
		PowerEquation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 6;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 15;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				int n = 100;
				_expected = 21620;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				int n = 22306;
				_expected = 68467;
				_received = _obj.count(n); break;
			}
			case 4:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.count(n); break;
			}
			case 5:
			{
				int n = 1000000000;
				_expected = -1;
				_received = _obj.count(n); break;
			}
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
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
