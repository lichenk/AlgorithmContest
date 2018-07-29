#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class CandleTimer {
	public:
	int differentTime(vector <int> A, vector <int> B, vector <int> len) {
		
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
		cout << "Testing CandleTimer (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454283680;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CandleTimer _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {0,1};
				int B[] = {1,2};
				int len[] = {10,1};
				_expected = 2;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {0,0,0};
				int B[] = {1,2,3};
				int len[] = {1,1,1};
				_expected = 2;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {0,0,0};
				int B[] = {1,2,3};
				int len[] = {1,2,3};
				_expected = 4;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {0,1,1,2,3,3,2,4};
				int B[] = {1,2,3,4,5,6,7,8};
				int len[] = {5,3,2,4,6,8,7,1};
				_expected = 7;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {0,0,0,0};
				int B[] = {1,2,3,4};
				int len[] = {123,456,789,1000};
				_expected = 8;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
				int B[] = {0,1,2,0,0,0,1,0,0,0,2,5,4,7,13,13,6,15,11,18,19,21,22,16,19,19,20,18,22,27};
				int len[] = {59,58,147,169,34,14,150,55,156,151,130,109,124,15,100,1,156,16,38,97,99,132,150,18,27,91,110,127,15,105};
				_expected = 65;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {0};
				int B[] = {1};
				int len[] = {1000};
				_expected = 2;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int len[] = ;
				_expected = ;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int len[] = ;
				_expected = ;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				int B[] = ;
				int len[] = ;
				_expected = ;
				_received = _obj.differentTime(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
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
