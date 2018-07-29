#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 58
#define UNDEF -1
ll n,m,d;
ll seen[MAXN][MAXN];
vector <string> gfield;
bool valid(ll x, ll y) {
	return (0<=x&&x<n&&0<=y&&y<m&&gfield[x][y] == 'v');
}

ll dfs(ll x, ll y, ll k) {
	if (!valid(x,y)) return 0;
	if (seen[x][y] != UNDEF) return 0;
	ll num = 1;
	seen[x][y] = k;
	for (ll dist = 1; dist <= d; dist++) {
		for (ll dx = 0; dx <= dist; dx++) {
			ll dy = dist-dx;
			num += dfs(x-dx,y-dy,k);
			num += dfs(x-dx,y+dy,k);
			num += dfs(x+dx,y-dy,k);
			num += dfs(x+dx,y+dy,k);
		}
	}
	return num;
}
ll f[MAXN*MAXN][2];
ll h[MAXN*MAXN];
class GooseInZooDivOne {
	public:
	int count(vector <string> field, int dist) {
		gfield=field;
		n = field.size();
		m = field[0].size();
		d = dist;
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < m; y++) {
				seen[x][y] = UNDEF;
			}
		}
		ll id = 1;
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < m; y++) {
				ll num = dfs(x,y,id);
				if (num > 0) {
					h[id] = num;
					id++;
				} 
			}
		}
		for (ll k = 0; k < id; k++) {
			for (ll i = 0; i < 2; i++) {
				f[k][i] = 0;
			}
		}
		f[0][0] = 1;
		f[0][1] = 0;
		for (ll k = 1; k < id; k++) {
			ll num = h[k];
			for (ll i = 0; i < 2; i++) {
				f[k][i] += f[k-1][i];
				f[k][(i+num)%2] += f[k-1][i];
			}
			for (ll i = 0; i < 2; i++) f[k][i] %= MOD;
		}
		ll ans = f[id-1][0];
		return (ans+MOD-1)%MOD;
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
		cout << "Testing GooseInZooDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453266343;
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
		GooseInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"vvv"};
				int dist = 0;
				_expected = 3;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 1:
			{
				string field[] = {"."};
				int dist = 100;
				_expected = 0;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 2:
			{
				string field[] = {"vvv"};
				int dist = 1;
				_expected = 0;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 3:
			{
				string field[] = {"v.v..................v............................"
				                 ,".v......v..................v.....................v"
				                 ,"..v.....v....v.........v...............v......v..."
				                 ,".........vvv...vv.v.........v.v..................v"
				                 ,".....v..........v......v..v...v.......v..........."
				                 ,"...................vv...............v.v..v.v..v..."
				                 ,".v.vv.................v..............v............"
				                 ,"..vv.......v...vv.v............vv.....v.....v....."
				                 ,"....v..........v....v........v.......v.v.v........"
				                 ,".v.......v.............v.v..........vv......v....."
				                 ,"....v.v.......v........v.....v.................v.."
				                 ,"....v..v..v.v..............v.v.v....v..........v.."
				                 ,"..........v...v...................v..............v"
				                 ,"..v........v..........................v....v..v..."
				                 ,"....................v..v.........vv........v......"
				                 ,"..v......v...............................v.v......"
				                 ,"..v.v..............v........v...............vv.vv."
				                 ,"...vv......v...............v.v..............v....."
				                 ,"............................v..v.................v"
				                 ,".v.............v.......v.........................."
				                 ,"......v...v........................v.............."
				                 ,".........v.....v..............vv.................."
				                 ,"................v..v..v.........v....v.......v...."
				                 ,"........v.....v.............v......v.v............"
				                 ,"...........v....................v.v....v.v.v...v.."
				                 ,"...........v......................v...v..........."
				                 ,"..........vv...........v.v.....................v.."
				                 ,".....................v......v............v...v...."
				                 ,".....vv..........................vv.v.....v.v....."
				                 ,".vv.......v...............v.......v..v.....v......"
				                 ,"............v................v..........v....v...."
				                 ,"................vv...v............................"
				                 ,"................v...........v........v...v....v..."
				                 ,"..v...v...v.............v...v........v....v..v...."
				                 ,"......v..v.......v........v..v....vv.............."
				                 ,"...........v..........v........v.v................"
				                 ,"v.v......v................v....................v.."
				                 ,".v........v................................v......"
				                 ,"............................v...v.......v........."
				                 ,"........................vv.v..............v...vv.."
				                 ,".......................vv........v.............v.."
				                 ,"...v.............v.........................v......"
				                 ,"....v......vv...........................v........."
				                 ,"....vv....v................v...vv..............v.."
				                 ,".................................................."
				                 ,"vv........v...v..v.....v..v..................v...."
				                 ,".........v..............v.vv.v.............v......"
				                 ,".......v.....v......v...............v............."
				                 ,"..v..................v................v....v......"
				                 ,".....v.....v.....................v.v......v......."};
				int dist = 3;
				_expected = 898961330;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 4:
			{
				string field[] = {"vv.vv"};
				int dist = 1;
				_expected = 3;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 5:
			{
				string field[] = {".vv..v.........v....", "....v.......vv...vvv", "...vv.v....v..vv....", "v......v....vv...v..", "..v..v..vv.v..vv....", "..v....v.v.....v...v", ".v......v..vv...v...", "vv..............v...", "..v..v.....vv.v.v..v", "v.........vv...v....", "......v..v.v.....v..", ".....v.....v....v..v", "..v.v....v.v.....v..", "..v.......vvv.....v.", "....v....v.vv.....v.", ".v...v.............v", "..vv.....v.........v", "..v.................", "v.........v.........", "v...........v....v..", "v.......v..........."};
				int dist = 0;
				_expected = 280261901;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			/*case 6:
			{
				string field[] = ;
				int dist = ;
				_expected = ;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
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
