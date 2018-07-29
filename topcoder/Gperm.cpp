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
const ll MN=100;
vector<ll> g[MN];
const ll MZ=1LL<<22LL;
ll ff2[MZ];
bool seen[MN];
vector<ll> active;
vector<int> vx,vy;
vector<ll> go;
ll solve() {
	ll n=active.size();
	map<ll,ll> h;
	vector<ll> e;
	for (ll i=0;i<n;i++) {
		//printf("%lld ",active[i]);
		h[active[i]]=i;
	}
	//printf("\n");
	for (ll i=0;i<vx.size();i++) {
		ll x=vx[i],y=vy[i];
		auto xx=h.find(x),yy=h.find(y);
		if (xx!=h.end()&&yy!=h.end()) {
			ll a=xx->second,b=yy->second;
			e.PB((1LL<<b)|(1LL<<a));
		}
	}
	ll es=e.size();
	ll zlim=1LL<<n;
	for (ll z=0;z<zlim;z++) ff2[z]=INF;
	ff2[0]=0;
	for (ll z=0;z<zlim;z++) {
		ll v=ff2[z];
		if (v>=INF) continue;
		ll vf=v>>32; ll vs=v&0xffffffff;
		for (ll k=0;k<n;k++) {
			ll msk=1LL<<k;
			if (z&msk) continue;
			ll nz=z|msk;
			ll cost=0;
			for (auto &m:e) {
				if ((nz&m)==m) cost++;
			}
			chkmin(ff2[nz],((vf+cost)<<32)|z);
		}
	}
	{
		ll z=zlim-1;
		while(z!=0) {
			ll cost=0;
			ll nz=ff2[z]&0xffffffff;
			for (auto &m:e) {
				if ((z&m)==m) cost++;
				if ((nz&m)==m) cost--;
			}
			//printf("%lld ",cost);
			go.PB(cost);
			z=nz;
		}
	}
}
void dfs(ll x) {
	if (seen[x]) return;
	active.PB(x);
	seen[x]=true;
	for (auto &w:g[x]) {
		dfs(w);
	}
}
class Gperm {
	public:
	int countfee(vector <int> x, vector <int> y) {
		vx=x;vy=y;
		ll n=x.size();
		for (ll i=0;i<n;i++) {
			ll a=x[i],b=y[i];
			g[a].PB(b); g[b].PB(a);
		}
		for (ll x=0;x<MN;x++) seen[x]=false;
		for (ll x=0;x<50;x++) {
			active.clear();
			dfs(x);
			solve();
		}
		ll final=0;
		ll ed=0;
		sort(go.begin(),go.end());
		for (auto &w:go) {
			ed+=w;
			final+=ed;
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
		cout << "Testing Gperm (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470877204;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Gperm _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0};
				int y[] = {1};
				_expected = 1;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,1};
				int y[] = {1,2};
				_expected = 2;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {4,7,7};
				int y[] = {7,4,4};
				_expected = 3;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,0,1};
				int y[] = {1,2,2};
				_expected = 4;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {7,8,9};
				int y[] = {4,5,6};
				_expected = 6;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};
				int y[] = {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};
				_expected = 53;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {19 ,5 ,16 ,7 ,19 ,18 ,9 ,9 ,3 ,9 ,13 ,1 ,6 ,9 ,6 ,10 ,18 ,16 ,13};
				int y[] = {4 ,19 ,6 ,19 ,17 ,13 ,5 ,1 ,0 ,8 ,18 ,9 ,11 ,3 ,14 ,5 ,7 ,6 ,3};
				_expected = 53;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {49};
				int y[] = {49};
				_expected = 1;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {0};
				int y[] = {49};
				_expected = 1;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
