#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 11
bool seen[MAXN][MAXN][MAXN], a[MAXN][MAXN][MAXN], b[MAXN][MAXN][MAXN];
char xy[MAXN][MAXN],yz[MAXN][MAXN],zx[MAXN][MAXN];
ll n;
void dfs(ll i, ll j, ll k) {
	if (0<=i&&i<n&&0<=j&&j<n&&0<=k&&k<n&&a[i][j][k] && !seen[i][j][k]) {
		seen[i][j][k] = true;
		b[i][j][k] = true;
		dfs(i-1,j,k);
		dfs(i+1,j,k);
		dfs(i,j-1,k);
		dfs(i,j+1,k);
		dfs(i,j,k-1);
		dfs(i,j,k+1);
	}
}

bool solve(ll x, ll y, ll z, vector <string> &XY, vector <string> &YZ, vector <string> &ZX) {
	if (!a[x][y][z]) return false;
	if (seen[x][y][z]) return false;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			for (ll k = 0; k < n; k++) {
				b[i][j][k] = false;
				xy[i][j] = 'N';
				yz[j][k] = 'N';
				zx[k][i] = 'N';
			}
	dfs(x,y,z);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			for (ll k = 0; k < n; k++) {
				if (b[i][j][k]) {
					if (!(XY[i][j] == 'Y' && YZ[j][k] == 'Y' && ZX[k][i] == 'Y')) {
						return false;
					}
					xy[i][j] = 'Y';
					yz[j][k] = 'Y';
					zx[k][i] = 'Y';
				}
			}
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++) {
			if (xy[i][j] != XY[i][j] ||
				yz[i][j] != YZ[i][j] ||
				zx[i][j] != ZX[i][j]
				)
				return false;
		}
	return true;
}

class ShadowSculpture {
	public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		n = XY.size();
		bool all0 = true;
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++) all0 = all0 && XY[i][j] == 'N' && YZ[i][j] == 'N' && ZX[i][j] == 'N';
		if (all0) return "Possible";
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++)
				for (ll k = 0; k < n; k++) {
					a[i][j][k] = true;
					seen[i][j][k] = false;
				}
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++)
				for (ll k = 0; k < n; k++) {
					if (XY[i][j] == 'N' || YZ[j][k] == 'N' || ZX[k][i] == 'N')
						a[i][j][k] = false;
				}
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++)
				for (ll k = 0; k < n; k++)
					if (solve(i,j,k,XY,YZ,ZX)) return "Possible";
		return "Impossible";
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


int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ShadowSculpture (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454040732;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ShadowSculpture _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string XY[] = {"YN","NN"};
				string YZ[] = {"YN","NN"};
				string ZX[] = {"YN","NN"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 1:
			{
				string XY[] = {"YN","NY"};
				string YZ[] = {"YN","NY"};
				string ZX[] = {"YN","NY"};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 2:
			{
				string XY[] = {"YYY","YNY","YYY"};
				string YZ[] = {"YYY","YNY","YYY"};
				string ZX[] = {"YYY","YNY","YYY"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 3:
			{
				string XY[] = {"YYY","YNY","YYY"};
				string YZ[] = {"NYY","YNY","YYY"};
				string ZX[] = {"YYY","YNY","YYN"};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 4:
			{
				string XY[] = {"N"};
				string YZ[] = {"N"};
				string ZX[] = {"N"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			case 5:
			{
				string XY[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
				string YZ[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
				string ZX[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}
			/*case 6:
			{
				string XY[] = ;
				string YZ[] = ;
				string ZX[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string XY[] = ;
				string YZ[] = ;
				string ZX[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(XY, XY+sizeof(XY)/sizeof(string)), vector <string>(YZ, YZ+sizeof(YZ)/sizeof(string)), vector <string>(ZX, ZX+sizeof(ZX)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
