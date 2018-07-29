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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
class TheDevice {
	public:
	int minimumAdditional(vector <string> plates) {
		ll n=plates[0].length();
		ll m=plates.size();
		ll need=0;
		for (ll x=0;x<n;x++) {
			ll zero=0,one=0;
			for (ll y=0;y<m;y++) {
				if (plates[y][x]=='0') zero++;
				else one++;
			}
			ll cand=max(0LL,1-zero)+max(0LL,2-one);
			need=max(need,cand);
		}
		return need;
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
		cout << "Testing TheDevice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459134765;
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
		TheDevice _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plates[] = {"010",
				                   "011",
				                   "101"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 1:
			{
				string plates[] = {"0",
				                   "1",
				                   "0",
				                   "1"};
				_expected = 0;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 2:
			{
				string plates[] = {"01010101",
				                   "10101010"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 3:
			{
				string plates[] = {"10010101011",
				                   "00010101001",
				                   "00100010111",
				                   "00101010101",
				                   "01010111101"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 4:
			{
				string plates[] = {"1101001011010",
				                   "0010000010101",
				                   "1010101011110",
				                   "1101010100111",
				                   "1011111110111"};
				_expected = 0;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			/*case 5:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
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
