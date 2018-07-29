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
class EvenRoute {
	public:
	string isItPossible(vector <int> x, vector <int> y, int wantedParity) {
		ll n=x.size();
		for (ll i=0;i<n;i++) {
			if ((abs(x[i]+y[i]))%2==wantedParity) {
				return "CAN";
			}
		}
		return "CANNOT";
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
		cout << "Testing EvenRoute (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471614155;
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
		EvenRoute _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {-1,-1,1,1};
				int y[] = {-1,1,1,-1};
				int wantedParity = 0;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 1:
			{
				int x[] = {-5,-3,2};
				int y[] = {2,0,3};
				int wantedParity = 1;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 2:
			{
				int x[] = {1001, -4000};
				int y[] = {0,0};
				int wantedParity = 1;
				_expected = "CAN";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 3:
			{
				int x[] = {11, 21, 0};
				int y[] = {-20, 42, 7};
				int wantedParity = 0;
				_expected = "CANNOT";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			case 4:
			{
				int x[] = {0, 6};
				int y[] = {10, -20};
				int wantedParity = 1;
				_expected = "CANNOT";
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int wantedParity = ;
				_expected = ;
				_received = _obj.isItPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), wantedParity); break;
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
