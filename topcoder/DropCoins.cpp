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
ll f[32][32];
vector<string> gb;
ll getsum(ll x, ll y) {
	if (x<0||y<0) return 0;
	else return f[x][y];
}
class DropCoins {
	public:
	int getMinimum(vector <string> board, int K) {
		gb=board;
		ll rlim=board.size(),clim=board[0].length();
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				ll got=0;
				for (ll x=0;x<=r;x++) for (ll y=0;y<=c;y++) {
					if(board[x][y]=='o') got++;
				}
				f[r][c]=got;
			}
		}
		ll ans=INF;
		for (ll sr=0;sr<rlim;sr++) for (ll tr=sr;tr<rlim;tr++) {
			for (ll sc=0;sc<clim;sc++) for (ll tc=sc;tc<clim;tc++) {
				ll have=getsum(tr,tc)-getsum(sr-1,tc)-getsum(tr,sc-1)+getsum(sr-1,sc-1);
				if (have==K) {
					/*printf("%d %d %d %d: %d. %d-%d-%d+%d\n",sr,tr,sc,tc,have,
						getsum(tr,tc),getsum(sr-1,tc),getsum(tr,sc-1),getsum(sr-1,sc-1));*/
					ll cand=0;
					ll r1=sr,r2=rlim-1-tr;
					if (r1>r2) swap(r1,r2);
					cand+=2*r1+r2;
					ll c1=sc,c2=clim-1-tc;
					if (c1>c2) swap(c1,c2);
					cand+=2*c1+c2;
					chkmin(ans,cand);
				}
			}
		}
		if (ans==INF) return -1;
		else return ans;
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
		cout << "Testing DropCoins (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472662853;
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
		DropCoins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".o.."
				                 ,"oooo"
				                 ,"..o."};
				int K = 3;
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 1:
			{
				string board[] = {".....o"
				                 ,"......"
				                 ,"oooooo"
				                 ,"oooooo"
				                 ,"......"
				                 ,"o....."};
				int K = 12;
				_expected = 3;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 2:
			{
				string board[] = {"...."
				                 ,".oo."
				                 ,".oo."
				                 ,"...."};
				int K = 3;
				_expected = -1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 3:
			{
				string board[] = {"......."
				                 ,"..ooo.."
				                 ,"ooooooo"
				                 ,".oo.oo."
				                 ,"oo...oo"};
				int K = 12;
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 4:
			{
				string board[] = {"................."
				                 ,".ooooooo...oooo.."
				                 ,".ooooooo..oooooo."
				                 ,".oo.......oo..oo."
				                 ,".oo.......oo..oo."
				                 ,".ooooo.....oooo.."
				                 ,".ooooooo...oooo.."
				                 ,".....ooo..oo..oo."
				                 ,"......oo..oo..oo."
				                 ,".ooooooo..oooooo."
				                 ,".oooooo....oooo.."
				                 ,"................."};
				int K = 58;
				_expected = 6;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 5:
			{
				string board[] = {"oo",
			                    "o."};
				int K = 2;
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 6:
			{
				string board[] = {"o"};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 7:
			{
				string board[] = {"oo"};
				int K = 1;
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 8:
			{
				string board[] = {"oo",
			                    ".o"};
				int K = 2;
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 9:
			{
				string board[] = {".o",
			                    "oo"};
				int K = 2;
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			case 10:
			{
				string board[] = {"o.",
			                    "oo"};
				int K = 2;
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
			}
			/*case 7:
			{
				string board[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
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
