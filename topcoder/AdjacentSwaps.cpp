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
bool g[55][55];
bool seen[55];
ll n;
bool hascyc;
void dfs(ll x) {
	if (seen[x]) {hascyc=true; return;}
	seen[x]=true;
	for (ll y=0;y<n;y++) {
		if(g[x][y]) dfs(y);
	}
}
bool findcyc() {
	for (ll x=0;x<n-1;x++) {
		memset(seen,0,sizeof seen);
		hascyc=false;
		dfs(x);
		if (hascyc) return true;
	}
	return false;
}
ll dp[55][55];
ll f(ll x, ll before) {
	ll after=x-1-before;
	// There are before before x-1, and after after x-1
	if (dp[x][before]!=UNDEF) return dp[x][before];
	ll final;
	if (x==n-1) final=1;
	else {
		bool mustbefore=g[x][x-1];
		bool mustafter=g[x-1][x];
		final=0;
		if (!mustafter) {
			for (ll k=0;k<=before;k++) {
				ll got=f(x+1,k);
				final+=got;
			}
		}
		if (!mustbefore) {
			for (ll k=0;k<=after;k++) {
				ll got=f(x+1,x-k);
				final+=got;
			}
		}
		//printf("x:%d before:%d final:%d mb:%d ma:%d\n",x,before,final,mustbefore,mustafter);
	}
	//printf("x:%d before:%d final:%d n-1:%d\n",x,before,final,n-1);
	final%=MOD;
	return dp[x][before]=final;
}
class AdjacentSwaps {
	public:
	int theCount(vector <int> p) {
		n=p.size();
		memset(g,0,sizeof g);
		for (ll x=0;x<n;x++) {
			ll y=-1;
			for (ll i=0;i<n;i++) {
				if (p[i]==x) y=i;
			}
			if (y>x) {
				for (ll i=x;i<=y-2;i++) {
					//printf("%d->%d\n",i,i+1);
					g[i][i+1]=1;
				}
			}
			else {
				for (ll i=x-1;i>=y+1;i--) {
					//printf("%d->%d\n",i,i-1);
					g[i][i-1]=1;
				}
			}
		}
		if (findcyc()) return 0;
		memset(dp,-1,sizeof dp);
		ll ans=f(1,0);
		bool used[55]; memset(used,0,sizeof used);
		vector<ll> v;
		while(v.size()<n-1) {
			for (ll x=0;x<n-1;x++) {
				if (used[x]) continue;
				ll z=0;
				for (ll y=0;y<n-1;y++) {
					z|=g[y][x];
				}
				if (z==0) {
					used[x]=true;
					v.PB(x);
					for (ll i=0;i<n;i++) {g[i][x]=0;g[x][i]=0;}
					break;
				}
			}
		}
		vector<int> q; for (ll x=0;x<n;x++) q.PB(x);
		for (auto &w:v) {
			//printf("w:%d\n",w);
			swap(q[w],q[w+1]);
		}
		if (q!=p) return 0;
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
		cout << "Testing AdjacentSwaps (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483773431;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AdjacentSwaps _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {1, 2, 0};
				_expected = 1;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0, 1};
				_expected = 0;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {2, 0, 3, 1};
				_expected = 2;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {1, 0, 3, 2};
				_expected = 0;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17};
				_expected = 716743312;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 5:
			{
				int p[] = {4,0,1,2,3};
				_expected = 1;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 6:
			{
				int p[] = {1,2,3,4,0};
				_expected = 1;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			/*case 7:
			{
				int p[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
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
