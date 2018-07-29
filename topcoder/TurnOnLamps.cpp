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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=60;
const ll MAXT=60;
vector<ll> g[MAXN];
ll init[MAXN][MAXN], impt[MAXN][MAXN];
ll f[MAXN][MAXT];
ll h[2][MAXT*2];
void dfs(ll x, ll p) {
	for (auto &y: g[x]) {
		if (y==p) continue;
		dfs(y,x);
	}
	ll idx=0;
	for (ll t=0;t<MAXT;t++) h[idx][t]=INF;
	h[idx][0]=0;
	for (auto &y: g[x]) {
		if (y==p) continue;
		idx^=1;
		for (ll t=0;t<MAXT;t++) h[idx][t]=INF;
		ll mod=init[x][y]^1;
		bool constrain = impt[x][y]==1;
		for (ll t=0;t<MAXT;t++) {
			for (ll k=0;k<MAXT;k++) {
				if (constrain&&(k%2!=mod)) continue;
				ll d=0;
				for (ll s=t+k;s>=t-k;s-=2) {
					if (s<0) break;
					chkmin(h[idx][s], h[idx^1][t]+f[y][k]+d);
					d++;
				}
			}
		}
	}
	for (ll t=0;t<MAXT;t++) {
		f[x][t]=h[idx][t];
	}
	// Terminate
	for (ll t=0;t<MAXT;t++) {
		for (ll s=t+1;s<MAXT;s++) {
			chkmin(f[x][t], f[x][s]+(s-t));
		}
	}
	// Start
	for (ll t=0;t<MAXT;t++) {
		for (ll s=t+1;s<MAXT;s++) {
			chkmin(f[x][s], f[x][t]);
		}
	}
}

class TurnOnLamps {
	public:
	int minimize(vector <int> roads, string initState, string isImportant) {
		ll n=roads.size();
		for (ll x=0;x<=n;x++) {
			for (ll y=0;y<=n;y++) {
				init[x][y]=UNDEF;
				impt[x][y]=UNDEF;
			}
		}
		for (ll i=0;i<n;i++) {
			ll x=roads[i],y=i+1;
			g[x].PB(y); g[y].PB(x);
			init[x][y]=(initState[i]=='1')?1:0;
			impt[x][y]=(isImportant[i]=='1')?1:0;
		}
		dfs(0,-1);
		return f[0][0];
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
		cout << "Testing TurnOnLamps (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457329404;
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
		TurnOnLamps _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int roads[] = {0,0,1,1};
				string initState = "0001";
				string isImportant = "0111";
				_expected = 1;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 1:
			{
				int roads[] = {0,0,1,1};
				string initState = "0000";
				string isImportant = "0111";
				_expected = 2;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 2:
			{
				int roads[] = {0,0,1,1,4,4};
				string initState = "000100";
				string isImportant = "111111";
				_expected = 2;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 3:
			{
				int roads[] = {0,0,1,1,4,4};
				string initState = "100100";
				string isImportant = "011101";
				_expected = 2;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 4:
			{
				int roads[] = {0,0,2,2,3,1,6,3,1};
				string initState = "010001110";
				string isImportant = "000110100";
				_expected = 1;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 5:
			{
				int roads[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
				string initState = "0000000000010000000000000010000010100000000000000";
				string isImportant = "1010111111111011011111000110111111111111111110111";
				_expected = 14;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 6:
			{
				int roads[] = {0};
				string initState = "0";
				string isImportant = "1";
				_expected = 1;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			case 7:
			{
				int roads[] = {0,0};
				string initState = "00";
				string isImportant = "11";
				_expected = 1;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
			}
			/*case 8:
			{
				int roads[] = ;
				string initState = ;
				string isImportant = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(roads, roads+sizeof(roads)/sizeof(int)), initState, isImportant); break;
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
