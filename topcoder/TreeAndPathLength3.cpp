#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
//#define LIM 4
class TreeAndPathLength3 {
	public:
	vector <int> construct(int s) {
		vector<int> ans;
		/*
		if (s+2 <= LIM-1) {
			for (ll i = 0; i <= s+1; i++) {
				ans.PB(i);
				ans.PB(i+1);
			}
			return ans;
		}
		*/
		ll k = 1;
		while (((k-1)*k) <= s) k++;
		k--;
		ll add = s - (k-1)*k;
		ll v = 1;
		for (ll i = 0; i < k; i++) {
			ans.PB(0); ans.PB(v);
			ans.PB(v); ans.PB(v+1);
			v += 2;
		}
		if (add > 0) {
			ans.PB(2); ans.PB(v);
			v++;
		}
		for (ll i = 1; i < add; i++) {
			ans.PB(v-1); ans.PB(v);
			v++;
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
		cout << "Testing TreeAndPathLength3 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449766464;
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
		TreeAndPathLength3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s = 1;
				int __expected[] = {0, 1, 1, 2, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 1:
			{
				int s = 2;
				int __expected[] = {0, 1, 1, 2, 2, 3, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 2:
			{
				int s = 6;
				int __expected[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 3:
			{
				int s = 8;
				int __expected[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			/*case 4:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}*/
			/*case 5:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}*/
			/*case 6:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
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
