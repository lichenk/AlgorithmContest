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
string f(ll n, ll k) {
	assert(k>=(1LL<<(n-1)));
	if (n==1) {
		if (k==1) return "A";
		else if (k==2) return "(A->A)";
		else assert(false);
	}
	ll mid=1LL<<(n-1);
	ll rem=k-mid;
	assert(left>=0);
	ll lmid=1LL<<(n-2);
	char c='A'+n-1;
	if (rem<lmid) {
		ll other=(1LL<<(n-1))-rem;
		assert(other>=lmid);
		return "(" + f(n-1,other)+"->"+c+")";
	}
	else {
		assert(rem>=lmid);
		string s;
		s+="(";
		s+=c;
		s+=("->"+f(n-1,rem)+")");
		return s;
	}
}
class MaterialImplication {
	public:
	string construct(int n, int k) {
		if (k>=(1LL<<(n-1))) {
			return f(n,k);
		}
		else return "Impossible";
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
		cout << "Testing MaterialImplication (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472446416;
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
		MaterialImplication _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int k = 1;
				_expected = "A";
				_received = _obj.construct(n, k); break;
			}
			case 1:
			{
				int n = 2;
				int k = 4;
				_expected = "(A->A)";
				_received = _obj.construct(n, k); break;
			}
			case 2:
			{
				int n = 2;
				int k = 3;
				_expected = "(A->B)";
				_received = _obj.construct(n, k); break;
			}
			case 3:
			{
				int n = 3;
				int k = 0;
				_expected = "Impossible";
				_received = _obj.construct(n, k); break;
			}
			case 4:
			{
				int n = 4;
				int k = 13;
				_expected = "(((A->B)->(C->D))->((A->C)->(D->B)))";
				_received = _obj.construct(n, k); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(n, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
