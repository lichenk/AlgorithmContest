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
ll f(ll imid, ll R, ll G, ll B, ll need) {
	ll least=imid;
	if (least>min(R,min(G,B))) return -1;
	ll extra=(R-least)+(G-least)+(B-least);
	ll have=min(least/need,extra);
	return have;
}
class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int _N) {
		ll n=_N;
		ll sum=(n*(n+1))/2;
		bool eq=(0==sum%3);
		if (eq) {
			ll need=sum/3;
			return min(R,min(G,B))/need;
		}
		else {
			ll need=sum/3;
			if (need==0) return R+G+B;
			ll imin=0,imax=min(R,min(G,B))+1;
			while(imin<imax) {
				ll imid=(imin+imax)/2;
				ll f0=f(imid, R, G, B, need);
				ll f1=f(imid+1, R, G, B, need);
				if (f0<=f1) {
					imin=imid+1;
				}
				else {
					imax=imid;
				}
			}
			return f(imin, R, G, B, need);
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
		cout << "Testing FoxPaintingBalls (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469724601;
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
		FoxPaintingBalls _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long R = 2LL;
				long long G = 2LL;
				long long B = 2LL;
				int N = 3;
				_expected = 1LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 1:
			{
				long long R = 1LL;
				long long G = 2LL;
				long long B = 3LL;
				int N = 3;
				_expected = 0LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 2:
			{
				long long R = 8LL;
				long long G = 6LL;
				long long B = 6LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 3:
			{
				long long R = 7LL;
				long long G = 6LL;
				long long B = 7LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 4:
			{
				long long R = 100LL;
				long long G = 100LL;
				long long B = 100LL;
				int N = 4;
				_expected = 30LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 5:
			{
				long long R = 19330428391852493LL;
				long long G = 48815737582834113LL;
				long long B = 11451481019198930LL;
				int N = 3456;
				_expected = 5750952686LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 6:
			{
				long long R = 1LL;
				long long G = 1LL;
				long long B = 1LL;
				int N = 1;
				_expected = 3LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			/*case 7:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
			}*/
			/*case 8:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
			}*/
			/*case 9:
			{
				long long R = LL;
				long long G = LL;
				long long B = LL;
				int N = ;
				_expected = LL;
				_received = _obj.theMax(R, G, B, N); break;
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
