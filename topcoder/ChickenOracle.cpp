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
bool can(int n, int eggCount, int lieCount, int liarCount) {
		ll oL = lieCount;
		ll pL = liarCount;
		ll egg=eggCount;
		ll sum=n-egg+pL-oL;
		if (sum%2==1) return false;
		ll B=(n-egg+pL-oL)/2;
		ll C=pL-B;
		ll A=egg-C;
		ll D=oL-C;
		if (C+D==oL && B+C==pL && A+C==egg && B+D==n-egg&&A>=0&&B>=0&&C>=0&&D>=0) return true;
		else return false;
}
class ChickenOracle {
	public:
	string theTruth(int n, int eggCount, int lieCount, int liarCount) {
		bool egg=can(n,eggCount,lieCount,liarCount);
		bool c=can(n,eggCount,n-lieCount,liarCount);
		if (egg&&c) return "Ambiguous";
		else if (egg) return "The egg";
		else if (c) return "The chicken";
		else return "The oracle is a lie";
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
		cout << "Testing ChickenOracle (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491238660;
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
		ChickenOracle _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 10;
				int eggCount = 10;
				int lieCount = 0;
				int liarCount = 0;
				_expected = "The egg";
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}
			case 1:
			{
				int n = 60;
				int eggCount = 40;
				int lieCount = 0;
				int liarCount = 30;
				_expected = "The oracle is a lie";
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}
			case 2:
			{
				int n = 60;
				int eggCount = 20;
				int lieCount = 5;
				int liarCount = 25;
				_expected = "The chicken";
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}
			case 3:
			{
				int n = 1000;
				int eggCount = 500;
				int lieCount = 250;
				int liarCount = 250;
				_expected = "Ambiguous";
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}
			/*case 4:
			{
				int n = ;
				int eggCount = ;
				int lieCount = ;
				int liarCount = ;
				_expected = ;
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}*/
			/*case 5:
			{
				int n = ;
				int eggCount = ;
				int lieCount = ;
				int liarCount = ;
				_expected = ;
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
			}*/
			/*case 6:
			{
				int n = ;
				int eggCount = ;
				int lieCount = ;
				int liarCount = ;
				_expected = ;
				_received = _obj.theTruth(n, eggCount, lieCount, liarCount); break;
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
