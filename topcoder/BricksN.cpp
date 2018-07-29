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
const ll mn=200;
ll g[mn];
ll dp[mn][mn];
ll gk;
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
ll f(ll w, ll h) {
	if (h==0) return 1;
	if (dp[w][h]!=UNDEF) return dp[w][h];
	ll tmp[mn];
	for (ll x=0;x<mn;x++) tmp[x]=0;
	for (ll x=0;x<=w;x++) tmp[x]=1;
	for (ll x=0;x<=w;x++) {
		for (ll l=1;l<=w;l++) {
			ll gapmin;
			if (x+l==w) gapmin=0;
			else gapmin=1;
			for (ll gap=gapmin;gap<=w;gap++) {
				if (x+l+gap<=w) {
					ll added=mul(mul(g[l],f(l,h-1)),tmp[x]);
					/*if(added) {
						printf("x:%lld l:%lld gap:%lld g[%lld]:%lld f(%lld,%lld):%lld tmp:%lld. added:%lld x+l+gap:%lld. final:%lld\n",
							x,l,gap,l,g[l],l,h-1,f(l,h-1),tmp[x],added,x+l+gap,tmp[w]);
					}*/
					tmp[x+l+gap]+=added;
					tmp[x+l+gap]%=MOD;
				}
			}
		}
	}
	ll final=tmp[w];
	dp[w][h]=final;
	//printf("w:%lld h:%lld final:%lld\n",w,h,final);
	return final;
}
class BricksN {
	public:
	int countStructures(int w, int h, int k) {
		gk=k;
		for (ll x=0;x<mn;x++) g[x]=0;
		g[0]=1;
		for (ll x=0;x<=w;x++) {
			for (ll l=1;l<=k;l++) {
				if (x+l<=w) {
					g[x+l]+=g[x];
					g[x+l]%=MOD;
				}
			}
		}
		for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) dp[x][y]=UNDEF;
		ll ans=f(w,h);
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
		cout << "Testing BricksN (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472953231;
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
		BricksN _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w = 3;
				int h = 1;
				int k = 3;
				_expected = 13;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 1:
			{
				int w = 3;
				int h = 2;
				int k = 3;
				_expected = 83;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 2:
			{
				int w = 1;
				int h = 5;
				int k = 1;
				_expected = 6;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 3:
			{
				int w = 10;
				int h = 10;
				int k = 3;
				_expected = 288535435;
				_received = _obj.countStructures(w, h, k); break;
			}
			case 4:
			{
				int w = 50;
				int h = 50;
				int k = 50;
				_expected = 92324271;
				_received = _obj.countStructures(w, h, k); break;
			}
			/*case 5:
			{
				int w = ;
				int h = ;
				int k = ;
				_expected = ;
				_received = _obj.countStructures(w, h, k); break;
			}*/
			/*case 6:
			{
				int w = ;
				int h = ;
				int k = ;
				_expected = ;
				_received = _obj.countStructures(w, h, k); break;
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
