#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
ll mod_pow(ll a, ll n) { ll ret = 1; ll p = a % MOD; while (n) { if (n & 1) ret = ret * p % MOD; p = p * p % MOD; n >>= 1; } return ret; }
ll mod_inv(ll a) {return mod_pow(a,MOD-2);}
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
}
/*def factorialMod(n, modulus):
    ans=1
    if n <= modulus//2:
        #calculate the factorial normally (right argument of range() is exclusive)
        for i in range(1,n+1):
            ans = (ans * i) % modulus   
    else:
        #Fancypants method for large n
        for i in range(1,modulus-n):
            ans = (ans * i) % modulus
        ans = modinv(ans, modulus)

        #Since m is an odd-prime, (-1)^(m-n) = -1 if n is even, +1 if n is odd
        if n % 2 == 0:
            ans = -1*ans + modulus
    return ans % modulus*/
ll fact(ll n) {
	ll ans=1;
	if (n<=MOD/2) {
		for (ll i=2;i<=n;i++) ans=(ans*i)%MOD;
		printf("Woof. n:%d ans:%d",n,ans);
		return ans;
	}
	else {
		for (ll i=2;i<MOD-n;i++) ans=(ans*i)%MOD;
		ans=mod_inv(ans);
		if (n%2==0) ans=-ans+MOD;
		printf("Meow");
		return ans;
	}
}
ll invfact(ll n) {
	return mod_inv(fact(n));
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact(n),mul(invfact(k),invfact(n-k)));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}
const ll MAXP=50000+2;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
		}
	}
}
const ll mz=1<<16;
ll dp[2][mz];
class Nim {
	public:
	int count(int K, int L) {
		sieve();
		vector<ll> p;
		for (auto &w:gpv) {
			if (w<=L) p.PB(w);
		}
		ll n=gpv.size();
		if (K<=n) {
			ll cur=0,nxt=1;
			memset(dp,0,sizeof dp);
			dp[0][0]=1;
			for (ll i=0;i<K;i++) {
				memset(dp[nxt],0,sizeof dp[nxt]);
				for (ll z=0;z<mz;z++) {
					ll v=dp[cur][z]%MOD;
					if (v==0) continue;
					for (auto &w:p) {
						dp[nxt][z^w]+=v;
					}
				}
				swap(cur,nxt);
			}
			return dp[cur][0]%MOD;
		}
		else {
			ll cur=0,nxt=1;
			memset(dp,0,sizeof dp);
			dp[0][0]=1;
			for (ll i=0;i<n;i++) {
				memset(dp[nxt],0,sizeof dp[nxt]);
				for (ll z=0;z<mz;z++) {
					ll v=dp[cur][z]%MOD;
					if (v==0) continue;
					for (auto &w:p) {
						dp[nxt][z^w]+=v;
					}
				}
			}
			ll got=dp[cur][0]%MOD;
			ll star=(K-n);
			if (star%2==1) return 0;
			star/=2;
			ll bar=n;
			init();
			ll ans=(got*starbar(star,bar))%MOD;
			return ans;
		}
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
		cout << "Testing Nim (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483554490;
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
		Nim _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 3;
				int L = 7;
				_expected = 6;
				_received = _obj.count(K, L); break;
			}
			case 1:
			{
				int K = 4;
				int L = 13;
				_expected = 120;
				_received = _obj.count(K, L); break;
			}
			case 2:
			{
				int K = 10;
				int L = 100;
				_expected = 294844622;
				_received = _obj.count(K, L); break;
			}
			case 3:
			{
				int K = 123456789;
				int L = 12345;
				_expected = 235511047;
				_received = _obj.count(K, L); break;
			}
			/*case 4:
			{
				int K = ;
				int L = ;
				_expected = ;
				_received = _obj.count(K, L); break;
			}*/
			/*case 5:
			{
				int K = ;
				int L = ;
				_expected = ;
				_received = _obj.count(K, L); break;
			}*/
			/*case 6:
			{
				int K = ;
				int L = ;
				_expected = ;
				_received = _obj.count(K, L); break;
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
