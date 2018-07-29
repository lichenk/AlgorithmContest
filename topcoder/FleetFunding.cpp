#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXN = 54;
ll n,gm;
pair<pair<ll,ll>,ll> p[MAXN];
ll gleft[MAXN];
ll ga[MAXN],gb[MAXN],gk[MAXN];
bool f(ll y) {
	for (ll i=0;i<n;i++) {
		gleft[i] = gk[i];
	}
	for (ll t=1; t<=gm;t++) {
		ll need = y;
		while (need > 0) {
			ll best = 0x7fffffff;
			ll idx = -1;
			for (ll j=0;j<n;j++) {
				if (gleft[j] > 0 && ga[j] <= t && t <= gb[j]) {
					if (gb[j] < best) {
						best = gb[j];
						idx = j;
					}
				}
			}
			if (idx == -1) {
				break;
			}
			ll take = min(need, gleft[idx]);
			need -= take;
			gleft[idx] -= take;
		}
		if (need > 0) {
			return false;
		}
	}
	return true;
}

class FleetFunding {
	public:
	int maxShips(int _m, vector <int> k, vector <int> a, vector <int> b) {
		gm=_m;
		n=k.size();
		for (ll i=0;i<n;i++) {
			p[i] = (MP(MP(b[i],a[i]),k[i]));
		}
		sort(p,p+n);
		for (ll i=0;i<n;i++) {
			ga[i] = p[i].first.second;
			gb[i] = p[i].first.first;
			gk[i] = p[i].second;
		}

		ll imin = 0; ll imax = 100*1000*1000 + 1;
		ll l=0, r=50000000;
		while (l<r) {
			ll mid = (l+r)/2 + 1;
			if (!f(mid)) {
				r=mid-1;
			}
			else l=mid;
		}
		return l;
		while (imin < imax) {
			ll imid = imin+(imax-imin)/2;
			if (f(imid)) {
				imin=imid+1;
			}
			else {
				imax = imid;
			}
		}
		imin--;
		return imin;
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
		cout << "Testing FleetFunding (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454778002;
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
		FleetFunding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 3;
				int k[] = {2,2,2};
				int a[] = {1,2,1};
				int b[] = {3,3,2};
				_expected = 2;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int m = 1;
				int k[] = {10,9,8,7,6,5,4,3,2,1};
				int a[] = {1,1,1,1,1,1,1,1,1,1};
				int b[] = {1,1,1,1,1,1,1,1,1,1};
				_expected = 55;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int m = 10;
				int k[] = {2,4,6,8,10,1,3,5,7,9};
				int a[] = {1,2,3,4,5,6,7,8,9,10};
				int b[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 1;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int m = 84457;
				int k[] = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
				          349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
				          574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
				          857994,991217,149619,415870};
				int a[] = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
				          3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998};
				int b[] = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
				          81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
				          84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456};
				_expected = 186;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int m = 2;
				int k[] = {1000000,1000000,1000000,1000000,1000000};
				int a[] = {1,1,1,2,2};
				int b[] = {1,1,2,2,2};
				_expected = 2500000;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int m = 1;
				int k[] = { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int b[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 50000000;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int m = 100000;
				int k[] = { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int b[] = { 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
				_expected = 500;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int m = 50;
				int k[] = { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int b[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 0;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
