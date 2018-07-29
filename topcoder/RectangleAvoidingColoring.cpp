#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll dprecur[52][2][2];
ll brd[2][52][52];
ll recur(ll y, ll wsame, ll bsame) {
	//printf("y:%lld ws:%lld bs:%lld ans:%lld\n",y,wsame,bsame,-1);
	if (y==-1) return 1;
	if (dprecur[y][wsame][bsame]!=-1) return dprecur[y][wsame][bsame];
	ll ans=0;
	for (ll t0=0;t0<2;t0++) {
		if (!brd[t0][0][y]) continue;
		for (ll t1=0;t1<2;t1++) {
			if (!brd[t1][1][y]) continue;
			ll new_wsame=wsame, new_bsame=bsame;
			if (t0==t1) {
				if (t0==0) new_wsame++;
				else new_bsame++;
			}
			if (new_wsame>1||new_bsame>1) continue;
			ll got=recur(y-1,new_wsame,new_bsame);
			//printf("y:%lld ws:%lld bs:%lld adds:%lld from %lld %lld %lld\n",y,wsame,bsame,got,y-1,new_wsame,new_bsame);
			ans+=got;
		}
	}
	//printf("y:%lld ws:%lld bs:%lld ans:%lld\n",y,wsame,bsame,ans);
	return dprecur[y][wsame][bsame]=ans;
}
ll n,m;
ll brdsig[2][52];
bool hasge2bits(ll x) {
  return (x & (x - 1));
}
ll dfs(ll prev, ll x) {
	ll zlim=(1LL<<m)-1;
	ll ans=0;
	for (ll wz=0;wz<=zlim;wz++) {
		if ((wz&brdsig[0][x])!=wz) continue;
		ll bz=(~wz)&zlim;
		if ((bz&brdsig[1][x])!=bz) continue;
		bool ok=true;
		for (ll i=0;i<x;i++) {
			ll pwz=((prev)>>((i)*m))&zlim;
			if (hasge2bits(pwz&wz)) {ok=false; break;}
			ll pbz=(~pwz)&zlim;
			if (hasge2bits(pbz&bz)) {ok=false; break;}
		}
		if (ok) {
			if (x==n-1) ans++;
			else {
				ll nprev=(prev<<m)|wz;
				ans+=dfs(nprev,x+1);
			}
		}
	}
	//printf("prev:%lld x:%lld ans:%lld\n",prev,x,ans);
	return ans;
}
class RectangleAvoidingColoring {
	public:
	long long count(vector <string> board) {
		n=board.size(),m=board[0].length();
		if (n>m) {
			vector<string> woof;
			woof.resize(m);
			for (ll y=0;y<m;y++) woof[y].resize(n);
			for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) woof[y][x]=board[x][y];
			return count(woof);
		}
		assert(n<=m);
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
			char c=board[x][y];
			if (c=='W') brd[0][x][y]=1;
			else if (c=='B') brd[1][x][y]=1;
			else {
				brd[0][x][y]=1;brd[1][x][y]=1;
			}
		}
		for (ll t=0;t<2;t++) {
			for (ll x=0;x<n;x++) {
				ll sig=0;
				for (ll y=0;y<m;y++) {
					if (brd[t][x][y]) sig|=(1LL<<y);
				}
				brdsig[t][x]=sig;
			}
		}
		if (m>=7||n<=2) {
			if (n==1) {
				ll ans=1;
				for (ll y=0;y<m;y++) if (board[0][y]=='?') ans*=2;
				return ans;
			}
			else if (n==2) {
				memset(dprecur,-1,sizeof dprecur);
				return recur(m-1,0,0);
			}
			else return 0;
		}
		else {
			ll ans=dfs(0,0);
			return ans;
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
		cout << "Testing RectangleAvoidingColoring (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487912142;
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
		RectangleAvoidingColoring _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"??",
				                  "??"};
				_expected = 14LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"B?",
				                  "?B"};
				_expected = 3LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"WW",
				                  "WW"};
				_expected = 0LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"??B??",
				                  "W???W",
				                  "??B??"};
				_expected = 12LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"??",
				                  "W?",
				                  "W?",
				                  "?W",
				                  "W?"};
				_expected = 16LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
