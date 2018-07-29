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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
class PiecewiseLinearFunction {
	public:
	int maximumSolutions(vector <int> Y) {
		ll n=Y.size();
		for (ll x=0;x<n-1;x++) {
			if (Y[x]==Y[x+1]) return -1;
		}
		ll ans=0;
		for (ll x=0;x<n;x++) {
			Y[x]*=2;
		}
		set<ll> s;
		for (ll x=0;x<n;x++) {
			s.insert(Y[x]);
			s.insert(Y[x]-1);
			s.insert(Y[x]+1);
		}
		for (auto &t:s) {
			ll cand=0;
			for (ll k=0;k<n-1;k++) {
				ll a=Y[k]; ll b=Y[k+1];
				if (a>b) swap(a,b);
				if (a<t&&t<b) cand++;
				else if (Y[k]==t) cand++;
				else if (k==n-2&&Y[k+1]==t) cand++;
			}
			chkmax(ans,cand);
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
		cout << "Testing PiecewiseLinearFunction (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460916742;
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
		PiecewiseLinearFunction _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Y[] = {3, 2};
				_expected = 1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int Y[] = {4, 4};
				_expected = -1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int Y[] = {1, 4, -1, 2};
				_expected = 3;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int Y[] = {2, 1, 2, 1, 3, 2, 3, 2};
				_expected = 5;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int Y[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
				_expected = 6;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 5:
			{
				int Y[] = {278832792, 465135153, -802394470, 142729209, -943268501, 908089082};
				_expected = 4;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
