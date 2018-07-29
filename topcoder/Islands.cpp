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
vector<pair<ll,ll> > neigh(ll r, ll c) {
	vector<pair<ll,ll> > v;
	v.PB(MP(r,c-1));
	v.PB(MP(r,c+1));
	v.PB(MP(r+1,c));
	v.PB(MP(r-1,c));
	if (r%2==0) {
		v.PB(MP(r+1,c-1));
		v.PB(MP(r-1,c-1));
	}
	else {
		v.PB(MP(r+1,c+1));
		v.PB(MP(r-1,c+1));
	}
	return v;
}
class Islands {
	public:
	int beachLength(vector <string> kingdom) {
		int n=kingdom.size(),m=kingdom[0].length();
		ll ans=0;
		for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
			for (auto &w:neigh(x,y)) {
				ll r=w.first,c=w.second;
				if (0<=r&&r<n&&0<=c&&c<m) {
					if (kingdom[x][y]!=kingdom[r][c]) ans++;
				}
			}
		}
		return ans/2;
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
		cout << "Testing Islands (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1494860868;
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
		Islands _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string kingdom[] = {".#...#.."};
				_expected = 4;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}
			case 1:
			{
				string kingdom[] = {"..#.##", 
				                    ".##.#.", 
				                    "#.#..."};
				_expected = 19;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}
			case 2:
			{
				string kingdom[] = {"#...#.....",
				                    "##..#...#."};
				_expected = 15;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}
			case 3:
			{
				string kingdom[] = {"....#.",
				                    ".#....",
				                    "..#..#",
				                    "####.."};
				_expected = 24;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}
			/*case 4:
			{
				string kingdom[] = ;
				_expected = ;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string kingdom[] = ;
				_expected = ;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string kingdom[] = ;
				_expected = ;
				_received = _obj.beachLength(vector <string>(kingdom, kingdom+sizeof(kingdom)/sizeof(string))); break;
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
