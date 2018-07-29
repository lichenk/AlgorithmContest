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
bool f[500],g[500];
class KingXNewCurrency {
	public:
	int howMany(int A, int B, int X) {
		ll a=A,b=B,x=X;
		ll k=__gcd(a,b);
		if (a%x==0&&b%x==0) return -1;
		ll ans=0;
		for (ll y=1;y<=405;y++) {
			ll gc=__gcd(x,y);
			if (0==k%gc) {
				for (ll i=0;i<204;i++) f[i]=0;
				f[0]=true;
				for (ll i=0;i<204;i++) {
					if (f[i]) {
						f[i+a]=true;
						f[i+b]=true;
					}
				}
				for (ll i=0;i<204;i++) g[i]=0;
				g[0]=true;
				for (ll i=0;i<204;i++) {
					if (g[i]) {
						g[i+x]=true;
						g[i+y]=true;
					}
				}
				bool ok=true;
				for (ll i=0;i<204;i++) {
					if (f[i]&&!g[i]) {
						ok=false; break;
					}
				}
				if(ok) {
					ans++;
				}
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
		cout << "Testing KingXNewCurrency (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471615701;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KingXNewCurrency _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 5;
				int B = 8;
				int X = 5;
				_expected = 5;
				_received = _obj.howMany(A, B, X); break;
			}
			case 1:
			{
				int A = 8;
				int B = 4;
				int X = 2;
				_expected = -1;
				_received = _obj.howMany(A, B, X); break;
			}
			case 2:
			{
				int A = 7;
				int B = 4;
				int X = 13;
				_expected = 1;
				_received = _obj.howMany(A, B, X); break;
			}
			case 3:
			{
				int A = 47;
				int B = 74;
				int X = 44;
				_expected = 2;
				_received = _obj.howMany(A, B, X); break;
			}
			case 4:
			{
				int A = 128;
				int B = 96;
				int X = 3;
				_expected = 65;
				_received = _obj.howMany(A, B, X); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int X = ;
				_expected = ;
				_received = _obj.howMany(A, B, X); break;
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
