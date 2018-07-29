#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class SumProduct {
	public:
	int findSum(vector <int> amount, int blank1, int blank2) {
		
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
		cout << "Testing SumProduct (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1504161234;
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
		SumProduct _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int amount[] = {0,2,1,1,0,0,0,0,0,0};
				int blank1 = 2;
				int blank2 = 2;
				_expected = 4114;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 1:
			{
				int amount[] = {1,6,0,0,0,0,0,0,0,0};
				int blank1 = 1;
				int blank2 = 2;
				_expected = 22;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 2:
			{
				int amount[] = {1,2,3,4,5,6,7,8,9,10};
				int blank1 = 15;
				int blank2 = 3;
				_expected = 340242570;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 3:
			{
				int amount[] = {3,14,15,92,65,35,89,79,32,38};
				int blank1 = 46;
				int blank2 = 26;
				_expected = 417461139;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 4:
			{
				int amount[] = {100,100,100,100,100,100,100,100,100,100};
				int blank1 = 100;
				int blank2 = 100;
				_expected = 372980218;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			/*case 5:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 6:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 7:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
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
