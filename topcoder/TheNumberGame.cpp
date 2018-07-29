#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class TheNumberGame {
	public:
	string determineOutcome(int A, int B) {
		ll s[100], t[100], r[100];
		ll n = 0;
		while (A > 0) {
			s[n] = A%10;
			A /= 10;
			n++;
		}
		ll m = 0;
		while (B > 0) {
			t[m] = B%10;
			B /= 10;
			m++;
		}
		bool good = false;
		for (ll i = 0; i <= n-m; i++) {
			bool ok = true;
			for (ll j = 0; j < m; j++) {
				if (s[i+j] != t[j]) {
					ok = false;
				}
			}
			if (ok) good = true;
		}
		for (ll i = 0; i < m; i++) {
			r[i] = t[m-1-i];
		}
		for (ll i = 0; i <= n-m; i++) {
			bool ok = true;
			for (ll j = 0; j < m; j++) {
				if (s[i+j] != r[j]) ok = false;
			}
			if (ok) good = true;
		}
		if (good) {
			return "Manao wins";
		}
		else {
			return "Manao loses";
		}
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
		cout << "Testing TheNumberGame (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449732931;
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
		TheNumberGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 45;
				int B = 4;
				_expected = "Manao wins";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 1:
			{
				int A = 45;
				int B = 5;
				_expected = "Manao wins";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 2:
			{
				int A = 99;
				int B = 123;
				_expected = "Manao loses";
				_received = _obj.determineOutcome(A, B); break;
			}
			case 3:
			{
				int A = 2356236;
				int B = 5666;
				_expected = "Manao loses";
				_received = _obj.determineOutcome(A, B); break;
			}
			/*case 4:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.determineOutcome(A, B); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
