#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[2][1<<20];
class MovingCandies {
	public:
	int minMoved(vector <string> t) {
		ll n=t.size(),m=t[0].length();
		ll zlim=1LL<<m;
		ll cur=0,nxt=1;
		for (ll z=0;z<zlim;z++) f[cur][z]=INF;
		{
			ll need
			for (ll y=m-1;y>=0;y--) {
			}
		}
		for (ll x=n-1;x>=0;x--) {
			for (ll z=0;z<zlim;z++) {

			}
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
			/*case 7:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
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
