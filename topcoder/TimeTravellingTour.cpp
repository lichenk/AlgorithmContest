#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<40LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll g[50][50];
ll n;
void init(vector<string> roads) {
	string ss; for (auto &w:roads) ss+=w;
	stringstream s(ss);
	ll a,b,cost; char c;
	for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) g[x][y]=(x==y)?0LL:INF;
	while(s>>a) {
		s>>c>>b>>c>>cost;
		chkmin(g[a][b],cost);
		chkmin(g[b][a],cost);
	}
	for (ll k=0;k<n;k++) for (ll i=0;i<n;i++) for(ll j=0;j<n;j++) chkmin(g[i][j],g[i][k]+g[k][j]);
}
vector<int> gc;
ll f[51][51][51];
class TimeTravellingTour {
	public:
	long long determineCost(int N, vector <int> cities, vector <string> roads) {
		n=N;
		gc=cities;
		init(roads);
		ll cs=cities.size();
		for (ll l=0;l<=cs;l++) for (ll x=0;x<n;x++) f[l][l][x]=0;
		for (ll d=0;d<=cs;d++) {
			for (ll l=0;l<cs;l++) {
				for (ll r=l+1;r<=min(l+d,cs);r++) {
					for (ll x=0;x<n;x++) {
						ll ans=INF;
						if (x==gc[l]) {
							chkmin(ans,f[l+1][r][x]);
						}
						for (ll k=l+1;k<r;k++) {
							ll y=gc[k];
							chkmin(ans, f[l][k][x]+f[k][r][x]);
						}
						f[l][r][x]=ans;
					}
					for (ll x=0;x<n;x++) {
						for (ll y=0;y<n;y++) {
							chkmin(f[l][r][x],f[l][r][y]+g[x][y]);
						}
					}
				}
			}
		}
		ll final=f[0][cs][0];
		if (final>=INF) return -1;
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
		cout << "Testing TimeTravellingTour (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484893410;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TimeTravellingTour _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int cities[] = {2,3,2,4};
				string roads[] = {"0,2,4 0,1,2 2,1,2 1,3,3 4,0,4"};
				_expected = 13LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 3;
				int cities[] = {1,0,1};
				string roads[] = {"0,2,1"," 2",",1,5"};
				_expected = 12LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 3;
				int cities[] = {2};
				string roads[] = {"0,1,2"};
				_expected = -1LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 6;
				int cities[] = {4, 1, 3, 2};
				string roads[] = {"0,1,5 0,2,5 0,5,2 2,3,5 2,4,2 3,4,4 3,5,1"};
				_expected = 19LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 12;
				int cities[] = {6, 1, 0, 2, 5, 6, 7, 5, 8, 0, 10, 6, 0, 2, 7, 2, 8, 1, 6, 3, 0, 1, 9, 2, 7, 6, 1, 11, 2, 4, 1, 6, 4, 1, 7, 6, 5, 1, 0, 2, 1, 10, 5, 0, 9, 0, 3, 5, 11, 5};
				string roads[] = {"3,9,4 1,2,4 1,11,3 1,7,3 7,8,7 3,5,", "3 2,5,1 1,8,7 4,11,1 0,10,8 2,", "4,1 5,11,4 2,3,8 0,7,9", " 1,3,6 8,11,6 5,9,3 1,10,2 ", "3,7,3 1,4,7 3,8,2 6,10,9 2,", "8,8 7,9,3 5,6,6 1,5,", "5 0,11,5 3,4,9 ", "0,6,8 0,5,3 1,9,5 2,9,3 2,6,4", " 4,8,8 6,9,2 0", ",3,2 1,6,6 6,7,3 5,8,6 8,", "10,9 4,10,2 0,4,7 6,", "11,5 10,11,3 4,7,7 2,7,7 9", ",10,2 0,9,6 9,11,1 5,7,", "5 0,1,8 2,11,6 0,8,2 7,", "11,8 0,2,3 2,10,9 4,6,3 4", ",9,2 5,10,6 3,11,2 7,10,7 4,5,", "9 3,10,1 8,9,9 3,6,2 6,8,5"};
				_expected = 100LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 8;
				int cities[] = {6,5,4,7};
				string roads[] = {
					"0,1,100 ",
					"1,2,100 ",
					"2,3,100 ",
					"1,4,1 ",
					"2,5,1 ",
					"3,6,1 ",
					"0,7,1 ",
				};
				_expected = 304LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 6:
			{
				int N = ;
				int cities[] = ;
				string roads[] = ;
				_expected = LL;
				_received = _obj.determineCost(N, vector <int>(cities, cities+sizeof(cities)/sizeof(int)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
