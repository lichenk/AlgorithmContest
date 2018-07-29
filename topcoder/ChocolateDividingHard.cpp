#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class ChocolateDividingHard {
	public:
	int findBest(vector <string> chocolate) {
		
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
		cout << "Testing ChocolateDividingHard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455000745;
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
		ChocolateDividingHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chocolate[] = {
				                     "95998",
				                     "21945",
				                     "23451",
				                     "99798",
				                     "74083"
				                     };
				_expected = 3;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			case 1:
			{
				string chocolate[] = {
				                     "12942",
				                     "23456",
				                     "99798",
				                     "98998",
				                     "67675"
				                     };
				_expected = 5;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			case 2:
			{
				string chocolate[] = {
				                     "129420",
				                     "234560",
				                     "997980",
				                     "989980",
				                     "676760"
				                     };
				_expected = 6;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			case 3:
			{
				string chocolate[] = {"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"};
				_expected = 44;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}
			/*case 4:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string chocolate[] = ;
				_expected = ;
				_received = _obj.findBest(vector <string>(chocolate, chocolate+sizeof(chocolate)/sizeof(string))); break;
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
