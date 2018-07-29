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
ll dp[1<<20];
ll n;
ll f(ll z) {
	if (dp[z]!=UNDEF) return dp[z];
	ll ans=0;
	for (ll i=0;i<n;i++) {
		if (z&(1LL<<i)) {
			{
				if (i+1<=n&&!(z&(1LL<<(i+1)))) {
					ll nz=z^(1LL<<i);
					if (i+1<n)nz|=1LL<<(i+1);
					if (!f(nz)) {
						//printf("%lld->%lld wins\n",z,nz);
						ans=1; break;
					}
				}
			}
			{
				if (i+3<=n&&
					(z&(1LL<<(i+1)))&&
					(z&(1LL<<(i+2)))&&
					!(z&(1LL<<(i+3)))) {
					ll nz=z^(1LL<<i);
					if(i+3<n)nz|=1LL<<(i+3);
					if (!f(nz)) {
						//printf("%lld->%lld wins\n",z,nz);
						ans=1; break;
					}
				}
			}
		}
	}
	dp[z]=ans;
	return ans;
}
class EllysCheckers {
	public:
	string getWinner(string board) {
		n=board.length();
		n--;
		ll init=0;
		for (ll i=0;i<n;i++) {
			if (board[i]=='o') init|=1LL<<i;
		}
		for (ll z=0;z<(1<<20);z++) dp[z]=UNDEF;
		dp[0]=0;
		if (f(init)) return "YES";
		else return "NO";
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
		cout << "Testing EllysCheckers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471710931;
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
		EllysCheckers _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board = ".o...";
				_expected = "YES";
				_received = _obj.getWinner(board); break;
			}
			case 1:
			{
				string board = "..o..o";
				_expected = "YES";
				_received = _obj.getWinner(board); break;
			}
			case 2:
			{
				string board = ".o...ooo..oo..";
				_expected = "NO";
				_received = _obj.getWinner(board); break;
			}
			case 3:
			{
				string board = "......o.ooo.o......";
				_expected = "YES";
				_received = _obj.getWinner(board); break;
			}
			case 4:
			{
				string board = ".o..o...o....o.....o";
				_expected = "NO";
				_received = _obj.getWinner(board); break;
			}
			/*case 5:
			{
				string board = ;
				_expected = ;
				_received = _obj.getWinner(board); break;
			}*/
			/*case 6:
			{
				string board = ;
				_expected = ;
				_received = _obj.getWinner(board); break;
			}*/
			/*case 7:
			{
				string board = ;
				_expected = ;
				_received = _obj.getWinner(board); break;
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
