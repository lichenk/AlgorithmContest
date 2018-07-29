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
const ll MAXN=52;
bool g[MAXN][MAXN];
bool inside(ll x, ll y, ll a, ll b, ll r) {
	return ((x-a)*(x-a)+(y-b)*(y-b)) < (r*r);
}
ll gn;
pair<ll,set<ll> > solve(ll x) {
	set<ll> s;
	{
		for (ll i=0;i<gn;i++) {
			if (g[i][x]) {
				s.insert(i);
			}
		}
	}
	while(1) {
		ll rm=-1;
		for (auto &i:s) {
			for (auto &j: s) {
				if (g[i][j]) {
					rm=i; break;
				}
			}
			if (rm!=-1) break;
		}
		if (rm==-1) break;
		s.erase(rm);
	}
	vector<pair<ll, set<ll> > > v;
	for (auto &w: s) {
		v.PB(solve(w));
	}
	ll fullxor=0;
	for (auto &w: v) {
		fullxor^=w.first;
	}
	set<ll> cands;
	cands.insert(fullxor);
	for (auto &w:v) {
		for (auto &y:w.second) {
			ll possible=fullxor^w.first^y;
			cands.insert(possible);
		}
	}
	ll nim=0;
	while(cands.find(nim)!=cands.end()) nim++;
	return MP(nim,cands);
}

ll go() {
	set<ll> s;
	for (ll i=0;i<gn;i++) s.insert(i);
	while(1) {
		ll rm=-1;
		for (auto &i:s) {
			for (auto &j: s) {
				if (g[i][j]) {
					rm=i; break;
				}
			}
			if (rm!=-1) break;
		}
		if (rm==-1) break;
		s.erase(rm);
	}
	vector<pair<ll, set<ll> > > v;
	for (auto &w: s) {
		v.PB(solve(w));
	}
	ll fullxor=0;
	for (auto &w: v) {
		fullxor^=w.first;
	}
	return fullxor;
}
class CirclesGame {
	public:
	string whoCanWin(vector <int> cx, vector <int> cy, vector <int> cr) {
		ll n=cx.size();
		gn=n;
		for (ll i=0;i<n;i++)
			for (ll j=0;j<n;j++) g[i][j]=false;
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<n;j++) {
				g[i][j]= inside(cx[i]+cr[i],cy[i],cx[j],cy[j],cr[j]);
			}
		}
		ll nim=go();
		if (nim==0) return "Bob";
		else return "Alice";
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
		cout << "Testing CirclesGame (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464191850;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CirclesGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0};
				int y[] = {0};
				int r[] = {1};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 3};
				int y[] = {0, 0};
				int r[] = {1, 1};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 0, 5};
				int y[] = {0, 0, 0};
				int r[] = {1, 2, 1};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 0, 0, 10, 10, 20};
				int y[] = {0, 0, 0, 0, 0, 0};
				int r[] = {1, 2, 3, 1, 2, 1};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {10,20,30,40,50,60,70,80};
				int y[] = {8,7,6,5,4,3,2,1};
				int r[] = {2,2,2,2,2,2,2,2};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {0, 3, 6, 9, 12, -4747, -4777};
				int y[] = {-5858, -5858, -5858, -5858, -5858, 777, 777};
				int r[] = {58, 1, 1, 1, 1, 44, 8};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
				int y[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
				int r[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {9659, -7125, -6257, 7872, 7570, -1172, 7375, 4158, -3041, 8005, 5481, -7277, 9519, -2155, -9347, 836, -7025, 0, 0, 0, 0};
				int y[] = {7657, -6899, -8435, 8657, -3989, 7797, -6908, -3003, 4674, -477, 3196, 6528, -7323, -8396, 8741, -9171, -6490, 0, 0, 0, 0};
				int r[] = {170, 9787, 4960, 4450, 22, 1571, 253, 394, 857, 2105, 210, 959, 1674, 364, 4452, 1150, 1063, 1, 2, 3, 4};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {5054, 2074, 4309, 5131, 3772, -9523, -8269, 7203, 3768, -8999, -481, -5381, -9970, 6921, -59, 1071, -7989, -6309, 5660, -5523, -8369, 1100, 4926, -6595, -9887, 9268, -2804, 7414, 2911, -1889, -4758, -2303, -3951, 7019, 2309};
				int y[] = {-7343, 6155, -8805, -6234, 1587, 6821, 5754, 8067, -6499, -6760, 9762, 6636, -5631, 9805, 1110, -4697, -3350, 1857, -3180, -3401, -9405, 1993, -1732, -9166, 7914, 5056, -8057, -6197, 4747, -4970, 5945, -9007, -875, 8539, -6671};
				int r[] = {1319, 2634, 9440, 5275, 505, 7864, 6085, 2652, 2924, 732, 168, 2302, 3704, 623, 934, 136, 30, 217, 431, 1008, 162, 377, 457, 822, 705, 642, 491, 409, 296, 1537, 240, 9, 683, 2016, 783};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 9:
			{
				int x[] = {0,0,0,0};
				int y[] = {0,0,0,0};
				int r[] = {1,2,3,4};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
