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
class ProductQuery {
	public:
	int theInput(int N, vector <int> Qfrom, vector <int> Qto, vector <int> output) {
		
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
		cout << "Testing ProductQuery (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471451494;
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
		ProductQuery _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int Qfrom[] = {0};
				int Qto[] = {0};
				int output[] = {5};
				_expected = 100;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int Qfrom[] = {0, 2, 0};
				int Qto[] = {1, 4, 4};
				int output[] = {3, 4, 6};
				_expected = 0;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int Qfrom[] = {0, 1};
				int Qto[] = {1, 2};
				int output[] = {5, 8};
				_expected = 4;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 8;
				int Qfrom[] = {2, 0, 3, 6};
				int Qto[] = {3, 7, 4, 6};
				int output[] = {2, 0, 6, 7};
				_expected = 118080;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 20;
				int Qfrom[] = {9, 6, 2, 3, 1, 3, 12, 3, 4, 6, 10, 18, 10, 11, 15, 5};
				int Qto[] = {12, 12, 4, 13, 7, 14, 17, 10, 5, 13, 11, 19, 17, 14, 17, 8};
				int output[] = {7, 5, 7, 5, 0, 5, 8, 5, 3, 5, 3, 9, 4, 1, 6, 5};
				_expected = 276398080;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 58;
				int Qfrom[] = {5, 5};
				int Qto[] = {8, 8};
				int output[] = {1, 2};
				_expected = 0;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int Qfrom[] = ;
				int Qto[] = ;
				int output[] = ;
				_expected = ;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int Qfrom[] = ;
				int Qto[] = ;
				int output[] = ;
				_expected = ;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int Qfrom[] = ;
				int Qto[] = ;
				int output[] = ;
				_expected = ;
				_received = _obj.theInput(N, vector <int>(Qfrom, Qfrom+sizeof(Qfrom)/sizeof(int)), vector <int>(Qto, Qto+sizeof(Qto)/sizeof(int)), vector <int>(output, output+sizeof(output)/sizeof(int))); break;
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
