#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class TwoNumberGroups {
	public:
	int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
		
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
		cout << "Testing TwoNumberGroups (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454196407;
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
		TwoNumberGroups _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int numA[] = {2};
				int B[] = {3,7};
				int numB[] = {1,1};
				_expected = 14;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {100};
				int numA[] = {2};
				int B[] = {1};
				int numB[] = {1};
				_expected = 28;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {5,1};
				int numA[] = {1,1};
				int B[] = {12,999999894};
				int numB[] = {1,1};
				_expected = 202073;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1};
				int numA[] = {1};
				int B[] = {1};
				int numB[] = {100000};
				_expected = 0;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {11795180,41472124,44285836,84280940,117000811,150317409,154188370,167804776,225797581,
				           240995620,301931440,306528163,327332717,333523124,341325123,350292524,400857064,401290197,
				           426573408,427972026,448467719,563926065,574489831,579516358,609409829,659343788,678481187,
				           775710113,806992032,831437250,839580344,842388073,869876247,899553191,902366903,975081878};
				int numA[] = {1188,1769,1782,1757,1527,4958,3083,4439,3621,3958,2655,2250,2079,3885,3598,
				              3236,3035,2286,7340,4127,3126,2904,2592,3082,3789,2776,3907,2368,4005,4863,
				              4482,3307,2459,1436,1656,2007};
				int B[] = {11795180,41472124,44285836,84280940,117000811,150317409,154188370,167804776,225797581,240995620,
				           301931440,306528163,327332717,333523124,341325123,350292524,400857064,401290197,426573408,
				           427972026,448467719,563926065,574489831,579516358,609409829,659343788,678481187,775710113,
				           806992032,831437250,839580344,842388073,869876247,899553191,902366903,942362007,975081878};
				int numB[] = {3024,902,798,2,1426,4959,3082,4439,3622,3958,2653,2249,2081,3884,3599,
				              3237,3033,2285,7340,4125,3127,2904,2592,3082,3789,2775,3907,2369,4006,
				              4863,4483,3307,623,2303,2642,1757,2107};
				_expected = 601548244;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				int numA[] = ;
				int B[] = ;
				int numB[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int numA[] = ;
				int B[] = ;
				int numB[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int numA[] = ;
				int B[] = ;
				int numB[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(numA, numA+sizeof(numA)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(numB, numB+sizeof(numB)/sizeof(int))); break;
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
