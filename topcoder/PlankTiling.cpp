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
ll f[3004][3004];
class PlankTiling {
	public:
	int sumup(int _H, int _W) {
		ll h,w;
		h=_H;
		w=_W;
		for (ll x=0;x<=w;x++) {
			for (ll t=0;t<h;t++) {
				f[x][t]=0;
			}
		}
		f[0][0]=1;
		for (ll x=0;x<=w;x++) {
			for (ll t=0;t<h;t++) {
				ll v = f[x][t]%MOD;
				if (x%h==0) {
					for (ll s=0;s<h;s++) {
						f[x+1][s] += v;
						f[x+1][s]%=MOD;
					}
					f[x+h][0] += v;
					f[x+h][0]%=MOD;
				}
				else {
					f[x+1][t] += v;
					f[x+1][t]%=MOD;
					f[x+h][t] += v;
					f[x+h][t]%=MOD;
				}
			}
		}
		ll ans=0;
		for (ll t=0;t<h;t++) {
			ans += f[w][t];
		}
		return ans%MOD;
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
		cout << "Testing PlankTiling (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456289168;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PlankTiling _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 2;
				int W = 4;
				_expected = 11;
				_received = _obj.sumup(H, W); break;
			}
			case 1:
			{
				int H = 4;
				int W = 4;
				_expected = 5;
				_received = _obj.sumup(H, W); break;
			}
			case 2:
			{
				int H = 3;
				int W = 9;
				_expected = 121;
				_received = _obj.sumup(H, W); break;
			}
			case 3:
			{
				int H = 29;
				int W = 841;
				_expected = 193514715;
				_received = _obj.sumup(H, W); break;
			}
			/*case 4:
			{
				int H = ;
				int W = ;
				_expected = ;
				_received = _obj.sumup(H, W); break;
			}*/
			/*case 5:
			{
				int H = ;
				int W = ;
				_expected = ;
				_received = _obj.sumup(H, W); break;
			}*/
			/*case 6:
			{
				int H = ;
				int W = ;
				_expected = ;
				_received = _obj.sumup(H, W); break;
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
