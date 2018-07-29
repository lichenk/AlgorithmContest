#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class BunnyComputer {
	public:
	int getMaximum(vector <int> preference, int k) {
		
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
		cout << "Testing BunnyComputer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486953912;
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
		BunnyComputer _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int preference[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
				int k = 2;
				_expected = 28;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}
			case 1:
			{
				int preference[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
				int k = 1;
				_expected = 31;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}
			case 2:
			{
				int preference[] = { 1, 2, 3, 4, 5, 6 };
				int k = 3;
				_expected = 14;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}
			case 3:
			{
				int preference[] = { 487, 2010 };
				int k = 2;
				_expected = 0;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}
			/*case 4:
			{
				int preference[] = ;
				int k = ;
				_expected = ;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				int preference[] = ;
				int k = ;
				_expected = ;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int preference[] = ;
				int k = ;
				_expected = ;
				_received = _obj.getMaximum(vector <int>(preference, preference+sizeof(preference)/sizeof(int)), k); break;
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
