#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<30LL;
bool cmp(const string &a, const string &b) {
	if (b=="?") return false;
	if (a=="?") return true;
	ll alen=a.length(),blen=b.length();
	if (alen!=blen) return alen<blen;
	else return a<b;
}
void chkmax(string &a, string b) {
	if (cmp(a,b)) a=b;
}
const ll mn=47+1;
const ll mk=5;
string f[mn][mn][mk][mk];
class TheBoringStoreDivOne {
	public:
	string find(string s, string t) {
		assert(!cmp("aa","b"));
		assert(cmp("aa","bb"));
		assert(cmp("aaa","bbb"));
		assert(cmp("?",""));
		assert(!cmp("","?"));
		assert(!cmp("?","?"));
		ll slen=s.length(),tlen=t.length();
		for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++)
			for (ll a=0;a<mk;a++) for (ll b=0;b<mk;b++) f[x][y][a][b]="?";
		f[0][0][0][0]="";
		for (ll sum=0;sum<=slen+tlen;sum++){
			for (ll x=0;x<slen;x++) {
				ll y=sum-x;
				if (!(0<=y&&y<tlen)) continue;
				for (ll a=0;a<mk;a++) {
					for (ll b=0;b<mk;b++) {
						string cur=f[x][y][a][b];
						if (a&1) chkmax(cur,f[x][y][a-1][b]);
						if (b&1) chkmax(cur,f[x][y][a][b-1]);
						if ((a&1)&&(b&1)) chkmax(cur,f[x][y][a-1][b-1]);
						if (cur=="?") continue;
						printf("x:%d y:%d a:%d b:%d f:%s\n",x,y,a,b,cur.c_str());
						if ((a&1)&&(b&1)&&s[x]==t[y]) {
							for (ll na=a;na<min(a+2,mk);na++) {
								for (ll nb=b;nb<min(b+2,mk);nb++) {
									chkmax(f[x+1][y+1][na][nb],cur+s[x]);
								}
							}
						}
						if ((a&1)==0) {
							for (ll na=a;na<min(a+2,mk);na++)
								chkmax(f[x+1][y][na][b],cur);
						}
						if ((b&1)==0) {
							for (ll nb=b;nb<min(b+2,mk);nb++)
								chkmax(f[x][y+1][a][nb],cur);
						}
					}
				}
			}
		}
		return f[slen][tlen][4][4];
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
		cout << "Testing TheBoringStoreDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485159033;
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
		TheBoringStoreDivOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string J = "StoreOfJohn";
				string B = "StoreOfBrus";
				_expected = "or";
				_received = _obj.find(J, B); break;
			}
			case 1:
			{
				string J = "JohnAndJohn";
				string B = "John";
				_expected = "";
				_received = _obj.find(J, B); break;
			}
			case 2:
			{
				string J = "JohnLikesToPlayGames";
				string B = "BrusAlsoLikesToPlayGames";
				_expected = "esToPlayGames";
				_received = _obj.find(J, B); break;
			}
			case 3:
			{
				string J = "abacaba";
				string B = "abacabadabacaba";
				_expected = "abaabacaba";
				_received = _obj.find(J, B); break;
			}
			case 4:
			{
				string J = "aa";
				string B = "bb";
				_expected = "ab";
				_received = _obj.find(J, B); break;
			}
			/*case 5:
			{
				string J = ;
				string B = ;
				_expected = ;
				_received = _obj.find(J, B); break;
			}*/
			/*case 6:
			{
				string J = ;
				string B = ;
				_expected = ;
				_received = _obj.find(J, B); break;
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
