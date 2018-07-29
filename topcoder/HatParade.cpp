#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class HatParade {
	public:
	int getPermutation(vector <int> value, vector <int> sum) {
		
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
		cout << "Testing HatParade (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450902522;
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
		HatParade _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int value[] = {2, 1, 3};
				int sum[] = {3, 1, 6};
				_expected = 2;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}
			case 1:
			{
				int value[] = {1, 1, 1, 1};
				int sum[] = {9, 1, 2, 3};
				_expected = 0;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}
			case 2:
			{
				int value[] = {4, 4, 4, 4};
				int sum[] = {16, 16, 8, 8};
				_expected = 4;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}
			case 3:
			{
				int value[] = {1, 2, 3, 4, 5, 6, 7};
				int sum[] = {1, 27, 6, 22, 18, 21, 7};
				_expected = 2;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}
			/*case 4:
			{
				int value[] = ;
				int sum[] = ;
				_expected = ;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int value[] = ;
				int sum[] = ;
				_expected = ;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int value[] = ;
				int sum[] = ;
				_expected = ;
				_received = _obj.getPermutation(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <int>(sum, sum+sizeof(sum)/sizeof(int))); break;
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
