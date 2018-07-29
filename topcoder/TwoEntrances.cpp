#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 3000
#define MAXFACT 3001

vector<ll> g[MAXN];
vector<ll> path;
ll fact[MAXFACT], invfact[MAXFACT];

ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	return ans;
}

void initfact(ll n) {
	fact[0] = 1;
	for (ll x = 1; x < n; x++) {
		fact[x] = (fact[x-1] * x) %MOD;
	}
	for (ll x = 0; x < n; x++) {
		invfact[x] = modexp(fact[x], MOD-2);
	}
}

bool getpath(ll x, ll p, ll t) {
	ll ans = 0;
	if (x==t) {
		path.PB(x);
		return true;
	}
	for (auto& y: g[x]) {
		if (y == p) continue;
		if (getpath(y,x,t)) {
			path.PB(x);
			return true;
		}
	}
	return false;
}

inline ll binom(ll n, ll k) {
	ll ans = (fact[n] * invfact[k])% MOD;
	ans = (ans * invfact[n-k])%MOD;
	return ans;
}

pair<ll,ll> f(ll x, ll p, ll t) {
	ll n = 0;
	ll ans = 1;
	for (auto& y: g[x]) {
		if (y==p || y == t) continue;
		pair<ll,ll> a = f(y, x, t);
		ll sy = a.first; ll fy = a.second;
		n += sy;
		ll cand = (fy * binom(n,sy))%MOD;
		ans = (ans * cand)%MOD;
	}
	return MP(n+1, ans);
}

class TwoEntrances {
	public:
	int count(vector <int> a, vector <int> b, int s1, int s2) {
		initfact(MAXFACT);
		ll n = a.size()+1;
		for (ll i = 0; i < n-1; i++) {
			ll v = a[i]; ll w = b[i];
			g[v].PB(w); g[w].PB(v);
		}
		getpath(s2, -1, s1);
		ll pathsz = path.size();
		assert(path[0] == s1);
		assert(path[pathsz-1] == s2);
		// Count the unmodified one first!!
		ll final = (f(s1,-1,-1).second + f(s2,-1,-1).second)%MOD;
		//printf("final:%lld + %lld = %lld\n",f(s1,-1,-1).second, f(s2,-1,-1).second,final);
		/*for (ll i = 0; i < pathsz; i++) {
			printf("i:%lld path:%lld\n",i,path[i]);
		}*/
		for (ll i = 0; i < pathsz-1; i++) {
			pair<ll,ll> p1 = f(s1,-1,path[i+1]);
			pair<ll,ll> p2 = f(s2,-1,path[i]);
			//printf("dbg: %lld %lld\n",s1,path[i+1]);
			ll cand = (p1.second * p2.second)%MOD;
			cand = (cand * binom(n, p1.first))%MOD;
			//printf("cand: %lld * %lld * %lld = %lld\n",p1.second,p2.second,binom(n, p1.first),cand);
			final = (final + cand) % MOD;
		}
		final = (final * modexp(2,MOD-2))%MOD;
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
		cout << "Testing TwoEntrances (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452397152;
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
		TwoEntrances _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 3};
				int s1 = 0;
				int s2 = 1;
				_expected = 4;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 1:
			{
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 3};
				int s1 = 0;
				int s2 = 2;
				_expected = 9;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 2:
			{
				int a[] = {0, 1, 1, 3, 3, 3, 6, 7, 6};
				int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				int s1 = 1;
				int s2 = 9;
				_expected = 16000;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 3:
			{
				int a[] = {0, 0, 1, 2, 3, 1, 2, 0, 6, 5, 10, 10};
				int b[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10, 11, 12};
				int s1 = 3;
				int s2 = 6;
				_expected = 310464;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 4:
			{
				int a[] = {0};
				int b[] = {1};
				int s1 = 1;
				int s2 = 0;
				_expected = 2;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 5:
			{
				int a[] = {0,1,2,1};
				int b[] = {1,2,3,4};
				int s1 = 0;
				int s2 = 2;
				_expected = 18;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 6:
			{
				int a[] = {0,0,0,3,3};
				int b[] = {1,2,3,4,5};
				int s1 = 0;
				int s2 = 5;
				_expected = 80;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 7:
			{
				int a[] = {0,0,2,2};
				int b[] = {1,2,3,4};
				int s1 = 0;
				int s2 = 4;
				_expected = 18;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 8:
			{
				int a[] = {0,1,1};
				int b[] = {1,2,3};
				int s1 = 0;
				int s2 = 3;
				_expected = 6;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
			}
			case 9:
			{
				int a[] = {0,0,2};
				int b[] = {1,2,3};
				int s1 = 0;
				int s2 = 3;
				_expected = 9;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), s1, s2); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
