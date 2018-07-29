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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
const ll MAXF=1002;
ll invfact[MAXF],fact[MAXF];
void init() {
	fact[0] = 1;
	for (ll i = 1; i < MAXF; i++) {
		fact[i] = (fact[i-1] * i)%MOD;
	}
	invfact[MAXF-1]=mod_inv(fact[MAXF-1],MOD);
	for (ll i=MAXF-2;i>=0;i--) {
		invfact[i]=(invfact[i+1]*(i+1))%MOD;
	}
}
ll binom(ll n, ll k) {
	if (n<k||n<0||k<0) return 0;
	return mul(fact[n],mul(invfact[n-k],invfact[k]));
}
ll f(ll n) {
	if (n<2) return 0;
	ll sub=n+1;
	return add(mod_pow(2,n,MOD),MOD-sub);
}
class IntersectingConvexHull {
	public:
	int count(vector <int> px, vector <int> py) {
		init();
		ll n=px.size();
		vector<point> p;
		for (ll i=0;i<n;i++) {
			p.PB(MP(px[i],py[i]));
		}
		ll sum=0;
		for (ll a=0;a<n;a++) for (ll b=0;b<n;b++) {
			if (a==b) continue;
			ll l=0,r=0;
			for (ll c=0;c<n;c++) {
				if (c==a||c==b) continue;
				if (ccw(p[c],p[a],p[b])>0) l++;
				else r++;
			}
			ll adder=mul(f(l),f(r));
			//printf("a:%lld b:%lld l:%lld r:%lld adder:%lld\n",a,b,l,r,adder);
			sum=add(sum,adder);
		}
		//sum=mul(sum,2);
		ll all=mod_pow(3,n,MOD);
		ll o1=mul(2,add(
			mul(binom(n,0),mod_pow(2,n,MOD)),
			mul(binom(n,1),mod_pow(2,n-1,MOD))+
			mul(binom(n,2),mod_pow(2,n-2,MOD))
			));
		ll o2=0;
		for (ll a=0;a<=2;a++) for (ll b=0;b<=2;b++) {
			o2=add(o2,mul(binom(n,a),binom(n-a,b)));
		}
		all=add(all,MOD+o2-o1);
		ll final=add(all,MOD-sum);
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
		cout << "Testing IntersectingConvexHull (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1476651687;
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
		IntersectingConvexHull _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,0,-1,-1,0,1};
				int y[] = {1,2,1,-1,-2,-1};
				_expected = 14;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {444, -646, 367, 302, -506, 810};
				int y[] = {-530, 660, 872, -78, -621, 77};
				_expected = 10;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-737, -245, -51, 943, -7, 1000, -976, -723};
				int y[] = {-355, 898, -372, -585, -98, -53, 490, -954};
				_expected = 900;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330};
				int y[] = {-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427};
				_expected = 296398747;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {1,0,-1,-1,0,1,3};
				int y[] = {1,2,1,-1,-2,-1,0};
				_expected = 154;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
