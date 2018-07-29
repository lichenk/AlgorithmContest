#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class LockersDivOne {
	public:
	int lastOpened(int n) {
		if (n==1) return 1;
		list<ll> s;
		ll k;
		if (n<=100) {
			k=2;
			for (ll x=1;x<=n;x++) s.PB(x);
		}
		else {
			k=4;
			for (ll x=2;x<=n;x+=2) {
				if ((x-2)%6!=0) s.PB(x);
			}
		}
		ll sz=s.size();
		while(1) {
			ll x=0;
			for (auto it=s.begin();it!=s.end();) {
				if (x%k==0) {
					//printf("Erase:%d x:%d\n",*it,x);
					it=s.erase(it);
					sz--;
					if (sz==1) {
						return *(s.begin());
					}
				}
				else {
					++it;
				}
				x++;
			}
			k++;
		}
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
		cout << "Testing LockersDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488652593;
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
		LockersDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 9;
				_expected = 6;
				_received = _obj.lastOpened(N); break;
			}
			case 1:
			{
				int N = 42;
				_expected = 42;
				_received = _obj.lastOpened(N); break;
			}
			case 2:
			{
				int N = 314;
				_expected = 282;
				_received = _obj.lastOpened(N); break;
			}
			case 3:
			{
				int N = 2000000;
				_expected = -1;
				_received = _obj.lastOpened(N); break;
			}
			case 4:
			{
				int N = 1;
				_expected = 1;
				_received = _obj.lastOpened(N); break;
			}
			case 5:
			{
				int N = 2;
				_expected = 2;
				_received = _obj.lastOpened(N); break;
			}
			case 6:
			{
				int N = 3;
				_expected = 2;
				_received = _obj.lastOpened(N); break;
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
