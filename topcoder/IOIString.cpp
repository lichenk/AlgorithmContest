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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
class IOIString {
	public:
	int countIOIs(vector <string> mask) {
		
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
		cout << "Testing IOIString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458752641;
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
		IOIString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string mask[] = {"IO?"};
				_expected = 1;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}
			case 1:
			{
				string mask[] = {"????"};
				_expected = 4;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}
			case 2:
			{
				string mask[] = {"?II"};
				_expected = 0;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}
			case 3:
			{
				string mask[] = {"I??O??I"};
				_expected = 16;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}
			case 4:
			{
				string mask[] = {"???I???????O???","???????????O??IO????????I???"};
				_expected = 438952513;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}
			/*case 5:
			{
				string mask[] = ;
				_expected = ;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string mask[] = ;
				_expected = ;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string mask[] = ;
				_expected = ;
				_received = _obj.countIOIs(vector <string>(mask, mask+sizeof(mask)/sizeof(string))); break;
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
