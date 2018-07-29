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
typedef pair<ll,ll> point;
const ll mn=52;
long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}

inline ll mul(ll aa,ll bb) {
	return (aa*bb)%MOD;
}
vector<int> d;
vector<ll> sx,sy;
ll vlm[mn][mn],vrm[mn][mn];
const ll slim=1<<16;
int dp[slim][50][50];
ll f(ll ship, ll hidx, ll dmin, ll dmax) {
	if (ship==0) return 1;
	bool isdp=(ship<slim);
	if (isdp) {
		int val=dp[ship][dmin][dmax];
		//printf("%lld %lld %lld dp:%d\n",ship,dmin,dmax,val);
		if (val!=-1) {
			return val;
		}
	}
	while (0==(ship&(1LL<<hidx))) hidx--;
	ll ans=0;
	for (ll imid=dmin;imid<=dmax;imid++) {
		ll lm=vlm[hidx][imid],rm=vrm[hidx][imid];
		if (lm==-1) continue;
		lm&=ship; rm&=ship;
		ll lc=imid-dmin;
		//printf("imid:%lld lm:%lld lc:%lld rm:%lld rc:%lld\n",imid,lm,lc,rm,rc);
		if (__builtin_popcountll(lm)==lc) {
			ll got=mul(f(lm,hidx+1,dmin,imid-1),f(rm,hidx+1,imid+1,dmax));
			ans+=got;
		}
	}
	//printf("ship:%lld hidx:%lld dmin:%lld dmax:%lld ans:%lld\n",ship,hidx,dmin,dmax,ans);
	ans%=MOD;
	if (isdp) dp[ship][dmin][dmax]=ans;
	return ans;
}
class CoastGuard {
	public:
	int count(vector <int> _d, vector <int> _x, vector <int> _y) {
		d=_d;
		sort(d.begin(),d.end());
		vector<pair<ll,ll> > v;
		ll n=_x.size();
		for (ll i=0;i<n;i++) v.PB(MP(_y[i],_x[i]));
		sort(v.begin(),v.end());
		//reverse(v.begin(),v.end());
		for (ll i=0;i<n;i++) {
			sx.PB(v[i].second);
			sy.PB(v[i].first);
		}
		for (ll m=0;m<n;m++) {
			for (ll c=0;c<n;c++){
				ll zl=0,zr=0;
				for (ll k=0;k<m;k++) {
					ll msk=1LL<<k;
					ll v=ccw(MP(sx[m],sy[m]),MP(sx[k],sy[k]),MP(d[c],0ll));
					if (v==0) {
						zl=-1; zr=-1; break;
					}
					if (v>0) zl|=msk;
					if (v<0) zr|=msk;
				}
				vlm[m][c]=zl;
				vrm[m][c]=zr;
				//printf("%d %d %lld %lld\n",m,c,zl,zr);
			}
		}
		ll ship=(1LL<<n)-1;
		memset(dp,-1,sizeof dp);
		ll ans=f(ship,n-1,0,n-1);
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
		cout << "Testing CoastGuard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1481682368;
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
		CoastGuard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {-2, 2};
				int x[] = {0, 1};
				int y[] = {1, 2};
				_expected = 2;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {1,2};
				int x[] = {1,2};
				int y[] = {10,10};
				_expected = 1;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {-2, 2, 98, 102};
				int x[] = {0, 1, 100, 101};
				int y[] = {1, 2, 1, 2};
				_expected = 4;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,109,229,294,589,615,741,822,859,1000};
				int x[] = {546,850,287,452,864,874,529,879,818,589};
				int y[] = {414,176,191,15,764,825,204,477,34,460};
				_expected = 400;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {-1,0,1};
				int x[] = {0,0,0};
				int y[] = {1,2,3};
				_expected = 2;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int d[] = {0};
				int x[] = {0};
				int y[] = {1};
				_expected = 1;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int d[] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9, 10, -10, 11, -11, 12, -12, 13, -13, 14, -14, 15, -15, 16, -16, 17, -17, 18, -18, 19, -19, 20, -20, 21, -21, 22, -22, 23, -23, 24, -24, 25, -25};
				int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				int y[] = {13, 2, 10, 50, 1, 28, 37, 32, 30, 46, 19, 47, 33, 41, 24, 34, 27, 42, 49, 18, 9, 48, 23, 35, 31, 8, 7, 12, 6, 5, 3, 22, 43, 36, 11, 40, 26, 4, 44, 17, 39, 38, 15, 14, 25, 16, 29, 20, 21, 45};
				_expected = 605552882;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 7:
			{
				int d[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int d[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
