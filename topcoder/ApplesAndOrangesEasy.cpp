#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll a[2001];
class ApplesAndOrangesEasy {
	public:
	int maximumApples(int N, int K, vector <int> info) {
		ll k = K; ll n = N;
		for (ll x = 0; x <= n; x++) {
			a[x] = 0;
		}
		for (auto& x: info) {
			a[x] = 1;
		}
		ll lim = k/2;
		for (ll x = 1; x <= n; x++) {
			ll l = x-(k-1);
			ll r = x;
			if (l < 1) {
				ll diff = 1 - l;
				r += diff;
				l += diff;
			}
			ll sum = 0;
			for (ll y = l; y <= r; y++) {
				sum += a[y];
			}
			bool good = (sum < lim);
			for (; r < min(n,x+(k-1)); r++, l++) {
				sum += a[r+1];
				sum -= a[l];
				good = good && (sum < lim);
			}
			if (good) {
				a[x] = 1;
			}
		}
		ll ans = 0;
		for (ll x = 1; x <= N; x++) {
			//printf("%lld: %lld\n",x,a[x]);
			ans += a[x];
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
		cout << "Testing ApplesAndOrangesEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450936005;
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
		ApplesAndOrangesEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				int info[] = {};
				_expected = 2;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 10;
				int K = 3;
				int info[] = {3, 8};
				_expected = 2;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 9;
				int K = 4;
				int info[] = {1, 4};
				_expected = 5;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int K = 4;
				int info[] = {2, 4};
				_expected = 4;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 23;
				int K = 7;
				int info[] = {3, 2, 9, 1, 15, 23, 20, 19};
				_expected = 10;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
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
