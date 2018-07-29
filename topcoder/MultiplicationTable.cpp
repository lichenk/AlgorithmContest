#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class MultiplicationTable {
	public:
	vector <int> getMultiplicationTable(vector <int> firstRow) {
		
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
		cout << "Testing MultiplicationTable (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449390109;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1100.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MultiplicationTable _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstRow[] = {1,2,0};
				int __expected[] = {1, 2, 0, 2, 0, 1, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 1:
			{
				int firstRow[] = {1,1,1};
				int __expected[] = {1, 1, 1, 1, 1, 1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 2:
			{
				int firstRow[] = {0,0,1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 3:
			{
				int firstRow[] = {0,1};
				int __expected[] = {0, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 4:
			{
				int firstRow[] = {2,3,0,1};
				int __expected[] = {2, 3, 0, 1, 3, 0, 1, 2, 0, 1, 2, 3, 1, 2, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 5:
			{
				int firstRow[] = {3,4,5,0,2,1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			case 6:
			{
				int firstRow[] = {0,1,2};
				int __expected[] = {0, 1, 2, 0, 1, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}
			/*case 7:
			{
				int firstRow[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int firstRow[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int firstRow[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMultiplicationTable(vector <int>(firstRow, firstRow+sizeof(firstRow)/sizeof(int))); break;
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
