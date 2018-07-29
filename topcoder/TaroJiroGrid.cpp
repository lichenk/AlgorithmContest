#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
vector<string> a;
ll n;
bool check() {
	for (ll j=0;j<n;j++) {
		char c=a[0][j];
		ll cnt=1;
		for (ll i=1;i<n;i++) {
			if (a[i][j]==c) {
				cnt++;
				if (cnt > n/2) return false;
			}
			else {
				c=a[i][j]; cnt=1;
			}
		}
	}
	return true;
}
class TaroJiroGrid {
	public:
	int getNumber(vector <string> grid) {
		n=grid.size();
		a=grid;
		if (check()) return 0;
		for (ll t=0;t<2;t++) {
			char c = t?'B':'W';
			for (ll x=0;x<n;x++) {
				//printf("%lld %c\n",x,c);
				a=grid;
				for (ll y=0;y<n;y++) {
					a[x][y]=c;
				}	
				if (check()) return 1;
			}
		}
		for (ll t=0;t<4;t++) {
			char c = (t&1)?'B':'W';
			char d = (t&2)?'B':'W';
			for (ll x1=0;x1<n;x1++) {
				for (ll x2=x1+1;x2<n;x2++) {
					a=grid;
					for (ll y=0;y<n;y++) {
						a[x1][y]=c;
						a[x2][y]=d;
					}	
					if (check()) return 2;
				}
			}
		}
		return 3;
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
		cout << "Testing TaroJiroGrid (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455341059;
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
		TaroJiroGrid _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"WB",
				                 "BB"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"WB",
				                 "WW"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"WB",
				                 "WB"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"WBBW",
				                 "WBWB",
				                 "WWBB",
				                 "BWWW"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"WBBWBB",
				                 "BBWBBW",
				                 "WWBWBW",
				                 "BWWBBB",
				                 "WBWBBW",
				                 "WWWBWB"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
