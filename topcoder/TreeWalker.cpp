#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MODD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll MAXN=100000+8;
ll A[MAXN];
ll inv2=500000004LL;
vector<ll> g[MAXN];
ll final=0;
ll dfs(ll x, ll p) {
	ll sum=0;
	ll selfsum=0;
	for (auto &w:g[x]) {
		if (w==p) continue;
		ll ans=dfs(w,x);
		sum+=ans; sum%=MODD;
		ll self=(ans*ans); self%=MODD;
		selfsum+=self; selfsum%=MODD;
	}
	ll child=sum*sum; child%=MODD;
	child+=(MODD-selfsum); child%=MODD;
	child=(child*inv2); child%=MODD;
	final+=child; final%=MODD;
	final+=sum; final%=MODD;
	ll total=1+sum; total%=MODD;
	return (total*inv2)%MODD;
}
class TreeWalker {
	public:
	int calc(int _N, int _A0, int _B, int _C, int _mod) {
		ll N=_N,A0=_A0,B=_B,C=_C,mod=_mod;
		A[0] = A0;
		for (ll i=1;i<=N-2;i++) {
			A[i] = (B * A[i-1] + C) % mod;
		}
		for (ll i=1;i<=N-1;i++) {
			ll j = A[i-1] % i;
			g[i].PB(j);
			g[j].PB(i);
		}
		dfs(0,-1);
		final*=mod_pow(2,N,MODD);
		final%=MODD;
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
		cout << "Testing TreeWalker (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462324525;
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
		TreeWalker _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int A0 = 0;
				int B = 1;
				int C = 1;
				int MOD = 1000;
				_expected = 34;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 1:
			{
				int N = 10;
				int A0 = 0;
				int B = 0;
				int C = 0;
				int MOD = 1;
				_expected = 13824;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 2:
			{
				int N = 16;
				int A0 = 15;
				int B = 1;
				int C = 1;
				int MOD = 16;
				_expected = 917506;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 3:
			{
				int N = 1000;
				int A0 = 385498676;
				int B = 349131547;
				int C = 115776323;
				int MOD = 614879544;
				_expected = 245566366;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 4:
			{
				int N = 100000;
				int A0 = 111222333;
				int B = 444555666;
				int C = 777888999;
				int MOD = 123456789;
				_expected = 119729770;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 5:
			{
				int N = 2;
				int A0 = 0;
				int B = 1;
				int C = 1;
				int MOD = 1000;
				_expected = 2;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 6:
			{
				int N = 1;
				int A0 = 0;
				int B = 1;
				int C = 1;
				int MOD = 1000;
				_expected = 0;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			/*case 7:
			{
				int N = ;
				int A0 = ;
				int B = ;
				int C = ;
				int MOD = ;
				_expected = ;
				_received = _obj.calc(N, A0, B, C, MOD); break;
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
