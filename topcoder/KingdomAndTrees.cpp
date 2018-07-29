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
class KingdomAndTrees {
	public:
	int minLevel(vector <int> heights) {
		ll imin=0,imax=1e12;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			ll prev=-1;
			bool ok=true;
			for (auto &w:heights) {
				ll lo=max(1LL,w-imid); ll hi=w+imid;
				if (!(hi>prev)) ok=false;
				ll take=max(lo,prev+1);
				prev=take;
			}
			if (!ok) imin=imid+1;
			else imax=imid;
		}
		return imin;
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
		cout << "Testing KingdomAndTrees (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470672752;
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
		KingdomAndTrees _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heights[] = {9, 5, 11};
				_expected = 3;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 1:
			{
				int heights[] = {5, 8};
				_expected = 0;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 2:
			{
				int heights[] = {1, 1, 1, 1, 1};
				_expected = 4;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 3:
			{
				int heights[] = {548, 47, 58, 250, 2012};
				_expected = 251;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			/*case 4:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.minLevel(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
