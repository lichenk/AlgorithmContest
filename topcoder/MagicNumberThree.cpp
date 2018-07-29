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
int f[55][3];
class MagicNumberThree {
	public:
	int countSubsequences(string s) {
		int n=s.length();
		f[0][0]=1;
		for (int i=0;i<n;i++) {
			int d=s[i]-'0';
			for (int x=0;x<3;x++) {
				int y=(x+d)%3;
				f[i+1][y]+=f[i][x]; f[i+1][y]%=MOD;
				f[i+1][x]+=f[i][x]; f[i+1][x]%=MOD;
			}
		}
		return (f[n][0]-1+MOD)%MOD;
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
		cout << "Testing MagicNumberThree (225.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1518717920;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 225.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MagicNumberThree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "132";
				_expected = 3;
				_received = _obj.countSubsequences(s); break;
			}
			case 1:
			{
				string s = "9";
				_expected = 1;
				_received = _obj.countSubsequences(s); break;
			}
			case 2:
			{
				string s = "333";
				_expected = 7;
				_received = _obj.countSubsequences(s); break;
			}
			case 3:
			{
				string s = "123456";
				_expected = 23;
				_received = _obj.countSubsequences(s); break;
			}
			case 4:
			{
				string s = "00";
				_expected = 3;
				_received = _obj.countSubsequences(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubsequences(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubsequences(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubsequences(s); break;
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
