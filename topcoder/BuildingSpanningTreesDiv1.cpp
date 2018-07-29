#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 987654323LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const int mx=4000+2;
class UnionFind {
  typedef int UFTYPE;
public:
  UFTYPE ufIdentity = 0;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return x+y;
  }
  inline UFTYPE getInitialValue(int x) {
    return 1;
  }
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  int getDataForPos(int x) {
    return ufData[x];
  }
};
UnionFind uf;

vector<vector<int> > g;

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) {
	if (n<0) {
		return mod_pow(mod_inv(a,mod),-n,mod);
	}
	ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret;
}


class BuildingSpanningTreesDiv1 {
	public:
	int getNumberOfSpanningTrees(int n, vector <int> vx, vector <int> vy) {
		g.resize(n+1);
		uf.init(mx);
		int k=vx.size();
		for (int i=0;i<k;i++) {
			int x=vx[i],y=vy[i];
			if (uf.ffind(x)==uf.ffind(y)) return 0;
			uf.funion(x,y);
		}
		vector<ll> deg;
		ll comps=0;
		for (int x=1;x<=n;x++) {
			if (x==uf.ffind(x)) {
				deg.PB(uf.getDataForPos(uf.ffind(x)));
				comps++;
			}
		}
		if (comps==1) return 1;
		ll ans=mod_pow(n,comps-2,MOD);
		for (auto &d:deg) {
			ans=(ans*(ll)d)%MOD;
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
		cout << "Testing BuildingSpanningTreesDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523722705;
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
		BuildingSpanningTreesDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int x[] = {1,2};
				int y[] = {2,3};
				_expected = 1;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int x[] = {1,3,4};
				int y[] = {2,4,5};
				_expected = 6;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int x[] = {1};
				int y[] = {2};
				_expected = 8;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 4;
				int x[] = {1,2,1};
				int y[] = {2,3,3};
				_expected = 0;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				int x[] = {1,4,2,3,5};
				int y[] = {4,7,6,5,8};
				_expected = 144;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1000;
				int x[] = {1};
				int y[] = {2};
				_expected = 529013784;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
