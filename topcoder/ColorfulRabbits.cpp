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
class ColorfulRabbits {
	public:
	int getMinimum(vector <int> replies) {
		map<ll,ll> h;
		for (auto &w:replies) {
			h[w+1]++;
		}
		ll ans=0;
		for (auto &w:h) {
			ll a=w.first,b=w.second;
			ans+=((b+a-1)/a)*a;
		}
		return ans;
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
		cout << "Testing ColorfulRabbits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484456750;
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
		ColorfulRabbits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int replies[] = { 1, 1, 2, 2 };
				_expected = 5;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
			}
			case 1:
			{
				int replies[] = { 0 };
				_expected = 1;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
			}
			case 2:
			{
				int replies[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 };
				_expected = 499;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
			}
			/*case 3:
			{
				int replies[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int replies[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int replies[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(replies, replies+sizeof(replies)/sizeof(int))); break;
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
