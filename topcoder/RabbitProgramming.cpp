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
const int mn=52;
ll C[mn][mn];
void init() {
	const ll n=mn-1,k=mn-1;
  for (ll i=0;i<=n;i++) {
  	for (ll j=0;j<=min(i,k);j++) {
  		if (j==0||j==i) C[i][j]=1;
  		else C[i][j]=C[i-1][j-1]+C[i-1][j];
  	}
  }
}
ll binom(ll n, ll k) {
	if (n<0||k<0) return 0;
	return C[n][k];
}
#define fst first
#define snd second
vector<pll> vbase;
vector<pll> vhi;
class RabbitProgramming {
	public:
	long long getTeams(vector <int> points, vector <string> standings, int qualified, int selected) {
		init();
		int np=points.size();
		int nr=standings.size();
		assert(np==standings[0].length());
		for (int r=0;r<nr;r++) {
			ll sump=0;
			ll sume=0;
			for (int p=0;p<np;p++) {
				if (standings[r][p]=='N') continue;
				if (points[p]>0) {
					sump+=points[p];
				}
				else sume-=points[p];
			}
			vbase.PB(MP(-sump,r));
			vhi.PB(MP(-(sump+sume),r));
		}
		ll final=0;
		bitset<mn> basebetter;
		for (auto &whi:vhi) {
			basebetter.reset();
			for (auto &wb:vbase) {
				if (wb<whi) basebetter[wb.snd]=1;
			}
			basebetter[whi.snd]=1;
			int promote_choice=0;
			for (auto &owhi:vhi) {
				if (basebetter[owhi.snd]) continue;
				if (owhi<whi) promote_choice++;
			}
			int basebettercnt=basebetter.count()-1;
			ll now=0;
			int otherlim=qualified-basebetter.count();
			for (int other=0;other<=otherlim;other++) {
				ll toadd=binom(basebettercnt,selected-1-other)*binom(promote_choice,other);
				now+=toadd;
			}
			//printf("whi:(%lld,%lld) basebettercnt:%d promote_choice:%d now:%lld\n",
			//	whi.fst,whi.snd,basebettercnt,promote_choice,now);
			final+=now;
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
		cout << "Testing RabbitProgramming (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495517697;
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
		RabbitProgramming _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = { 1, -10 };
				string standings[] = { "NY", 
				                       "YN", 
				                       "YN",
				                       "YN" };
				int qualified = 3;
				int selected = 2;
				_expected = 5LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
			}
			case 1:
			{
				int points[] = { -250, -500, -1000 };
				string standings[] = { "YYY", 
				                       "YNY", 
				                       "YYN", 
				                       "YYN", 
				                       "YNN" };
				int qualified = 4;
				int selected = 2;
				_expected = 10LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
			}
			case 2:
			{
				int points[] = { 5, -12, 5, -15, 10, -20, 3, -25, 7, -32, 21, -45 };
				string standings[] = { "YYYYYYYYYNYY", 
				                       "YYYNYYYYYNNN", 
				                       "YYYNYNYYNNYN", 
				                       "YYYYYNYYYYNN", 
				                       "YYNNYNYNYYNN", 
				                       "YYYNNNYYNNNN", 
				                       "YYNNNNYYNNNN", 
				                       "NNYNYYYNYNNN", 
				                       "NNNNNNYYYNNN", 
				                       "YYYNNNYYYNNN" };
				int qualified = 4;
				int selected = 3;
				_expected = 99LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
			}
			/*case 3:
			{
				int points[] = ;
				string standings[] = ;
				int qualified = ;
				int selected = ;
				_expected = LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
			}*/
			/*case 4:
			{
				int points[] = ;
				string standings[] = ;
				int qualified = ;
				int selected = ;
				_expected = LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
			}*/
			/*case 5:
			{
				int points[] = ;
				string standings[] = ;
				int qualified = ;
				int selected = ;
				_expected = LL;
				_received = _obj.getTeams(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <string>(standings, standings+sizeof(standings)/sizeof(string)), qualified, selected); break;
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
