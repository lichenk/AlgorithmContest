#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<29ULL;
const ll UNDEF = -1234;
//template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
//template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
inline void chkmax(ll &a, ll &b) {
	if (b==UNDEF) return;
	if (a==UNDEF) a=b;
	if (a<b) a=b;
	return;
}
inline void chkmin(ll &a, ll &b) {
	if (b==UNDEF) return;
	if (a==UNDEF) a=b;
	if (a>b) a=b;
	return;
}
ll hx[13],hy[13];
const ll EMPTY=0;
const ll COIN=1;
const ll HAT=2;
ll f[1594323*3];
ll p3[14];
class MagicalHats {
	public:
	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
		p3[0]=1;
		for (ll i=1;i<14;i++) {
			p3[i]=p3[i-1]*3;
		}
		ll bxsz=board.size();
		ll bysz=board[0].length();
		ll h=0;
		for (ll i=0;i<bxsz;i++) for (ll j=0;j<bysz;j++) {
			if (board[i][j]=='H') {
				hx[h]=i; hy[h]=j; h++;
				//printf("h: %d. %d %d\n",h,i,j);
			}
		}
		ll csz=coins.size();
		ll zlim=1; for (ll i=0;i<=h;i++) zlim*=3;
		for (ll zz=0;zz<zlim;zz++) {
			bool ok=true;
			ll coins=0;
			ll sx=0,sy=0;
			ll tmpz=zz;
			for (ll i=0;i<h;i++) {
				ll r=tmpz%3;
				tmpz/=3;
				if (r==HAT) {ok=false; break;}
				else if (r==COIN) coins++;
				else {
					sx^=1<<hx[i];
					sy^=1<<hy[i];
				}
			}
			ll ans=UNDEF;
			if (ok&&coins==csz&&sx==0&&sy==0) ans=0;
			f[zz]=ans;
			//if (zz==40) printf("A zz:%d f:%d.  %d %d %d %d\n",zz,f[zz],ok,coins,sx,sy);
		}
		for (ll k=0;k<h;k++) {
			for (ll zz=0;zz<zlim;zz++) {
				ll tmpz=zz;
				if (f[zz]==0) {
					for (ll i=0;i<h;i++) {
						ll r=tmpz%3;
						tmpz/=3;
						f[zz+p3[i]*(HAT-r)]=0;
					}
				}
			}
		}
		for (ll zz=0;zz<zlim;zz++) {
			ll tmpz=zz;
			ll revealed=0;
			for (ll i=0;i<h;i++) {
				ll r=tmpz%3;
				if (r==EMPTY||r==COIN) revealed++;
				tmpz/=3;
			}
			if (revealed!=numGuesses) f[zz]=UNDEF;
			//printf("C zz:%d f:%d\n",zz,f[zz]);
		}
		for (ll zz=0;zz<zlim;zz++) {
			ll tmpz=zz;
			ll ans=UNDEF;
			for (ll i=0;i<h;i++) {
				ll r=tmpz%3;
				tmpz/=3;
				if (r==HAT) {
					ll cand=UNDEF;
					for (ll choice=EMPTY;choice<=COIN;choice++) {
						ll delta=p3[i]*(choice-HAT);
						ll nz=zz+delta;
						if (f[nz]!=UNDEF) {
							ll newcand=f[nz]+choice;
							chkmin(cand,newcand);
							//printf("zz:%d nz:%d f[nz]:%d newcand:%d\n",zz,nz,f[nz],newcand);
						}
					}
					chkmax(ans,cand);
				}
			}
			//printf("zz:%d f[zz]:%d ans:%d\n",zz,f[zz],ans);
			chkmax(f[zz],ans);
		}
		ll got=f[zlim-1];
		if (got==UNDEF) return -1;
		ll final=0;
		sort(coins.begin(),coins.end());
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
			case 8:
			{
				string board[] = {"HH.", ".HH"};
				int coins[] = {3, 3, 3, 3};
				int numGuesses = 2;
				_expected = 6;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
			case 9:
			{
				string board[] = {"HHHH", "H.HH", "HHH.", ".HHH", "...."};
				int coins[] = {6920, 5348, 2014, 899, 1848};
				int numGuesses = 13;
				_expected = 17029;
				_received = _obj.findMaximumReward(vector <string>(board, board+sizeof(board)/sizeof(string)), vector <int>(coins, coins+sizeof(coins)/sizeof(int)), numGuesses); break;
			}
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
