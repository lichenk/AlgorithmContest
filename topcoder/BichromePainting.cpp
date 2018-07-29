#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 21
class BichromePainting {
	public:
	string isThatPossible(vector <string> board, int k) {
		ll n = board.size();
		while(1) {
			bool found = false;
			for (ll x = 0; x <= n-k; x++) {
				for (ll y = 0; y <= n-k; y++) {
					bool ok = true;
					bool allq = true;
					char c = '?';
					for (ll i = x; i < x+k; i++) {
						for (ll j = y; j < y+k; j++) {
							if (board[i][j] != '?') {
								allq = false;
								if (c == '?') c = board[i][j];
							}
							if (!(board[i][j] == '?' || board[i][j] == c)) {
								if(x==4&&y==4) printf("%lld,%lld\n",i,j);
								ok = false; break;
							}
						}
						if (ok == false) break;
					}
					if (ok && !allq) {
						//printf("%lld,%lld\n",x,y);
						for (ll i = x; i < x+k; i++) {
							for (ll j = y; j < y+k; j++) {
								board[i][j] = '?';
							}
						}
						found = true;
					}
				}
			}
			if (found == false) break;
		}
		//for (ll x = 0; x < n; x++) {
		//	for (ll y = 0; y < n; y++) {
		//		printf("%c",board[x][y]);
		//	}
		//	printf("\n");
		//}
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < n; y++) {
				if (!(board[x][y] == 'W' || board[x][y] == '?')) return "Impossible";
			}
		}
		return "Possible";
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
		cout << "Testing BichromePainting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451760573;
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
		BichromePainting _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"BBBW",
				                  "BWWW",
				                  "BWWW",
				                  "WWWW"};
				int k = 3;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 1:
			{
				string board[] = {"BW",
				                  "WB"};
				int k = 2;
				_expected = "Impossible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 2:
			{
				string board[] = {"BWBWBB",
				                  "WBWBBB",
				                  "BWBWBB",
				                  "WBWBBB",
				                  "BBBBBB",
				                  "BBBBBB"};
				int k = 2;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 3:
			{
				string board[] = {"BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "BBBBBB"};
				int k = 2;
				_expected = "Impossible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 4:
			{
				string board[] = {"BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "BBBBBB"};
				int k = 1;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 5:
			{
				string board[] = {"BB",
				                  "BB"};
				int k = 2;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			/*case 6:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
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
