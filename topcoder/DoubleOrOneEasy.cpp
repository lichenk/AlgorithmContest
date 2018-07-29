#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define INF 9223372036854775807LL
class DoubleOrOneEasy {
	public:
	int minimalSteps(int ai, int bi, int newAi, int newBi) {
		ll a = ai; ll b = bi; ll newA = newAi; ll newB = newBi;
		ll final = INF;
		ll ans = 0;
		while (newA >= 2*a && newB >= 2*b) {
			//printf("%lld %lld",newA, newB);
			if (newA - a == newB -b && newA-a >= 0) {
				//printf("%lld + %lld = %lld\n",ans,newA-a,ans+(newA-a));
				final = min(final, ans+(newA-a));
			}
			if (newA % 2 == 1 && newB % 2 == 1) {
				newA--; newB--; ans++;
			}
			else if (newA%2 == 0 && newB%2 == 0){
				newA /= 2; newB /= 2; ans++;
			}
			else break;
		}
		if (newA - a == newB -b && newA-a >= 0) {
			final = min(final, ans+(newA-a));
		}
		if (final == INF) return -1;
		else return final;
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
		cout << "Testing DoubleOrOneEasy (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451234628;
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
		DoubleOrOneEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 100;
				int b = 1000;
				int newA = 101;
				int newB = 1001;
				_expected = 1;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 1:
			{
				int a = 100;
				int b = 1000;
				int newA = 202;
				int newB = 2002;
				_expected = 2;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 2:
			{
				int a = 2;
				int b = 2;
				int newA = 1;
				int newB = 1;
				_expected = -1;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 3:
			{
				int a = 1;
				int b = 111111111;
				int newA = 8;
				int newB = 888888888;
				_expected = 3;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 4:
			{
				int a = 1;
				int b = 111111111;
				int newA = 9;
				int newB = 999999999;
				_expected = -1;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 5:
			{
				int a = 1;
				int b = 2;
				int newA = 999999999;
				int newB = 1000000000;
				_expected = 999999998;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 6:
			{
				int a = 100;
				int b = 200;
				int newA = 499;
				int newB = 899;
				_expected = 28;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
			}
			case 7:
			{
				int a = 100;
				int b = 100;
				int newA = 800;
				int newB = 800;
				_expected = 3;
				_received = _obj.minimalSteps(a, b, newA, newB); break;
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
