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

inline ll sq(ll x) {return (x*x)%MOD;}
const ll MAXP=31622+5;
bool sieve_array[MAXP+1];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) sieve_array[i] = true;
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if (sieve_array[i]) pv.PB(i);
	}
}

vector<ll> factorize(ll n) {
	set<ll> factors;
	for (auto &p:pv) {
		if (n%p==0) {
			factors.insert(p);
			while (n%p==0) {
				n/=p;
			}
		}
	}
	if (n>1) factors.insert(n);
	vector<ll> fv;
	for (auto &w: factors) {
		fv.PB(w);
		//printf("Factor:%lld\n",w);
	}
	return fv;
}
const ll inv6 = 166666668LL;
inline ll mul(ll x,ll y) {
	return (x*y)%MOD;
}
inline ll sumsq(ll n) {
	return mul(n,mul(n+1,mul(2*n+1,inv6)));
}

class ReflectiveRectangle {
	public:
	int findSum(int _sideA, int _sideB, int _bounces) {
		ll c=_bounces+2;
		if (c%2==1) return 0;
		if (c==2) return sq(_sideA)+sq(_sideB);
		sieve();
		vector<ll> factors = factorize(c);
		ll k=min(20LL,(ll)factors.size());
		ll lim=1ULL<<k;
		ll ans=0;
		for (ll zz=1;zz<lim;zz++) {
			ll prod=1;
			for (ll i=0;i<k;i++) {
				if ((1ULL<<i)&zz) prod *= factors[i];
			}
			ll pos=(__builtin_popcountll(zz)%2==0)?-1:1;
			ll sum=mul(sumsq(c/prod),mul(prod,prod));
			ans=(ans+MOD+pos*sum)%MOD;
		}
		ll fsz=factors.size();
		for (ll s=k;s<fsz;s++) {
			ll p=factors[s];
			for (ll x=p;x<c;x+=p) {
				bool ok=true;
				for (ll i=0;i<s;i++) {
					if (x%factors[i]==0) {ok=false; break;}
				}
				if(ok) {
					ans=(ans+x*x)%MOD;
				}
			}
		}
		ll final=(MOD+sumsq(c)-ans)%MOD;
		//printf("f:%lld. ans:%lld\n",final,ans);
		final = (final*(sq(_sideA)+sq(_sideB)))%MOD;
		return final;
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
		cout << "Testing ReflectiveRectangle (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457817843;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ReflectiveRectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sideA = 3;
				int sideB = 4;
				int bounces = 0;
				_expected = 25;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 1:
			{
				int sideA = 3;
				int sideB = 3;
				int bounces = 2;
				_expected = 180;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 2:
			{
				int sideA = 13;
				int sideB = 17;
				int bounces = 1;
				_expected = 0;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 3:
			{
				int sideA = 59325;
				int sideB = 31785;
				int bounces = 262142;
				_expected = 48032850;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 4:
			{
				int sideA = 1000000;
				int sideB = 1000000;
				int bounces = 1000000000;
				_expected = 145972110;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 5:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 8;
				_expected = 280;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 6:
			{
				int sideA = 157;
				int sideB = 10013;
				int bounces = 8;
				_expected = 39874422;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 7:
			{
				int sideA = 100007;
				int sideB = 100009;
				int bounces = 14;
				_expected = 175993186;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 8:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 14;
				_expected = 1360;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 9:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 4;
				_expected = 52;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 10:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 6;
				_expected = 168;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 11:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 10;
				_expected = 392;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 12:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 12;
				_expected = 5278;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 13:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 100;
				_expected = 1435616;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 14:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 16;
				_expected = 8502;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 15:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 18;
				_expected = 14040;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 16:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 20;
				_expected = 21450;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 17:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 22;
				_expected = 20072;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 18:
			{
				int sideA = 2;
				int sideB = 3;
				int bounces = 24;
				_expected = 35828;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 19:
			{
				int sideA = 1;
				int sideB = 1;
				int bounces = 22;
				_expected = 3088;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
			case 20:
			{
				int sideA = 100007;
				int sideB = 100009;
				int bounces = 10000000;
				_expected = 980425119;
				_received = _obj.findSum(sideA, sideB, bounces); break;
			}
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
