#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class ANewHope {
	public:
	int count(vector <int> firstWeek, vector <int> lastWeek, int D) {
		
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
		cout << "Testing ANewHope (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453266313;
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
		ANewHope _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstWeek[] = {1,2,3,4};
				int lastWeek[] = {4,3,2,1};
				int D = 3;
				_expected = 4;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 1:
			{
				int firstWeek[] = {8,5,4,1,7,6,3,2};
				int lastWeek[] = {2,4,6,8,1,3,5,7};
				int D = 3;
				_expected = 3;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 2:
			{
				int firstWeek[] = {1,2,3,4};
				int lastWeek[] = {1,2,3,4};
				int D = 2;
				_expected = 1;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			/*case 3:
			{
				int firstWeek[] = ;
				int lastWeek[] = ;
				int D = ;
				_expected = ;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}*/
			/*case 4:
			{
				int firstWeek[] = ;
				int lastWeek[] = ;
				int D = ;
				_expected = ;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}*/
			/*case 5:
			{
				int firstWeek[] = ;
				int lastWeek[] = ;
				int D = ;
				_expected = ;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
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
