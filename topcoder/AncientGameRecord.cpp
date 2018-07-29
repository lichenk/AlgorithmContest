#include <bits/stdc++.h>
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
class AncientGameRecord {
	public:
	int minimalRemove(int n, int m, vector <int> x, vector <int> y, string d) {
		
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
		cout << "Testing AncientGameRecord (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485831209;
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
		AncientGameRecord _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int x[] = {0,1,1,0};
				int y[] = {0,0,1,1};
				string d = "DRUL";
				_expected = 0;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int x[] = {0,1};
				int y[] = {1,0};
				string d = "LU";
				_expected = 1;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}
			case 2:
			{
				int n = 3;
				int m = 3;
				int x[] = {0,0,0,1,2,1};
				int y[] = {0,1,1,1,1,2};
				string d = "RLDDRL";
				_expected = 1;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}
			case 3:
			{
				int n = 3;
				int m = 3;
				int x[] = {0,0,2,2};
				int y[] = {0,0,2,2};
				string d = "ULDR";
				_expected = 4;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}
			case 4:
			{
				int n = 6;
				int m = 6;
				int x[] = {0,5,4,1,3,2,5,4,2,2,5,4,1,3,2,5};
				int y[] = {5,4,1,1,1,2,3,5,4,2,0,2,0,0,2,1};
				string d = "DRULLLUDRUDLRUDL";
				_expected = 4;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				int x[] = ;
				int y[] = ;
				string d = ;
				_expected = ;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int x[] = ;
				int y[] = ;
				string d = ;
				_expected = ;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int x[] = ;
				int y[] = ;
				string d = ;
				_expected = ;
				_received = _obj.minimalRemove(n, m, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), d); break;
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
