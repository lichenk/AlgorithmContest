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
const ll MAXN=2508;
ld f[2][MAXN+60], g[2][MAXN+60];
ld p[MAXN],q[MAXN];
class FixedDiceGameDiv1 {
	public:
	double getExpectation(int a, int b, int _C, int d) {
		if (a*b <= _C) return -1;
		for (ll i=0;i<MAXN;i++) {
			f[0][i]=0; g[0][i]=0;
		}
		f[0][0]=1;
		for (ll i=0;i<a;i++) {
			ll p=i%2; ll c=(i+1)%2;
			for (ll x=0;x<MAXN;x++) {
				f[c][x]=0;
			}
			for (ll x=0;x<MAXN;x++) {
				ld v=f[p][x];
				for (ll j=1;j<=b;j++) {
					f[c][x+j]+=v;
				}
			}
		}
		{
			ll c=a%2;
			for (ll x=0;x<MAXN;x++) p[x]=f[c][x];
		}
		g[0][0]=1;
		for (ll i=0;i<_C;i++) {
			ll p=i%2; ll c=(i+1)%2;
			for (ll x=0;x<MAXN;x++) {
				g[c][x]=0;
			}
			for (ll x=0;x<MAXN;x++) {
				ld v=g[p][x];
				for (ll j=1;j<=d;j++) {
					g[c][x+j]+=v;
				}
			}
		}
		{
			ll c=_C%2;
			for (ll x=0;x<MAXN;x++) q[x]=g[c][x];
		}
		for (ll x=1;x<MAXN;x++) q[x]+=q[x-1];
		ld ans=0;
		ld psum=0;
		for (ll x=1;x<MAXN;x++) {
			ld prob = p[x]*q[x-1];
			psum+=prob;
			ans += prob*x;
		}
		return ans/psum;
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
		cout << "Testing FixedDiceGameDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457236796;
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
		FixedDiceGameDiv1 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 1;
				int d = 5;
				_expected = 2.0;
				_received = _obj.getExpectation(a, b, c, d); break;
			}
			case 1:
			{
				int a = 3;
				int b = 1;
				int c = 1;
				int d = 3;
				_expected = 3.0;
				_received = _obj.getExpectation(a, b, c, d); break;
			}
			case 2:
			{
				int a = 1;
				int b = 5;
				int c = 1;
				int d = 1;
				_expected = 3.4999999999999996;
				_received = _obj.getExpectation(a, b, c, d); break;
			}
			case 3:
			{
				int a = 2;
				int b = 6;
				int c = 50;
				int d = 30;
				_expected = -1.0;
				_received = _obj.getExpectation(a, b, c, d); break;
			}
			case 4:
			{
				int a = 50;
				int b = 11;
				int c = 50;
				int d = 50;
				_expected = 369.8865999182022;
				_received = _obj.getExpectation(a, b, c, d); break;
			}
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getExpectation(a, b, c, d); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getExpectation(a, b, c, d); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getExpectation(a, b, c, d); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
