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
const ll mt=2e4+4;
ll f[mt],g[mt];
ll solve(ll maxT) {
	ll ans=0;
	for (ll t=0;t<=maxT;t++) {
		ans+=f[t]*g[maxT-t];
		ans%=MOD;
	}
	return ans;
}
class PatrolRoute {
	public:
	int countRoutes(int X, int Y, int minT, int maxT) {
		for (ll t=0;t<=maxT;t++) {
			if (t&1) f[t]=0;
			else {
				ll k=t/2;
				ll num=max(X-k,0LL);
				ll got=num*max(k-1,0LL);
				f[t]=got;
//				if (got) printf("t:%d got:%d\n",t,got);
			}
		}
		for (ll t=0;t<=maxT;t++) {
			if (t&1) g[t]=0;
			else {
				ll k=t/2;
				ll num=max(Y-k,0LL);
				ll got=num*max(k-1,0LL);
				g[t]=got;
			}
		}
		for (ll t=1;t<=maxT;t++) {
			g[t]+=g[t-1];
			g[t]%=MOD;
		}
		ll plus=solve(maxT);
		ll minus=solve(minT-1);
		//printf("recv %d %d\n",plus,minus);
		ll ans=plus-minus;
		ans+=MOD;
		ans%=MOD;
		ans*=6;
		ans%=MOD;
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
		cout << "Testing PatrolRoute (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471239432;
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
		PatrolRoute _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X = 3;
				int Y = 3;
				int minT = 1;
				int maxT = 20000;
				_expected = 6;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 1:
			{
				int X = 3;
				int Y = 3;
				int minT = 4;
				int maxT = 7;
				_expected = 0;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 2:
			{
				int X = 4;
				int Y = 6;
				int minT = 9;
				int maxT = 12;
				_expected = 264;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 3:
			{
				int X = 7;
				int Y = 5;
				int minT = 13;
				int maxT = 18;
				_expected = 1212;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			case 4:
			{
				int X = 4000;
				int Y = 4000;
				int minT = 4000;
				int maxT = 14000;
				_expected = 859690013;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}
			/*case 5:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}*/
			/*case 6:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
			}*/
			/*case 7:
			{
				int X = ;
				int Y = ;
				int minT = ;
				int maxT = ;
				_expected = ;
				_received = _obj.countRoutes(X, Y, minT, maxT); break;
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
