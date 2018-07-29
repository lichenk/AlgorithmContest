#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1<<25;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll b[14],c[14];
ll p[1<<13][2];
ll pop[1<<13][2];
inline ll getq(ll sub, ll uni) {
	ll tmp=sub&uni;
	if (tmp==sub) return 1;
	if (tmp==0) return 0;
	else return -1;
}

class YetAnotherBoardGame {
	public:
	int minimumMoves(vector <string> board) {
		ll xlim=board.size();
		ll ylim=board[0].size();
		for (ll x=0;x<xlim;x++) {
			ll t=0;
			for (ll y=0;y<ylim;y++) {
				t*=2;
				if(board[x][y]=='W') t++;
			}
			c[x]=t;
			//printf("%lld: %lld\n",x,t);
		}
		ll lim=1<<ylim;
		for (ll zz=0;zz<lim;zz++) {
			ll z=zz;
			ll ans0=0;
			for (ll x=0;x<ylim;x++) {
				if ((z>>x)&1) {
					if (x-1>=0) {ans0 ^= (1<<(x-1));}
					if (x+1<ylim)  {ans0 ^= (1<<(x+1));}
				}
			}
			//printf("%lld: %lld %lld\n",zz,ans0,ans1);
			p[zz][0]=ans0;
			p[zz][1]=__builtin_popcountll(zz);
		}
		ll ans=INF;
		for (ll zz=0;zz<lim;zz++) {
			for (ll ss=0;ss<lim;ss++) {
				ll qm = zz;
				for (ll x=0;x<xlim;x++) {
					b[x]=c[x];
				}
				ll cand=0;
				{
					ll x=-1;
					ll tt=ss;
					ll q=getq(tt,qm);
					if (q==-1) continue;
					b[x+1] ^= p[tt][0];
					if(q) b[x+1] ^= tt;
					b[x+2] ^= tt;
					cand+=p[tt][1];
				}
				bool good=true;
				for (ll x=0;x<xlim-1;x++) {
					ll tt=b[x];
					ll q=getq(tt,qm);
					if (q==-1) {good=false; break;}
					b[x+1] ^= p[tt][0];
					if(q) b[x+1] ^= tt;
					b[x+2] ^= tt;
					cand+=p[tt][1];
				}
				if (good&&b[xlim-1]==0) {
					ans=min(ans,cand);
				}
			}
		}
		if (ans>=INF) return -1;
		return ans;
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
		cout << "Testing YetAnotherBoardGame (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456594552;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		YetAnotherBoardGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"BBBBBBBBB",
				                  "BBWBBBBBB",
				                  "BWWWBBBBB",
				                  "BBWBBBWBB",
				                  "BBBBBWBWB",
				                  "BBBBBBWBB"};
				_expected = 2;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"BBW",
				                  "WWW",
				                  "BWW"};
				_expected = 2;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"WBW",
				                  "BBW",
				                  "WBW"};
				_expected = 4;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"BBBB",
				                  "WBWB",
				                  "BBBB",
				                  "BBBB"};
				_expected = -1;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"WWWWWBW",
				                  "WBWBWBW",
				                  "BBWBBWW"};
				_expected = 7;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW",
				                  "WWWWWWWWWW"};
				_expected = 30;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"BBB",
				                  "BBB",
				                  "BBB"};
				_expected = 0;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"BWB",
				                  "WBW",
				                  "BWB"};
				_expected = 1;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"BWB",
				                  "WWW",
				                  "BWB"};
				_expected = 1;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 9:
			{
				string board[] = {"BWB",
				                  "WBB",
				                  "BBB"};
				_expected = 1;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
