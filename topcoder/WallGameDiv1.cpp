#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll INF = 0x3fffffff;
const ll UNDEF = -1;
const ll MAXN = 54;
ll cost[MAXN],rawcost[MAXN];
ll f[MAXN][MAXN][MAXN], g[MAXN][MAXN][MAXN], h[MAXN], q[MAXN];
ll n;

inline ll getcost(ll x, ll y) {
	if (x <= y) {
		return cost[y] - cost[x-1];
	}
	else return 0;
}

ll eel(ll x, ll y, ll k);
ll rabbit(ll x, ll y, ll k) {
	if (f[x][y][k] != UNDEF) return f[x][y][k];
	ll ans = min(eel(x,y,x-1) + getcost(x,k) , eel(x,y,y) + getcost(k,y-1));
	f[x][y][k] = ans;
	//printf("rabbit:%d %d %d: %d\n",x,y,k,ans);
	return ans;
}
ll eel(ll x, ll y, ll k) {
	if (g[x][y][k] != UNDEF) return g[x][y][k];
	ll nx = min(x,k);
	ll ny = max(y,k+1);
	ll ans = h[k]+rawcost[k];
	if (!(nx==1 && ny==n+1)) {
		ans = max(rabbit(nx,ny,k), ans);
	}
	g[x][y][k] = ans;
	//printf("eel:%d %d %d: %d\n",x,y,k,ans);
	return ans;
}

class WallGameDiv1 {
	public:
	int play(vector <string> costs) {
		ll m=costs.size();
		n = costs[0].length();
		for (ll i=1;i<=n;i++) {
			h[i] = costs[m-1][i-1] - '0';
		}
		for (ll r = m-2; r >= 0; r--) {
			for (ll i=1;i<=n;i++) {
				cost[i] = costs[r][i-1] - '0';
				rawcost[i] = costs[r][i-1] - '0';
			}
			cost[0] = 0;
			for (ll i=1;i<=n;i++) {
				cost[i] += cost[i-1];
			}
			for (ll x=0;x<=n+2;x++) {
				for (ll y=0;y<=n+2;y++) {
					for (ll k=0;k<=n+2;k++) {
						f[x][y][k] = -INF;
						g[x][y][k] = INF;
					}
				}
			}
			for (ll x=1;x<=n;x++) {
				for (ll y=x;y<=n+1;y++) {
					for (ll k=1;k<=n;k++) {
						f[x][y][k] = UNDEF;
						g[x][y][k] = UNDEF;
					}
				}
			}
			for (ll k=1;k<=n;k++) {
				q[k] = eel(k,k,k);
			}
			for (ll k=1;k<=n;k++) //printf("qk %d: %d %d\n",k,q[k],eel(k,k,k));
			for (ll x=1;x<=n;x++) {
				for (ll y=x;y<=n+1;y++) {
					for (ll k=1;k<=n;k++) {
						//printf("r:%d. %d %d %d: %d %d\n",r,x,y,k,f[x][y][k],g[x][y][k]);
					}
				}
			}
			for (ll k=1;k<=n;k++) {
				h[k] = q[k];
			}
		}
		ll final = INF;
		for (ll k=1;k<=n;k++) {
			final = min(h[k],final);
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
		cout << "Testing WallGameDiv1 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454735236;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WallGameDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string costs[] = {"12"
				                 ,"34"};
				_expected = 6;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 1:
			{
				string costs[] = {"99999"
				                 ,"99999"
				                 ,"99999"};
				_expected = 99;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 2:
			{
				string costs[] = {"11111"
				                 ,"90005"};
				_expected = 10;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 3:
			{
				string costs[] = {"4417231387449337370319219832088987579792"
				                 ,"3117295688208899006196193430472892512797"
				                 ,"0835796222361526836944954410684516919758"
				                 ,"1988200069973565052900745230547016216225"
				                 ,"8080511471118865780390486996601082102418"
				                 ,"4229084185957675819725844582167613108400"
				                 ,"9068653877952162764545674979144308771754"
				                 ,"8551565425951612499712254182109991511690"
				                 ,"7090525592007482152807163656647658543093"
				                 ,"9198968742256995592729889137556032960142"
				                 ,"2071864379877766468141740053503050313101"
				                 ,"1055375249261868472993219156394129253481"
				                 ,"2461178270502857106406495509025426298874"
				                 ,"8216781259733537757203421037984512664825"
				                 ,"4693452554407216935375049784445568498482"
				                 ,"2709693439640250842244170297203200674391"
				                 ,"5122217695676372684217182241705137947908"
				                 ,"6668814191410691246849638388008228444294"
				                 ,"4952122070212780440963814752538149378639"
				                 ,"9827737761436134120332969866554332504400"
				                 ,"3412406588339828249986707470540386748886"
				                 ,"7521506848088506994554600408372456405830"
				                 ,"1916926179183007872881163173153907665999"
				                 ,"6636166791472761992310264951474925339024"
				                 ,"6679667717747231380196787943691121008076"
				                 ,"3218993234115685151069259138068533004433"
				                 ,"4920152552986426962081492913852060211795"
				                 ,"0365186235986445521382132973036266396894"
				                 ,"3205351414936828189305188614651974318855"
				                 ,"3144278971529524658788277656125598825426"
				                 ,"5525287537572356662391582052968411726245"
				                 ,"2130137226726919525622574701068062252930"
				                 ,"2369996694245544770519574837226971226841"
				                 ,"6806769058165410189286521891570936341547"
				                 ,"0448109211631660241710734664066810078242"
				                 ,"4622919135804954122810530631429501069659"
				                 ,"0235247446548732490429856705369583140671"
				                 ,"2193399741215975228987754171460722199304"
				                 ,"1203037020703833716225328076959743850915"
				                 ,"5419885193880826109484912489603262199432"};
				_expected = 7366;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 4:
			{
				string costs[] = {"284",
													"417",
													"729",
				                 };
				_expected = 33;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 5:
			{
				string costs[] = {"4872","3918","4027","5102"};
				_expected = 58;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 6:
			{
				string costs[] = {"487",
												  "391",
												  "402"};
				_expected = 36;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			case 7:
			{
				string costs[] = {"391",
												  "402"};
				_expected = 15;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
			}
			/*case 6:
			{
				string costs[] = {"487",
												  "15,26,17"};
				_expected = 36;
				_received = _obj.play(vector <string>(costs, costs+sizeof(costs)/sizeof(string))); break;
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
