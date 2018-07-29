#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class VampireTree {
	public:
	int maxDistance(vector <int> num) {
		ll n = num.size();
		ll best = -1;
		for (ll x = 0; x < n; x++) {
			ll r = num[x];
			vector<ll> a;
			ll numzero = 0;
			for (ll i = 0; i < n; i++) {
				if (i != x) {
					if (num[i]-1 == 0) {
						numzero++;
					}
					else {
						a.PB(num[i]-1);
					}
				}
			}
			a.PB(r);
			ll k = a.size();
			ll needed_zeros = 1;
			for (ll i = 0; i < k; i++) {
				needed_zeros += (a[i] - 1);
			}
			if (numzero == needed_zeros) {
				ll dist = k;
				if (r >= 2) {
					dist++;
				}
				best = max(dist, best);
			}
		}
		return best;
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
		cout << "Testing VampireTree (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1448935203;
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
		VampireTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int num[] = {1, 2, 1};
				_expected = 2;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 1:
			{
				int num[] = {2, 2, 2};
				_expected = -1;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 2:
			{
				int num[] = {1, 1, 1, 1, 4};
				_expected = 2;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 3:
			{
				int num[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
				_expected = -1;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 4:
			{
				int num[] = {4,3,2,1,1,1,1,1};
				_expected = 4;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 5:
			{
				int num[] = {1,1};
				_expected = 1;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 6:
			{
				int num[] = {2,3,4,2,1,1,1,1,1};
				_expected = 5;
				_received = _obj.maxDistance(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
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
