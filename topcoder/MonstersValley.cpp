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
ll f[104][104];
class MonstersValley {
	public:
	int minimumPrice(vector<long long> dread, vector <int> price) {
		ll n=dread.size();
		for (ll x=0;x<104;x++) for (ll y=0;y<104;y++) f[x][y]=-1;
		f[0][0]=0;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<104;y++) {
				ll v=f[x][y];
				if (v==-1) continue;
				//printf("%lld %lld: %lld\n",x,y,v);
				if (v>=dread[x]) {
					chkmax(f[x+1][y],v);
				}
				chkmax(f[x+1][y+price[x]], v+dread[x]);
			}
		}
		for (ll y=0;y<104;y++) {
			if (f[n][y]!=-1) return y;
		}
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
		cout << "Testing MonstersValley (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462249505;
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
		MonstersValley _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long dread[] = {8, 5, 10};
				int price[] = {1, 1, 2};
				_expected = 2;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 1:
			{
				long long dread[] = {1, 2, 4, 1000000000};
				int price[] = {1, 1, 1, 2};
				_expected = 5;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 2:
			{
				long long dread[] = {200, 107, 105, 206, 307, 400};
				int price[] = {1, 2, 1, 1, 1, 2};
				_expected = 2;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 3:
			{
				long long dread[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
				int price[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
				_expected = 5;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 4:
			{
				long long dread[] = {1,1};
				int price[] = {1,1};
				_expected = 1;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			/*case 5:
			{
				long long dread[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long dread[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.minimumPrice(vector<long long>(dread, dread+sizeof(dread)/sizeof(long long)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
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
