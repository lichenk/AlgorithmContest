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
vector<int> gm;
ll f(ll r, ll k) {
	if (r==0) return 0;
	if (k==gm.size()) {
		return ((r)*(r+1))/2;
	}
	ll m=gm[k];
	if (r<m) return f(r,k+1);
	ll newr=(r/m)*m;
	ll ans=((newr)/m)*f(m-1,k+1);
	if (r>newr) ans+=f(r%m,k+1);
	return ans;
}
class ModModMod {
	public:
	long long findSum(vector <int> m, int R) {
		gm=m;
		return f(R,0);
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
		cout << "Testing ModModMod (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463336738;
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
		ModModMod _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m[] = {5,3,2};
				int R = 10;
				_expected = 4LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 1:
			{
				int m[] = {33, 15, 7, 10, 100, 9, 5};
				int R = 64;
				_expected = 92LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 2:
			{
				int m[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
				int R = 992363;
				_expected = 12792005LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 3:
			{
				int m[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
				int R = 100;
				_expected = 4950LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 4:
			{
				int m[] = {2934};
				int R = 10000000;
				_expected = 14664070144LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 5:
			{
				int m[] = {3,2};
				int R = 5;
				_expected = 2LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			/*case 6:
			{
				int m[] = ;
				int R = ;
				_expected = LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}*/
			/*case 7:
			{
				int m[] = ;
				int R = ;
				_expected = LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
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
