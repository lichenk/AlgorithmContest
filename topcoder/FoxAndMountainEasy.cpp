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
class FoxAndMountainEasy {
	public:
	string possible(int n, int h0, int hn, string history) {
		ll mingo=0;
		ll inc=0;
		for (auto &c:history) {
			if (c=='U') inc++;
			else inc--;
			chkmin(mingo,inc);
		}
		ll diff=hn-(inc+h0);
		ll adiff=abs(diff);
		ll fr=n-history.length();
		ll exc=fr-adiff;
		if (exc<0) return "NO";
		if (0!=(exc%2)) return "NO";
		exc/=2;
		ll u=adiff+exc; ll d=exc;
		if (diff<0) swap(u,d);
		if (h0+mingo+u<0) return "NO";
		return "YES";
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
		cout << "Testing FoxAndMountainEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1467582437;
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
		FoxAndMountainEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int h0 = 0;
				int hn = 4;
				string history = "UU";
				_expected = "YES";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 1:
			{
				int n = 4;
				int h0 = 0;
				int hn = 4;
				string history = "D";
				_expected = "NO";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 2:
			{
				int n = 4;
				int h0 = 100000;
				int hn = 100000;
				string history = "DDU";
				_expected = "YES";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 3:
			{
				int n = 4;
				int h0 = 0;
				int hn = 0;
				string history = "DDU";
				_expected = "NO";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 4:
			{
				int n = 20;
				int h0 = 20;
				int hn = 20;
				string history = "UDUDUDUDUD";
				_expected = "YES";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 5:
			{
				int n = 20;
				int h0 = 0;
				int hn = 0;
				string history = "UUUUUUUUUU";
				_expected = "YES";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 6:
			{
				int n = 20;
				int h0 = 0;
				int hn = 0;
				string history = "UUUUUUUUUUU";
				_expected = "NO";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 7:
			{
				int n = 2;
				int h0 = 0;
				int hn = 1;
				string history = "";
				_expected = "NO";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			case 8:
			{
				int n = 4;
				int h0 = 4;
				int hn = 0;
				string history = "DDUU";
				_expected = "NO";
				_received = _obj.possible(n, h0, hn, history); break;
			}
			/*case 9:
			{
				int n = ;
				int h0 = ;
				int hn = ;
				string history = ;
				_expected = ;
				_received = _obj.possible(n, h0, hn, history); break;
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
