#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 308
#define MAXM 308
ll f[MAXN][MAXN];
ll g[MAXM];

inline vector<ll> load(vector<string> L) {
	string s = "";
	for (ll i=0; i<L.size();++i) s+=L[i];
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
class WolfInZooDivOne {
	public:
	int count(int N, vector <string> L, vector <string> R) {
		vector<ll> a = load(L);
		vector<ll> b = load(R);
		ll M = a.size();
		for (ll i = 0; i < M; i++) {
			a[i]++;b[i]++;
		}
		N++;
		g[0] = 0;
		for (ll x = 1; x < N; x++) {
			g[x] = x-1;
		}
		for (ll i = 0; i < M; i++) {
			ll ai = a[i]; ll bi = b[i];
			for (ll j = ai; j <= bi; j++) {
				g[j] = min(g[j], ai-1);
			}
		}
		for (ll x = 0; x < N; x++) {
			for (ll y = 0; y < N; y++) {
				f[x][y] = 0;
			}
		}
		f[0][0] = 1;
		for (ll x = 1; x < N; x++) {
			f[x][0] = 1;
		}
		for (ll x = 1; x < N; x++) {
			for (ll y = 1; y < x; y++) {
				ll ans = 0;
				ll zlim = g[x];
				for (ll z = 0; z <= zlim; z++) {
					ans = (ans + f[y][z])%MOD;
				}
				f[x][y] = ans%MOD;
			}
		}
		ll final = f[0][0];
		for (ll x = 1; x < N; x++) {
			for (ll y = 0; y < x; y++) {
				final = (f[x][y] + final)%MOD;
			}
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
		cout << "Testing WolfInZooDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453267925;
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
		WolfInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				string L[] = {"0"};
				string R[] = {"4"};
				_expected = 16;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 5;
				string L[] = {"0 1"};
				string R[] = {"2 4"};
				_expected = 21;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 10;
				string L[] = {"0 4 2 7"};
				string R[] = {"3 9 5 9"};
				_expected = 225;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 100;
				string L[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
				string R[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
				_expected = 6419882;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
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
