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
class SumFullSet {
	public:
	string isSumFullSet(vector <int> e) {
		ll n=e.size();
		for (ll i=0;i<n;i++) {
			for (ll j=i+1;j<n;j++) {
				bool good=false;
				for (ll k=0;k<n;k++) {
					if (e[k]==e[i]+e[j]) {
						good=true; break;
					}
				}
				if (!good) return "not closed";
			}
		}
		return "closed";
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
		cout << "Testing SumFullSet (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462118787;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SumFullSet _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int elements[] = {-1,0,1};
				_expected = "closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			case 1:
			{
				int elements[] = {-1,1};
				_expected = "not closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			case 2:
			{
				int elements[] = {0,1};
				_expected = "closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			case 3:
			{
				int elements[] = {0,1,1};
				_expected = "not closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			case 4:
			{
				int elements[] = {16,0,43,43,-36,-49,-46,-16,40,34,-43,-24,13,-48,45,19,12,0,43,6,26,-23,50,28,-3,21,46,45,-32,-41,0,-27,42,19,47,-36,-21,-1,5,-21,-28,-43,23,-26,-5,21,-41,16,-37,38};
				_expected = "not closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			case 5:
			{
				int elements[] = {10};
				_expected = "closed";
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}
			/*case 6:
			{
				int elements[] = ;
				_expected = ;
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int elements[] = ;
				_expected = ;
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int elements[] = ;
				_expected = ;
				_received = _obj.isSumFullSet(vector <int>(elements, elements+sizeof(elements)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
