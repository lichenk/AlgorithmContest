#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll mask = (1ULL<<50ULL) - 1ULL;
class LimitedMemorySeries2 {
	public:
	int getSum(int n, long long x0, long long a, long long b) {
		ll x = x0;
		ll ans = 0;
		for (ll i=0;i<n;i++) {
			ll l=x;
			ll r=x;
			ll k=0;
			while (i-k >= 1 && i+k < n-1) {
				l = ((l-b)^a)&mask;
				r = ((r^a)+b)&mask;
				//printf("%lld %lld %lld %lld\n",x,l,r,k);
				if (l >= x || r >= x) break;
				k++;
			}
			//printf("i:%lld k:%lld\n",i,k);
			ans = (ans+k)%MOD;
			x = ((x ^ a) + b) & mask;
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
		cout << "Testing LimitedMemorySeries2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454780848;
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
		LimitedMemorySeries2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				long long x0 = 2LL;
				long long a = 23LL;
				long long b = 1LL;
				_expected = 2;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 1:
			{
				int n = 100;
				long long x0 = 0LL;
				long long a = 0LL;
				long long b = 1LL;
				_expected = 0;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 2:
			{
				int n = 234234;
				long long x0 = 1125899906842623LL;
				long long a = 123456789123456LL;
				long long b = 987654321549687LL;
				_expected = 1144970;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 3:
			{
				int n = 10000000;
				long long x0 = 12345678912345LL;
				long long a = 98765094309812LL;
				long long b = 34893049812392LL;
				_expected = 65420804;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			/*case 4:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
			}*/
			/*case 5:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
			}*/
			/*case 6:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
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
