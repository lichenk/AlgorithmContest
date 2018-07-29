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
class YamanoteLine {
	public:
	long long howMany(int n, vector <int> s1, vector <int> t1, vector <int> l1, vector <int> s2, vector <int> t2, vector <int> l2) {
		
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
		cout << "Testing YamanoteLine (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469683837;
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
		YamanoteLine _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int s1[] = {};
				int t1[] = {};
				int l1[] = {};
				int s2[] = {0,1,2};
				int t2[] = {1,2,0};
				int l2[] = {1,1,1};
				_expected = 1LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int s1[] = {};
				int t1[] = {};
				int l1[] = {};
				int s2[] = {0,1,2};
				int t2[] = {1,2,0};
				int l2[] = {2,2,2};
				_expected = 4LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int s1[] = {};
				int t1[] = {};
				int l1[] = {};
				int s2[] = {0,1,2};
				int t2[] = {2,0,1};
				int l2[] = {3,3,3};
				_expected = 2LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 4;
				int s1[] = {0,1,2,3};
				int t1[] = {2,3,0,1};
				int l1[] = {3,4,4,3};
				int s2[] = {1,3};
				int t2[] = {3,1};
				int l2[] = {5,5};
				_expected = 4LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 4;
				int s1[] = {0,2};
				int t1[] = {2,0};
				int l1[] = {5,5};
				int s2[] = {1,3};
				int t2[] = {3,1};
				int l2[] = {4,4};
				_expected = 0LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 5;
				int s1[] = {};
				int t1[] = {};
				int l1[] = {};
				int s2[] = {0,2};
				int t2[] = {2,4};
				int l2[] = {2,2};
				_expected = -1LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 10;
				int s1[] = {5,7,2,3,9,4,6,0,4,2};
				int t1[] = {0,8,3,9,8,0,8,7,1,7};
				int l1[] = {61,54,20,64,25,73,83,79,86,56};
				int s2[] = {4,5,4,0,8,3,8,5,5,9};
				int t2[] = {5,2,0,1,1,4,7,6,8,3};
				int l2[] = {1951,6102,3625,5737,1590,1228,9234,1342,9060,1008};
				_expected = 5726LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}
			/*case 7:
			{
				int n = ;
				int s1[] = ;
				int t1[] = ;
				int l1[] = ;
				int s2[] = ;
				int t2[] = ;
				int l2[] = ;
				_expected = LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int s1[] = ;
				int t1[] = ;
				int l1[] = ;
				int s2[] = ;
				int t2[] = ;
				int l2[] = ;
				_expected = LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int s1[] = ;
				int t1[] = ;
				int l1[] = ;
				int s2[] = ;
				int t2[] = ;
				int l2[] = ;
				_expected = LL;
				_received = _obj.howMany(n, vector <int>(s1, s1+sizeof(s1)/sizeof(int)), vector <int>(t1, t1+sizeof(t1)/sizeof(int)), vector <int>(l1, l1+sizeof(l1)/sizeof(int)), vector <int>(s2, s2+sizeof(s2)/sizeof(int)), vector <int>(t2, t2+sizeof(t2)/sizeof(int)), vector <int>(l2, l2+sizeof(l2)/sizeof(int))); break;
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
