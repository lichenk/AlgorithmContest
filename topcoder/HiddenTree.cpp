#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int MOD = 1000000007;
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
const int mn=14;
const int mz=1<<14;
int dp[mn][mz];
int gn;
vector<int> b;
int f(int k, int active) {
	if (k==gn) return 1;
	int dpval=dp[k][active];
	if (dpval!=-1) return dpval;
	int activek=(1<<k)|active;
	ll ans=f(k+1,activek);
	FORNESI(sub, active) {
		ll sum=0;
		for (int i=0;i<k;i++) {
			if (sub&(1<<i)) {
				sum+=b[i];
			}
		}
		if (sum<b[k]) {
			ans+=f(k+1, activek&(~sub));
		}
	}
	return dp[k][active]=ans%MOD;
}
class HiddenTree {
	public:
	int count(vector <int> _b) {
		memset(dp,-1,sizeof dp);
		b=_b;
		sort(b.begin(),b.end());
		gn=b.size();
		int ans=f(0,0);
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
		cout << "Testing HiddenTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515999026;
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
		HiddenTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int b[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int b[] = {3,1,2};
				_expected = 5;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int b[] = {3,1,1};
				_expected = 4;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int b[] = {1000000000,1,2,3,4,5,6};
				_expected = 2870;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int b[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
				_expected = 178290591;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int b[] = {474747474};
				_expected = 1;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int b[] = {536870912,536870912,536870912,536870912,536870912,
				          536870912,536870912,536870912,536870912};
				_expected = 1;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 7:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
