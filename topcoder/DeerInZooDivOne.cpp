#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class DeerInZooDivOne {
	public:
	int getmax(vector <int> a, vector <int> b) {
		
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
		cout << "Testing DeerInZooDivOne (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453272064;
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
		DeerInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 3};
				_expected = 2;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {1, 8, 1, 7, 4, 2, 5, 2};
				int b[] = {5, 3, 6, 8, 2, 6, 8, 0};
				_expected = 4;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0};
				int b[] = {1};
				_expected = 1;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0, 11, 10, 10, 19, 17, 6, 17, 19, 10, 10, 11, 9, 9, 14, 2, 13, 11, 6};
				int b[] = {7, 5, 2, 12, 8, 9, 16, 8, 4, 18, 8, 13, 15, 13, 17, 16, 3, 1, 7};
				_expected = 8;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {14, 13, 28, 15, 20, 4, 9, 6, 1, 23, 19, 25, 25, 8, 14, 16, 2, 8, 15, 25, 22, 22, 28, 10, 10, 14, 24, 27, 8};
				int b[] = {21, 5, 12, 13, 27, 1, 24, 17, 27, 17, 23, 14, 18, 26, 7, 26, 11, 0, 25, 23, 3, 29, 22, 11, 22, 29, 15, 28, 29};
				_expected = 11;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
