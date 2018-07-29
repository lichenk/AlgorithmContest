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
class SimpleMaze {
	public:
	int findSum(vector <int> moves) {
		
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
		cout << "Testing SimpleMaze (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1519711788;
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
		SimpleMaze _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int moves[] = {1,1,1,1,-1,1,-1,-1,-1,-1,1,-1};
				_expected = 16;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 1:
			{
				int moves[] = {10,10,-10,-10};
				_expected = 33000;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 2:
			{
				int moves[] = {1,3,1,-3,2,1,1,-1,1,2,-2,1,2,1,-6,-4};
				_expected = 629;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 3:
			{
				int moves[] = {3,1,-2,1,1,1,-1,1,1,1,1,1,-3,-6};
				_expected = 237;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 4:
			{
				int moves[] = {-2,-2,-1,-3,-1,1,-1,2,-1,2,-2,-2,-1,-2,-1,-1,-1,3,-1,2,-9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,1,-2,-4,9,-3,-7,-6,-1,-3,2,2,1,2,1,1,1,1,1,-1,1,-1,1,-5,-1,-1,-1,-1,-1,3,1,3,-1,-1,-1,-3,-1,-1,-1,-1,-2,1,-1,2,-1,3,1,2,1,4,-2,9,1,1,2,-1,1,-2,1,1,1,1,1,1,1,1,1,5,-2,1,-2,1,-2,1,-3,2,3,1,3,2,-3,1,-3,2,3,1,2,1,2,1,3};
				_expected = 516034;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 5:
			{
				int moves[] = {1000000,1000000,-1000000,-1000000};
				_expected = 333218986;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			/*case 6:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
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
