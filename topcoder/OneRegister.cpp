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
ll gt;
const string BAD="?";
string gm(string a, string b) {
	if (a==BAD) return b;
	if (b==BAD) return a;
	if (a.length()==b.length()) return min(a,b);
	else if (a.length()<b.length()) return a;
	else return b;
}
string dfs(ll x) {
	ll t=gt;
	if (x>t) return BAD;
	if (x==t) return "";
	string final=BAD;
	if (x*x!=x) {
		string got=dfs(x*x);
		if (got!=BAD) {
			got="*"+got;
			final=got;
		}
	}
	if (x+x!=x) {
		string got=dfs(x+x);
		if (got!=BAD) {
			got="+"+got;
			if (final==BAD) final=got;
			else final=gm(final,got);
		}
	}
	return final;
}
class OneRegister {
	public:
	string getProgram(int _s, int _t) {
		ll s=_s,t=_t;
		gt=t;
		if (s==t) return "";
		if (t==0) return "-";
		string final=dfs(s);
		string ans="/"+dfs(1);
		if (ans!="/?") {
			final=gm(final,ans);
		}
		if (final=="?") return ":-(";
		return final;
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
		cout << "Testing OneRegister (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487948553;
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
		OneRegister _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s = 7;
				int t = 392;
				_expected = "+*+";
				_received = _obj.getProgram(s, t); break;
			}
			case 1:
			{
				int s = 7;
				int t = 256;
				_expected = "/+***";
				_received = _obj.getProgram(s, t); break;
			}
			case 2:
			{
				int s = 4;
				int t = 256;
				_expected = "**";
				_received = _obj.getProgram(s, t); break;
			}
			case 3:
			{
				int s = 7;
				int t = 7;
				_expected = "";
				_received = _obj.getProgram(s, t); break;
			}
			case 4:
			{
				int s = 7;
				int t = 9;
				_expected = ":-(";
				_received = _obj.getProgram(s, t); break;
			}
			case 5:
			{
				int s = 10;
				int t = 1;
				_expected = "/";
				_received = _obj.getProgram(s, t); break;
			}
			/*case 6:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.getProgram(s, t); break;
			}*/
			/*case 7:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.getProgram(s, t); break;
			}*/
			/*case 8:
			{
				int s = ;
				int t = ;
				_expected = ;
				_received = _obj.getProgram(s, t); break;
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
