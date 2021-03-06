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
const ll mn=55;
ll dp[mn][mn];
vector<int> a;
ll n;
ll f(ll x, ll y) {
	if (y-x<=1) return 0;
	if (dp[x][y]!=UNDEF) return dp[x][y];
	ll ans=0;
	for (ll z=x+1;z<=y-1;z++) {
		chkmax(ans,f(x,z)+f(z,y));
	}
	ans+=a[x]*a[y];
	dp[x][y]=ans;
	return ans;
}
class CasketOfStar {
	public:
	int maxEnergy(vector <int> weight) {
		a=weight;
		n=a.size();
		for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) dp[x][y]=UNDEF;
		ll ans=f(0,n-1);
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
		cout << "Testing CasketOfStar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471730997;
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
		CasketOfStar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weight[] = {1,2,3,4};
				_expected = 12;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int weight[] = {100,2,1,3,100};
				_expected = 10400;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int weight[] = {2,2,7,6,90,5,9};
				_expected = 1818;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int weight[] = {477,744,474,777,447,747,777,474};
				_expected = 2937051;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int weight[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 13;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 5:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
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
