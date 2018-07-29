#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<int>a,b;
ll as,bs;
ll ac,bc;
ll v;
ll sa[55],sb[55];
void dfsb(ll j);
void dfsa(ll i) {
	//printf("i:%lld\n",a[i]);
	if (sa[i]) return;
	sa[i]=1;
	ac++;
	for (ll j=0;j<bs;j++) {
		//printf("Consider: %lld\n",b[j]);
		if (b[j]==a[i]+v) dfsb(j);
		if (b[j]==a[i]-v) dfsb(j);
	}
}
void dfsb(ll j) {
	//printf("j:%lld\n",b[j]);
	if (sb[j]) return;
	sb[j]=1;
	bc++;
	for (ll i=0;i<as;i++) {
		if (a[i]==b[j]+v) dfsa(i);
		if (a[i]==b[j]-v) dfsa(i);
	}
}
ll dp[55][55];
ll f(ll x, ll y) {
	if (x<0||y<0) return 0;
	if (x==0) return 1;
	if (y==0) return 0;
	if (dp[x][y]!=-1) return dp[x][y];
	ll ans=f(x-1,y-1)+f(x-1,y-2);
	//printf("x:%lld y:%lld ans:%lld\n",x,y,ans);
	return dp[x][y]=ans;
}
class OneDimensionalBalls {
	public:
	long long countValidGuesses(vector <int> _a, vector <int> _b) {
		a=_a,b=_b;
		sort(a.begin(),a.end()); sort(b.begin(),b.end());
		as=a.size(),bs=b.size();
		set<ll> vs;
		for (ll i=0;i<as;i++) for (ll j=0;j<bs;j++) {
			vs.insert(abs(a[i]-b[j]));
		}
		ll final=0;
		memset(dp,-1,sizeof dp);
		for (auto &vv:vs) {
			v=vv;
			if (v<=0) continue;
			ll ans=1;
			memset(sa,0,sizeof sa);
			memset(sb,0,sizeof sb);
			for (ll i=0;i<as;i++) {
				if (sa[i]) continue;
				ac=0,bc=0;
				dfsa(i);
				ans*=f(ac,bc);
				/*if (ac>bc) ans*=0;
				else if (ac==bc) ans*=1;
				else if (ac==bc-1) ans*=2;
				else assert(false);*/
				//printf("v:%lld i:%lld ans:%lld ac:%lld bc:%lld\n",v,i,ans,ac,bc);
			}
			final+=ans;
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
		cout << "Testing OneDimensionalBalls (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484510991;
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
		OneDimensionalBalls _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstPicture[] = {12,11};
				int secondPicture[] = {10,11,13};
				_expected = 3LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}
			case 1:
			{
				int firstPicture[] = {1,2,3};
				int secondPicture[] = {1,2,3};
				_expected = 0LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}
			case 2:
			{
				int firstPicture[] = {1,3};
				int secondPicture[] = {1,3};
				_expected = 1LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}
			case 3:
			{
				int firstPicture[] = {7234};
				int secondPicture[] = {6316,689156,689160,689161,800000,1000001};
				_expected = 6LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}
			case 4:
			{
				int firstPicture[] = {6,2,4};
				int secondPicture[] = {1,2,3,4,5,7,8};
				_expected = 7LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}
			/*case 5:
			{
				int firstPicture[] = ;
				int secondPicture[] = ;
				_expected = LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int firstPicture[] = ;
				int secondPicture[] = ;
				_expected = LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int firstPicture[] = ;
				int secondPicture[] = ;
				_expected = LL;
				_received = _obj.countValidGuesses(vector <int>(firstPicture, firstPicture+sizeof(firstPicture)/sizeof(int)), vector <int>(secondPicture, secondPicture+sizeof(secondPicture)/sizeof(int))); break;
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
