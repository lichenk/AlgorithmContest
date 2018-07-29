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
typedef vector<int> vi;
const int mn=(47*20)+2;
const int BASE=2*mn;
ll h[2][BASE+mn][mn];
ll solve(vi &f, vi &g) {
	int n=f.size();
	memset(h[0],0,sizeof h[0]);
	h[0][BASE][0]=1;
	int sufgsum=0; for (int x=0;x<n;x++) sufgsum+=g[x];
	for (int k=0;k<n;k++) {
		sufgsum-=g[k];
		int cur=k&1; int nxt=cur^1;
		memset(h[nxt],0,sizeof h[0]);
		for (int x=-BASE;x<mn;x++) {
			for (int y=0;y<mn;y++) {
				ll waysnow=h[cur][x+BASE][y];
				if (waysnow==0) continue;
				{
					// Set x to A
					int newx=x+f[k]-g[k];
					int virx=newx+g[k];
					int newy=max(y,virx);
					if (newy<=sufgsum) {
						h[nxt][newx+BASE][newy]+=waysnow;
					}
				}
				{
					// Set x to B
					int newx=x-g[k];
					int newy=max(0,y-g[k]);
					if (sufgsum>=newy) {
						h[nxt][newx+BASE][newy]+=waysnow;
					}
				}
			}
		}
	}
	ll good=0;
	for (int x=0;x<BASE+mn;x++) {
		for (int y=0;y<mn;y++) good+=h[n&1][x][y];
	}
	ll bad=(1LL<<n) - good;
	return bad;
}
class TheMoviesLevelThreeDivOne {
	public:
	long long find(vector <int> f, vector <int> g) {
		ll bads=solve(f,g)+solve(g,f);
		ll good=(1LL<<((ll)f.size()))-bads;
		return good;
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
		cout << "Testing TheMoviesLevelThreeDivOne (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521519339;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMoviesLevelThreeDivOne _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int timeJ[] = {4, 4};
				int timeB[] = {4, 4};
				_expected = 2LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 1:
			{
				int timeJ[] = {1, 4};
				int timeB[] = {4, 2};
				_expected = 1LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 2:
			{
				int timeJ[] = {10, 10, 10, 10};
				int timeB[] = {1, 1, 1, 10};
				_expected = 3LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 3:
			{
				int timeJ[] = {1, 2, 3, 4, 5, 6, 7};
				int timeB[] = {7, 6, 5, 4, 3, 2, 1};
				_expected = 98LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 4:
			{
				vi f,g; for (int i=0;i<47;i++) {f.PB(20); g.PB(20);}
				_expected = 0LL;
				_received = _obj.find(f,g); break;
			}
			/*case 5:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
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
