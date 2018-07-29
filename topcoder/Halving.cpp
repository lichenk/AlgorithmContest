#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
map<int,int> h;
void gen(int x, int step) {
	if (x==0) return;
	if (h.find(x)!=h.end()) return;
	h[x]=step;
	gen(x/2,step+1);
	gen((x+1)/2,step+1);
}
map<int,int> g[2];
class Halving {
	public:
	int minSteps(vector <int> a) {
		gen(a[0],0);
		int cur=0,nxt=1;
		g[cur]=h;
		for (int i=1;i<a.size();i++) {
			h.clear();
			gen(a[i],0);
			g[nxt].clear();
			for (auto &w:g[cur]) {
				auto it=h.find(w.fst);
				if (it==h.end()) continue;
				g[nxt][w.fst]=w.snd+it->snd;
			}
			swap(cur,nxt);
		}
		int ans=1e9;
		for (auto &w:g[cur]) chkmin(ans,w.snd);
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
		cout << "Testing Halving (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517088153;
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
		Halving _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {11, 4};
				_expected = 3;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {1000000000, 1000000000, 1000000000, 1000000000};
				_expected = 0;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1, 2, 3, 4, 5, 6, 7};
				_expected = 10;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {13, 13, 7, 11, 13, 11};
				_expected = 11;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {1, 1};
				_expected = 0;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.minSteps(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
