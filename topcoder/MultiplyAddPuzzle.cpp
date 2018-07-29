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
class MultiplyAddPuzzle {
	public:
	long long minimalSteps(long long _s, long long _t, long long _a, long long _b) {
		ll s=_s,t=_t,a=_a,b=_b;
		if (s==t) return 0;
		if (t==0) {
			if (b==0) return 1;
			else return -1;
		}
		if (a==0) {
			if (s==0) return -1;
			if (b==0) return -1;
			ll ans=0;
			ll k=0;
			while(s<t) {
				if (k>65) break;
				s*=b;
				ans++;
				k++;
			}
			if (s==t) return ans;
			else return -1;
		}
		if (b==0||b==1) {
			ll diff=t-s;
			if (diff>=0&&(diff%a)==0) {
				ll sol=diff/a;
				return sol;
			}
			if (b==0) {
				diff=t;
				if (diff>=0&&(diff%a)==0) {
					ll sol=diff/a;
					return sol+1;
				}
			}
			return -1;
		}
		ll bn=s;
		ll final=-1;
		for (ll n=0;n<=65;n++) {
			if (bn>t) break;
			ll numer=t-bn;
			if (numer<0) break;
			if (numer==0) {
				ll ans=n;
				if (final==-1) final=ans;
				else chkmin(final,ans);
			}
			else if (numer%a==0) {
				ll x=numer/a;
				ll ans=n;
				for (ll i=0;i<n;i++) {
					ans+=x%b;
					x/=b;
				}
				ans+=x;
				if (final==-1) final=ans;
				else chkmin(final,ans);
			}
			bn*=b;
		}
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
		cout << "Testing MultiplyAddPuzzle (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485829639;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MultiplyAddPuzzle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s = 10LL;
				long long t = 40LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = 2LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 1:
			{
				long long s = 10LL;
				long long t = 28LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = 2LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 2:
			{
				long long s = 10LL;
				long long t = 99LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = -1LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 3:
			{
				long long s = 345LL;
				long long t = 12345LL;
				long long a = 1LL;
				long long b = 10LL;
				_expected = 895LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 4:
			{
				long long s = 1000000000000000000LL;
				long long t = 1000000000000000000LL;
				long long a = 1000000000000000000LL;
				long long b = 1000000000000000000LL;
				_expected = 0LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 5:
			{
				long long s = 0LL;
				long long t = 0LL;
				long long a = 0LL;
				long long b = 0LL;
				_expected = 0LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 6:
			{
				long long s = 5LL;
				long long t = 0LL;
				long long a = 0LL;
				long long b = 0LL;
				_expected = 1LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 7:
			{
				long long s = 7LL;
				long long t = 4LL;
				long long a = 2LL;
				long long b = 0LL;
				_expected = 3LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
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
