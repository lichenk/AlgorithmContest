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
const ll mn=1e6+4;
bool sn[mn];
class MultiplyXPlusOne {
	public:
	int minimalSteps(int s, int t) {
		queue<pair<ll,ll> > q;
		q.push(MP(s,0LL));
		while(!q.empty()) {
			auto get=q.front();
			q.pop();
			ll x=get.first,y=get.second;
			if (x==t) return y;
			{
				ll c=2*x+1;
				if (c<mn&&!sn[mn]) {
					sn[c]=true;
					q.push(MP(c,y+1));
				}
			}
			{
				ll c=3*x+1;
				if (c<mn&&!sn[mn]) {
					sn[c]=true;
					q.push(MP(c,y+1));
				}
			}
		}
		return -1;
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
		cout << "Testing MultiplyXPlusOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470974733;
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
		MultiplyXPlusOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s = 1;
				int t = 22;
				_expected = 3;
				_received = _obj.minimalSteps(s, t); break;
			}
			case 1:
			{
				int s = 1;
				int t = 31;
				_expected = 3;
				_received = _obj.minimalSteps(s, t); break;
			}
			case 2:
			{
				int s = 100;
				int t = 99;
				_expected = -1;
				_received = _obj.minimalSteps(s, t); break;
			}
			case 3:
			{
				int s = 55555;
				int t = 1000000;
				_expected = 3;
				_received = _obj.minimalSteps(s, t); break;
			}
			case 4:
			{
				int s = 1;
				int t = 1;
				_expected = 0;
				_received = _obj.minimalSteps(s, t); break;
			}
			/*case 5:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.minimalSteps(s, t); break;
			}*/
			/*case 6:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.minimalSteps(s, t); break;
			}*/
			/*case 7:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.minimalSteps(s, t); break;
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
