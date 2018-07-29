#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class SlimeXSlimesCity {
	public:
	int merge(vector <int> _population) {
		ll n=_population.size();
		ll ans=0;
		vector<ll> v; for (auto &w:_population) v.PB(w);
		for (ll x=0;x<n;x++) {
			priority_queue<ll,vector<ll>,greater<ll> > pq;
			for (ll y=0;y<n;y++) {
				if (x!=y) pq.push(v[y]);
			}
			ll now=v[x];
			bool bad=false;
			while(!pq.empty()) {
				ll a=pq.top(); pq.pop();
				if (a<=now) now+=a;
				else bad=true;
			}
			if (!bad) ans++;
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
		cout << "Testing SlimeXSlimesCity (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484292515;
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
		SlimeXSlimesCity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int population[] = {2, 3, 4};
				_expected = 2;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			case 1:
			{
				int population[] = {1, 2, 3};
				_expected = 2;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			case 2:
			{
				int population[] = {8,2,3,8};
				_expected = 2;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			case 3:
			{
				int population[] = {1000000000, 999999999, 999999998, 999999997};
				_expected = 3;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			case 4:
			{
				int population[] = {1,1,1};
				_expected = 3;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			case 5:
			{
				int population[] = {1, 2, 4, 6, 14, 16, 20};
				_expected = 3;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}
			/*case 6:
			{
				int population[] = ;
				_expected = ;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int population[] = ;
				_expected = ;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int population[] = ;
				_expected = ;
				_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
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
