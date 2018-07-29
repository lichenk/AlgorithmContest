#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<int> a;
ll asz;
ld dp[55][55];
ld f(ll lo, ll hi) {
	if (lo>=hi) return 0;
	ld dpval=dp[lo][hi];
	if (dpval>-1) return dpval;
	ll num=0;
	ld ans=0;
	for (ll x=0;x<asz;x++) {
		ll p=a[x];
		if (lo<=p&&p<=hi) {
			ll cost=0;
			for (ll y=0;y<x;y++) {
				if (p<a[y]&&a[y]<=hi) cost++;
			}
			for (ll y=x+1;y<asz;y++) {
				if (lo<=a[y]&&a[y]<p) cost++;
			}
			ans+=f(lo,p-1)+f(p+1,hi)+cost;
			num++;
		}
	}
	if (num>0) ans/=num;
	dp[lo][hi]=ans;
	return ans;
}
class QuickSort {
	public:
	double getEval(vector <int> _a) {
		for (auto &w:_a) --w;
		a=_a;
		asz=a.size();
		for (ll x=0;x<55;x++) for (ll y=0;y<55;y++) dp[x][y]=-2;
		return f(0,49);
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
		cout << "Testing QuickSort (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487949862;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		QuickSort _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L[] = {1,2,3,4,5};
				_expected = 0.0;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 1:
			{
				int L[] = {1,2,4,3,5,6};
				_expected = 1.0;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 2:
			{
				int L[] = {3,2,1};
				_expected = 2.6666666666666665;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 3:
			{
				int L[] = {50,40,30,20,10,15,25,35,45};
				_expected = 11.07698412698413;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			/*case 4:
			{
				int L[] = ;
				_expected = ;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int L[] = ;
				_expected = ;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int L[] = ;
				_expected = ;
				_received = _obj.getEval(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
