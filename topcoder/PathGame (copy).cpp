#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const string P1="Snuke";
const string P2="Sothe";
class PathGame {
	public:
	string judge(vector <string> board) {
		bool alldot=true;
		ll n=board[0].length();
		for (ll x=0;x<2;x++) {
			for (ll y=0;y<n;y++) {
				alldot=alldot && (board[x][y] == '.');
			}
		}
		if (alldot) {
			if (n%2==0) return P2;
			else return P1;
		}
		ll dd=0;
		if (board[0][0]=='.'&&board[1][0]=='.'&&board[0][1]=='.'&&board[1][1]=='.') dd++;
		if (board[0][n-1]=='.'&&board[1][n-1]=='.'&&board[0][n-2]=='.'&&board[1][n-2]=='.') dd++;
		if(dd==1) return P1;
		else if(dd==0) {
			ll px,py;
			ll sy=0; ll ey=n-1;
			if(board[0][sy]=='.'&&board[0][sy+1]=='.') {px=0;py=sy;}
			else{px=1;py=sy;}
			ll c=0;
			while(1) {
				if (py==ey+1) break;
				if(py==ey || board[px][py+1]=='.') py++;
				else px ^= 1;
				c++;
			}
			ll dots=0;
			for (ll x=0;x<2;x++) {
				for (ll y=sy;y<=ey;y++) {
					if(board[x][y]=='.')dots++;
				}
			}
			ll take=dots-c;
			if(take%2==0) return P2;
			else return P1;
		}
		else if (dd==2) {
			ll sy=-1;
			for (ll y=0;y<n;y++) {
				for (ll x=0;x<2;x++) {
					if (board[x][y]=='#' && sy==-1) {
						sy=y;
					}
				}
			}
			ll ey=-1;
			for (ll y=n-1;y>=0;y--) {
				for (ll x=0;x<2;x++) {
					if (board[x][y]=='#' && ey==-1) {
						ey=y;
					}
				}
			}

			ll px,py;
			if(board[0][sy]=='.'&&board[0][sy+1]=='.') {px=0;py=sy;}
			else{px=1;py=sy;}
			ll c=0;
			while(1) {
				if (py==ey+1) break;
				if(py==ey || board[px][py+1]=='.') py++;
				else px ^= 1;
				c++;
			}
			ll dots=0;
			for (ll x=0;x<2;x++) {
				for (ll y=sy;y<=ey;y++) {
					if(board[x][y]=='.')dots++;
				}
			}
			ll take=dots-c;
			take += (sy-2);
			take += (n-ey-1-2);
			ll ctl=0;
			if (sy>=4) ctl++;
			if (n-ey-1>=4) ctl++;
			if (ctl==1) return P1;
			if (ctl==2) return P2;
			if (take%2==0) return P2;
			else return P1;
		}
		else assert(false);
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
		cout << "Testing PathGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454794955;
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
		PathGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#.."
				                 ,"..."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#"
				                 ,"."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"....."
				                 ,"..#.."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".#..."
				                 ,"....."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".....#..#........##......."
				                 ,"..........#..........#...."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"#....#"
				                 ,"..#..."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] ={".....................#...#......#.#..............#...........................#....................#......#.................#.................#...........#..",
												 "....#.........#.....................#.#....#...........#..#........#.............................................#.....#.......#...#...#...#................"} ;
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {".#..........#.....#.....#..............................#.......##..#...#.....###....#....",
				                  ".......#.......#.....#.......#........#........#...........#..............#............#."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"......."
				                 ,"....#.."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 9:
			{
				string board[] = {"....."
				                 ,"..#.."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 10:
			{
				string board[] = {"....."
				                 ,"....#"};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
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
