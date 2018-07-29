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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=54;
vector<ll> g[MAXN];
vector<int> hs;
ll n;
ll binsearch(ll key) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (hs[imid]<key) imin=imid+1;
		else imax=imid;
	}
	return imin;
}
ll f[MAXN][MAXN];
class SkiResorts {
	public:
	long long minCost(vector <string> road, vector <int> alt) {
		n=road.size();
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				if (road[x][y]=='Y') g[x].PB(y);
			}
		}
		hs=alt;
		sort(hs.begin(),hs.end());
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				f[x][y]=INF;
			}
		}
		for (ll y=0;y<n;y++) {
			f[0][y] = abs(alt[0]-hs[y]);
		}
		for (ll t=0;t<=n+20;t++) {
			for (ll x1=0;x1<n;x1++) {
				for (ll y1=0;y1<n;y1++) {
					ll val=f[x1][y1];
					if (val>=INF) continue;
					for (auto &x2: g[x1]) {
						for (ll y2=0;y2<=y1;y2++) {
							chkmin(f[x2][y2],val+abs(alt[x2]-hs[y2]));
						}
					}
				}
			}
		}
		ll ans=INF;
		for (ll y=0;y<n;y++) {
			chkmin(ans,f[n-1][y]);
		}
		if (ans>=INF) return -1;
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
		cout << "Testing SkiResorts (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458921312;
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
		SkiResorts _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string road[] = {"NYN",
				                 "YNY",
				                 "NYN"};
				int altitude[] = {30, 20, 10};
				_expected = 0LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 1:
			{
				string road[] = {"NY",
				                 "YN"};
				int altitude[] = {10, 20};
				_expected = 10LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 2:
			{
				string road[] = {"NYN",
				                 "YNN",
				                 "NNN"};
				int altitude[] = {573, 573, 573};
				_expected = -1LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 3:
			{
				string road[] = {"NNYNNYYYNN",
				                 "NNNNYNYNNN",
				                 "YNNNNYYNNN",
				                 "NNNNNNYNYY",
				                 "NYNNNNNNYY",
				                 "YNYNNNNYNN",
				                 "YYYYNNNYNN",
				                 "YNNNNYYNNN",
				                 "NNNYYNNNNN",
				                 "NNNYYNNNNN"};
				int altitude[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
				_expected = 12LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			/*case 4:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string road[] = ;
				int altitude[] = ;
				_expected = LL;
				_received = _obj.minCost(vector <string>(road, road+sizeof(road)/sizeof(string)), vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
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
