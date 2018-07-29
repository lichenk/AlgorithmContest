#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
vector<string> glevel;
bool seen[100][100];
ll n,m;
bool valid(ll i, ll j) {
	return (0 <= i) && (i <= n) && (0 <= j) && (j < m) && glevel[i+1][j] == 'X' && (glevel[i][j] == '.' || i == n);
}
class ArcadeManao {
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		glevel = level;
		ll imin = 0; ll imax = 50;
		n = level.size();
		m = level[0].length();
		while(imin < imax) {
			ll imid = (imin + imax)/2;
			for (ll i = 0; i <= n; i++) {
				for (ll j = 0; j < m; j++) {
					seen[i][j] = false;
				}
			}
			queue<pair<ll,ll> > q;
			for (ll j = 0; j < m; j++) {
				ll i = 1;
				if (valid(i,j)) {
					q.push(MP(i,j)); seen[i][j] = true;
				}
			}
			bool good = false;
			while(!q.empty()) {
				pair<ll,ll> v = q.front();
				if (v.first == coinRow && v.second == coinColumn) {
					good = true; break;
				}
				printf("x:%lld y:%lld\n",v.first,v.second);
				q.pop();
				vector<pair<ll,ll> > neigh;
				neigh.PB(MP(v.first,v.second-1));
				neigh.PB(MP(v.first,v.second+1));
				for (ll i = max(1LL, v.first-imid); i <= min(n-1, v.first+imid); i++) {
					neigh.PB(MP(i,v.second));
				}
				for (auto& w: neigh) {
					ll x = w.first; ll y = w.second;
					if (valid(x,y)) {
						if (!seen[x][y]) {
							seen[x][y] = true;
							q.push(w);
						}
					}
				}
			}
			printf("%lld %d\n",imid,good);
			return 0;
			if (!good) {
				imin = imid + 1;
			}
			else {
				imax = imid;
			}
		}
		assert(imin == imax);
		return imin;
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
		cout << "Testing ArcadeManao (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451107905;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArcadeManao _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string level[] = {"XXXX....",
				                  "...X.XXX",
				                  "XXX..X..",
				                  "......X.",
				                  "XXXXXXXX"};
				int coinRow = 2;
				int coinColumn = 4;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 1:
			{
				string level[] = {"XXXX",
				                  "...X",
				                  "XXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 1;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 2:
			{
				string level[] = {"..X..",
				                  ".X.X.",
				                  "X...X",
				                  ".X.X.",
				                  "..X..",
				                  "XXXXX"};
				int coinRow = 1;
				int coinColumn = 3;
				_expected = 4;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 3:
			{
				string level[] = {"X"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 0;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 4:
			{
				string level[] = {"XXXXXXXXXX",
				                  "...X......",
				                  "XXX.......",
				                  "X.....XXXX",
				                  "..XXXXX..X",
				                  ".........X",
				                  ".........X",
				                  "XXXXXXXXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			/*case 5:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 6:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 7:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
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
