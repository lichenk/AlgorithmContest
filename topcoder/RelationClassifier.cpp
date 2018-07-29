#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class RelationClassifier {
	public:
	string isBijection(vector <int> domain, vector <int> range) {
		
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
		cout << "Testing RelationClassifier (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737450;
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
		RelationClassifier _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int domain[] = {1, 1};
				int range[] = {2, 3};
				_expected = "Not";
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}
			case 1:
			{
				int domain[] = {4, 5};
				int range[] = {2, 2};
				_expected = "Not";
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}
			case 2:
			{
				int domain[] = {1};
				int range[] = {2};
				_expected = "Bijection";
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}
			case 3:
			{
				int domain[] = {1, 2, 3, 4, 5};
				int range[] = {1, 2, 3, 4, 5};
				_expected = "Bijection";
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}
			case 4:
			{
				int domain[] = {14, 12, 10, 13, 20, 18, 9, 17, 14, 9};
				int range[] = {18, 6, 8, 15, 2, 14, 10, 13, 13, 15};
				_expected = "Not";
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}
			/*case 5:
			{
				int domain[] = ;
				int range[] = ;
				_expected = ;
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int domain[] = ;
				int range[] = ;
				_expected = ;
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int domain[] = ;
				int range[] = ;
				_expected = ;
				_received = _obj.isBijection(vector <int>(domain, domain+sizeof(domain)/sizeof(int)), vector <int>(range, range+sizeof(range)/sizeof(int))); break;
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
