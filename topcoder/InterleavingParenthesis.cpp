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
const ll mn=2500+4;
ll d[mn][mn],c[mn][mn];
int cor(string s, string t) {
		swap(s,t);
		ll xlim=s.length(),ylim=t.length();
		d[0][0]=0;
		c[0][0]=1;
		for (ll x=0;x<=xlim;x++) {
			for (ll y=0;y<=ylim;y++) {
				ll dnow=d[x][y];
				ll cnow=c[x][y]%MOD;
				if (dnow<0||cnow==0) continue;
				if (x<xlim) {
					if (s[x]=='(') {
						d[x+1][y]=dnow+1;
						c[x+1][y]+=cnow; c[x+1][y]%=MOD;
					}
					else {
						if (dnow-1>=0) {
							d[x+1][y]=dnow-1;
							c[x+1][y]+=cnow; c[x+1][y]%=MOD;
						}
					}
				}
				if (y<ylim) {
					if (t[y]=='(') {
						d[x][y+1]=dnow+1;
						c[x][y+1]+=cnow;
						c[x][y+1]%=MOD;
					}
					else {
						if (dnow-1>=0) {
							d[x][y+1]=dnow-1;
							c[x][y+1]+=cnow;
							c[x][y+1]%=MOD;
						}
					}
				}
			}
		}
		if (d[xlim][ylim]!=0) return 0;
		return c[xlim][ylim]%MOD;
}
int wro(string s1, string s2) {
}
void bf() {
	srand(time(0)+clock()+rand());
	ll xlim=rand()%5+1;
	ll ylim=rand()%5+1;
	string s,t;
	for (int i=0;i<xlim;i++) if (rand()&1) s+="("; else s+=")";
	for (int i=0;i<ylim;i++) if (rand()&1) t+="("; else t+=")";
	int cor1=cor(s,t);
	int wr=wro(s,t);
	if (cor1!=wr) {
		cout<<cor1<<" wr:"<<wr<<endl;
		cout<<s<<endl;
		cout<<t<<endl;
	}
	exit(0);
}
class InterleavingParenthesis {
	public:
	int countWays(string s, string t) {
		bf();
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
		cout << "Testing InterleavingParenthesis (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499907601;
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
		InterleavingParenthesis _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s1 = "(()";
				string s2 = "())";
				_expected = 19;
				_received = _obj.countWays(s1, s2); break;
			}
			case 1:
			{
				string s1 = ")";
				string s2 = "(";
				_expected = 1;
				_received = _obj.countWays(s1, s2); break;
			}
			case 2:
			{
				string s1 = "(((((";
				string s2 = ")))))";
				_expected = 42;
				_received = _obj.countWays(s1, s2); break;
			}
			case 3:
			{
				string s1 = "()(()";
				string s2 = "))((())";
				_expected = 10;
				_received = _obj.countWays(s1, s2); break;
			}
			case 4:
			{
				string s1 = "()()()()()()()()()()()()()()()()()()()()";
				string s2 = "()()()()()()()()()()()()()()()()()";
				_expected = 487340184;
				_received = _obj.countWays(s1, s2); break;
			}
			case 5:
			{
				string s1 = "(())())))";
				string s2 = "(())()";
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
			}
			case 6:
			{
				string s1 = "";
				string s2 = ")";
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
			}
			case 7:
			{
				string s1 = "";
				string s2 = "(";
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
			}
			case 8:
			{
				string s1 = "((";
				string s2 = "))";
				_expected = 2;
				_received = _obj.countWays(s1, s2); break;
			}
			case 9:
			{
				string s1 = "";
				string s2 = "";
				for (int i=0;i<2500;i++) {s1+="("; s2+=")";}
				_expected = 0;
				_received = _obj.countWays(s1, s2); break;
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
