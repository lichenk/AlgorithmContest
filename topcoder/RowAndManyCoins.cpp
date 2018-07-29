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
class RowAndManyCoins {
	public:
	string getWinner(string cells) {
		ll a=0,b=0;
		ll n=cells.size();
		if (cells[0]=='A') a++;
		else b++;
		for (ll x=1;x<n;x++) {
			if (cells[x]!=cells[x-1]) {
				if (cells[x]=='A') a++;
				else b++;
			}
		}
		if (a>=b) return "Alice";
		else return "Bob";
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
		cout << "Testing RowAndManyCoins (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1473445145;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RowAndManyCoins _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cells = "ABBB";
				_expected = "Alice";
				_received = _obj.getWinner(cells); break;
			}
			case 1:
			{
				string cells = "BBBB";
				_expected = "Bob";
				_received = _obj.getWinner(cells); break;
			}
			case 2:
			{
				string cells = "BA";
				_expected = "Alice";
				_received = _obj.getWinner(cells); break;
			}
			case 3:
			{
				string cells = "BABBABBB";
				_expected = "Bob";
				_received = _obj.getWinner(cells); break;
			}
			case 4:
			{
				string cells = "ABABBBABAABBAA";
				_expected = "Alice";
				_received = _obj.getWinner(cells); break;
			}
			case 5:
			{
				string cells = "BBBAAABBAAABBB";
				_expected = "Bob";
				_received = _obj.getWinner(cells); break;
			}
			/*case 6:
			{
				string cells = ;
				_expected = ;
				_received = _obj.getWinner(cells); break;
			}*/
			/*case 7:
			{
				string cells = ;
				_expected = ;
				_received = _obj.getWinner(cells); break;
			}*/
			/*case 8:
			{
				string cells = ;
				_expected = ;
				_received = _obj.getWinner(cells); break;
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
