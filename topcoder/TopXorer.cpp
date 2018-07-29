#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll have[60];
class TopXorer {
	public:
	int maximalRating(vector <int> _v) {
		vector<ll> v; for (auto &x:_v) v.PB(x);
		for (auto &x:v) {
			for (ll k=0;k<60;k++) {
				ll msk=1LL<<k;
				if (x&msk) {
					//printf("k:%lld\n",k);
					have[k]++;
				}
			}
		}
		ll ans=0;
		for (ll k=59;k>=0;k--) {
			if(have[k]==1) {
				ans|=1LL<<k;
			}
			else if (have[k]>=2) {
				ans|=(1LL<<k);
				ans|=((1LL<<(k))-1);
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
		cout << "Testing TopXorer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1519708066;
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
		TopXorer _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {2,2,2};
				_expected = 3;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,2,4,8,16};
				_expected = 31;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1024,1024};
				_expected = 2047;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {7,4,12,33,6,8,3,1};
				_expected = 47;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0};
				_expected = 0;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {13};
				_expected = 13;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {8,9};
				_expected = 8|7;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {8,7};
				_expected = 8|7;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {1000000000,1};
				_expected = 1000000000|1;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 9:
			{
				int x[] = {1000000001,1};
				_expected = 1000000000|1;
				_received = _obj.maximalRating(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
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
