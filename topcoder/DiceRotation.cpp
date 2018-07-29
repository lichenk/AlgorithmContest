#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=4+2;
const ll mc=6;
const ll UP=0,RIGHT=1,DOWN=2,LEFT=3,FRONT=4,BACK=5;
ll incx[mc]={RIGHT,DOWN,LEFT,UP,FRONT,BACK};
ll incy[mc]={BACK,RIGHT,FRONT,LEFT,UP,DOWN};
ll f[mn][mn][mc];
ll eff(int x, int y) {
	ll s=x+y;
	if (x==4||y==4) return s-1;
	if (x>=2&&y>=2) return 2;
	return 0;
}
ll bruteforce(int goalx, int goaly) {
	memset(f,0,sizeof f);
	f[0][0][0]=1;
	ll lim=mn-1;
	for (ll s=0;s<=2*lim;s++) {
		for (ll x=0;x<lim;x++) {
			ll y=s-x;
			if (0<=y&&y<lim) {
				for (ll c=0;c<6;c++) {
					ll val=f[x][y][c];
					if (s!=0&&c==0) continue;
					f[x+1][y][incx[c]]+=val;
					f[x][y+1][incy[c]]+=val;
				}
			}
		}
	}
	return f[goalx][goaly][0];
}
ll solve(int x, int y) {
	if (x<=4&&y<=4) return bruteforce(x,y);
	else return eff(x,y);
}
class DiceRotation {
	public:
	int theCount(int goalx, int goaly) {
		return solve(goalx,goaly);
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
		cout << "Testing DiceRotation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485058937;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DiceRotation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int goalx = 2;
				int goaly = 2;
				_expected = 2;
				_received = _obj.theCount(goalx, goaly); break;
			}
			case 1:
			{
				int goalx = 5;
				int goaly = 8;
				_expected = 2;
				_received = _obj.theCount(goalx, goaly); break;
			}
			case 2:
			{
				int goalx = 47;
				int goaly = 58;
				_expected = 2;
				_received = _obj.theCount(goalx, goaly); break;
			}
			case 3:
			{
				int goalx = 489;
				int goaly = 489;
				_expected = 2;
				_received = _obj.theCount(goalx, goaly); break;
			}
			case 4:
			{
				int goalx = 1000000000;
				int goaly = 1000000000;
				_expected = 2;
				_received = _obj.theCount(goalx, goaly); break;
			}
			/*case 5:
			{
				int goalx = ;
				int goaly = ;
				_expected = ;
				_received = _obj.theCount(goalx, goaly); break;
			}*/
			/*case 6:
			{
				int goalx = ;
				int goaly = ;
				_expected = ;
				_received = _obj.theCount(goalx, goaly); break;
			}*/
			/*case 7:
			{
				int goalx = ;
				int goaly = ;
				_expected = ;
				_received = _obj.theCount(goalx, goaly); break;
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
