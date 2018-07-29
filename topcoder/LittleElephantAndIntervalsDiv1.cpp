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
ll f[2000];
class LittleElephantAndIntervalsDiv1 {
	public:
	long long getNumber(int M, vector <int> L, vector <int> R) {
		ll n=L.size();
		for (ll i=0;i<2000;i++) f[i]=UNDEF;
		for (ll i=n-1;i>=0;i--) {
			for (ll x=L[i];x<=R[i];x++) {
				if (f[x]==UNDEF) f[x]=i;
			}
		}
		set<ll> s;
		for (ll i=0;i<2000;i++) {
			if (f[i]!=UNDEF) {
				s.insert(f[i]);
				//printf("%lld\n",f[i]);
			}
		}
		ll k=s.size();
		return 1LL<<k;
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
		cout << "Testing LittleElephantAndIntervalsDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470846628;
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
		LittleElephantAndIntervalsDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 4;
				int L[] = {1, 2, 3};
				int R[] = {1, 2, 3};
				_expected = 8LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int M = 3;
				int L[] = {1, 1, 2};
				int R[] = {3, 1, 3};
				_expected = 4LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int M = 1000;
				int L[] = {47};
				int R[] = {747};
				_expected = 2LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int M = 42;
				int L[] = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16, 28, 13, 27, 9, 18, 4, 10, 3, 4, 4, 3, 4, 1, 18, 18, 2, 38, 4, 10, 12, 3, 30, 11, 38, 2, 13, 1, 13, 18, 16, 13, 2, 14, 27, 13, 3, 26, 19, 5, 10};
				int R[] = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19, 31, 28, 35, 27, 30, 13, 31, 5, 8, 25, 40, 10, 3, 26, 23, 9, 40, 8, 40, 23, 12, 37, 35, 39, 11, 34, 10, 21, 22, 21, 24, 5, 39, 27, 17, 16, 26, 35, 25, 36};
				_expected = 256LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			/*case 4:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = LL;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
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
