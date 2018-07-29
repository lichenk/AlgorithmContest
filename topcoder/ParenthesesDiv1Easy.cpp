#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<20ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
pair<ll,pair<ll,ll> > f[1008][1008];
ll a[1008];
ll gadd[1008][1008];
ll gpeak[1008][1008];
class ParenthesesDiv1Easy {
	public:
	vector <int> correct(string s) {
		ll n=s.length();
		for (ll x=0;x<n;x++) {
			a[x]=(s[x]=='(')?1:-1;
		}
		for (ll y=0;y<n;y++) {
			ll add=0,peak=0;
			for (ll x=y;x>=0;x--) {
				add+=a[x];
				chkmax(peak,add);
				gadd[x][y]=add;
				gpeak[x][y]=peak;
			}
		}
		ll maxh=n+2;
		for (ll x=0;x<=n;x++) {
			for (ll h=0;h<=maxh;h++) {
				f[x][h]=MP(INF,MP(-1,-1));
			}
		}
		f[0][0]=MP(0,MP(-1,-1));
		for (ll x=0;x<n;x++) {
			for (ll h=0;h<=maxh;h++) {
				ll k=f[x][h].first;
				if (k>=INF) continue;
				for (ll y=x+1;y<=n;y++) {
					ll add=gadd[x][y-1]; ll peak=gpeak[x][y-1];
					//printf("x:%d y:%d add:%d peak:%d\n",x,y,add,peak);
					ll sub=-add; ll low=-peak;
					if (h+low>=0) {
						ll nk=k+1;
						if (nk<f[y][h+sub].first) {
							//printf("%d %d->%d %d. %d->%d\n",x,h,y,h+sub,k,nk);
							f[y][h+sub]=MP(nk,MP(x,h));
						}
					}
				}
				if (k<f[x+1][h+a[x]].first) {
					f[x+1][h+a[x]]=MP(k,MP(-2,-2));
				}
			}
		}
		ll ansv=f[n][0].first;
		if (ansv>10) {
			vector<int> fail={-1};
			return fail;
		}
		else {
			vector<int> ans;
			ll x=n;
			ll h=0;
			while(1) {
				ll y=f[x][h].second.first;
				ll nh=f[x][h].second.second;
				if (y==-1) break;
				else if (y==-2) {
					x--;
					h-=a[x];
				}
				else {
					ans.PB(y); ans.PB(x-1);
					x=y;h=nh;
				}
			}
			return ans;
		}
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
		cout << "Testing ParenthesesDiv1Easy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460732403;
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
		ParenthesesDiv1Easy _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = ")(";
				int __expected[] = {0, 0, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 1:
			{
				string s = "))))))((((((";
				int __expected[] = {0, 5, 6, 11 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 2:
			{
				string s = "))()())()";
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 3:
			{
				string s = ")()(((";
				int __expected[] = {0, 0, 3, 3, 5, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 4:
			{
				string s = "()";
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			/*case 5:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
