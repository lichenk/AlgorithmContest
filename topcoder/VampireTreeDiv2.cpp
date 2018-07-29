#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class VampireTreeDiv2 {
	public:
	int countMinSamples(vector <int> A, vector <int> B) {
		
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
		cout << "Testing VampireTreeDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737483;
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
		VampireTreeDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {0};
				int B[] = {-1};
				_expected = 2;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {0, 1};
				int B[] = {-1, 0};
				_expected = 3;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {0, 0, 2, 2};
				int B[] = {-1, -1, -1, -1};
				_expected = 2;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {0, 1, 2, 3};
				int B[] = {-1, -1, -1, -1};
				_expected = 1;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {0, 1, 1, 2, 1, 2, 2, 5, 7, 6, 5, 10, 6, 6, 12, 6, 6, 2, 8, 0, 16, 5, 8, 2, 14};
				int B[] = {-1, -1, -1, -1, 0, -1, -1, -1, 2, 7, 10, 11, 7, 9, -1, 5, -1, 15, 4, 7, 9, -1, 13, 6, 24};
				_expected = 78;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {0,1,0,3,0,5,0,7,0,9,0,11,0,13,0,15,0,17,0,19,0,21,0,23,0,25,0,27,0,29,0,31,0,33,0,35,0,37,0,39,0,41,0,43,0,45,0,47,0,49,0,51,0,53,0,55,0,57,0,59,0};
				int B[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
				_expected = 73741818;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.countMinSamples(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
