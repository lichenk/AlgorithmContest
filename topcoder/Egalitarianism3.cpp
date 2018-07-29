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
vector<pair<ll,ll> > g[52];
ll dist[52];
vector<int> ga,gb,glen;
unordered_map<ll,ll> f[52];
void dfs(ll x, ll p) {
	f[x][0]++;
	for (auto &wl:g[x]) {
		ll w=wl.first; ll l=wl.second;
		if (w==p) continue;
		dfs(w,x);
		for (auto &pp:f[w]) {
			ll dist=pp.first;
			ll cnt=pp.second;
			if(cnt>0) {
				f[x][dist+l]++; //Only inc by 1
			}
		}
	}
}
class Egalitarianism3 {
	public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		ga=a,gb=b,glen=len;
		for (ll i=0;i<n-1;i++) {
			ll x=a[i]-1,y=b[i]-1;
			g[x].PB(MP(y,len[i])); g[y].PB(MP(x,len[i]));
		}
		ll ans = min(2,n);
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) f[y].clear();
			dfs(x,-1LL);
			for (auto &w:f[x]) {
				ans = max(ans, w.second);
			}
			//assert(false);
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
		cout << "Testing Egalitarianism3 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457025683;
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
		Egalitarianism3 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int a[] = {1,1,1};
				int b[] = {2,3,4};
				int len[] = {1,1,1};
				_expected = 3;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 6;
				int a[] = {1,2,3,2,3};
				int b[] = {2,3,4,5,6};
				int len[] = {2,1,3,2,3};
				_expected = 3;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 10;
				int a[] = {1,1,1,1,1,1,1,1,1};
				int b[] = {2,3,4,5,6,7,8,9,10};
				int len[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
				_expected = 9;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int a[] = {};
				int b[] = {};
				int len[] = {};
				_expected = 1;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 2;
				int a[] = {1};
				int b[] = {2};
				int len[] = {3};
				_expected = 2;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 4;
				int a[] = {1,1,1};
				int b[] = {2,3,4};
				int len[] = {3,4,5};
				_expected = 2;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int len[] = ;
				_expected = ;
				_received = _obj.maxCities(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(len, len+sizeof(len)/sizeof(int))); break;
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
