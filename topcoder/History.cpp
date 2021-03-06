#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<29ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
bool intersect(ll l1, ll r1, ll l2, ll r2) {
	return !(r1<l2||r2<l1);
}
const ll MAXN=52;
vector<ll> dyn[MAXN];
ll gl[MAXN][MAXN],gr[MAXN][MAXN];
class History {
	public:
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
		ll dsz=dynasties.size();
		for (ll i=0;i<dsz;i++) {
			dyn[i]=load(dynasties[i]);
		}
		for (ll x=0;x<dsz;x++) {
			for (ll y=0;y<dsz;y++) {
				gr[x][y]=INF; gl[x][y]=INF;
			}
		}
		{
			string bat="";
			for (auto &w:battles) bat+=w;
			ll blen=bat.length();
			for (ll i=0;i<blen;i+=6) {
				ll x=bat[i]-'A';
				ll ix=bat[i+1]-'0';
				ll y=bat[i+3]-'A';
				ll iy=bat[i+4]-'0';
				ll xl=dyn[x][ix], xr=dyn[x][ix+1]-1;
				ll yl=dyn[y][iy], yr=dyn[y][iy+1]-1;
				ll maxr=xr-yl, maxl=yr-xl;
				//printf("x:%d y:%d maxr:%d maxl:%d\n",x,y,maxr,maxl);
				chkmin(gr[x][y],maxr);
				chkmin(gl[x][y],maxl);
				gr[y][x]=gl[x][y];
				gl[y][x]=gr[x][y];
			}
		}
		for (ll k=0;k<dsz;k++) {
			for (ll x=0;x<dsz;x++) {
				for (ll y=0;y<dsz;y++) {
					chkmin(gl[x][y],gl[x][k]+gl[k][y]);
					chkmin(gr[x][y],gr[x][k]+gr[k][y]);
				}
			}
		}
		ll qsz=queries.size();
		string ans="";
		for (ll i=0;i<qsz;i++) {
			ll x=queries[i][0]-'A';
			ll ix=queries[i][1]-'0';
			ll y=queries[i][3]-'A';
			ll iy=queries[i][4]-'0';
			ll xl=dyn[x][ix], xr=dyn[x][ix+1]-1;
			ll yl=dyn[y][iy], yr=dyn[y][iy+1]-1;
			ll maxr=xr-yl, maxl=yr-xl;
			bool good=intersect(-maxl,maxr,-gl[x][y],gr[x][y]);
			if (good) ans+="Y";
			else ans+="N";
		}
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
		cout << "Testing History (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460918770;
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
		History _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string dynasties[] = {"1 2 4",
				                      "1 2 3"};
				string battles[] = {"A1-B0"};
				string queries[] = {"A0-B0",
				                    "A0-B1",
				                    "A1-B0",
				                    "A1-B1"};
				_expected = "NNYY";
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}
			case 1:
			{
				string dynasties[] = {"1000 2000 3000 10000",
				                      "600 650 2000",
				                      "1 1001 20001"};
				string battles[] = {"B1-C0 A0-B0 A2-C1 B1-C1"};
				string queries[] = {"A0-B1",
				                    "A1-B1",
				                    "A2-B1",
				                    "C0-A0",
				                    "B0-A2",
				                    "C1-B0"};
				_expected = "YYYYNN";
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}
			case 2:
			{
				string dynasties[] = {"1 4 5",
				                      "10 13 17"};
				string battles[] = {"A0-B0 A0-B0 B0-A0"};
				string queries[] = {"A1-B0",
				                    "A0-B1",
				                    "A1-B1"};
				_expected = "YYY";
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}
			case 3:
			{
				string dynasties[] = {"1 5 6",
				                      "1 2 5"};
				string battles[] = {"A0",
				                    "-B0 A",
				                    "1-B1"};
				string queries[] = {"A0-B0",
				                    "A1-B0",
				                    "A0-B1",
				                    "A1-B1"};
				_expected = "YNYY";
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}
			case 4:
			{
				string dynasties[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"};
				string battles[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"};
				string queries[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"};
				_expected = "YNYNNYNNNY";
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}
			/*case 5:
			{
				string dynasties[] = ;
				string battles[] = ;
				string queries[] = ;
				_expected = ;
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string dynasties[] = ;
				string battles[] = ;
				string queries[] = ;
				_expected = ;
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string dynasties[] = ;
				string battles[] = ;
				string queries[] = ;
				_expected = ;
				_received = _obj.verifyClaims(vector <string>(dynasties, dynasties+sizeof(dynasties)/sizeof(string)), vector <string>(battles, battles+sizeof(battles)/sizeof(string)), vector <string>(queries, queries+sizeof(queries)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
