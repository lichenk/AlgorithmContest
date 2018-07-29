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
class TeamContest {
	public:
	int worstRank(vector <int> s) {
		ll n=s.size();
		ll my=min(s[0],min(s[1],s[2]))+max(s[0],max(s[1],s[2]));
		vector<int> v;
		for (ll i=3;i<n;i++) v.PB(s[i]);
		sort(v.begin(),v.end(), greater<int>());
		n-=3;
		ll ans=1;
		while(!v.empty()) {
			ll x=*(v.begin());
			v.erase(v.begin());
			ll zidx=-1;
			for (ll i=v.size()-1;i>=0;i--) {
				if (v[i]+x>my) {zidx=i;break;}
			}
			if (zidx>=1) {
				v.erase(v.begin()+zidx);
				v.erase(v.begin()+zidx-1);
				ans++;
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
		cout << "Testing TeamContest (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458920496;
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
		TeamContest _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int strength[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
				_expected = 2;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 1:
			{
				int strength[] = {5, 7, 3};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 2:
			{
				int strength[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 3:
			{
				int strength[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5};
				_expected = 3;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 4:
			{
				int strength[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43};
				_expected = 3;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 5:
			{
				int strength[] = {183857, 538843, 183226, 978182, 430735, 830873};
				_expected = 2;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			/*case 6:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
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
