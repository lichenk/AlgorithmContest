#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class BichromeSky {
	public:
	double totallyCovered(vector <int> redX, vector <int> redY, vector <int> prob, vector <int> blueX, vector <int> blueY) {
		
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
		cout << "Testing BichromeSky (1050.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451881237;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1050.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BichromeSky _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int redX[] = {3,-3,0};
				int redY[] = {-1,-1,2};
				int prob[] = {400,500,600};
				int blueX[] = {1,0,-1};
				int blueY[] = {0,1,0};
				_expected = 0.12;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			case 1:
			{
				int redX[] = {3,-3,3,-3};
				int redY[] = {3,3,-3,-3};
				int prob[] = {200,300,400,500};
				int blueX[] = {0,1,-1};
				int blueY[] = {-1,-2,-2};
				_expected = 0.088;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			case 2:
			{
				int redX[] = {3,-3,0};
				int redY[] = {-1,-1,2};
				int prob[] = {400,500,600};
				int blueX[] = {1,0,-1,123456};
				int blueY[] = {0,1,0,-654321};
				_expected = 0.0;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			case 3:
			{
				int redX[] = {0,-2,-3,-4,-3,-2,0,2,3,4,3,2};
				int redY[] = {4,3,2,0,-2,-3,-4,-3,-2,0,2,3};
				int prob[] = {501,502,503,504,505,506,507,508,509,510,511,512};
				int blueX[] = {1,-1,-1,1};
				int blueY[] = {1,1,-1,-1};
				_expected = 0.6555037822772468;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			case 4:
			{
				int redX[] = {0,1,-3,3};
				int redY[] = {0,4,-2,-2};
				int prob[] = {200,300,400,500};
				int blueX[] = {0,-1,1};
				int blueY[] = {1,-1,-1};
				_expected = 0.06;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			case 5:
			{
				int redX[] = {10,-17,12,-11,-13,-10,-15,14,-4,2};
				int redY[] = {8,17,-13,-19,-14,11,17,8,-8,-15};
				int prob[] = {412,360,656,876,984,160,368,873,223,128};
				int blueX[] = {-9,-3,6,-9,-5,4,-3,10,-7,2};
				int blueY[] = {-6,10,10,-9,-10,-6,2,-10,-9,6};
				_expected = 0.34037052019900405;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}
			/*case 6:
			{
				int redX[] = ;
				int redY[] = ;
				int prob[] = ;
				int blueX[] = ;
				int blueY[] = ;
				_expected = ;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int redX[] = ;
				int redY[] = ;
				int prob[] = ;
				int blueX[] = ;
				int blueY[] = ;
				_expected = ;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int redX[] = ;
				int redY[] = ;
				int prob[] = ;
				int blueX[] = ;
				int blueY[] = ;
				_expected = ;
				_received = _obj.totallyCovered(vector <int>(redX, redX+sizeof(redX)/sizeof(int)), vector <int>(redY, redY+sizeof(redY)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(blueX, blueX+sizeof(blueX)/sizeof(int)), vector <int>(blueY, blueY+sizeof(blueY)/sizeof(int))); break;
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
