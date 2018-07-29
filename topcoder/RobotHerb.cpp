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
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
class RobotHerb {
	public:
	long long getdist(int T, vector <int> a) {
		ll n=a.size();
		ll x=0,y=0;
		ll dir=0;
		for (ll i=0;i<4*n;i++) {
			ll g=a[i%n];
			x+=dx[dir]*g;
			y+=dy[dir]*g;
			dir=(dir+g)%4;
		}
		assert(dir==0);
		ll k=T/4;
		ll left=T%4;
		x*=k;
		y*=k;
		for (ll i=0;i<left*n;i++) {
			ll g=a[i%n];
			x+=dx[dir]*g;
			y+=dy[dir]*g;
			dir=(dir+g)%4;
		}
		return abs(x)+abs(y);
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
		cout << "Testing RobotHerb (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459114946;
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
		RobotHerb _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int T = 1;
				int a[] = {1,2,3};
				_expected = 2LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int T = 100;
				int a[] = {1};
				_expected = 0LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int T = 5;
				int a[] = {1,1,2};
				_expected = 10LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int T = 1000000000;
				int a[] = {100};
				_expected = 100000000000LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int T = 570;
				int a[] = {2013,2,13,314,271,1414,1732};
				_expected = 4112LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int T = 1000000000;
				int a[] = {10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000};
				_expected = 500000000000000000LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 6:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
