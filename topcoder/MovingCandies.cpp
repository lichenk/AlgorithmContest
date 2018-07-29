#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> ppll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=21;
ll f[2][mn][mn];
ll n,m;
ll s[mn][mn];
bool valid(ll x,ll y) {
	return (0<=x)&&(x<n)&&(0<=y)&&(y<m);
}
class MovingCandies {
	public:
	int minMoved(vector <string> t) {
		n=t.size(),m=t[0].length();
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) s[x][y]=(t[x][y]=='#')?0:1;
		ll cur=0,nxt=1;
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) f[cur][x][y]=INF;
		ll nums=0;
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) nums+=(t[x][y]=='#')?1:0;
		f[cur][0][0]=(t[0][0]=='#')?0:1;
		ll ans=INF;
		for (ll t=0;t<nums;t++) {
			for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) f[nxt][x][y]=INF;
			chkmin(ans,f[cur][n-1][m-1]);
			for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
				for (ll nx=x-1;nx<=x+1;nx+=2) {
					ll ny=y;
					if (valid(nx,ny)) {
						chkmin(f[nxt][nx][ny],f[cur][x][y]+s[nx][ny]);
					}
				}
				for (ll ny=y-1;ny<=y+1;ny+=2) {
					ll nx=x;
					if (valid(nx,ny)) chkmin(f[nxt][nx][ny],f[cur][x][y]+s[nx][ny]);
				}
			}
			swap(cur,nxt);
		}
		if (ans>=INF/2) return -1;
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
		cout << "Testing MovingCandies (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485014405;
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
		MovingCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..#.#",
				             ".#....#"
				             };
				_expected = 3;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..###",
				             ".#....#"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string t[] = {
				             ".#..",
				             "##..",
				             "..#.",
				             "..#.",
				             "..##",
				             "..##"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string t[] = {
				             ".....",
				             ".###.",
				             "####.",
				             "....."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 4:
			{
				string t[] = {
				             ".#...#.###.#",
				             "#.#.##......",
				             ".#.#......#.",
				             "..#.......#.",
				             "##.........."
				             };
				_expected = 9;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 5:
			{
				string t[] = {
				             "###.#########..#####",
				             ".#######.###########"
				             };
				_expected = 0;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 6:
			{
				string t[] = {
				             "..",
				             ".."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 7:
			{
				string t[] = {
				             "#.",
				             ".#"
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 8:
			{
				string t[] = {
				             "##",
				             ".."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 9:
			{
				string t[] = {
				             "."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 10:
			{
				string t[] = {
				             "#"
				             };
				_expected = 0;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 11:
			{
				string t[] = {
					"###",
					"...",
					"#.#"
				};
				_expected = 1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 12:
			{
				string t[] = {
					"###",
					"...",
					"..#"
				};
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 13:
			{
				string t[] = {
					".##",
					"..#",
					"#.#"
				};
				_expected = 1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 14:
			{
				string t[] = {
"####################",
"...................#",
"####################",
"#...................",
"####################",
"...................#",
"####################",
"....................",
"#...................",
"####################",
"...................#",
"...................#",
"...................#",
"...................#",
};
				_expected = 3;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 9:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
