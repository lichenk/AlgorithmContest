#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll fac[200*200+4];
class FoxStones {
	public:
	int getCount(int N, int M, vector <int> sx, vector <int> sy) {
		fac[0]=1;
		for (ll i=1;i<200*200+4;i++) fac[i]=(fac[i-1]*i)%MOD;
		map<vector<int>,int> h;
		ll ss=sx.size();
		for (ll x=1;x<=N;x++) for (ll y=1;y<=M;y++) {
			vector<int> v;
			for (ll k=0;k<ss;k++) {
				ll d=max(abs(x-sx[k]),abs(y-sy[k]));
				v.PB(d);
			}
			h[v]++;
		}
		ll ans=1;
		for (auto &w:h) {
			ll c=w.second;
			ans=(ans*fac[c])%MOD;
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
		cout << "Testing FoxStones (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484460018;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxStones _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 6;
				int M = 1;
				int sx[] = {3};
				int sy[] = {1};
				_expected = 4;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int M = 2;
				int sx[] = {2};
				int sy[] = {1};
				_expected = 6;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int M = 3;
				int sx[] = {1,2,3};
				int sy[] = {1,2,3};
				_expected = 8;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 12;
				int M = 34;
				int sx[] = {5,6,7,8,9,10};
				int sy[] = {11,12,13,14,15,16};
				_expected = 410850247;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				int sx[] = ;
				int sy[] = ;
				_expected = ;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				int sx[] = ;
				int sy[] = ;
				_expected = ;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int sx[] = ;
				int sy[] = ;
				_expected = ;
				_received = _obj.getCount(N, M, vector <int>(sx, sx+sizeof(sx)/sizeof(int)), vector <int>(sy, sy+sizeof(sy)/sizeof(int))); break;
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
