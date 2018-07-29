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
class JumpFurther {
	public:
	int furthest(int N, int badStep) {
		for (ll x=0;x<=N;x++) {
			ll s=0;
			bool bad=false;
			for (ll y=1;y<=N;y++) {
				if (y==x) continue;
				s+=y;
				if (s==badStep) {bad=true; break;}
			}
			if (!bad) {
				return s;
			}
		}
		return -1;
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
		cout << "Testing JumpFurther (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460694324;
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
		JumpFurther _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int badStep = 2;
				_expected = 3;
				_received = _obj.furthest(N, badStep); break;
			}
			case 1:
			{
				int N = 2;
				int badStep = 1;
				_expected = 2;
				_received = _obj.furthest(N, badStep); break;
			}
			case 2:
			{
				int N = 3;
				int badStep = 3;
				_expected = 5;
				_received = _obj.furthest(N, badStep); break;
			}
			case 3:
			{
				int N = 1313;
				int badStep = 5858;
				_expected = 862641;
				_received = _obj.furthest(N, badStep); break;
			}
			case 4:
			{
				int N = 1;
				int badStep = 757065;
				_expected = 1;
				_received = _obj.furthest(N, badStep); break;
			}
			/*case 5:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
			}*/
			/*case 6:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
			}*/
			/*case 7:
			{
				int N = ;
				int badStep = ;
				_expected = ;
				_received = _obj.furthest(N, badStep); break;
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
