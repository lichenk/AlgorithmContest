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
class OnlySanta {
	public:
	string solve(string s) {
		int lastn=-1;
		for (int i=0;i<s.length();i++) {
			if (s[i]=='N') lastn=i;
		}
		string t="SANTA";
		string ans="";
		int k=0;
		for (int i=0;i<=lastn;i++) {
			char x=s[i];
			ans+=x;
			if (k<t.length()&&x==t[k]) k++;
		}
		for (;k<t.length();k++) ans+=t[k];
		for (int i=lastn+1;i<s.length();i++) ans+=s[i];
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
		cout << "Testing OnlySanta (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515875194;
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
		OnlySanta _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "STANA";
				_expected = "STANTA";
				_received = _obj.solve(S); break;
			}
			case 1:
			{
				string S = "STN";
				_expected = "SANTNA";
				_received = _obj.solve(S); break;
			}
			case 2:
			{
				string S = "RATSNOOOA";
				_expected = "DEARATSNOOOSANTA";
				_received = _obj.solve(S); break;
			}
			case 3:
			{
				string S = "SXAYNTA";
				_expected = "OOOOSOXAYNTOOOOAOOO";
				_received = _obj.solve(S); break;
			}
			case 4:
			{
				string S = "SNTA";
				_expected = "SANTA";
				_received = _obj.solve(S); break;
			}
			case 5:
			{
				string S = "ASNTA";
				_expected = "SASNTAS";
				_received = _obj.solve(S); break;
			}
			case 6:
			{
				string S = "NIELATA";
				_expected = "SANIELATAJA";
				_received = _obj.solve(S); break;
			}
			case 7:
			{
				string S = "X";
				_expected = "SSAAXNNTTAA";
				_received = _obj.solve(S); break;
			}
			case 8:
			{
				string S = "SATA";
				_expected = "SANTASATA";
				_received = _obj.solve(S); break;
			}
			/*case 9:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 10:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
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
