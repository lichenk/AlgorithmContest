#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class FindingKids {
	public:
	long long getSum(int n, int q, int A, int B, int C) {
		
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
		cout << "Testing FindingKids (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737612;
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
		FindingKids _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int q = 2;
				int A = 0;
				int B = 1;
				int C = 1;
				_expected = 15LL;
				_received = _obj.getSum(n, q, A, B, C); break;
			}
			case 1:
			{
				int n = 5;
				int q = 4;
				int A = 3;
				int B = 2;
				int C = 1;
				_expected = 43376LL;
				_received = _obj.getSum(n, q, A, B, C); break;
			}
			case 2:
			{
				int n = 200000;
				int q = 200000;
				int A = 12345;
				int B = 67890;
				int C = 111213141;
				_expected = 133378408428237LL;
				_received = _obj.getSum(n, q, A, B, C); break;
			}
			/*case 3:
			{
				int n = ;
				int q = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getSum(n, q, A, B, C); break;
			}*/
			/*case 4:
			{
				int n = ;
				int q = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getSum(n, q, A, B, C); break;
			}*/
			/*case 5:
			{
				int n = ;
				int q = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getSum(n, q, A, B, C); break;
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
