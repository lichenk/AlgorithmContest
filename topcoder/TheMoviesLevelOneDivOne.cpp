#include "bits/stdc++.h"
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
class TheMoviesLevelOneDivOne {
	public:
	long long find(int _n, int _m, vector <int> row, vector <int> seat) {
		ll n=_n,m=_m;
		ll all=n*(m-1);
		set<pair<int,int> > s;
		int rsz=row.size();
		for (int i=0;i<rsz;i++) {
			int r=row[i],d=seat[i];
			for (int c=max(1LL,(ll)d-1LL);c<=min(m-1,(ll)d);c++) {
				s.insert(MP(r,c));
			}
		}
		ll ans=all-s.size();
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
		cout << "Testing TheMoviesLevelOneDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521477232;
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
		TheMoviesLevelOneDivOne _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 3;
				int row[] = {1, 2};
				int seat[] = {2, 3};
				_expected = 1LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 3;
				int row[] = {1, 1, 1, 2, 2, 2};
				int seat[] = {1, 2, 3, 1, 2, 3};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int m = 7;
				int row[] = {1};
				int seat[] = {1};
				_expected = 23LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 10;
				int m = 8;
				int row[] = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
				int seat[] = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
				_expected = 54LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 1;
				int m = 1;
				int row[] = {1};
				int seat[] = {1};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1;
				int m = 2;
				int row[] = {1,1};
				int seat[] = {1,2};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 1;
				int m = 2;
				int row[] = {1};
				int seat[] = {1};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 1;
				int m = 2;
				int row[] = {1};
				int seat[] = {2};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 8:
			{
				int n = 1;
				int m = 3;
				int row[] = {1};
				int seat[] = {3};
				_expected = 1LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 9:
			{
				int n = 1;
				int m = 3;
				int row[] = {1};
				int seat[] = {1};
				_expected = 1LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 10:
			{
				int n = 1;
				int m = 3;
				int row[] = {1};
				int seat[] = {2};
				_expected = 0LL;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
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
