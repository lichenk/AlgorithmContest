#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<40ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXN=32;
const ll BASE=902;
ll tl[MAXN][MAXN][2*BASE];
ll br[MAXN][MAXN][2*BASE];
ll la[2*BASE];
ll ra[MAXN][2*BASE];
ll solve(vector<string> flowers, ll maxDiff) {
	ll xlim=flowers.size(),ylim=flowers[0].size();
	for (ll x=0;x<xlim;x++) for (ll y=0;y<ylim;y++) for (ll z=0;z<2*BASE;z++) {
		br[x][y][z]=-INF;
		tl[x][y][z]=-INF;
	}
	for (ll sx=0;sx<xlim;sx++) {
		for (ll sy=0;sy<ylim;sy++) {
			for (ll ex=sx;ex<xlim;ex++) {
				ll l=0,p=0;
				for (ll ey=sy;ey<ylim;ey++) {
					for (ll x=sx;x<=ex;x++) {
						char c=flowers[x][ey];
						if (c=='L') l++;
						else if (c=='P') p++;
					}
					chkmax(br[sx][sy][l-p+BASE],l+p);
				}
			}
			for (ll ex=sx;ex>=0;ex--) {
				ll l=0,p=0;
				for (ll ey=sy;ey>=0;ey--) {
					for (ll x=sx;x>=ex;x--) {
						char c=flowers[x][ey];
						if (c=='L') l++;
						else if (c=='P') p++;
					}
					chkmax(tl[sx][sy][l-p+BASE],l+p);
				}
			}
		}
	}
	for (ll v=0;v<2*BASE;v++) {la[v]=-INF;ra[xlim-1][v]=-INF;}
	for (ll bx=xlim-1;bx>=1;bx--) {
		for (ll y=0;y<ylim;y++) {
			for (ll v=0;v<2*BASE;v++) {
				chkmax(ra[bx][v],br[bx][y][v]);
			}
		}
		for (ll v=0;v<2*BASE;v++) {
			ra[bx-1][v]=ra[bx][v];
		}
	}
	ll ans=-INF;
	for (ll bx=0;bx<xlim-1;bx++) {
		for (ll y=0;y<ylim;y++) {
			for (ll v=0;v<2*BASE;v++) {
				chkmax(la[v],tl[bx][y][v]);
			}
		}
		for (ll lv=0;lv<2*BASE;lv++) {
			for (ll rv=0;rv<2*BASE;rv++) {
				if (abs(lv+rv-2*BASE)<=maxDiff) {
					//printf("hit");
					chkmax(ans,la[lv]+ra[bx+1][rv]);
					/*ll cand=la[lv]+ra[bx+1][rv];
					if (cand>=0) {
						printf("bx:%lld lv:%lld rv:%lld ans:%lld\n",bx,lv-BASE,rv-BASE,cand);
					}*/
				}
			}
		}
	}
	return ans;
}
class FoxAndFlowerShopDivOne {
	public:
	int theMaxFlowers(vector <string> flowers, int maxDiff) {
		ll c1=solve(flowers,maxDiff);
		ll xlim=flowers.size(),ylim=flowers[0].size();
		vector<string> rot; rot.resize(ylim);
		for (ll y=0;y<ylim;y++) rot[y].resize(xlim);
		for (ll x=0;x<xlim;x++) for (ll y=0;y<ylim;y++) rot[y][x]=flowers[x][y];
		ll c2=solve(rot,maxDiff);
		ll final=max(c1,c2);
		if (final<0) return -1;
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
		cout << "Testing FoxAndFlowerShopDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469725851;
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
		FoxAndFlowerShopDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string flowers[] = {"LLL",
				                    "PPP",
				                    "LLL"};
				int maxDiff = 1;
				_expected = 7;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 1:
			{
				string flowers[] = {"LLL",
				                    "PPP",
				                    "LLL"};
				int maxDiff = 0;
				_expected = 6;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 2:
			{
				string flowers[] = {"...",
				                    "...",
				                    "..."};
				int maxDiff = 3;
				_expected = 0;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 3:
			{
				string flowers[] = {"LLPL.LPP",
				                    "PLPPPPLL",
				                    "L.P.PLLL",
				                    "LPL.PP.L",
				                    ".LLL.P.L",
				                    "PPLP..PL"};
				int maxDiff = 2;
				_expected = 38;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 4:
			{
				string flowers[] = {"LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL",
				                    "LLLLLLLLLL"};
				int maxDiff = 0;
				_expected = -1;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 5:
			{
				string flowers[] = {"LLLP..LLP.PLL.LL..LP",
				                    "L.PL.L.LLLL.LPLLPLP.",
				                    "PLL.LL.LLL..PL...L..",
				                    ".LPPP.PPPLLLLPLP..PP",
				                    "LP.P.PPL.L...P.L.LLL",
				                    "L..LPLPP.PP...PPPL..",
				                    "PP.PLLL.LL...LP..LP.",
				                    "PL...P.PPPL..PLP.L..",
				                    "P.PPPLPLP.LL.L.LLLPL",
				                    "PLLPLLP.LLL.P..P.LPL",
				                    "..LLLPLPPPLP.P.LP.LL",
				                    "..LP..L..LLPPP.LL.LP",
				                    "LPLL.PLLPPLP...LL..P",
				                    "LL.....PLL.PLL.P....",
				                    "LLL...LPPPPL.PL...PP",
				                    ".PLPLLLLP.LPP...L...",
				                    "LL...L.LL.LLLPLPPPP.",
				                    "PLPLLLL..LP.LLPLLLL.",
				                    "PP.PLL..L..LLLPPL..P",
				                    ".LLPL.P.PP.P.L.PLPLL"};
				int maxDiff = 9;
				_expected = 208;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 6:
			{
				string flowers[] = {"LP"};
				int maxDiff = 0;
				_expected = 2;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 7:
			{
				string flowers[] = {"LL"};
				int maxDiff = 2;
				_expected = 2;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
			}
			case 8:
			{
				string flowers[] = {"LL"};
				int maxDiff = 1;
				_expected = -1;
				_received = _obj.theMaxFlowers(vector <string>(flowers, flowers+sizeof(flowers)/sizeof(string)), maxDiff); break;
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
