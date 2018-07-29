#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class CityMap {
	public:
	string getLegend(vector <string> cityMap, vector <int> POIs) {
		
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
		cout << "Testing CityMap (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449737504;
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
		CityMap _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cityMap[] = {"M....M",
				                    "...R.M",
				                    "R..R.R"};
				int POIs[] = {3, 4};
				_expected = "MR";
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}
			case 1:
			{
				string cityMap[] = {"XXXXXXXZXYYY"};
				int POIs[] = {1, 8, 3};
				_expected = "ZXY";
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}
			case 2:
			{
				string cityMap[] = {"...........",
				                    "...........",
				                    "...........",
				                    "..........T"};
				int POIs[] = {1};
				_expected = "T";
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}
			case 3:
			{
				string cityMap[] = {"AIAAARRI.......GOAI.",
				                    ".O..AIIGI.OAAAGI.A.I",
				                    ".A.IAAAARI..AI.AAGR.",
				                    "....IAI..AOIGA.GAIA.",
				                    "I.AIIIAG...GAR.IIAGA",
				                    "IA.AOA....I....I.GAA",
				                    "IOIGRAAAO.AI.AA.RAAA",
				                    "AI.AAA.AIR.AGRIAAG..",
				                    "AAAAIAAAI...AAG.RGRA",
				                    ".J.IA...G.A.AA.II.AA"};
				int POIs[] = {16,7,1,35,11,66};
				_expected = "GOJIRA";
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}
			/*case 4:
			{
				string cityMap[] = ;
				int POIs[] = ;
				_expected = ;
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string cityMap[] = ;
				int POIs[] = ;
				_expected = ;
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string cityMap[] = ;
				int POIs[] = ;
				_expected = ;
				_received = _obj.getLegend(vector <string>(cityMap, cityMap+sizeof(cityMap)/sizeof(string)), vector <int>(POIs, POIs+sizeof(POIs)/sizeof(int))); break;
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
