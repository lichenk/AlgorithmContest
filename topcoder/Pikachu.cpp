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
class Pikachu {
	public:
	vector <int> bestEncoding(vector <int> freq) {
		
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
		cout << "Testing Pikachu (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471969963;
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
		Pikachu _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int freq[] = {1,1};
				int __expected[] = {4, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			case 1:
			{
				int freq[] = {1,1,2};
				int __expected[] = {9, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			case 2:
			{
				int freq[] = {1,1,1,1};
				int __expected[] = {13, 48 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			case 3:
			{
				int freq[] = {2,3,5,7,11,13,17,19};
				int __expected[] = {309, 96 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			case 4:
			{
				int freq[] = {533,533,533,353,335,335};
				int __expected[] = {10290, 288 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			case 5:
			{
				int freq[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
				int __expected[] = {72, 362124467 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}
			/*case 6:
			{
				int freq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int freq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int freq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.bestEncoding(vector <int>(freq, freq+sizeof(freq)/sizeof(int))); break;
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
