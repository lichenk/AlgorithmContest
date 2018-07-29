#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class SRMDiv0Easy {
	public:
	int get(int N, vector <int> L, vector <int> R, vector <int> X, vector <int> Y) {
		
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
		cout << "Testing SRMDiv0Easy (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470894236;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SRMDiv0Easy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int L[] = {0,1};
				int R[] = {0,1};
				int X[] = {1,2};
				int Y[] = {2,3};
				_expected = 2;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int L[] = {0,1};
				int R[] = {0,1};
				int X[] = {1,3};
				int Y[] = {2,4};
				_expected = -1;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int L[] = {0,1,0,0,2};
				int R[] = {2,2,1,0,2};
				int X[] = {1,3,1,4,2};
				int Y[] = {11,13,19,15,17};
				_expected = 41;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 12;
				int L[] = {0,0,1,4,9,7,0};
				int R[] = {6,11,11,4,10,11,0};
				int X[] = {1,73,334,1,1,5,362};
				int Y[] = {546,342,645,249,999,535,458};
				_expected = -1;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 200;
				int L[] = {0,49,0,97,0,65,0,55,0,24,0,86,0,139,0,34,0,11,0,62,0,172,0,59,0,97,0,47,0,156,0,24,0,103,0,184,0,130,0,154,0,26,0,121,0,72,0,183,0,5};
				int R[] = {48,199,96,199,64,199,54,199,23,199,85,199,138,199,33,199,10,199,61,199,171,199,58,199,96,199,46,199,155,199,23,199,102,199,183,199,129,199,153,199,25,199,120,199,71,199,182,199,4,199};
				int X[] = {1,1,1,1,2,1,2,2,2,2,1,1,1,1,2,1,1,1,1,1,2,2,2,1,2,1,1,2,2,1,1,1,2,2,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,1};
				int Y[] = {964,962,952,993,983,973,971,954,978,980,958,999,991,978,977,991,971,976,977,998,968,992,951,955,987,981,986,958,968,966,992,957,975,995,958,995,983,985,956,974,966,986,985,999,959,989,980,998,971,973};
				_expected = 24202;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 5;
				int L[] = {};
				int R[] = {};
				int X[] = {};
				int Y[] = {};
				_expected = 0;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
