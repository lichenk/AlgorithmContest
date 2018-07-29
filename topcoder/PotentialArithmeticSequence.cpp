#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class PotentialArithmeticSequence {
	public:
	int numberOfSubsequences(vector <int> d) {
		const ll bs = 1ULL<<32;
		ll n=d.size();
		for (ll i=0;i<n;i++) {
			d[i] = min(d[i],31);
		}
		ll ans=0;
		for (ll x=0;x<n;x++) {
			for (ll y=x;y<n;y++) {
				ll hi=-1;
				ll ihi=0;
				for (ll k=x;k<=y;k++) {
					if (d[k]>hi) {
						hi=d[k];
						ihi=k;
					}
				}
				ll t=bs+(1ULL<<hi);
				bool good=true;
				for (ll k=ihi;k<=y;k++) {
					if (__builtin_ctzll(t) != d[k]) good=false;
					t++;
				}
				t=bs+(1ULL<<hi);
				for (ll k=ihi;k>=x;k--) {
					if (__builtin_ctzll(t) != d[k]) good=false;
					t--;
				}
				if (good) {
					//printf("x:%lld y:%lld\n",x,y);
					ans++;
				}
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
		cout << "Testing PotentialArithmeticSequence (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455177834;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PotentialArithmeticSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {0,1,0,2,0,1,0};
				_expected = 28;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {0,0,0,0,0,0,0};
				_expected = 7;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {0,0,0,0,1,1,1};
				_expected = 8;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {0,100,0,2,0};
				_expected = 11;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
				_expected = 49;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				_expected = ;
				_received = _obj.numberOfSubsequences(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
