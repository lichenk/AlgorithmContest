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
class SimilarNamesCustom {
	public:
	int count(vector <string> names, vector <int> info1, vector <int> info2) {
		
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
		cout << "Testing SimilarNamesCustom (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1482718602;
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
		SimilarNamesCustom _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = {"kenta", "kentaro", "ken"};
				int info1[] = {0};
				int info2[] = {1};
				_expected = 3;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 1:
			{
				string names[] = {"hideo", "hideto", "hideki", "hide"};
				int info1[] = {0, 0};
				int info2[] = {1, 2};
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 2:
			{
				string names[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
				int info1[] = {0, 1, 3, 5};
				int info2[] = {1, 2, 4, 6};
				_expected = 2;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 3:
			{
				string names[] = {"taro", "jiro", "hanako"};
				int info1[] = {0, 1};
				int info2[] = {1, 0};
				_expected = 0;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 4:
			{
				string names[] = {"alice", "bob", "charlie"};
				int info1[] = {};
				int info2[] = {};
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			case 5:
			{
				string names[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun", "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
				int info1[] = {17, 5, 6, 13, 5};
				int info2[] = {9, 2, 14, 17, 14};
				_expected = 994456648;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}
			/*case 6:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string names[] = ;
				int info1[] = ;
				int info2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), vector <int>(info1, info1+sizeof(info1)/sizeof(int)), vector <int>(info2, info2+sizeof(info2)/sizeof(int))); break;
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
