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
const ll mn=3002;
ll dpf[mn][mn],dpg[mn][mn];
string a;
ll n;
ll f(ll x, ll y);
ll g(ll x, ll y);
void q(ll x) {
	assert(0<=x&&x<MOD);
}
ll norm(ll x) {
	x%=MOD; if (x<0) x+=MOD; q(x); return x;
}
ll f(ll x, ll y) {
	if (dpf[x][y]!=-1) return dpf[x][y];
	ll ans;
	if (x>y) ans=1;
	else {
		ans=f(x,y-1)+f(x+1,y)-f(x+1,y-1);
		if (a[x]==a[y]) ans+=f(x+1,y-1);
	}
	return dpf[x][y]=norm(ans);
}
ll g(ll x, ll y) {
	if (x<0||y>n-1) return 1;
	if (dpg[x][y]!=-1) return dpg[x][y];
	ll ans;
	{
		ans=g(x-1,y)+g(x,y+1)-g(x-1,y+1);
		if (a[x]==a[y]) ans+=g(x-1,y+1);
	}
	return dpg[x][y]=norm(ans);
}
ll h(ll x, ll y) {
	ll ans;
	if (x>y) ans=1;
	else if (a[x]==a[y]) {
		q(f(x+1,y-1));
		q(g(x-1,y+1));
		ans = norm(f(x+1,y-1)*g(x-1,y+1));
	}
	else ans = 0;
	return norm(ans);
}
ll vcnt[mn];
class PalindromicSubseq {
	public:
	int solve(string s) {
		a=s;
		n=a.length();
		memset(dpf,-1,sizeof dpf);
		memset(dpg,-1,sizeof dpg);
		for (ll x=0;x<n;x++) {
			for (ll y=x;y<n;y++) {
				ll got=h(x,y);
				vcnt[x]+=got; vcnt[x]%=MOD;
				if (y!=x) vcnt[y]+=got; vcnt[y]%=MOD;
			}
		}
		ll final=0;
		for (ll i=0;i<n;i++) {
			ll cand=norm((i+1)*norm(vcnt[i]));
			//printf("i:%d cand:%d\n",i,cand);
			final=final^norm(cand);
		}
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
		cout << "Testing PalindromicSubseq (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486787955;
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
		PalindromicSubseq _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "aaba";
				_expected = 30;
				_received = _obj.solve(s); break;
			}
			case 1:
			{
				string s = "abcd";
				_expected = 4;
				_received = _obj.solve(s); break;
			}
			case 2:
			{
				string s = "tcoct";
				_expected = 60;
				_received = _obj.solve(s); break;
			}
			case 3:
			{
				string s = "zyzyzzzzxzyz";
				_expected = 717;
				_received = _obj.solve(s); break;
			}
			case 4:
			{
				string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				_expected = 1025495382;
				_received = _obj.solve(s); break;
			}
			case 5:
			{
				string s = "a";
				_expected = 1;
				_received = _obj.solve(s); break;
			}
			case 6:
			{
				string s = "ab";
				_expected = 1^2;
				_received = _obj.solve(s); break;
			}
			case 7:
			{
				string s = "aa";
				_expected = 2^4;
				_received = _obj.solve(s); break;
			}
			case 8:
			{
				string s = "aaa";
				_expected = 4^8^12;
				_received = _obj.solve(s); break;
			}
			case 9:
			{
				string s = "aaaa";
				_expected = 8^16^24^32;
				_received = _obj.solve(s); break;
			}
			case 10:
			{
				string s = "aaaaa";
				_expected = 16^(16*2)^(16*3)^(16*4)^(16*5);
				_received = _obj.solve(s); break;
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
