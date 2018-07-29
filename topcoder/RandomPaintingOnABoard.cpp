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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
class RandomPaintingOnABoard {
	public:
	double expectedSteps(vector <string> prob) {
		
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
		cout << "Testing RandomPaintingOnABoard (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457329896;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomPaintingOnABoard _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string prob[] = {"10",
				                 "01"};
				_expected = 3.0;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}
			case 1:
			{
				string prob[] = {"11",
				                 "11"};
				_expected = 3.6666666666666665;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}
			case 2:
			{
				string prob[] = {"11",
				                 "12"};
				_expected = 3.9166666666666665;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}
			case 3:
			{
				string prob[] = {"0976",
				                 "1701",
				                 "7119"};
				_expected = 11.214334077031307;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}
			case 4:
			{
				string prob[] = {"000000000000001000000",
				                 "888999988889890999988",
				                 "988889988899980889999",
				                 "889898998889980999898",
				                 "988889999989880899999",
				                 "998888998988990989998",
				                 "998988999898990889899"};
				_expected = 1028.7662876159634;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}
			/*case 5:
			{
				string prob[] = ;
				_expected = ;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string prob[] = ;
				_expected = ;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string prob[] = ;
				_expected = ;
				_received = _obj.expectedSteps(vector <string>(prob, prob+sizeof(prob)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
