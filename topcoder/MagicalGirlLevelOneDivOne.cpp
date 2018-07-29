#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class MagicalGirlLevelOneDivOne {
	public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
		bool has=false;
		for (auto &w:jumpTypes) {
			if (w%2==0) has=true;
		}
		if (has) return "YES";
		if ((x+y)%2==0) return "YES";
		return "NO";
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
		cout << "Testing MagicalGirlLevelOneDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483848413;
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
		MagicalGirlLevelOneDivOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int jumpTypes[] = {2};
				int x = 5;
				int y = 4;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 1:
			{
				int jumpTypes[] = {3};
				int x = 5;
				int y = 4;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 2:
			{
				int jumpTypes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int x = 1000000000;
				int y = -999999999;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 3:
			{
				int jumpTypes[] = {999999999};
				int x = 999999999;
				int y = 0;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			/*case 4:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}*/
			/*case 5:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}*/
			/*case 6:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
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
