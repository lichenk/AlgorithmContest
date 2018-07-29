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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class CosmicBlocks {
	public:
	int getNumOrders(vector <int> blockTypes, int minWays, int maxWays) {
		
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
		cout << "Testing CosmicBlocks (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470013395;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CosmicBlocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int blockTypes[] = {2,2,2};
				int minWays = 1;
				int maxWays = 1;
				_expected = 6;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 1:
			{
				int blockTypes[] = {1,1,1,1,1,1};
				int minWays = 720;
				int maxWays = 720;
				_expected = 1;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 2:
			{
				int blockTypes[] = {2,2};
				int minWays = 1;
				int maxWays = 2;
				_expected = 3;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 3:
			{
				int blockTypes[] = {1,2};
				int minWays = 1;
				int maxWays = 2;
				_expected = 2;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 4:
			{
				int blockTypes[] = {1};
				int minWays = 1;
				int maxWays = 1;
				_expected = 1;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 5:
			{
				int blockTypes[] = {1,2,4,8};
				int minWays = 5;
				int maxWays = 30;
				_expected = 27;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 6:
			{
				int blockTypes[] = {1,2,3,4,5,6};
				int minWays = 1;
				int maxWays = 720;
				_expected = 4445;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			case 7:
			{
				int blockTypes[] = {7500,1000,7500,1000,7500};
				int minWays = 8;
				int maxWays = 88;
				_expected = 448;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}
			/*case 8:
			{
				int blockTypes[] = ;
				int minWays = ;
				int maxWays = ;
				_expected = ;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}*/
			/*case 9:
			{
				int blockTypes[] = ;
				int minWays = ;
				int maxWays = ;
				_expected = ;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
			}*/
			/*case 10:
			{
				int blockTypes[] = ;
				int minWays = ;
				int maxWays = ;
				_expected = ;
				_received = _obj.getNumOrders(vector <int>(blockTypes, blockTypes+sizeof(blockTypes)/sizeof(int)), minWays, maxWays); break;
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
