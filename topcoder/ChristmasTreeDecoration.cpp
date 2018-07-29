#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

ll p[51];
ll find(ll x) {
	if (p[x] != x) {
		p[x] = find(p[x]);
	}
	return p[x];
}
void funion(ll x, ll y) {
	ll xr = find(x);
	ll yr = find(y);
	p[xr] = yr;
}

class ChristmasTreeDecoration {
	public:
	int solve(vector <int> col, vector <int> x, vector <int> y) {
		ll n = col.size();
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
		ll m = x.size();
		pair<ll, pair<ll,ll> > v[201];
		for (ll i = 0; i < m; i++) {
			ll a = x[i]-1; ll b = y[i]-1;
			ll cost =  (col[a]==col[b])?1:0;
			v[i] = MP(cost, MP(a,b));
		}
		sort(v,v+m);
		ll ans = 0;
		for (ll i = 0; i < m; i++) {
			ll a = v[i].second.first;
			ll b = v[i].second.second;
			ll cost = v[i].first;
			if (find(a) != find(b)) {
				funion(a,b);
				ans += cost;
			}
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
		cout << "Testing ChristmasTreeDecoration (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453790975;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChristmasTreeDecoration _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4};
				int y[] = {2,3,4,1};
				_expected = 1;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4,1,2};
				int y[] = {2,3,4,1,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int col[] = {50,50,50,50};
				int x[] = {1,2,3,1,1,2};
				int y[] = {2,3,4,4,3,4};
				_expected = 3;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int col[] = {1,4,2,3};
				int x[] = {1,2,3};
				int y[] = {2,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int col[] = {1,1,1,2,2,2,3,3,3,4,4,4};
				int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
				int y[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
				_expected = 5;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
