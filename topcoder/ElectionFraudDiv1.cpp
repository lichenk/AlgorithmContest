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
const ll mk=1e3+2;
const ll mn=52;
bool f[mn+10][mk+10];
vector<ll> h[101];
class ElectionFraudDiv1 {
	public:
	int MinimumVoters(vector <int> v) {
		ll n=v.size();
		for (ll k=1;k<mk;k++) {
			for (ll p=0;p<=100;p++) h[p].clear();
			for (ll x=0;x<=k;x++) {
				ll num=x*100;
				ll gotp=num/k;
				ll minneed=(k+1)/2;
				if (num%k>=minneed) gotp++;
				h[gotp].PB(x);
			}
			for (ll x=0;x<=n;x++) for (ll y=0;y<=k;y++) f[x][y]=false;
			f[0][0]=true;
			for (ll x=0;x<n;x++) {
				for (ll y=0;y<=k;y++) {
					if (f[x][y]) {
						for (auto &w:h[v[x]]) {
							if (y+w<mk) f[x+1][y+w]=true;
						}
					}
				}
			}
			if (f[n][k]) return k;
		}
		return -1;
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
		cout << "Testing ElectionFraudDiv1 (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471016638;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ElectionFraudDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int percentages[] = {33, 33, 33};
				_expected = 3;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			case 1:
			{
				int percentages[] = {29, 29, 43};
				_expected = 7;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			case 2:
			{
				int percentages[] = {12, 12, 12, 12, 12, 12, 12, 12};
				_expected = -1;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			case 3:
			{
				int percentages[] = {13, 13, 13, 13, 13, 13, 13, 13};
				_expected = 8;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			case 4:
			{
				int percentages[] = {0, 1, 100};
				_expected = 200;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			case 5:
			{
				int percentages[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
				_expected = 97;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}
			/*case 6:
			{
				int percentages[] = ;
				_expected = ;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int percentages[] = ;
				_expected = ;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int percentages[] = ;
				_expected = ;
				_received = _obj.MinimumVoters(vector <int>(percentages, percentages+sizeof(percentages)/sizeof(int))); break;
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
