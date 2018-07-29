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
vector<ll>gb;
inline ll getceil(ll s, ll d) {
	return (s+d-1)/d;
}
bool solve(ll s) {
	ll got=0;
	set<ll> h;
	for (auto &w:gb) {
		ll lower=getceil(s,w+1);
		lower=max(lower,1LL);
		while(h.find(lower)!=h.end()) lower++;
		h.insert(lower);
		got+=lower;
	}
	bool ok=(got<=s);
	return ok;
}
class DivisibleSetDiv1 {
	public:
	string isPossible(vector <int> b) {
		time_t tstart = clock();
		for (auto &w:b) gb.PB(w);
		for (ll s=0;;s++) {
			if (0==(s&0xff)) {
				if ((clock()-tstart) > 1.6 * CLOCKS_PER_SEC) {
					return "Impossible";
				}
			}
			if (solve(s)) {
				return "Possible";
			}
		}
		return "Impossible";
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
		cout << "Testing DivisibleSetDiv1 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471518002;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DivisibleSetDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int b[] = {2,1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int b[] = {1,1};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int b[] = {7, 7, 7};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int b[] = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int b[] = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8,5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int b[] = {2,2};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int b[] = {3,1,3};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
