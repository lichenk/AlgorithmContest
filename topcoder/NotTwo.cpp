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
class NotTwo {
	public:
	int maxStones(int width, int height) {
		ll final=0;
		for (ll ii=0;ii<2;ii++) {
			ll t=0;
			for (ll x=0;x<width;x++) {
				if(x%4==0||x%4==1) t++;
			}
			ll ans=0;
			for (ll y=0;y<height;y++) {
				if (y%4==0) ans+=t;
				if (y%4==1) ans+=t;
				if (y%4==2) ans+=(width-t);
				if (y%4==3) ans+=(width-t);
			}
			final=max(ans,final);
			swap(width,height);
		}
		return final;

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
		cout << "Testing NotTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457937287;
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
		NotTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 3;
				int height = 2;
				_expected = 4;
				_received = _obj.maxStones(width, height); break;
			}
			case 1:
			{
				int width = 3;
				int height = 3;
				_expected = 5;
				_received = _obj.maxStones(width, height); break;
			}
			case 2:
			{
				int width = 8;
				int height = 5;
				_expected = 20;
				_received = _obj.maxStones(width, height); break;
			}
			/*case 3:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
			}*/
			/*case 4:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
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
