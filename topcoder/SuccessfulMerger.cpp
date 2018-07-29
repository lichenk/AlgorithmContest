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
const ll mn=54;
set<ll> g[mn];
bool seen[mn];
vector<ll> cycle;
vector<ll> st;
bool findcycle(ll x, ll p) {
	if (seen[x]) {
		cycle.clear();
		ll stsz=st.size();
		for (ll i=stsz-1;i>=0;i--) {
			cycle.PB(st[i]);
			if (st[i]==x) break;
		}
		return true;
	}
	seen[x]=true;
	st.PB(x);
	for (auto &y:g[x]) {
		if (y==p) continue;
		if(findcycle(y,x)) {
			return true;
		}
	}
	st.pop_back();
	return false;
}
class SuccessfulMerger {
	public:
	int minimumMergers(vector <int> road) {
		ll n=road.size();
		for (ll i=0;i<n;i++) {
			ll x=i,y=road[i];
			g[x].insert(y);
			g[y].insert(x);
		}
		ll nonleaf=0;
		for (ll x=0;x<n;x++) {
			if (g[x].size()>1) nonleaf++;
		}
		for (ll x=0;x<n;x++) seen[x]=false;
		if (findcycle(0,-1)) {
			for (auto &w:cycle) {
				if (g[w].size()==2) return max(0ll,nonleaf-2);
			}
			return max(0ll,nonleaf-1);
		}
		return max(0ll,nonleaf-1);
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
		cout << "Testing SuccessfulMerger (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1473098679;
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
		SuccessfulMerger _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int road[] = {2, 2, 1, 1, 1};
				_expected = 1;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 1:
			{
				int road[] = {3, 4, 5, 4, 5, 3};
				_expected = 2;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 2:
			{
				int road[] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 1};
				_expected = 1;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 3:
			{
				int road[] = {1, 2, 3, 0};
				_expected = 2;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 4:
			{
				int road[] = {31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4};
				_expected = 25;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 5:
			{
				int road[] = {1, 0};
				_expected = 0;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			/*case 6:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
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
