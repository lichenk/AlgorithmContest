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
class TheNicePair {
	public:
	int solve(vector <int> A) {
		ll n=A.size();
		ll ans=-1;
		for (ll x=0;x<n;x++) {
			for (ll y=x;y<n;y++) {
				for (ll d=2;d<=1000;d++) {
					ll cnt=0;
					for (ll t=x;t<=y;t++) {
						if ((A[t]%d)==0) {
							cnt++;
						}
					}
					if (cnt >= (y-x+1+1)/2) {
						ans=max(ans,y-x);
					}
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
		cout << "Testing TheNicePair (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458964696;
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
		TheNicePair _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {5,5,5,5,5};
				_expected = 4;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,1,1,1};
				_expected = -1;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {2,3,5,7};
				_expected = 1;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {8,8,5,5,5};
				_expected = 4;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1,1000,1000,1,1000,1,999};
				_expected = 5;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1000,1,1,1000};
				_expected = 3;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1};
				_expected = 15;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
