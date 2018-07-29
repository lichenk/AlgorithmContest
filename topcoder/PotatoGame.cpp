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
int dp[10000];
int f(int n) {
	if (dp[n]!=-1) return dp[n];
	for (int x=1;x<=n;x*=4) {
		if (!f(n-x)) return 1;
	}
	return 0;
}
int smart(int x) {
	x%=5;
	return x==1||x==3||x==4;
}
class PotatoGame {
	public:
	string theWinner(int n) {
		memset(dp,-1,sizeof dp);
		dp[0]=0;
		for (int x=0;x<=30;x++) {
			//printf("x:%d f:%d\n",x,f(x));
			assert(f(x)==smart(x));
		}
		return smart(n)?"Taro":"Hanako";
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
		cout << "Testing PotatoGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520823287;
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
		PotatoGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = "Taro";
				_received = _obj.theWinner(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = "Hanako";
				_received = _obj.theWinner(n); break;
			}
			case 2:
			{
				int n = 3;
				_expected = "Taro";
				_received = _obj.theWinner(n); break;
			}
			/*case 3:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
			}*/
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
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
