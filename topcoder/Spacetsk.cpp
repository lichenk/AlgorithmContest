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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

inline ll mul(ll x,ll y) {return (x*y)%MOD;}
ll fact[6000],invfact[6000];
void init() {
	fact[0]=1;
	for (ll x=1;x<6000;x++) {
		fact[x]=mul(fact[x-1],x);
	}
	for (ll x=0;x<6000;x++) invfact[x]=mod_inv(fact[x],MOD);
}
ll binom(ll n, ll k) {
	return mul(fact[n],mul(invfact[n-k],invfact[k]));
}
ll gcd(ll x,ll y) {
	if (x==0) return y;
	if (y==0) return x;
	return __gcd(x,y);
}
ll f[2504][2504];
class Spacetsk {
	public:
	int countsets(int L, int H, int K) {
		if (K==1) {
			return (L+1)*(H+1);
		}
		init();
		for (ll x=1;x<2504;x++) {
			f[x][0]=0;
			for (ll y=1;y<2504;y++) {
				f[x][y]=(__gcd(x,y)==1)?1:0;
			}
		}
		for (ll x=0;x<2504;x++) for (ll y=1;y<2504;y++) f[x][y]+=f[x][y-1];
		for (ll x=1;x<2504;x++) for (ll y=0;y<2504;y++) f[x][y]+=f[x-1][y];
		ll zxans=0;
		ll axans=0;
		for (ll s=0;s<=L;s++) {
			for (ll k=K;k<=max(L,H)+1;k++) {
				ll x[2],y[2];
				for (ll c=0;c<2;c++) {
					ll denom=k+c-1;
					x[c]=(L-s)/denom;
					y[c]=H/denom;
					//printf("s:%lld c:%lld x:%lld y:%lld\n",s,c,x[c],y[c]);
				}
				ll axcand[2],zxcand[2];
				for (ll c=0;c<2;c++) {
					axcand[c]=f[x[c]][y[c]];
					zxcand[c]=y[c]?1:0;
				}
				ll axc=axcand[0]-axcand[1];
				ll zxc=zxcand[0]-zxcand[1];
				//printf("s:%lld k:%lld axc:%lld zxc:%lld and %lld\n",s,k,axc,zxc,binom(k,K));
				axc=mul(axc,binom(k,K));
				zxc=mul(zxc,binom(k,K));
				axans+=axc;
				zxans+=zxc;
				////printf("%lld %lld\n",zxans,axans);
			}
		}
		//printf("%lld %lld\n",zxans,axans);
		ll ans=zxans+(axans*2);
		ans%=MOD;
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
		cout << "Testing Spacetsk (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470894622;
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
		Spacetsk _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int H = 1;
				int K = 2;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 1:
			{
				int L = 1;
				int H = 1;
				int K = 1;
				_expected = 4;
				_received = _obj.countsets(L, H, K); break;
			}
			case 2:
			{
				int L = 2;
				int H = 2;
				int K = 1;
				_expected = 9;
				_received = _obj.countsets(L, H, K); break;
			}
			case 3:
			{
				int L = 2;
				int H = 2;
				int K = 2;
				_expected = 23;
				_received = _obj.countsets(L, H, K); break;
			}
			case 4:
			{
				int L = 5;
				int H = 5;
				int K = 3;
				_expected = 202;
				_received = _obj.countsets(L, H, K); break;
			}
			case 5:
			{
				int L = 561;
				int H = 394;
				int K = 20;
				_expected = 786097180;
				_received = _obj.countsets(L, H, K); break;
			}
			case 6:
			{
				int L = 1;
				int H = 2;
				int K = 2;
				_expected = 10;
				_received = _obj.countsets(L, H, K); break;
			}
			/*case 7:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
			}*/
			/*case 8:
			{
				int L = ;
				int H = ;
				int K = ;
				_expected = ;
				_received = _obj.countsets(L, H, K); break;
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
