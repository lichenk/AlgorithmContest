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
const int mk=16;
const int mz=1<<mk;
int dp[mz][2];
int vp[2];
const int LOSE=0,DRAW=1,WIN=2;
int f(int z, int p) {
	if (dp[z][p]!=-1) return dp[z][p];
	int ans=LOSE;
	for (int k=0;k<mk;k++) {
		if (z&(1<<k)) continue;
		int nz=z|(1<<k);
		bool win=((nz&vp[p])==vp[p]);
		bool lose=((nz&vp[p^1])==vp[p^1]);
		if (win&&lose) chkmax(ans,DRAW);
		else if (win) chkmax(ans,WIN);
		else if (lose) chkmax(ans,LOSE);
		else {
			chkmax(ans,2-f(nz,p^1));
		}
	}
	return dp[z][p]=ans;
}

class DoorsGame {
	public:
	int determineOutcome(string doors, int trophy) {		
		memset(dp,-1,sizeof dp);
		int n=doors.size();
		int a=0,b=0;
		for (int i=0;i<trophy;i++) {
			a|=1<<(doors[i]-'A');
		}
		for (int i=n-1;i>=trophy;i--) {
			b|=1<<(doors[i]-'A');
		}
		vp[0]=a; vp[1]=b;
		int ans=f(0,0);
		if (ans==DRAW) return 0;
		int same=__builtin_popcount(a&b);
		int x=__builtin_popcount(a&(~b));
		int y=__builtin_popcount(b&(~a));
		if (ans==WIN) {
			return min(2*(x+same)-1, x+same+y);
		}
		else if (ans==LOSE) {
			swap(x,y);
			return -min(2*(x+same), x+same+y);
		}
		else assert(0);
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
		cout << "Testing DoorsGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521175134;
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
		DoorsGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string doors = "ABCD";
				int trophy = 2;
				_expected = 3;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 1:
			{
				string doors = "ABCC";
				int trophy = 2;
				_expected = -2;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 2:
			{
				string doors = "ABABAB";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 3:
			{
				string doors = "ABAPDCAA";
				int trophy = 5;
				_expected = -4;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 4:
			{
				string doors = "MOCFDCE";
				int trophy = 3;
				_expected = 5;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 5:
			{
				string doors = "ABCCDE";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 6:
			{
				string doors = "ABCCD";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 7:
			{
				string doors = "PP";
				int trophy = 1;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 8:
			{
				string doors = "ABB";
				int trophy = 2;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 9:
			{
				string doors = "BAA";
				int trophy = 2;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 10:
			{
				string doors = "AAB";
				int trophy = 2;
				_expected = 1;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 11:
			{
				string doors = "AB";
				int trophy = 1;
				_expected = 1;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 12:
			{
				string doors = "ABCCDA";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 13:
			{
				string doors = "ABCDEFGHIJKLMNOPABCDEFGHIJKLMNOP";
				int trophy = 9;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
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
