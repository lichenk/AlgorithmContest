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
const ll mn=3000+4;
bool f[mn+4];
bool g[mn+4];
ll sig[mn+4];
const ll pre=1e3+4;
class PartisanGame {
	public:
string getWinner(int n, vector<int> a, vector<int> b) {
	string res;
	int ma=0,mb=0;
	for (auto &w:a) ma|=(w-1);
	for (auto &w:b) mb|=(w-1);
		int dp[2][2]={{0}};
	bool bit[2];
	int __a=1,__b=0;
	for (int i=1;i<=n;i++) {
		__a=i&1,__b=(i-1)&1;
		bit[0]=((~dp[__b][1])&ma)>0;
		bit[1]=((~dp[__b][0])&mb)>0;
		if (i>=100 and (dp[__a][0]&((1<<10)-1))==(dp[__a][0]&((1<<20)-1)&~(1<<10)-1)) {
			int temp=1<<(10-((n-i)%10));
			if (temp&dp[__a][0]) return "Alice";
			else return "Bob";
		}
	}
	if (dp[n&1][0]&1)res="Alice";
	else res="Bob";
	return res;
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
		cout << "Testing PartisanGame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1477479603;
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
		PartisanGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int a[] = {3, 4};
				int b[] = {4};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 10;
				int a[] = {1};
				int b[] = {4, 3, 2};
				_expected = "Bob";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 104982;
				int a[] = {2, 3, 4, 5};
				int b[] = {2, 5};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 999999999;
				int a[] = {4};
				int b[] = {5};
				_expected = "Bob";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 1000000000;
				int a[] = {1,2,3,4,5};
				int b[] = {1,2,3,4,5};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 44889;
				int a[] = {1,2,5};
				int b[] = {1,2,3};
				_expected = "Bob";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
