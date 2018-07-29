#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<int> a;
ll n;
const ll mn=41;
int dp[mn][mn*mn][mn][2];
ll f(ll pos, ll presum, ll prev, ll decr) {
	ll got=dp[pos][presum][prev][decr];
	if (got!=-1) return got;
	ll ans;
	if (pos==n) ans=1;
	else {
		ll lim=(pos!=0)?min(presum/pos,40LL):40;
		ans=0;
		if (a[pos]==-1) {
			for (ll x=0;x<=lim;x++) {
				ll ndecr=(x<prev)?1:0;
				if (!(decr&&ndecr)) {
					ll got=f(pos+1,presum+x,x,ndecr);
					ans+=got;
				}
			}
		}
		else {
			ll x=a[pos];
			if (x<=lim) {
				ll ndecr=(x<prev)?1:0;
				if (!(decr&&ndecr)) {
					ll got=f(pos+1,presum+x,x,ndecr);
					ans+=got;
				}
			}
		}
		ans%=MOD;
	}
	//printf("pos:%lld presum:%lld prev:%lld decr:%lld ans:%lld\n",
	//	pos,presum,prev,decr,ans);
	return dp[pos][presum][prev][decr]=ans;
}
class FoxAverageSequence {
	public:
	int theCount(vector <int> seq) {
		a=seq;
		n=a.size();
		memset(dp,-1,sizeof dp);
		ll ans=f(0,0,0,0);
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
		cout << "Testing FoxAverageSequence (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484435502;
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
		FoxAverageSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seq[] = {3, -1};
				_expected = 4;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int seq[] = {5, 3, -1};
				_expected = 2;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int seq[] = {-1, 0, 40};
				_expected = 0;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int seq[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1};
				_expected = 579347890;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int seq[] = {-1, 12, 25, 0, 18, -1};
				_expected = 58;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 5:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
