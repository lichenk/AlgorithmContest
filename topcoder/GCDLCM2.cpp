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

#define MAXP 3165
bool a[MAXP+1];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) a[i] = true;
	a[0] = false; a[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(a[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				a[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if (a[i]) pv.PB(i);
	}
}

class GCDLCM2 {
	public:
	int getMaximalSum(vector <int> start, vector <int> d, vector <int> cnt) {
		sieve();
		ll L=start.size();
		vector<ll> v;
		for (ll i=0;i<L;i++) {
			for (ll j=0;j<cnt[i];j++) {
				v.PB(start[i]+j*d[i]);
			}
		}
		sort(v.begin(),v.end(), greater<ll>());
		ll n=v.size();
		map<ll,map<ll,stack<ll>, greater<ll> >, greater<ll> > h;
		for (ll k=0;k<n;k++) {
			ll x=v[k];
			for (ll pi=0;pi<plim;pi++) {
				ll p=pv[pi];
				if (x%p==0) {
					ll ppow=0;
					while(x%p==0) {
						ppow++;
						x/=p;
					}
					h[pi][ppow].push(k);
				}
				if (x==1) break;
			}
		}
		ll final=0;
		while(1) {
			ll gcdsum=0;
			ll lcm=1;
			for (auto &g:h) {
				ll p=pv[g.first];
				for (auto &w:g.second) {
					ll ppow=w.first;
					while(!w.second.empty()) {
						ll t=w.second.top();
						w.second.pop();
						if (good[t]) {
							lcm = (lcm*modexp(p,ppow));
							break;
						}
					}
				}
			}

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
		cout << "Testing GCDLCM2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456767405;
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
		GCDLCM2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start[] = {1};
				int d[] = {1};
				int cnt[] = {3};
				_expected = 8;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 1:
			{
				int start[] = {3};
				int d[] = {0};
				int cnt[] = {5};
				_expected = 15;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 2:
			{
				int start[] = {2};
				int d[] = {2};
				int cnt[] = {4};
				_expected = 32;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 3:
			{
				int start[] = {1, 2};
				int d[] = {2, 3};
				int cnt[] = {2, 2};
				_expected = 33;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 4:
			{
				int start[] = {5 ,6};
				int d[] = {23, 45};
				int cnt[] = {50000, 50000};
				_expected = 804225394;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 5:
			{
				int start[] = {2,4,5};
				int d[] = {0,0,0};
				int cnt[] = {1,1,1};
				_expected = 23;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 6:
			{
				int start[] = {6,4,5};
				int d[] = {0,0,0};
				int cnt[] = {1,1,1};
				_expected = 63;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 7:
			{
				int start[] = {2,3,2,3};
				int d[] = {0,0,0};
				int cnt[] = {1,1,1,1};
				_expected = 14;
				_received = _obj.getMaximalSum(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
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
