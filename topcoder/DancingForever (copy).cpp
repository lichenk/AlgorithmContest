#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define SZ 250
bool seen[SZ], bad[SZ];
ll path[SZ];
vector<ll> g[SZ], h[SZ];
ll f[SZ][SZ], c[SZ][SZ];
ll t;
#define NOPATH 0
#define UNDEF -1
#define MP make_pair
#define INF 999999999999999999LL
pair<ll,ll> dfs(ll x, ll k) {
	seen[x] = true;
	path[k] = x;
	if (x == t) {
		return MP(INF,k);
	}
	for(vector<ll>::iterator it = g[x].begin(); it != g[x].end(); ++it) {
		ll y = *it;
		ll cf = c[x][y] - f[x][y];
		if (!seen[y] && cf > 0) {
			pair<ll,ll> cand = dfs(y, k+1);
			if (cand.first != NOPATH) {
				return MP(min(cf, cand.first), cand.second);
			}
		}
	}
	return MP(NOPATH,UNDEF);
}


class DancingForever {
	public:
	vector <int> getStablePairs(string x) {
		ll n = round(sqrt(x.length()));
		ll BOY = 0; ll GIRL = n;
		ll s = 2*n + 1; t = 2*n + 2;
		ll q = t+1;
		for (ll i = 0; i < q; i++) {
			for (ll j = 0; j < q; j++) {
				f[i][j] = 0; c[i][j] = 0;
			}
			bad[i] = false;
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (x[n*i+j] == 'Y') {
					ll a = BOY+i; ll b = GIRL+j;
					g[a].PB(b);
					//printf("%lld to %lld\n",a,b);
					h[a].PB(b);
					h[b].PB(a);
					c[a][b] = 1;
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			{
				ll a = s; ll b = BOY+i;
				g[a].PB(b);
				//printf("%lld to %lld\n",a,b);
				c[a][b] = 1;
			}
			{
				ll a = GIRL+i; ll b = t;
				g[a].PB(b);
				//printf("%lld to %lld\n",a,b);
				c[a][b] = 1;
			}
		}
		while(1) {
			for (ll i = 0; i < q; i++) {
				for (ll j = 0; j < q; j++) {
					f[i][j] = 0;
				}
				bad[i] = false;
			}
			while(1) {
				for (ll i = 0; i < q; i++) {
					seen[i] = false;
				}
				pair<ll,ll> cap_lim = dfs(s,0);
				ll cap = cap_lim.first;
				if (cap == NOPATH) break;
				ll lim = cap_lim.second;
				for (ll i = 0; i < lim; i++) {
					ll u = path[i];
					ll v = path[i+1];
					f[u][v] = f[u][v] + cap;
					f[v][u] = f[v][u] - cap;
				}
			}
			bool good = true;
			for (ll i = 0; i < n; i++) {
				ll v = GIRL + i;
				if (f[v][t] == 0) {
					if (c[v][t] == 1) good = false;
					c[v][t] = 0;
					for (auto& w: h[v]) {
						c[s][w] = 0;
					}
				}
			}
			if(good) break;
		}
		vector<int> ans;
		vector<ll> help;
		for (ll i = 0; i < n; i++) {
			ll v = BOY + i;
			if (!bad[v]) {
				for (ll j = 0; j < n; j++) {
					ll w = GIRL+j;
					if (f[v][w] == 1) {
						assert(!bad[w]);
						assert((x[n*i+j] == 'Y'));
						ans.PB(i);
						ans.PB(j);
						help.PB(i);
						break;
					}
				}
			}
		}
		set<ll> range;
		for (auto& i: help) {
			for (ll j = 0; j < n; j++) {
				if ((x[n*i+j] == 'Y')) {
					range.insert(j);
				}
			}
		}
		assert(range.size() <= help.size());
		if (ans.size() == 0) {
			ans.PB(-1);
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
		cout << "Testing DancingForever (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449378709;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 850.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DancingForever _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x = "YYNNNYYNNNYYYNNY";
				int __expected[] = {0, 0, 1, 1, 2, 2, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 1:
			{
				string x = "YNNNYYNNYYNNNNYY";
				int __expected[] = {1, 0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 2:
			{
				string x = "YNYYNYYNY";
				int __expected[] = {1, 0, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 3:
			{
				string x = "YYYNNYYYNNNNNYYNNNYYNNNYY";
				int __expected[] = {3, 3, 4, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 4:
			{
				string x = "Y";
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 5:
			{
				string x = "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYNYYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYYNYYYYYYNYYYYYNYYYYYYYYNYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYNYYYYYYYYYYYYYYYYYNYYYYYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYYYYYYYYYYNNYYYYYYYYYYYYNYYYYNYNYYYYNYYYYNYYNYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYNYYNYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYNYYYYYYYYNYYYYYNYYYYYYYYYYNYYYYYYYYYYYYYYYYYNYYYYYNYYYYYNYYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNNNNNYNYNNYNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNNNNYNNNNYNNNNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYNYYYYYYYNYYYYYYYYYYYYYYNYYYYYYYYNYYYYYYNNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYNYYYYYYYYNNNNNNYNNYNNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYNYYYYYYYYYYYYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYYYYNYYYYYNYYYYYYYYYYYYYNYYYYYYYYYYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYNYYYYYYNYYYYYYYYYYYYYNYYYYYYYYNNYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYNYYYYYYYYYYYYYYYYYNYYNYYYYYYYYYNNNNNYNYNNYNNYNNNNYNNNNNYNNNNNNNYNNNNNNNNNNYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYNYYNYYNYYYYYYNYYYYYYYYYYYYYNYNYYYYYYYNYNYYYYYYNYYYNYNYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYY";
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 6:
			{
				string x = "YNNNYNNNYNNNNNNYNYYYYNNNNYYYNNNNNNNY";
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 7:
			{
				string x = "YNYYYYYNYYYYYYYYNNYYYYNNNNNNNNYNNYYNNYNYNNNYYNNYNNNNYYYYNNYNNYYYNNYYYYNNNYYYYNNYNYYYNYNYNYNYNYNYNYYNNYYYYNYYYYYYYYNNYYYYNNYNNNNNYNYYYNNYNYNNYYNNYNNYNNYYYNNYNNNYYYNNYYNYNNNYYYYNNNNYYNNYNYYYNYNYNYNY";
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
