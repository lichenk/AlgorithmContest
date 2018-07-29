#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class BearFair {
	public:
	string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
		
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
		cout << "Testing BearFair (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454728243;
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
		BearFair _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int b = 6;
				int upTo[] = {3,6};
				int quantity[] = {2,4};
				_expected = "fair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int b = 6;
				int upTo[] = {3,6};
				int quantity[] = {2,3};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int b = 6;
				int upTo[] = {1,2,3};
				int quantity[] = {1,1,2};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 50;
				int b = 1000;
				int upTo[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
				             186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
				int quantity[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
				_expected = "fair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 4;
				int b = 1000;
				int upTo[] = {400,600};
				int quantity[] = {4,0};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
