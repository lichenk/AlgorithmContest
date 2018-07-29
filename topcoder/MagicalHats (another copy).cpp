#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<29ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll hx[13],hy[13];
int gok[1<<13];
int f[14][14][1<<13];
class MagicalHats {
	public:
	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
		ll b=board.size();
		ll h=0;
		for (ll i=0;i<b;i++) for (ll j=0;j<b;j++) {
			if (board[i][j]=='H') {
				hx[h]=i; hy[h]=j; h++;
			}
		}
		ll zlim=1<<h;
		for (ll z=0;z<zlim;z++) gok[z]=0;
		ll isr=0,isc=0;
		for (ll i=0;i<h;i++) {
			isr^=1<<hx[i];
			isc^=1<<hy[i];			
		}
		for (ll z=0;z<zlim;z++) {
			ll sr=isr,sc=isc;
			ll cnt=0;
			for (ll i=0;i<h;i++) {
				if (z&(1<<i)) {
					sr^=1<<hx[i];
					sc^=1<<hy[i];
					cnt++;
				}
			}
			if (sr==0&&sc==0) {
				gok[z]|=1<<cnt;
			}
		}
		for (ll t=0;t<h;t++) {
			for (ll z=0;z<zlim;z++) {
				if (z&(1<<t)) {
					gok[z]|=gok[z^(1<<t)];
				}
			}
		}
		ll csz=coins.size();
		{
			ll k=0;
			for (ll c=0;c<=csz;c++) {
				for (ll z=0;z<zlim;z++) {
					f[k][c][z]=(gok[z]&(1<<c))?0:-INF;
					printf("k:%d c:%d z:%d got f:%d\n",k,c,z,f[k][c][z]);
				}
			}
		}
		for (ll k=1;k<=numGuesses;k++) {
			for (ll c=0;c<=csz;c++) {
				for (ll z=0;z<zlim;z++) {
					ll ans=-INF;
					if (gok[z]&(1<<c)) {
						if (c-1>=0) {
							for (ll i=0;i<h;i++) {
								chkmax(ans,f[k-1][c-1][z^(1<<i)]+1);
							}
						}
						for (ll i=0;i<h;i++) {
							chkmax(ans,f[k-1][c][z^(1<<i)]);
						}
					}
					f[k][c][z]=ans;
					printf("k:%d c:%d z:%d got f:%d\n",k,c,z,f[k][c][z]);
				}
			}
		}
		ll got=f[numGuesses][csz][zlim-1];
		sort(coins.begin(),coins.end());
		ll final=0;
		for (ll i=0;i<got;i++) {
			final+=coins[i];
		}
		return final;
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
		cout << "Testing MagicalHats (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470004552;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MagicalHats _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"H"};
				int coins[] = {1};
				int numGuesses = 1;
				_expected = 1;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 1:
			{
				string board[] = {"HHH",
				                  "H.H",
				                  "HH."};
				int coins[] = {9};
				int numGuesses = 1;
				_expected = 9;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 2:
			{
				string board[] = {"HH",
				                  "HH"};
				int coins[] = {1,2,3,4};
				int numGuesses = 3;
				_expected = 6;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 3:
			{
				string board[] = {"HHH",
				                  "HHH",
				                  "H.H"};
				int coins[] = {13,13,13,13};
				int numGuesses = 2;
				_expected = 13;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 4:
			{
				string board[] = {"HHH",
				                  "HHH",
				                  "H.H"};
				int coins[] = {13,13,13,13};
				int numGuesses = 3;
				_expected = 26;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 5:
			{
				string board[] = {"H.H.",
				                  ".H.H",
				                  "H.H."};
				int coins[] = {17};
				int numGuesses = 6;
				_expected = -1;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 6:
			{
				string board[] = {"HHH",
				                  "H.H",
				                  "HHH",
				                  "H.H",
				                  "HHH"};
				int coins[] = {33,337,1007,2403,5601,6003,9999};
				int numGuesses = 5;
				_expected = 1377;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 7:
			{
				string board[] = {".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".............",
				                  ".....H.H.....",
				                  "......H......",
				                  ".....H.H.....",
				                  ".............",
				                  ".............",
				                  ".............",
				                  "............."};
				int coins[] = {22};
				int numGuesses = 3;
				_expected = 22;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			/*case 8:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				int coins[] = ;
				int numGuesses = ;
				_expected = ;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
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
