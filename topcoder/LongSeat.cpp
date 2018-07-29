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
class LongSeat {
	public:
	vector <string> canSit(int L, vector <int> width) {
		
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
		cout << "Testing LongSeat (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456633161;
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
		LongSeat _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 2;
				int width[] = {1, 1};
				string __expected[] = {"Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 1:
			{
				int L = 10;
				int width[] = {100, 2, 4, 2};
				string __expected[] = {"Stand", "Sit", "Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 2:
			{
				int L = 37;
				int width[] = {3, 7, 5, 6, 4, 4, 1, 3};
				string __expected[] = {"Sit", "Sit", "Sit", "Unsure", "Unsure", "Unsure", "Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 3:
			{
				int L = 400;
				int width[] = {92, 65, 99, 46, 24, 85, 95, 84};
				string __expected[] = {"Sit", "Sit", "Unsure", "Unsure", "Unsure", "Unsure", "Stand", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 4:
			{
				int L = 1000000000;
				int width[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				string __expected[] = {"Sit", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 5:
			{
				int L = 1;
				int width[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				string __expected[] = {"Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			/*case 6:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
