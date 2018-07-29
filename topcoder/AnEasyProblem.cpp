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
class AnEasyProblem {
	public:
	int solve(long long sum) {
		for (ll k=0;k<(ll)2e8;k++) {
			ll a=-1;
			ll b=(2*k) + 1;
			ll c=(-k*k-k)/2-sum;
			ll x = (-b+sqrt(b*b-4*a*c))/(2*a);
			if (x>0 && a*x*x+b*x+c == 0) {
				return k;
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
		cout << "Testing AnEasyProblem (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456376434;
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
		AnEasyProblem _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long sum = 6LL;
				_expected = 3;
				_received = _obj.solve(sum); break;
			}
			case 1:
			{
				long long sum = 7LL;
				_expected = -1;
				_received = _obj.solve(sum); break;
			}
			case 2:
			{
				long long sum = 100LL;
				_expected = 15;
				_received = _obj.solve(sum); break;
			}
			case 3:
			{
				long long sum = 1000000000000LL;
				_expected = 1428571;
				_received = _obj.solve(sum); break;
			}
			/*case 4:
			{
				long long sum = LL;
				_expected = ;
				_received = _obj.solve(sum); break;
			}*/
			/*case 5:
			{
				long long sum = LL;
				_expected = ;
				_received = _obj.solve(sum); break;
			}*/
			/*case 6:
			{
				long long sum = LL;
				_expected = ;
				_received = _obj.solve(sum); break;
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
