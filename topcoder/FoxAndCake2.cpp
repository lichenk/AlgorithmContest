#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
bool bf(ll c, ll s) {
	if (c==0&&s==0) return true;
	if (c<=0||s<=0) return false;
	for (int x=1;x<=c;x++) {
		for (int y=1;y<=s;y++) {
			if (__gcd(x,y)>1) {
				if (bf(c-x,s-y)) return true;
			}
		}
	}
	return false;
}
bool smart(ll c, ll s) {
	if (__gcd(c,s)>1) return true;
	for (int x=2;x<c;x++) {
		for (int y=2;y<s;y++) {
			if (__gcd(x,y)>1&&__gcd(c-x,s-y)>1) {
				return true;
			}
		}
	}
	return false;
}

bool wrong(int c, int s) {
	
}

bool correct(ll x, ll y) {
	if (x>y) swap(x,y);
	if (__gcd(x,y)>1) return true;
	if ((x==5||x>=7)&&(y==5||y>=7)) return true;
	return false;
}
void brute() {
	for (ll c=1;c<=200;c++) for (ll s=1;s<=200;s++) {
		if ((bf(c,s)!=correct(c,s))) printf("%lld %lld\n",c,s);
	}
}

class FoxAndCake2 {
	public:
	string isPossible(int _c, int _s) {
		brute();
		return "";
		//ll c=_c,s=_s;
		//bool ans=solve(c,s);
		//if (ans) return "Possible";
		//else return "Impossible";
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
		cout << "Testing FoxAndCake2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495296002;
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
		FoxAndCake2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int c = 74;
				int s = 109;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 1:
			{
				int c = 1000000000;
				int s = 1000000000;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 2:
			{
				int c = 1;
				int s = 58;
				_expected = "Impossible";
				_received = _obj.isPossible(c, s); break;
			}
			/*case 3:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 4:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 5:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
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
