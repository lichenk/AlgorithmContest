#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class ShufflingCardsDiv1 {
	public:
	int shuffle(vector <int> permutation) {
		
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
		cout << "Testing ShufflingCardsDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453829335;
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
		ShufflingCardsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int permutation[] = {1,2,3,4};
				_expected = 0;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 1:
			{
				int permutation[] = {1,4,3,2};
				_expected = 2;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 2:
			{
				int permutation[] = {6,3,5,2,4,1};
				_expected = 4;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 3:
			{
				int permutation[] = {8,5,4,9,1,7,6,10,3,2};
				_expected = 2;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 4:
			{
				int permutation[] = {9,1,7,2,10,3,6,4,8,5};
				_expected = 4;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			/*case 5:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.shuffle(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
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
