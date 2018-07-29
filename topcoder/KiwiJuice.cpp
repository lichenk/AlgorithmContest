#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[1<<15][2][51];
class KiwiJuice {
	public:
	int theProfit(int T, vector <int> bottles, vector <int> prices) {
		ll n=bottles.size();
		ll zlim=1<<n;
		memset(f,-1,sizeof f);
		f[0][0][0]=0;
		for (ll z=0;z<zlim;z++) {
			for (ll bot=0;bot<2;bot++) {
				for (ll sum=0;sum<=T;sum++) {
					if (bot==0&&sum!=0) continue;
					ll score=f[z][bot][sum];
					if (score==-1) continue;
					for (ll x=0;x<n;x++) {
						ll msk=1<<x;
						if ((msk&z)==0) {
							ll A=bottles[x];
							for (ll k=0;k<2;k++) {
								if (bot==0&&k==0) continue;
								ll adder=k?A:-(T-A);
								ll newscore=score;
								if(bot) newscore+=k?prices[0]:prices[T];
								ll newsum=sum+adder;
								if (0<=newsum&&newsum<=T) {
									chkmax(f[z|msk][1][newsum], newscore);
									chkmax(f[z|msk][0][0], newscore+prices[newsum]);
								}
							}
						}
					}
				}
			}
		}
		return f[zlim-1][0][0];
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
		cout << "Testing KiwiJuice (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491716462;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KiwiJuice _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 10;
				int bottles[] = {5, 8};
				int prices[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10};
				_expected = 10;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 1:
			{
				int C = 10;
				int bottles[] = {5, 8};
				int prices[] = {0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10};
				_expected = 20;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 2:
			{
				int C = 10;
				int bottles[] = {4, 5, 3, 7};
				int prices[] = {14, 76, 12, 35, 6, 94, 26, 3, 93, 90, 420};
				_expected = 625;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 3:
			{
				int C = 1;
				int bottles[] = {0};
				int prices[] = {1000000, 1000000};
				_expected = 1000000;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 4:
			{
				int C = 49;
				int bottles[] = {2, 47, 24, 14, 0, 32, 9, 12, 31, 46, 39, 12, 16, 22, 29};
				int prices[] = {428668, 995687, 128567, 37241, 496916, 238624, 304781, 997819, 85856, 417008,
				               398570, 951499, 750349, 333625, 927594, 188616, 942498, 259414, 654344, 354809,
				               25303, 226854, 98578, 207140, 305527, 358343, 393213, 256248, 282644, 103327,
				               667191, 103402, 609183, 619323, 189127, 518006, 778846, 400460, 128334, 795097,
				               605203, 669142, 121825, 934404, 837430, 554265, 610818, 546228, 80784, 949440};
				_expected = 12873962;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 5:
			{
				int C = 49;
				int bottles[] = {14, 49, 7, 43, 38, 6, 0, 43, 33, 37, 47, 2, 33, 38, 36};
				int prices[] = {674691, 440522, 183834, 256802, 707517, 888454, 381983, 949638, 438647, 322507, 356829, 115538, 726541, 10795, 648150, 285109, 595409, 54004, 256643, 553213, 487217, 218846, 814026, 599083, 519513, 69290, 719225, 481537, 319008, 505537, 261901, 781922, 690011, 915540, 199125, 681753, 369998, 610325, 950439, 63311, 403569, 447428, 536784, 871056, 567881, 71373, 905521, 943380, 511872, 557407};
				_expected = 12472594;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			/*case 6:
			{
				int C = ;
				int bottles[] = ;
				int prices[] = ;
				_expected = ;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int C = ;
				int bottles[] = ;
				int prices[] = ;
				_expected = ;
				_received = _obj.theProfit(C, vector <int>(bottles, bottles+sizeof(bottles)/sizeof(int)), vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
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
