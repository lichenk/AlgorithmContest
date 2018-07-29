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
const ll MAXV=1024;
const ll MAXN=50;
ll f[MAXV];
ll adj[MAXN];
class XorTravelingSalesman {
	public:
	int maxProfit(vector <int> cityValues, vector <string> roads) {
		ll n=cityValues.size();
		for (ll x=0;x<n;x++) {
			ll mask=0;
			for (ll y=0;y<n;y++) {
				if(roads[x][y]=='Y') {
					mask|=1LL<<y;
				}
			}
			adj[x]=mask;
		}
		f[0]=1;
		for (ll v=1;v<MAXV;v++) f[v]=0;
		for (ll t=0;t<=(n*n);t++) {
			for (ll x=0;x<n;x++) {
				for (ll v=0;v<MAXV;v++) {
					if (f[v]&(1LL<<x)) {
						f[v^cityValues[x]]|=adj[x];
					}
				}
			}
		}
		ll ans=0;
		for (ll v=0;v<MAXV;v++) {
			for (ll x=0;x<n;x++) {
				if (f[v]&(1LL<<x)) chkmax(ans,v^cityValues[x]);
			}
		}
		return ans;
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
		cout << "Testing XorTravelingSalesman (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1467650241;
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
		XorTravelingSalesman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cityValues[] = {0, 7, 11, 5, 2};
				string roads[] = {"NYNYY",
				                  "YNYNN",
				                  "NYNNN",
				                  "YNNNN",
				                  "YNNNN"};
				_expected = 14;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				int cityValues[] = {556};
				string roads[] = {"N"};
				_expected = 556;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				int cityValues[] = {0, 4, 8, 32, 512};
				string roads[] = {"NYYYY",
				                  "YNNNN",
				                  "YNNNN",
				                  "YNNNN",
				                  "YNNNN"};
				_expected = 556;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 3:
			{
				int cityValues[] = {37, 1, 19, 64, 42, 41, 64, 64, 54, 16, 256, 36, 64, 2, 4, 2, 62, 29, 58, 64, 1, 32, 16,
				                    256, 17, 2, 17, 4, 1, 64, 21, 8, 256, 63, 3, 1, 43, 15, 8, 39, 41, 8, 16, 8, 16, 256, 64, 512, 45, 64};
				string roads[] = {"NNNNNNYYYYNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNYYNNNYYNN",
				                  "NNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                  "NNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNYNNYNYNNNNNNYNNNNNNNNNNYNNNNNNNNNNN",
				                  "NNYNNNYNNNNNNNNYNNYNNNYYNNNYNYNNNNYNNNNNNNNYNNNNNN",
				                  "YNYNNYNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNYNN",
				                  "YNNYNNYNYNYYNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNN",
				                  "YNNNNNNYNNNNNNNNNNNNNNYNYNNNNNNNNNNYYYNNNNNNNYNNNY",
				                  "YNNNNNNNNNNNNNNNNYNYNYNYYNNNYNNNNYNNNNNNNNNNNNNNNY",
				                  "NNNNNNNYNNNNYNNNNNNNNYYNNNYYNNNNYNYYNNNNNNNNNNNNNN",
				                  "NNNNNNNYNNNNNNYNNNNYYNNNYNNYYNNNNNNNNNNNNNYNYNNNNN",
				                  "NNNNNNNNNNYNNNNNYNNNNYNNNNNNNNNNYNYNNYNYNNNYNYNNNN",
				                  "NNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNNYNN",
				                  "NNNNNNNNNNNYNNNNNYNYNNYYNNNNNYNNNNNNNNNYNNYNNYNNNN",
				                  "NNNNYYYNNNNNNYNNNYYNNYNNNYNYYNNNNNNNNNYYYNNYNNYNYN",
				                  "NYNNNNNNNNNNYNNNNNNNYNNNYYNNNYNNNNYNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNYNNNNYYNNNNNNYNNNYNNNNNYNNYNYYNNNNYNNNYNN",
				                  "NNNYYYNNNNNNNNNYNNNNNYNYNYNNNNNNNNYNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNYNYNNYNNNNNNYNYYYNNNNNNNNNNNYNNYNNNNNYNNN",
				                  "NNNNYNNNNNNYNNNNYNNNNYNNNYYNNNYNNNYNNNNNNNNNNYNYNY",
				                  "NNNNNNNNNYYNYNNYNNYYYNYNNNNNNNNYNYNNNNNNNNNNYNNNNN",
				                  "NNNNNYNNYNYNNNYNNYNNNYNNNNNNNNNNNYNNYNYNNYNNNNNNNN",
				                  "NNNNNYNNNYNNNNYNNNYYNNNNNNNNNNNNNNNNNNNNNNYNNNYNNN",
				                  "NYNNNNNNYYNYNNNNYNNYNNNNNNNNNNYNNNNNNYNNNYNNYNNNNN",
				                  "NNNNNNNNNNNNNYNYYNYYYNNNNNNYNNNNNNNNNNNYYNNNNNNNYN",
				                  "NNNNNNNNNNYNNNNNNYNNYNNNNNNNNYNNNNYNNNNNNYYNNNNYNN",
				                  "NNNNYYNNNNYYNNNYNNNNNNNNNYNNNYYNYNNNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNYNYNNNYNNNNNNNNNNNNNYNNNNYNNNNNNNNYNNYNYN",
				                  "NNNNNYNNNNNNNNYNYNNNNNNNNNYYYNNNNNNNNYNNNNYNNNNNNN",
				                  "NNNNNNNNNNNNNNNNNNNNYNNNYNNYNNNNNYNNNNNNNNNNNNNNNY",
				                  "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNYNNNNNNN",
				                  "NNNNNNNNNNYNYNNNNYNNNNNNNNNYNNNYNNNYYNNNNNYNNNYNNN",
				                  "NNNNNNNNNYNNNNNNNNNNNYYNNNNNNNYNNNNNNNYNNYNNNNNNNN",
				                  "NNNNNYNYNNYNYNNNYNYNYNNNNNYNYNNNNNNYYNYNYNYNNNNNYN",
				                  "YNNNNNYNYNYNNNNNNYNNNNNNNNNNNNNNYNYNNNNNYNNYNNNYNN",
				                  "NNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNYNYNNNNNNYNNNNNNYN",
				                  "NNNNNNNYYNNNYNNNNYNYNNNNYNNNNYNNNNNNNNNNNYNNNNYNNN",
				                  "NNNNYNNNNNNNNYNYNYNNNNYNNNNNNNNNNYYNNNNYNNNNNNNNNY",
				                  "NNNNNNNNNNNNYNYYNNNNNNNNNYNNNNNNNNNNNNYNNNNNYNYYNN",
				                  "NNNNNNNNNNNNNNNYNNNYNNNNNYNNNNNNNNYYNNNNNNNNNNNNNN",
				                  "NYNNNNNNNNNNNNNNNNNNNNYNYNYNNNNNNYNNYYNNNNNNNNNNNN",
				                  "NYNNNNNNNNNYNNYNNNNNNNNYNNYNNYNYYNYNNNNNNNNNYNNNNN",
				                  "NNNNNYNNNNNNYNNYNYNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNY",
				                  "NNNNNNYNNNNYNNNNNNNNNYNNYNNNNNNNNNNNNNNYNNYNNYNNNY",
				                  "NNNNNNNNYNNNYNYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
				                  "NYNNNNNNNNNNNNNYNNNYNNNYNNNNYNNNYNNNNYNYNNNNNNNNNN",
				                  "NYNNNNYNNNNNNYNNNYNNYNNNNNYNNNNNNNNYNNNYNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNYNNNNNNNNNYNNYNNNNNYNYNNNNNNNNNNNNN",
				                  "NNNNNNNNYYNNNNNNNNNNYNNNNNNNNNYNNNNNNNYNNNNYYNNNNN"};
				_expected = 895;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 4:
			{
				int cityValues[] = {362, 756, 756, 680, 144, 725, 624, 69, 771, 399};
				string roads[] = {"NNNNNNNNNN", "NNYYYYYYYN", "NYNYYNYNNY", "NYYNNNYNNY", "NYYNNYNNYN", "NYNNYNNYYY", "NYYYNNNYNN", "NYNNNYYNNN", "NYNNYYNNNN", "NNYYNYNNNN"};
				_expected = 362;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 5:
			{
				int cityValues[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int cityValues[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxProfit(vector <int>(cityValues, cityValues+sizeof(cityValues)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
