#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class SlimeXGrandSlimeAuto {
	public:
	int travel(vector <int> cars, vector <int> districts, vector <string> roads, int inverseWalkSpeed, int inverseDriveSpeed) {
		
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
		cout << "Testing SlimeXGrandSlimeAuto (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484292852;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SlimeXGrandSlimeAuto _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cars[] = {1};
				int districts[] = {2,3,0};
				string roads[] = {
				                 "..0.",
				                 "...1",
				                 "0..2",
				                 ".12."};
				int inverseWalkSpeed = 5;
				int inverseDriveSpeed = 1;
				_expected = 36;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}
			case 1:
			{
				int cars[] = {1};
				int districts[] = {2, 0};
				string roads[] = {
				                 ".A.",
				                 "A.B",
				                 ".B."};
				int inverseWalkSpeed = 2;
				int inverseDriveSpeed = 1;
				_expected = 262;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}
			case 2:
			{
				int cars[] = {2,2};
				int districts[] = {1,2,1};
				string roads[] = {
				                 ".a4",
				                 "a..",
				                 "4.."};
				int inverseWalkSpeed = 3;
				int inverseDriveSpeed = 1;
				_expected = 95;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}
			case 3:
			{
				int cars[] = {1};
				int districts[] = {2, 0};
				string roads[] = {
				                 ".B.",
				                 "B.A",
				                 ".A."};
				int inverseWalkSpeed = 2;
				int inverseDriveSpeed = 1;
				_expected = 262;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}
			case 4:
			{
				int cars[] = {2,5,1,2};
				int districts[] = {1,5,1,2,4};
				string roads[] = {
				                 ".12.4.",
				                 "1....7",
				                 "2..3..",
				                 "..3..5",
				                 "4.....",
				                 ".7.5.."};
				int inverseWalkSpeed = 53;
				int inverseDriveSpeed = 37;
				_expected = 1259;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}
			/*case 5:
			{
				int cars[] = ;
				int districts[] = ;
				string roads[] = ;
				int inverseWalkSpeed = ;
				int inverseDriveSpeed = ;
				_expected = ;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}*/
			/*case 6:
			{
				int cars[] = ;
				int districts[] = ;
				string roads[] = ;
				int inverseWalkSpeed = ;
				int inverseDriveSpeed = ;
				_expected = ;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
			}*/
			/*case 7:
			{
				int cars[] = ;
				int districts[] = ;
				string roads[] = ;
				int inverseWalkSpeed = ;
				int inverseDriveSpeed = ;
				_expected = ;
				_received = _obj.travel(vector <int>(cars, cars+sizeof(cars)/sizeof(int)), vector <int>(districts, districts+sizeof(districts)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string)), inverseWalkSpeed, inverseDriveSpeed); break;
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
