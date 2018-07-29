#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
ll f[102][102*102];
class XYZCoder {
	public:
	int countWays(int _room, int _size) {
		ll room=_room,size=_size;
		room--;
		memset(f,0,sizeof f);
		f[0][0]=1;
		for (ll x=0;x<room;x++) {
			for (ll y=1;y<102*102;y++) {
				f[x][y]+=f[x][y-1];
				f[x][y]%=MOD;
			}
			ll ybound=(x+1)*size;
			for (ll y=1;y<=ybound;y++) {
				f[x+1][y]+=f[x][y-1];
				f[x+1][y]%=MOD;
			}
		}
		ll ans=0;
		for (ll y=0;y<102*102;y++) {
			ans=(ans+f[room][y])%MOD;
		}
		for (ll x=1;x<=room+1;x++) {
			ans=(ans*x)%MOD;
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
		cout << "Testing XYZCoder (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1476650337;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XYZCoder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int room = 2;
				int size = 1;
				_expected = 2;
				_received = _obj.countWays(room, size); break;
			}
			case 1:
			{
				int room = 1;
				int size = 2;
				_expected = 1;
				_received = _obj.countWays(room, size); break;
			}
			case 2:
			{
				int room = 2;
				int size = 2;
				_expected = 4;
				_received = _obj.countWays(room, size); break;
			}
			case 3:
			{
				int room = 4;
				int size = 5;
				_expected = 6840;
				_received = _obj.countWays(room, size); break;
			}
			case 4:
			{
				int room = 100;
				int size = 100;
				_expected = 718243627;
				_received = _obj.countWays(room, size); break;
			}
			/*case 5:
			{
				int room = ;
				int size = ;
				_expected = ;
				_received = _obj.countWays(room, size); break;
			}*/
			/*case 6:
			{
				int room = ;
				int size = ;
				_expected = ;
				_received = _obj.countWays(room, size); break;
			}*/
			/*case 7:
			{
				int room = ;
				int size = ;
				_expected = ;
				_received = _obj.countWays(room, size); break;
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
