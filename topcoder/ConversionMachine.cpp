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
class ConversionMachine {
	public:
	int countAll(string word1, string word2, vector <int> costs, int maxCost) {
		
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
		cout << "Testing ConversionMachine (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469910438;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 850.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ConversionMachine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string word1 = "a";
				string word2 = "b";
				int costs[] = {100,2,3};
				int maxCost = 205;
				_expected = 2;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}
			case 1:
			{
				string word1 = "abcba";
				string word2 = "abcba";
				int costs[] = {67,23,43};
				int maxCost = 0;
				_expected = 1;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}
			case 2:
			{
				string word1 = "cccccccc";
				string word2 = "aaaaaaaa";
				int costs[] = {10000000,1,1};
				int maxCost = 100;
				_expected = 40320;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}
			case 3:
			{
				string word1 = "aa";
				string word2 = "cc";
				int costs[] = {1,10,100};
				int maxCost = 1787;
				_expected = 123611681;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}
			/*case 4:
			{
				string word1 = ;
				string word2 = ;
				int costs[] = ;
				int maxCost = ;
				_expected = ;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}*/
			/*case 5:
			{
				string word1 = ;
				string word2 = ;
				int costs[] = ;
				int maxCost = ;
				_expected = ;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
			}*/
			/*case 6:
			{
				string word1 = ;
				string word2 = ;
				int costs[] = ;
				int maxCost = ;
				_expected = ;
				_received = _obj.countAll(word1, word2, vector <int>(costs, costs+sizeof(costs)/sizeof(int)), maxCost); break;
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
