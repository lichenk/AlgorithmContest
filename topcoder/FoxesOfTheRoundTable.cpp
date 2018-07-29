#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class FoxesOfTheRoundTable {
	public:
	vector <int> minimalDifference(vector <int> h) {
		
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
		cout << "Testing FoxesOfTheRoundTable (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449357100;
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
		FoxesOfTheRoundTable _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int h[] = {1,99,50,50};
				int __expected[] = {0, 3, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 1:
			{
				int h[] = {123,456,789};
				int __expected[] = {0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 2:
			{
				int h[] = {10,30,40,50,60};
				int __expected[] = {0, 1, 4, 3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 3:
			{
				int h[] = {1,2,3,4,8,12,13,14 };
				int __expected[] = {0, 1, 2, 3, 5, 6, 7, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 4:
			{
				int h[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
				int __expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			/*case 5:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
