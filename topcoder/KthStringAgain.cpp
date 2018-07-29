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
string prefix;
string gs;
ll dp[52][52][52];
ll f(ll x, ll l, ll r) {
	if (dp[x][l][r]!=UNDEF) return dp[x][l][r];
	ll pl=prefix.length();
	ll n=gs.length();
	ll ans=0;
	if (l+r==n) ans=1;
	else if (x>=n) ans=0;
	else {
		{
			if (l>=pl||gs[x]==prefix[l]) ans+=f(x+1,l+1,r);
		}
		{
			if (n-1-r>=pl||gs[x]==prefix[n-1-r]) ans+=f(x+1,l,r+1);
		}
	}
	//printf("x:%lld l:%lld r:%lld. ans:%lld\n",x,l,r,ans);
	return dp[x][l][r]=ans;
}
class KthStringAgain {
	public:
	string getKth(string s, long long k) {
		ll n=s.length();
		gs=s;
		//prefix="yzx";
		//memset(dp,-1,sizeof dp);
		//printf("%lld\n",f(0,0,0));
		//return "";
		//return 0;
		//k--;
		string ans="";
		for (ll x=0;x<n;x++) {
			ll sum=0;
			for (char c='a';c<='z';c++) {
				prefix=ans+c;
				memset(dp,-1,sizeof dp);
				ll got=f(0,0,0);
				//if(got)printf("%s: %lld\n",prefix.c_str(),got);
				if (sum+got>=k) {
					ans=ans+c;
					k-=sum;
					break;
				}
				sum+=got;
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
		cout << "Testing KthStringAgain (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1477481988;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KthStringAgain _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "xyz";
				long long k = 5LL;
				_expected = "yzx";
				_received = _obj.getKth(s, k); break;
			}
			case 1:
			{
				string s = "abc";
				long long k = 1LL;
				_expected = "abc";
				_received = _obj.getKth(s, k); break;
			}
			case 2:
			{
				string s = "abc";
				long long k = 8LL;
				_expected = "cba";
				_received = _obj.getKth(s, k); break;
			}
			case 3:
			{
				string s = "topcoder";
				long long k = 58LL;
				_expected = "ooredcpt";
				_received = _obj.getKth(s, k); break;
			}
			case 4:
			{
				string s = "aaaabcdeeeghhhhhiijjjkllmmooooqqrrrrssttuuvvvvvwyy";
				long long k = 38517901796974LL;
				_expected = "aaaacdeehhhijklmmqqrsttvvvvwyyvuusrrrooooljjihhgeb";
				_received = _obj.getKth(s, k); break;
			}
			/*case 5:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
			}*/
			/*case 6:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
			}*/
			/*case 7:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
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
