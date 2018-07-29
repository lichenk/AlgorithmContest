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
bool sn[55][55];
ll ac[55],ar[55];
vector<string> b;
ll rlim,clim;
void dfs(ll r, ll c) {
	if (sn[r][c]) return;
	sn[r][c]=true;
	for (ll x=0;x<rlim;x++) {
		if (b[x][c]=='#') dfs(x,c);
	}
	for (ll y=0;y<clim;y++) {
		if (b[r][y]=='#') dfs(r,y);
	}
}
class MagicBoard {
	public:
	string ableToUnlock(vector <string> board) {
		b=board;
		rlim=board.size(),clim=board[0].length();
		for (ll r=0;r<rlim;r++) ar[r]=0;
		for (ll c=0;c<clim;c++) ac[c]=0;
		ll ir,ic;
		for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
			if (board[r][c]=='#') {ar[r]++,ac[c]++; ir=r,ic=c;}
		}
		ll oddr=0,oddc=0;
		for (ll r=0;r<rlim;r++) if (ar[r]&1) oddr++;
		for (ll c=0;c<clim;c++) if (ac[c]&1) oddc++;
		if ((oddc<=1&&oddr<=1)||(oddc<=2&&oddr<=0)) {
			for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) sn[r][c]=false;
			dfs(ir,ic);
			for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
				if (board[r][c]=='#'&&sn[r][c]==false) return "NO";
			}
			return "YES";
		}
		return "NO";
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
		cout << "Testing MagicBoard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471969959;
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
		MagicBoard _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"##",
				                  ".#"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#.",
				                  ".#"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"##",
				                  "##",
				                  "##"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"###",
				                  "###",
				                  "###"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"###",
				                  "..#",
				                  "###",
				                  "#..",
				                  "###"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"................",
				                  ".######..######.",
				                  ".######..######.",
				                  ".##......##..##.",
				                  ".##......##..##.",
				                  ".######..######.",
				                  ".######..######.",
				                  ".....##..##..##.",
				                  ".....##..##..##.",
				                  ".######..######.",
				                  ".######..######.",
				                  "................"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"#"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
