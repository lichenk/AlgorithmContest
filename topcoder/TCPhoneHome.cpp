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
class TCPhoneHome {
	public:
	long long validNumbers(int digits, vector <string> v) {
		int n=v.size();
		ll ans=1;
		for (int i=0;i<digits;i++) ans*=10;
		for (int x=0;x<n;x++) {
			int xlen=v[x].length();
			bool ok=1;
			for (int y=0;y<n;y++) {
				if (x==y) continue;
				int ylen=v[y].length();
				if ((xlen>ylen)&&(v[x].substr(0,ylen)==v[y])) {
					ok=0;
				}
			}
			if (ok) {
				ll sub=1;
				for (int i=0;i<digits-xlen;i++) sub*=10;
				ans-=sub;
			}
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
		cout << "Testing TCPhoneHome (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520819580;
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
		TCPhoneHome _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int digits = 7;
				string specialPrefixes[] = {"0", "1", "911"};
				_expected = 7990000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 1:
			{
				int digits = 10;
				string specialPrefixes[] = {"0", "1", "911"};
				_expected = 7990000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 2:
			{
				int digits = 8;
				string specialPrefixes[] = {"1", "12", "123"};
				_expected = 90000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 3:
			{
				int digits = 9;
				string specialPrefixes[] = {"12", "13", "14"};
				_expected = 970000000LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 4:
			{
				int digits = 3;
				string specialPrefixes[] = {"411"};
				_expected = 999LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 5:
			{
				int digits = 1;
				string specialPrefixes[] = {"1","0"};
				_expected = 8LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 6:
			{
				int digits = 2;
				string specialPrefixes[] = {"11"};
				_expected = 99LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
			}
			case 7:
			{
				int digits = 2;
				string specialPrefixes[] = {"1","12","3","33","34"};
				_expected = 80LL;
				_received = _obj.validNumbers(digits, vector <string>(specialPrefixes, specialPrefixes+sizeof(specialPrefixes)/sizeof(string))); break;
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
