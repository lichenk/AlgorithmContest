#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll h[1000];
class OddEvenTree {
	public:
	vector <int> getTree(vector <string> x) {
		ll n = x[0].size();
		for (ll j = 0; j < n; j++) {
			if (x[0][j] == 'E') {
				h[j] = 0;
			}
			else {
				h[j] = 1;
			}
		}
		bool good = true;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (x[i][j] == 'E') {
					good = good && (h[i] == h[j]);
				}
				else {
					good = good && (h[i] != h[j]);
				}
			}
		}
		vector<int> ans;
		if (!good) {
			ans.PB(-1);
			return ans;
		}
		ll v = -1;
		for (ll i = 0; i < n; i++) {
			if (h[i] == 1) {
				v = i;
				ans.PB(0);
				ans.PB(i);
			}
		}
		if (v == -1) {
			vector<int> oops;
			oops.PB(-1);
			return oops;
		}
		for (ll i = 1; i < n; i++) {
			if (h[i] == 0) {
				ans.PB(v);
				ans.PB(i);
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
		cout << "Testing OddEvenTree (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449377632;
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
		OddEvenTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x[] = {"EOE",
				              "OEO",
				              "EOE"};
				int __expected[] = {0, 1, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 1:
			{
				string x[] = {"EO",
				              "OE"};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 2:
			{
				string x[] = {"OO",
				              "OE"};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 3:
			{
				string x[] = {"EO",
				              "EE"};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 4:
			{
				string x[] = {"EOEO",
				              "OEOE",
				              "EOEO",
				              "OEOE"};
				int __expected[] = {0, 1, 0, 3, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			/*case 5:
			{
				string x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
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
