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
ll b[54];
ll n;
class SuffixArrayDiv1 {
	public:
	int minimalCharacters(vector <int> SA) {
		n=SA.size();
		for (ll i=0;i<n;i++) {
			b[SA[i]]=i+1;
		}
		b[n]=0;
		ll ans=1;
		for (ll i=1;i<n;i++) {
			ll pos = SA[i];
			if (b[SA[i]+1] < b[SA[i-1]+1]) {
				ans++;
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
		cout << "Testing SuffixArrayDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457027018;
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
		SuffixArrayDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int SA[] = {3,0,1,2};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 1:
			{
				int SA[] = {3,2,1,0};
				_expected = 1;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 2:
			{
				int SA[] = {0,1,2,3};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 3:
			{
				int SA[] = {7,4,8,6,1,5,2,9,3,0};
				_expected = 4;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 4:
			{
				int SA[] = {0};
				_expected = 1;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 5:
			{
				int SA[] = {1,0};
				_expected = 1;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 6:
			{
				int SA[] = {0,1};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 7:
			{
				int SA[] = {0,1,2};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 8:
			{
				int SA[] = {2,1,0};
				_expected = 1;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 9:
			{
				int SA[] = {3,1,2,0};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 10:
			{
				int SA[] = {3,0,2,1};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 11:
			{
				int SA[] = {0,2,1,3};
				_expected = 3;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 12:
			{
				int SA[] = {0,3,1,2};
				_expected = 3;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
			}
			case 13:
			{
				int SA[] = {0,3,2,1};
				_expected = 2;
				_received = _obj.minimalCharacters(vector <int>(SA, SA+sizeof(SA)/sizeof(int))); break;
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
