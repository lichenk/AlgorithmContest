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
class LargestSubsequence {
	public:
	string getLargest(string s) {
		ll n=s.length();
		string ans="";
		ll x=0;
		while(x<n) {
			pair<char,ll> best=MP((char)0,-INF);
			for (ll y=x;y<n;y++) {
				chkmax(best,MP(s[y],-y));
			}
			ans+=best.first;
			x=-best.second+1;
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
		cout << "Testing LargestSubsequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483553181;
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
		LargestSubsequence _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "test";
				_expected = "tt";
				_received = _obj.getLargest(s); break;
			}
			case 1:
			{
				string s = "a";
				_expected = "a";
				_received = _obj.getLargest(s); break;
			}
			case 2:
			{
				string s = "example";
				_expected = "xple";
				_received = _obj.getLargest(s); break;
			}
			case 3:
			{
				string s = "aquickbrownfoxjumpsoverthelazydog";
				_expected = "zyog";
				_received = _obj.getLargest(s); break;
			}
			/*case 4:
			{
				string s = ;
				_expected = ;
				_received = _obj.getLargest(s); break;
			}*/
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.getLargest(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.getLargest(s); break;
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
