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
ll sq(ll x) {
	return x*x;
}
ll f[2][1008];
ll h[2];
class ParenthesesDiv1Hard {
	public:
	int minCost(string s) {
		ll n=s.length();
		{
			ll h=0;
			for (ll x=0;x<n;x++) {
				if (s[x]=='(') h++;
				else h--;
				if (h<0) return -1;
			}
			if (h!=0) return -1;
		}
		for (ll k=0;k<2;k++) {
			h[k]=0;
			for (ll x=0;x<n;x++) f[k][x]=0;
		}
		ll ans=0;
		string a[2];
		for (ll x=0;x<n;x++) {
			if (s[x]=='(') {
				ll p[2];
				{
					for (ll k=0;k<2;k++) p[k]=0;
					for (ll k=0;k<2;k++) {
						for (ll ht=0;ht<=h[k];ht++) {
							ll gain=sq(h[k]+1-ht)-sq(f[k][ht]);
							assert(h[k]+1-ht<=f[k][ht]+1);
							//printf("x:%d k:%d ht:%d h[k]:%d f[k][ht]:%d gain:%d\n",
							//	x,k,ht,h[k],f[k][ht],gain);
							p[k]+=max(gain,0LL);
						}
					}
				}
				//for (ll k=0;k<2;k++) printf("x:%d k:%d p:%d\n",x,k,p[k]);
				ll k;
				if (p[0]<p[1]) k=0;
				else if (p[1]<p[0]) k=1;
				else k=(h[0]<=h[1])?0:1;
				a[k]+='(';
				ans+=p[k];
				h[k]++;
				f[k][h[k]]=0;
				for (ll ht=0;ht<=h[k];ht++) {
					chkmax(f[k][ht],h[k]-ht);
				}
			}
			else {
				ll k;
				if (h[0]>h[1]) k=0;
				else if (h[1]>h[0]) k=1;
				else {
					k=f[0][h[0]]>f[1][h[1]]?0:1;
				}
				a[k]+=')';
				f[k][h[k]]=0;
				h[k]--;
				f[k][h[k]]=0;
				assert(h[k]>=0);
			}
		}
		cout<<a[0]<<endl<<a[1]<<endl;
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
		cout << "Testing ParenthesesDiv1Hard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460734897;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ParenthesesDiv1Hard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "(())";
				_expected = 2;
				_received = _obj.minCost(s); break;
			}
			case 1:
			{
				string s = "((())())(()()())";
				_expected = 11;
				_received = _obj.minCost(s); break;
			}
			case 2:
			{
				string s = "())(()";
				_expected = -1;
				_received = _obj.minCost(s); break;
			}
			case 3:
			{
				string s = "(((((((((())))))))))";
				_expected = 110;
				_received = _obj.minCost(s); break;
			}
			case 4:
			{
				string s = "()";
				_expected = 1;
				_received = _obj.minCost(s); break;
			}
			case 5:
			{
				string s = "(((())()()()((((()))))(((())))()()()))(()(()))";
				_expected = 69;
				_received = _obj.minCost(s); break;
			}
			case 6:
			{
				string s = "(()())()()(())()(())()()()()()()()()()()((()())()(())())()()(())()(((()()())))()()(()(()))()(())(())()(()())()()(())()()((()))()()(()()())()(())()()()";
				_expected = 90;
				_received = _obj.minCost(s); break;
			}
			case 7:
			{
				string s = "(((((((((()(()((((((((((((((()(((((((()())(((((((((((((((((((()(((()()(())()))()((())((((((())))))))))))))))))))))))))))))))))))))))))))))))))))))))))";
				_expected = 17133;
				_received = _obj.minCost(s); break;
			}
			case 8:
			{
				string s = "(())()";
				_expected = 3;
				_received = _obj.minCost(s); break;
			}
			case 9:
			{
				string s = "(((())))()()";
				_expected = 12;
				_received = _obj.minCost(s); break;
			}
			case 10:
			{
				string s = "()()(())((())(())(())(()(())(((()(((((()())((())()((())((()(())))()()(()()((()(((((((()))))(())((())(((())(()(())())(()(()))))))))))))))))))))))";
				_expected = 1228;
				_received = _obj.minCost(s); break;
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
