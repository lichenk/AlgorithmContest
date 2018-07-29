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
ll solve(vector<char> inp) {
	map<char,ll> h;
	for (auto &c:inp) h[c]++;
	vector<ll> v;
	for (auto &w:h) v.PB(w.snd);
	sort(v.begin(),v.end(),greater<ll>());
	ll ans=0;
	ll vs=v.size();
	for (ll i=0;i<vs;i++) {
		ans+=i*v[i];
	}
	return ans;
}
class RowsOrdering {
	public:
	int order(vector <string> rows) {
		ll n=rows.size();
		ll m=rows[0].length();
		vector<ll> v;
		for (ll y=0;y<m;y++) {
			vector<char> inp;
			for (ll x=0;x<n;x++) inp.PB(rows[x][y]);
			ll got=solve(inp);
			//printf("y:%lld got:%lld\n",y,got);
			v.PB(got);
		}
		sort(v.begin(),v.end(),greater<ll>());
		ll ans=n;
		ll mt=1;
		for (auto &w:v) {
			w%=MOD;
			ans+=(mt*w)%MOD;
			mt=(mt*50)%MOD;
		}
		return ans%MOD;
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
		cout << "Testing RowsOrdering (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483815123;
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
		RowsOrdering _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rows[] = {"bb", "cb", "ca"};
				_expected = 54;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			case 1:
			{
				string rows[] = {"abcd", "ABCD"};
				_expected = 127553;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			case 2:
			{
				string rows[] = {"Example", "Problem"};
				_expected = 943877448;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			case 3:
			{
				string rows[] = {"a", "b", "c", "d", "e", "f", "g"};
				_expected = 28;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			case 4:
			{
				string rows[] = {"a", "a"};
				_expected = 2;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			case 5:
			{
				string rows[] = {"dolphinigle", "ivanmetelsk", "lympandaaaa"};
				_expected = 356186235;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}
			/*case 6:
			{
				string rows[] = ;
				_expected = ;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string rows[] = ;
				_expected = ;
				_received = _obj.order(vector <string>(rows, rows+sizeof(rows)/sizeof(string))); break;
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
