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
const ll mn=24;
ll a[mn][mn];
ll rlim,clim;
vector<ll> h;
vector<ll> g;
ll antimask;
const ll full=(1<<21)-1;
void dfs(ll x, ll y, ll sig, ll k) {
	ll v=a[x][y];
	if (v==-1) return;
	ll msk=1LL<<v;
	if (sig&msk) return;
	sig|=msk;
	if (k==10) {
		h.PB(sig);
		g.PB((~(sig&antimask))&full);
		return;
	}
	dfs(x+1,y,sig,k+1);
	dfs(x-1,y,sig,k+1);
	dfs(x,y+1,sig,k+1);
	dfs(x,y-1,sig,k+1);
}
class AlphabetPaths {
	public:
	long long count(vector <string> letterMaze) {
		string translate="ABCDEFZHIKLMNOPQRSTVX";
		map<char,ll> transmap;
		for (ll i=0;i<translate.length();i++) transmap[translate[i]]=i;
		transmap['.']=-1;
		rlim=letterMaze.size(),clim=letterMaze[0].length();
		for (ll r=0;r<mn;r++) for (ll c=0;c<mn;c++) a[r][c]=-1;
		for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
			a[r+1][c+1]=transmap[letterMaze[r][c]];
		}
		ll ans=0;
		for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
			ll x=r+1,y=c+1;
			antimask=~(1LL<<a[x][y]);
			dfs(x,y,0,0);
			sort(h.begin(),h.end());
			sort(g.begin(),g.end());
			//for (auto &w:h) printf("%lld ",w);
			//printf("\n");
			//for (auto &w:g) printf("%lld ",w);
			//printf("\n\n");
			ll hsz=h.size(),gsz=g.size();
			ll hi=0,gi=0;
			while(hi<hsz) {
				ll orig=h[hi];
				ll hcnt=0,gcnt=0;
				while(h[hi]==orig&&hi<hsz) {hi++; hcnt++;}
				while(g[gi]<orig&&gi<gsz) {gi++;}
				while(g[gi]==orig&&gi<gsz) {gi++; gcnt++;}
				ans+=(hcnt*gcnt);
			}
			h.clear();g.clear();
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
		cout << "Testing AlphabetPaths (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472957155;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlphabetPaths _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letterMaze[] = {"ABCDEFZHIXKLMNOPQRST",
				                       "...................V"};
				_expected = 2LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 1:
			{
				string letterMaze[] = {".................VT.",
				                       "....................",
				                       "ABCDEFZHIXKLMNOPQRS.",
				                       "..................S.",
				                       ".................VT."};
				_expected = 0LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 2:
			{
				string letterMaze[] = {"TBCDE.PQRSA", 
				                       "FZHIXKLMNOV"};
				_expected = 50LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 3:
			{
				string letterMaze[] = {"ABCDEF.",
				                       "V....Z.",
				                       "T....H.",
				                       "S....I.",
				                       "R....X.",
				                       "KLMNOPQ"};
				_expected = 4LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			case 4:
			{
				string letterMaze[] = {"ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM", "OPQRSTVOPQRSTVOPQRST", "ABCDEFZABCDEFZABCDEF", "HIXKLMNHIXKLMNHIXKLM"};
				_expected = 5338808LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}
			/*case 5:
			{
				string letterMaze[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string letterMaze[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(letterMaze, letterMaze+sizeof(letterMaze)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
