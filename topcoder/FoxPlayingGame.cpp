#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class FoxPlayingGame {
	public:
	double theMax(int nA, int nB, int paramA, int paramB) {
		ld sa=(ld)paramA/1000.0;
		ld sb=(ld)paramB/1000.0;
		ld final;

		{
			ld ans=0;
			for (ll i=0;i<nA;i++) ans+=sa;
			final=ans;
		}
		{
			ld ans=0;
			for (ll i=0;i<nA;i++) ans+=sa;
			for (ll i=0;i<min(nB,1);i++) ans*=sb;
			chkmax(final,ans);
		}
		{
			ld ans=0;
			for (ll i=0;i<nA;i++) ans+=sa;
			for (ll i=0;i<nB;i++) ans*=sb;
			chkmax(final,ans);
		}
		{
			ld ans=0;
			for (ll i=0;i<nA;i++) ans+=sa;
			for (ll i=0;i<nB-1;i++) ans*=sb;
			chkmax(final,ans);
		}
		return final;
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
		cout << "Testing FoxPlayingGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484435026;
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
		FoxPlayingGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int nA = 5;
				int nB = 4;
				int paramA = 3000;
				int paramB = 2000;
				_expected = 240.0;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			case 1:
			{
				int nA = 3;
				int nB = 3;
				int paramA = 2000;
				int paramB = 100;
				_expected = 6.0;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			case 2:
			{
				int nA = 4;
				int nB = 3;
				int paramA = -2000;
				int paramB = 2000;
				_expected = -8.0;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			case 3:
			{
				int nA = 5;
				int nB = 5;
				int paramA = 2000;
				int paramB = -2000;
				_expected = 160.0;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			case 4:
			{
				int nA = 50;
				int nB = 50;
				int paramA = 10000;
				int paramB = 2000;
				_expected = 5.62949953421312E17;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			case 5:
			{
				int nA = 41;
				int nB = 34;
				int paramA = 9876;
				int paramB = -1234;
				_expected = 515323.9982341775;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}
			/*case 6:
			{
				int nA = ;
				int nB = ;
				int paramA = ;
				int paramB = ;
				_expected = ;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}*/
			/*case 7:
			{
				int nA = ;
				int nB = ;
				int paramA = ;
				int paramB = ;
				_expected = ;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
			}*/
			/*case 8:
			{
				int nA = ;
				int nB = ;
				int paramA = ;
				int paramB = ;
				_expected = ;
				_received = _obj.theMax(nA, nB, paramA, paramB); break;
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
