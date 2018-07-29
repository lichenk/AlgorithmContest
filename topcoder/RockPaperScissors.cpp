#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class RockPaperScissors {
	public:
	double bestScore(vector <int> rockProb, vector <int> paperProb, vector <int> scissorsProb) {
		
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
		cout << "Testing RockPaperScissors (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452749034;
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
		RockPaperScissors _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int rockProb[] = {100, 100, 100};
				int paperProb[] = {100, 100, 100};
				int scissorsProb[] = {100, 100, 100};
				_expected = 3.999999999999999;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}
			case 1:
			{
				int rockProb[] = {300};
				int paperProb[] = {0};
				int scissorsProb[] = {0};
				_expected = 3.0;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}
			case 2:
			{
				int rockProb[] = {300, 0,   0};
				int paperProb[] = {0,   300, 0};
				int scissorsProb[] = {0,   0,   300};
				_expected = 6.333333333333332;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}
			case 3:
			{
				int rockProb[] = {100,  0};
				int paperProb[] = {200, 100};
				int scissorsProb[] = {0,   200};
				_expected = 3.7222222222222223;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}
			case 4:
			{
				int rockProb[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
				                 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
				                 ,0,0,0,0,0,0,0,0,0};
				int paperProb[] = {150,300,300,300,300,300,300,300,300,300,300,300,300,300
				                  ,300,300,300,300,300,300,300,300,300,300,300,300,300,300
				                  ,300,300,300,300,300,300,300,300,300,300,300,300,300,300
				                  ,300,300,300,300,300,300,300,300};
				int scissorsProb[] = {150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
				                     ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
				                     ,0,0,0,0,0,0,0,0,0};
				_expected = 149.00000000000003;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}
			/*case 5:
			{
				int rockProb[] = ;
				int paperProb[] = ;
				int scissorsProb[] = ;
				_expected = ;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int rockProb[] = ;
				int paperProb[] = ;
				int scissorsProb[] = ;
				_expected = ;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int rockProb[] = ;
				int paperProb[] = ;
				int scissorsProb[] = ;
				_expected = ;
				_received = _obj.bestScore(vector <int>(rockProb, rockProb+sizeof(rockProb)/sizeof(int)), vector <int>(paperProb, paperProb+sizeof(paperProb)/sizeof(int)), vector <int>(scissorsProb, scissorsProb+sizeof(scissorsProb)/sizeof(int))); break;
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
