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
class TheMagicMatrix {
	public:
	int find(int n, vector <int> rows, vector <int> columns, vector <int> values) {
		
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
		cout << "Testing TheMagicMatrix (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483074996;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMagicMatrix _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int rows[] = {0, 1};
				int columns[] = {1, 0};
				int values[] = {4, 4};
				_expected = 10;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int rows[] = {0, 1};
				int columns[] = {1, 0};
				int values[] = {4, 7};
				_expected = 0;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int rows[] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3};
				int columns[] = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2};
				int values[] = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1};
				_expected = 2;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 474;
				int rows[] = {44, 77};
				int columns[] = {47, 74};
				int values[] = {4, 7};
				_expected = 83494518;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
