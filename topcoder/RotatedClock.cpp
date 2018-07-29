#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class RotatedClock {
	public:
	string getEarliest(int hourHand, int minuteHand) {
		ll full=12*60;
		for (ll t=0;t<full;t++) {
			ll h=t*360;
			if (h%full!=0) continue;
			h/=full;
			ll m=(t%60)*360/60;
			for (ll k=0;k<12;k++) {
				if ((h+30*k)%360==hourHand&&(m+30*k)%360==minuteHand) {
					ll hour=t/60;
					ll minute=t%60;
					string hr=to_string(hour);
					string min=to_string(minute);
					if (hr.size()<2) hr='0'+hr;
					if (min.size()<2) min='0'+min;
					return hr+":"+min;
				}
			}
		}
		return "";
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
		cout << "Testing RotatedClock (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483844125;
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
		RotatedClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hourHand = 70;
				int minuteHand = 300;
				_expected = "08:20";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 1:
			{
				int hourHand = 90;
				int minuteHand = 120;
				_expected = "11:00";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 2:
			{
				int hourHand = 240;
				int minuteHand = 36;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 3:
			{
				int hourHand = 19;
				int minuteHand = 19;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 4:
			{
				int hourHand = 1;
				int minuteHand = 12;
				_expected = "00:02";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			/*case 5:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}*/
			/*case 6:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}*/
			/*case 7:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
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
