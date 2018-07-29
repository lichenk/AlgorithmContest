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

void gauss(vector<vector<ll> > &a, ll p) {
	ll n=a.size();
	ll m=a[0].size();
	ll r=0; // Which row are we at?
	for (ll k=0;k<m;k++) { // Column to eliminate
		for (ll x=r;x<n;x++) {
			if (a[x][k]!=0) { // Is a[x][k] invertible?
				//printf("r:%lld x:%lld k:%lld\n",r,x,k);
				swap(a[x],a[r]);
				ll invk=mod_inv(a[r][k],p);
				for (ll y=0;y<m;y++) {
					a[r][y]=(a[r][y]*invk)%p;
					//printf("%lld ",a[r][y]);
				}
				//printf("\n");
				for (ll s=r+1;s<n;s++) {
					if (a[s][k]) {
						ll mul=a[s][k];
						for (ll y=0;y<m;y++) {
							a[s][y]=(a[s][y]-((mul*a[r][y])%p)+p)%p;
						}
					}
				}
				r++;
				break;
			}
		}
	}
}
class XorAndSum {
	public:
	long long maxSum(vector<long long> number) {
		ll n=number.size();
		ll m=60;
		vector<vector<ll> > a(n,vector<ll>(m));
		vector<vector<ll> > b(n,vector<ll>(m));
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
			if (number[x]&(1LL<<(m-1-y))) a[x][y]=1;
			else a[x][y]=0;
		}
		gauss(a,2);
		ll ans=0;
		for (ll x=0;x<n;x++) {
			for (ll r=0;r<n;r++) {
				if (r==x) continue;
				ll fstb=-1;
				for (ll y=0;y<m;y++) {
					if (a[r][y]) {fstb=y; break;}
				}
				if (fstb==-1) continue;
				if (a[x][fstb]==0) {
					//printf("XOR: %lld %lld for fstb:%lld\n",x,r,fstb);
					for (ll y=0;y<m;y++) {
						a[x][y]^=a[r][y];
					}
				}
			}
		}
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				//printf("%lld ",a[x][y]);
				ans+=a[x][y]*(1LL<<(m-1-y));
			}
			//printf("\n");
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
		cout << "Testing XorAndSum (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1467596499;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XorAndSum _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long number[] = {1,0};
				_expected = 2LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 1:
			{
				long long number[] = {1,2,3};
				_expected = 8LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 2:
			{
				long long number[] = {0,0,0,0,0,0,0,0,0,0};
				_expected = 0LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 3:
			{
				long long number[] = {2,3,5,7,11,13,17,19};
				_expected = 233LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 4:
			{
				long long number[] = {123456789012345, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = 1234567890123450LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 5:
			{
				long long number[] = {627,674,281,272,289,877,62,122,603,189,615};
				_expected = 10742LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			case 6:
			{
				long long number[] = {557};
				_expected = 557LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long number[] = ;
				_expected = LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long number[] = ;
				_expected = LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
			}*/
			/*case 9:
			{
				long long number[] = ;
				_expected = LL;
				_received = _obj.maxSum(vector<long long>(number, number+sizeof(number)/sizeof(long long))); break;
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
