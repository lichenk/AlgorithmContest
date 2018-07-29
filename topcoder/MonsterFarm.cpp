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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
bool sn[55];
vector<ll> v[55];
bool dfs(ll x, ll init) {
	if (x==init&&sn[x]) return true;
	if (sn[x]) return false;
	sn[x]=true;
	if (v[x].size()==1) for (auto &w:v[x]) {
		if(dfs(w,init)) return true;
	}
	return false;
}
bool cyc[55];
bool is[2][55];
ll f[2][55];
class MonsterFarm {
	public:
	int numMonsters(vector <string> transforms) {
		ll n=transforms.size();
		for (ll x=0;x<n;x++) {
			v[x]=load(transforms[x]);
		}		
		for (auto &w:v) {
			for (auto &q:w) q--;
		}
		for (ll x=0;x<n;x++) cyc[x]=false;
		for (ll x=0;x<n;x++) {
			for (ll i=0;i<n;i++) sn[i]=0;
			if (dfs(x,x)) cyc[x]=true;
		}
		for (ll x=0;x<n;x++) is[0][x]=false;
		is[0][0]=true;
		ll lim=n+5;
		for (ll k=0;k<lim;k++) {
			ll cur=k&1,nxt=cur^1;
			for (ll x=0;x<n;x++) is[nxt][x]=false;
			for (ll x=0;x<n;x++) {
				if (is[cur][x]) {
					for (auto &w:v[x]) is[nxt][w]=true;
				}
			}
		}
		{
			ll nxt=(lim)&1;
			for (ll x=0;x<n;x++) {
				if (is[nxt][x]&&!cyc[x]) return -1;
			}
		}
		for (ll x=0;x<n;x++) f[0][x]=0;
		f[0][0]=1;
		for (ll k=0;k<lim;k++) {
			ll cur=k&1,nxt=cur^1;
			for (ll x=0;x<n;x++) f[nxt][x]=0;
			for (ll x=0;x<n;x++) {
				for (auto &w:v[x]) {
					f[nxt][w]+=f[cur][x];
					f[nxt][w]%=MOD;
				}
			}
		}
		ll ans=0;
		{
			ll nxt=(lim)&1;
			for (ll x=0;x<n;x++) {
				ans+=f[nxt][x];
				ans%=MOD;
			}
		}
		return ans%=MOD;
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
		cout << "Testing MonsterFarm (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472013562;
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
		MonsterFarm _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string transforms[] = {"1"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 1:
			{
				string transforms[] = {"1 1"};
				_expected = -1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 2:
			{
				string transforms[] = {"2", "3", "1"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 3:
			{
				string transforms[] = {"1", "3 4", "2", "2"};
				_expected = 1;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 4:
			{
				string transforms[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"};
				_expected = 24;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 5:
			{
				string transforms[] = {"2 3","5 7","2 4","5","6","4","7"};
				_expected = 5;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			case 6:
			{
				string transforms[] = {"37 11", "2", "45 17", "47 48", "5", "6", "30 22", "8", "3 23", "8 2", "27 32", "34 42", "15 49", "14", "15", "46", "17", "41 19", "16 20", "38 43", "21", "22", "21 28", "24", "39 26", "5 35", "36 29", "28", "12 7", "30", "31", "50 9", "33", "34", "35", "10 44", "25 18", "38", "31 24", "40", "33 40", "42", "43", "6 14", "45", "46", "47", "48", "49", "4 13"};
				_expected = 25;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}
			/*case 7:
			{
				string transforms[] = ;
				_expected = ;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string transforms[] = ;
				_expected = ;
				_received = _obj.numMonsters(vector <string>(transforms, transforms+sizeof(transforms)/sizeof(string))); break;
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
