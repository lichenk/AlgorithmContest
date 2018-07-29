#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define INF 9999999999LL
class BridgeBuilding {
	public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
		ll n = a.size() + 1;
		for (ll x = 0; x <= n; x++) {
			for (ll p = 0; p <= n; p++) {
				s[x][p] = INF;
			}
		}		
		for (ll p = 1; p <= n; p++) {
			s[p][p] = 0;
			for (ll x = p+1; x <= n; x++) {
				s[x][p] = s[x-1][p] + a[x-1] + b[x-1];
			}
		}
		for (ll x = 0; x <= n; x++) {
			for (ll p = 0; p <= n; p++) {
				for (ll k = 0; k <= K; k++) {
					aa[x][p][k] = INF;
					ab[x][p][k] = INF;
					ba[x][p][k] = INF;
					bb[x][p][k] = INF;
				}
			}
		}
		aa[1][0][0] = 0;
		bb[1][0][0] = 0;
		aa[1][1][1] = 0;
		bb[1][1][1] = 0;
		ab[1][1][1] = 0;
		ba[1][1][1] = 0;

		for (ll x = 2; x <= n; x++) {
			// TODO: Disqualify if |x-p| is too large (>= answer)
			// Check if a-a, b-b, a-b, b-a out of bounds (assume x is chosen too)
			// Binary search on answer
			for (ll p = 0; p <= x; p++) {
				for (ll k = 0; k <= K; k++) {
					// Case 1: No bridge here
					aa[x][p][k] = min(aa[x][p][k], aa[x-1][p][k] + a[x-1]);
					bb[x][p][k] = min(bb[x][p][k], bb[x-1][p][k] + b[x-1]);
					ab[x][p][k] = min(ab[x][p][k], ab[x-1][p][k] + b[x-1]);
					ba[x][p][k] = min(ba[x][p][k], ba[x-1][p][k] + a[x-1]);
					ab[x][p][k] = max(ab[x][p][k], s[x][p]);
					ba[x][p][k] = max(ba[x][p][k], s[x][p]);
				}
				for (ll k = 1; k <= K; k++) {
					// Case 2: Bridge here
					aa[x][x][k] = min(min(aa[x-1][p][k-1]+a[x-1], ab[x-1][p][k-1] + b[x-1]), aa[x][x][k]);
					bb[x][x][k] = min(min(bb[x-1][p][k-1]+b[x-1], ba[x-1][p][k-1] + a[x-1]), bb[x][x][k]);
					ab[x][x][k] = min(aa[x][x][k], ab[x][x][k]);
					ba[x][x][k] = min(bb[x][x][k], ba[x][x][k]);
				}
			}
		}
		for (ll x = 1; x <= n; x++) {
			for (ll p = 0; p <= x; p++) {

			}
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
		cout << "Testing BridgeBuilding (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449642352;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BridgeBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {2,1,1,1,2};
				int b[] = {1,9,1,9,1};
				int K = 4;
				_expected = 6;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 1:
			{
				int a[] = {1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50};
				int b[] = {50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1};
				int K = 43;
				_expected = 42;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 2:
			{
				int a[] = {50,10,15,31,20,23,7,48,5,50};
				int b[] = {2,5,1,8,3,2,16,11,9,1};
				int K = 3;
				_expected = 124;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 3:
			{
				int a[] = {50,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int b[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,50};
				int K = 4;
				_expected = 17;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 4:
			{
				int a[] = {2,4,10,2,2,22,30,7,28,14,17,6,32,41,1,3,16,20,40,39,6,4,18,3,3,7,
				           3,2,2,14,10,6,38,6,13,3,6,1,23,26,9,17,1,38,1,21,2,12,3,13,28,6,4,
				          10,3,1,1,43,15,11,18,6,41,1,2,5,6,26,43,9,5,13,1,27,1,33,12,16,1,12,
				          1,37,34,6,20,3,21,3,1,17,3,10,2,1,8,25,2,6,7,1,7,22,11,8,49,9,1,7,1,
				          13,17,20,27,31,43,1};
				int b[] = {5,26,1,2,6,2,16,3,15,1,1,38,2,4,6,1,2,3,11,2,2,2,25,16,2,15,45,3,10,
				          4,17,5,6,1,16,13,29,3,1,2,4,47,4,10,1,2,23,3,29,20,4,21,1,28,7,25,6,6,
				          10,1,2,1,17,6,1,28,2,2,12,2,3,42,39,11,18,3,15,4,1,15,3,9,4,26,4,13,41,
				          1,27,1,14,1,2,14,5,33,1,34,5,17,23,3,33,14,23,2,29,18,3,41,1,45,5,4,6,2};
				int K = 5;
				_expected = 1184;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minDiameter(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
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
