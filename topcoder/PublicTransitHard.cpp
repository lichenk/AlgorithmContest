#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class PublicTransitHard {
	public:
	int countValidTeleporters(int N, vector <int> edges, int X) {
		
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
		cout << "Testing PublicTransitHard (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450979878;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1100.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PublicTransitHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int edges[] = {0, 1, 2};
				int X = 1;
				_expected = 1;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 1:
			{
				int N = 3;
				int edges[] = {0, 0};
				int X = 2;
				_expected = 6;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 2:
			{
				int N = 6;
				int edges[] = {0, 0, 0, 1, 1};
				int X = 2;
				_expected = 1;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 3:
			{
				int N = 7;
				int edges[] = {0, 1, 0, 1, 2, 4};
				int X = 3;
				_expected = 0;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 4:
			{
				int N = 16;
				int edges[] = {0, 1, 0, 2, 0, 0, 4, 5, 8, 9, 10, 11, 8, 4, 6};
				int X = 7;
				_expected = 31;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 5:
			{
				int N = 56;
				int edges[] = {0, 1, 1, 3, 1, 5, 1, 0, 8, 8, 10, 10, 12, 10, 10, 8, 16, 16, 18, 19, 19, 21, 19, 19, 24, 25, 25, 27, 18, 0, 30, 30, 30, 33, 34, 34, 34, 30, 38, 39, 39, 38, 42, 43, 0, 45, 45, 45, 48, 45, 45, 51, 45, 53, 54};
				int X = 12;
				_expected = 610;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			/*case 6:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
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
