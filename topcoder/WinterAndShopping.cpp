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
class WinterAndShopping {
	public:
	int getNumber(vector <int> first, vector <int> red, vector <int> green, vector <int> blue) {
		
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
		cout << "Testing WinterAndShopping (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1482719092;
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
		WinterAndShopping _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int first[] = {1};
				int red[] = {1};
				int green[] = {1};
				int blue[] = {1};
				_expected = 6;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int first[] = {1};
				int red[] = {3};
				int green[] = {0};
				int blue[] = {0};
				_expected = 1;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int first[] = {1, 2};
				int red[] = {1, 1};
				int green[] = {1, 1};
				int blue[] = {1, 1};
				_expected = 6;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int first[] = {47, 47};
				int red[] = {1, 0};
				int green[] = {0, 1};
				int blue[] = {0, 0};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int first[] = {1, 100, 200};
				int red[] = {100, 1, 0};
				int green[] = {100, 3, 7};
				int blue[] = {100, 2, 4};
				_expected = 79290907;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 5:
			{
				int first[] = {1, 3};
				int red[] = {3, 4};
				int green[] = {4, 4};
				int blue[] = {2, 1};
				_expected = 840;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 6:
			{
				int first[] = {2, 1};
				int red[] = {100, 100};
				int green[] = {100, 100};
				int blue[] = {99, 100};
				_expected = 412784747;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 7:
			{
				int first[] = {1, 220, 150};
				int red[] = {70, 70, 50};
				int green[] = {70, 70, 50};
				int blue[] = {70, 70, 50};
				_expected = 291495139;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 8:
			{
				int first[] = {2, 2, 70, 159};
				int red[] = {100, 20, 21, 52};
				int green[] = {100, 20, 29, 45};
				int blue[] = {100, 22, 39, 30};
				_expected = 139586270;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 9:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 11:
			{
				int first[] = ;
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
