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
const int mx=1e6+2;
typedef int UFTYPE;
class UnionFind {
public:

// Custom
UFTYPE ufIdentity = -1;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
	return max(x,y);
}
inline UFTYPE getInitialValue(int x) {
	return x;
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

const ll mn=2e6+2;
int filled[mn];
int filledsum[mn];
UnionFind uf;
class RightTriangle {
	public:
	long long triangleCount(int _places, int _points, int _a, int _b, int _c) {
		ll places=_places, points=_points, a=_a, b=_b, c=_c;
		uf.init(places+1);
		for (ll n=0;n<points;n++) {
			int want=(a*n*n+b*n+c)%places;
			int x=uf.ffind(want);
			int P=uf.getDataForPos(x);
			if (P==places) {
				x=uf.ffind(0);
				P=uf.getDataForPos(x);
			}
			uf.funion(P,P+1);
			filled[P]=1;
			filled[P+places]=1;
			filledsum[P]=1;
			filledsum[P+places]=1;
		}
		for (ll i=1;i<=2*places;i++) filledsum[i]+=filledsum[i-1];
		if (places&1) return 0;
		ll mid=places/2;
		ll ans=0;
		for (ll x=0;x<places;x++) {
			ll y=x+mid;
			if (filled[x]&&filled[y]) {
				ll sum=filledsum[y-1]-filledsum[x];
				ans+=sum;
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
		cout << "Testing RightTriangle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1501772908;
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
		RightTriangle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int places = 9;
				int points = 3;
				int a = 0;
				int b = 3;
				int c = 0;
				_expected = 0LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 1:
			{
				int places = 40;
				int points = 3;
				int a = 5;
				int b = 0;
				int c = 0;
				_expected = 1LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 2:
			{
				int places = 4;
				int points = 4;
				int a = 16;
				int b = 24;
				int c = 17;
				_expected = 4LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 3:
			{
				int places = 1000000;
				int points = 47000;
				int a = 0;
				int b = 2;
				int c = 5;
				_expected = 0LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 4:
			{
				int places = 200000;
				int points = 700;
				int a = 123456;
				int b = 789012;
				int c = 345678;
				_expected = 6980LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 5:
			{
				int places = 109998;
				int points = 92342;
				int a = 31428;
				int b = 47142;
				int c = 214223;
				_expected = 3448252620LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			case 6:
			{
				int places = 1000000;
				int points = 47000;
				int a = 0;
				int b = 2;
				int c = 5;
				_expected = 0LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
			}
			/*case 7:
			{
				int places = ;
				int points = ;
				int a = ;
				int b = ;
				int c = ;
				_expected = LL;
				_received = _obj.triangleCount(places, points, a, b, c); break;
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
