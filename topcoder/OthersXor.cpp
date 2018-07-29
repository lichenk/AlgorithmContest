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
#define REP(i,n) for(int i=0;i<(n);i++)
ll cnt[1000];
class OthersXor {
	public:

long long minSum(vector <int> x) {
	int N=x.size();
	ll ans=0;
	vector<int> y,z;
	REP(i,x.size()) {
		if (x[i]!=-1) y.PB(x[i]);
	}
	int M=y.size();
	if (N==M) {
		REP(i,x.size()) {
			int t=0;
			REP(j,x.size()) {
				if (i==j) t=t^x[j];
			}
			z.PB(t);
			ans+=t;
		}
		REP(i,x.size()) {
			int t=0;
			REP(j,x.size()) {
				if (i!=j) t=t^x[j];
			}
			if (t!=x[i]) ans=-1;
		}
	}
	else {
		REP(i,y.size()) {
			int t=0;
			REP(j,y.size()) {
				if (i!=j) t=t^x[j];
			}
			z.PB(t);
		}
		int c=0;
		REP(i,z.size()) c=c^z[i];
		REP(i,z.size()) {
			ans+=z[i]-c;
			ans+=c;
		}
		return ans;
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
		cout << "Testing OthersXor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1474902003;
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
		OthersXor _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,-1,3};
				_expected = 3LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,1};
				_expected = -1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {70,100};
				_expected = 170LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-1,0,-1,100,36};
				_expected = 164LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
				          0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
				          1073741823,1073741823,1073741823,123456789,987654321,804289383};
				_expected = 11992352010LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
				_expected = -1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {-1,-1};
				_expected = 0LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {0};
				_expected = 0LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {1};
				_expected = -1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 9:
			{
				int x[] = {-1};
				_expected = 0LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 10:
			{
				int x[] = {1,1};
				_expected = 2LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 11:
			{
				int x[] = {1,0};
				_expected = 1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
