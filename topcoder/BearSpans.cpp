#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 1004
bool g[MAXN][MAXN];
class BearSpans {
	public:
	vector <int> findAnyGraph(int n, int m, int k) {
		ll oldm = m;
		vector<int> ans;
		vector<int> fail;
		fail.PB(-1);
		set<ll> comp;
		for (ll x = 1; x <= n; x++) comp.insert(x);
		for (ll t = 0; t < k-1; t++) {
			ll sz = comp.size();
			if (sz == 1)
			{
				return fail;
			}
			else {
				m -= (sz+1)/2;
				if (m < 0) return fail;
				vector<ll> v;
				for (auto &c: comp) {
					v.PB(c);
				}
				for (ll i = 0; i < sz; i++) {
					ll c = v[i];
					ans.PB(c);
					if (i%2 != 0) {
						comp.erase(c);
					}
				}
				if (sz % 2 != 0) {
					comp.erase(v[sz-1]);
					ans.PB(v[sz-2]);
				}
			}
		}
		{
			ll sz = comp.size();
			if (sz == 1) {
				return fail;
			}
			vector<ll> v;
			for (auto &c: comp) {
				v.PB(c);
			}
			for (ll i = 1; i < sz; i++) {
				ans.PB(v[0]);
				ans.PB(v[i]);
				m--;
			}
			if (m < 0) return fail;
		}
		{
			ll sz = ans.size();
			for (ll x = 1; x <= n; x++) {
				for (ll y = 1; y <= n; y++) {
					g[x][y] = false;
				}
				g[x][x] = true;
			}
			for (ll i = 0; i < sz; i+=2) {
				ll x = ans[i]; ll y = ans[i+1];
				g[x][y] = true;
				g[y][x] = true;
			}
			for (ll x = 1; x <= n; x++) {
				if (m == 0) break;
				for (ll y = 1; y <= n; y++) {
					if (m == 0) break;
					if (!g[x][y]) {
						ans.PB(x); ans.PB(y);
						g[x][y] = true;
						g[y][x] = true;
						m--;
					}
					if (m == 0) break;
				}
				if (m == 0) break;
			}

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
		cout << "Testing BearSpans (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453998386;
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
		BearSpans _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 17;
				int m = 22;
				int k = 1;
				int __expected[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 1:
			{
				int n = 9;
				int m = 12;
				int k = 3;
				int __expected[] = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 2:
			{
				int n = 9;
				int m = 12;
				int k = 7;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 3:
			{
				int n = 1000;
				int m = 999;
				int k = 970;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 4:
			{
				int n = 2;
				int m = 1;
				int k = 1;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 5:
			{
				int n = 3;
				int m = 2;
				int k = 1;
				int __expected[] = {1, 2, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 6:
			{
				int n = 3;
				int m = 3;
				int k = 2;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			/*case 7:
			{
				int n = ;
				int m = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}*/
			/*case 9:
			{
				int n = ;
				int m = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
