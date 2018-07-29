#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class TravellingPurchasingMan {
	public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
		
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
		cout << "Testing TravellingPurchasingMan (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452748299;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TravellingPurchasingMan _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string interestingStores[] = {"1 10 10" , "1 55 31", "10 50 100" };
				string roads[] = {"1 2 10"};
				_expected = 1;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 3;
				string interestingStores[] = {"1 10 10" , "1 55 30", "10 50 100" };
				string roads[] = {"1 2 10"};
				_expected = 2;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 5;
				string interestingStores[] = {"0 1000 17"};
				string roads[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
				_expected = 0;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 3:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
