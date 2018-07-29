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
ll b[54][54];
class FlipGame {
	public:
	int minOperations(vector <string> board) {
		ll n=board.size(); ll m=board[0].length();
		for (ll x=0;x<n;x++) for(ll y=0;y<m;y++) b[x][y]=(board[x][y]=='1')?1:0;
		for (ll ans=0;;ans++) {
			ll py=-1;
			for (ll x=0;x<n;x++) {
				ll fy=-1;
				for (ll y=m-1;y>=py+1;y--) {
					if (b[x][y]==1) {fy=y; break;}
				}
				py=max(py,fy);
				for (ll y=0;y<=py;y++) {
					b[x][y]^=1;
				}
				//printf("x:%d flips up to py:%d\n",x,py);
			}
			//for (ll x=0;x<n;x++) {for (ll y=0;y<m;y++) printf("%d",b[x][y]); printf("\n");}
			//printf("\n");
			if (py==-1) return ans;
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
		cout << "Testing FlipGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471017815;
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
		FlipGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"1000",
				                  "1110",
				                  "1111"};
				_expected = 1;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"1111",
				                  "1111",
				                  "1111"};
				_expected = 1;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"00",
				                  "00",
				                  "00"};
				_expected = 0;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"00000000",
				                  "00100000",
				                  "01000000",
				                  "00001000",
				                  "00000000"};
				_expected = 4;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"000000000000001100000000000000",
				                  "000000000000011110000000000000",
				                  "000000000000111111000000000000",
				                  "000000000001111111100000000000",
				                  "000000000011111111110000000000",
				                  "000000000111111111111000000000",
				                  "000000001100111111001100000000",
				                  "000000011000011110000110000000",
				                  "000000111100111111001111000000",
				                  "000001111111111111111111100000",
				                  "000011111111111111111111110000",
				                  "000111111111000000111111111000",
				                  "001111111111100001111111111100",
				                  "011111111111110011111111111110",
				                  "111111111111111111111111111111"};
				_expected = 29;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
