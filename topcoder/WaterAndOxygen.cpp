#include <bits/stdc++.h>
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
class WaterAndOxygen {
	public:
	double maxDays(int _remainH20, int _remainO2, int _costH2O, int _costO2) {
		ld remainH20 =_remainH20; ld remainO2=_remainO2; ld costH2O=_costH2O; ld costO2=_costO2;
		ld imin=0,imax=1e20;
		for (ll k=0;k<3000;k++) {
			ld imid=(imin+imax)/2;
			ld needO2=max(0.0L,costO2*imid-remainO2);
			ld needH20=costH2O*imid+needO2*2;
			if (needH20<=remainH20) imin=imid;
			else imax=imid;
		}
		return imin;
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
		cout << "Testing WaterAndOxygen (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491677578;
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
		WaterAndOxygen _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int remainH20 = 64;
				int remainO2 = 70;
				int costH2O = 3;
				int costO2 = 7;
				_expected = 12.0;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			case 1:
			{
				int remainH20 = 99;
				int remainO2 = 102;
				int costH2O = 1;
				int costO2 = 1;
				_expected = 99.0;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			case 2:
			{
				int remainH20 = 101;
				int remainO2 = 99;
				int costH2O = 1;
				int costO2 = 1;
				_expected = 99.66666666666667;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			case 3:
			{
				int remainH20 = 123456789;
				int remainO2 = 987654321;
				int costH2O = 123;
				int costO2 = 456;
				_expected = 1003713.731707317;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			case 4:
			{
				int remainH20 = 987654321;
				int remainO2 = 123456789;
				int costH2O = 456;
				int costO2 = 123;
				_expected = 1758643.7307692308;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			case 5:
			{
				int remainH20 = 0;
				int remainO2 = 0;
				int costH2O = 13;
				int costO2 = 27;
				_expected = 0.0;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}
			/*case 6:
			{
				int remainH20 = ;
				int remainO2 = ;
				int costH2O = ;
				int costO2 = ;
				_expected = ;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}*/
			/*case 7:
			{
				int remainH20 = ;
				int remainO2 = ;
				int costH2O = ;
				int costO2 = ;
				_expected = ;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}*/
			/*case 8:
			{
				int remainH20 = ;
				int remainO2 = ;
				int costH2O = ;
				int costO2 = ;
				_expected = ;
				_received = _obj.maxDays(remainH20, remainO2, costH2O, costO2); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
