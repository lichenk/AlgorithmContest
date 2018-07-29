#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define sz(c) ((ll)(c).size())
using namespace std;
typedef long long ll;
// FFT
typedef pair<ll, ll> Pii;

#define FOR(i,n) for(ll i = 0; i < (n); i++)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll MAXLOGNTT=12;
const ll MAXNTT=1LL<<MAXLOGNTT;

template<ll mod, ll primitive_root>
class NTT {
public:
  ll get_mod() const { return mod; }
  ll wcache[2][MAXLOGNTT][MAXNTT];
  void init(ll n) {
  	for (ll sign=0;sign<2;sign++) {
    	const ll g = primitive_root; //g is primitive root of mod
    	ll h = (ll)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
    	if (sign == 0) h = (ll)mod_inv(h, mod); //h = h^-1 % mod
    	ll logm=0;
    	for (ll m = 1; m < n; m *= 2) {
    	  const ll m2 = 2 * m;
    	  const ll base = mod_pow(h, n / m2, mod);
    	  ll w = 1;
    	  FOR(x, m) {
    	  	wcache[sign][logm][x]=w;
    	    w = w * base % mod;
    	  }
    	  logm++;
    	}
    }
  }
  void _ntt(vector<ll>& a, ll sign) {
    const ll n = sz(a);

    if (sign == -1) sign=0;

    ll i = 0;
    for (ll j = 1; j < n - 1; ++j) {
      for (ll k = n >> 1; k >(i ^= k); k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }

    ll logm=0;
    for (ll m = 1; m < n; m *= 2) {
      const ll m2 = 2 * m;
      FOR(x, m) {
      	ll w=wcache[sign][logm][x];
        for (ll s = x; s < n; s += m2) {
          ll u = a[s];
          ll d = a[s + m] * w % mod;
          ll as=u+d;
          if (as>=mod) as-=mod;
          a[s]=as;
          ll sm=u-d;
          if (sm<0) sm+=mod;
          a[s+m]=sm;
        }
      }
      logm++;
    }

    for (auto& x : a) if (x < 0) x += mod;
  }
  void ntt(vector<ll>& input) {
    _ntt(input, 1);
  }
  void intt(vector<ll>& input) {
    _ntt(input, -1);
    const ll n_inv = mod_inv(sz(input), mod);
    for (auto& x : input) x = x * n_inv % mod;
  }

  vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
    ll ntt_size = 1;
    while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

    vector<ll> _a = a, _b = b;
    _a.resize(ntt_size); _b.resize(ntt_size);

    ntt(_a);
    ntt(_b);

    FOR(i, ntt_size){
      (_a[i] *= _b[i]) %= mod;
    }

    intt(_a);
    return _a;
  }
  vector<ll> powup(const vector<ll>& a, ll exponent){
    ll ntt_size = 1;
    while (ntt_size < (sz(a)*exponent)) ntt_size *= 2;

    vector<ll> _a = a;
    _a.resize(ntt_size);

    ntt(_a);

    FOR(i, ntt_size){
      _a[i]=mod_pow(_a[i], exponent, mod);
    }

    intt(_a);
    return _a;
  }
};

typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;

NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;

vector<ll> mul(vector<ll> a, vector<ll> b,ll mod){
  for (auto& x : a) x %= mod;
  for (auto& x : b) x %= mod;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);

  const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
  const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
  const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
  const ll m12_mod = m1 * m2 % mod;
  vector<ll> ret(sz(x));
  FOR(i, sz(x)){
    ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
    if (v1 < 0) v1 += m2;
    ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
    if (v2 < 0) v2 += m3;
    ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
    if (constants3 < 0) constants3 += mod;
    ret[i] = constants3;
  }

  return ret;
}
void init_ntt() {
	ntt1.init(MAXNTT);ntt2.init(MAXNTT);ntt3.init(MAXNTT);
}
const ll MOD=1000000007ll;
const ll MAXF=2002;
ll fact[MAXF],invfact[MAXF];
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
class ConnectedStates {
	public:
	int getSum(vector <int> _a) {
		init();
		init_ntt();
		vector<ll> a;
		for (auto &w:_a) a.PB(w);
		vector<ll> ans={1};
		ll n=a.size();
		ll maxc=n-2;
		for (auto &w:a) {
			vector<ll> v;
			ll c=w;
			for (ll s=0;s<=maxc;s++) {
				ll coeff=((s+1)*c)%MOD;
				coeff=(coeff*invfact[s])%MOD;
				v.PB(coeff);
				c=(c*w)%MOD;
			}
			ans=mul(ans,v,MOD);
			ans.resize(maxc+1);
		}
		ll final=ans[n-2];
		final=(final*fact[n-2])%MOD;
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
		cout << "Testing ConnectedStates (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1476662390;
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
		ConnectedStates _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {3, 10};
				_expected = 30;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {2, 2, 2};
				_expected = 96;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1, 1, 1, 1};
				_expected = 60;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {205659656, 888625810};
				_expected = 118040021;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2, 1, 2, 1, 2};
				_expected = 27808;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {14204721, 921856626, 804287587, 304606131, 277490604, 
				          310739929, 900757841, 818413665, 155154829, 836327185, 
				          602928524, 26132484, 587345385, 936362852, 92603422};
				_expected = 376924431;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {56, 52, 15, 38, 41, 45, 63, 100, 7, 25, 3, 71, 44, 21, 23, 14, 91, 12, 13, 92, 30, 70, 93, 36, 68, 2, 76, 98, 12, 97, 100, 68, 77, 42, 27, 78, 91, 40, 97, 1, 16, 15, 69, 85, 53, 95, 93, 9, 2, 76, 29, 23, 75, 17, 35, 67, 91, 11, 5, 92, 75, 14, 84, 6, 16, 21, 39, 8, 51, 33, 90, 80, 77, 80, 90, 93, 75, 63, 7, 41, 7, 40, 8, 78, 27, 30, 4, 7, 61, 6, 88, 31, 7, 57, 66, 19, 77, 79, 64, 54, 80, 7, 31, 52, 61, 18, 36, 45, 24, 2, 46, 3, 48, 58, 61, 51, 76, 30, 59, 70, 4, 42, 36, 99, 74, 39, 89, 39, 22, 76, 61, 20, 3, 93, 98, 53, 22, 86, 47, 20, 67, 58, 64, 85, 15, 64, 60, 73, 78, 15, 69, 88, 46, 87, 55, 75, 54, 23, 100, 13, 84, 66, 28, 60, 14, 38, 71, 24, 88, 75, 21, 97, 73, 62, 71, 89, 90, 13, 51, 86, 97, 72, 9, 60, 11, 83, 93, 8, 86, 8, 78, 74, 65, 51, 65, 19, 27, 96, 69, 97, 56, 66, 15, 79, 38, 42, 14, 6, 91, 91, 72, 44, 12, 100, 5, 64, 55, 68, 17, 1, 88, 82, 71, 20, 68, 39, 23, 67, 58, 45, 97, 18, 11, 56, 42, 67, 3, 22, 61, 35, 74, 100, 6, 29, 44, 70, 78, 34, 22, 88, 25, 40, 83, 36, 75, 71, 1, 75, 35, 29, 17, 2, 22, 9, 44, 16, 55, 33, 39, 39, 73, 9, 54, 49, 15, 1, 37, 80, 50, 97, 19, 86, 22, 38, 28, 11, 71, 100, 12, 42, 91, 89, 45, 86, 63, 30, 22, 77, 41, 60, 12, 66, 99, 22, 60, 50, 57, 49, 75, 29, 26, 87, 63, 68, 10, 85, 96, 87, 28, 13, 11, 42, 24, 85, 49, 36, 58, 18, 22, 46, 50, 32, 23, 7, 14, 51, 100, 54, 63, 18, 12, 8, 60, 29, 67, 35, 78, 59, 88, 64, 37, 80, 86, 23, 53, 50, 96, 3, 65, 42, 60, 4, 9, 33, 77, 81, 89, 98, 79, 32, 83, 96, 92, 9, 65, 12, 38, 3, 82, 8, 97, 46, 55, 83, 12, 72, 75, 87, 76, 1, 19, 92, 42, 69, 25, 47, 42, 32, 42, 36, 3, 7, 77, 60, 98, 62, 38, 92, 56, 29, 74, 94, 23, 14, 90, 16, 69, 45, 84, 23, 59, 62, 30, 36, 32, 50, 51, 56, 26, 48, 37, 35, 94, 2, 12, 13, 1, 57, 68, 62, 34, 58, 54, 93, 24, 29, 65, 58, 18, 45, 85, 28, 38, 60, 51, 72, 64, 97, 25, 67, 65, 17, 82, 29, 64, 52, 2, 97, 8, 99, 87, 57, 93, 88, 39, 64, 7, 62, 83, 44, 95, 30, 33, 17, 100, 33, 7, 25, 6, 16, 95, 42, 56, 89, 10, 63, 89, 96, 16, 49, 74, 76, 37, 57, 39, 39, 46, 80, 73, 1, 24, 61, 7, 87, 54, 18, 58, 17, 56, 81, 39, 59, 96, 92, 95, 30, 93, 34, 60, 27, 72, 61, 88, 26, 69, 34, 13, 27, 73, 28, 40, 2, 4, 5, 74, 48, 89, 88, 10, 93, 9, 38, 36, 49, 95, 65, 15, 40, 92, 76, 98, 9, 100, 32, 10, 70, 70, 55, 98, 64, 38, 43, 67, 33, 20, 36, 15, 85, 87, 61, 83, 56, 43, 23, 51, 78, 64, 86, 35, 3, 65, 70, 69, 3, 41, 87, 24, 11, 96, 98, 50, 48, 30, 68, 94, 39, 70, 80, 52, 10, 46, 55, 9, 50, 90, 45, 46, 60, 12, 68, 75, 37, 62, 2, 34, 35, 56, 69, 40, 82, 33, 73, 27, 82, 85, 46, 10, 52, 82, 65, 11, 7, 56, 66, 45, 15, 29, 53, 48, 75, 91, 32, 60, 62, 11, 35, 29, 8, 38, 24, 11, 39, 77, 11, 90, 24, 39, 57, 11, 25, 62, 42, 81, 43, 44, 49, 69, 10, 70, 40, 98, 61, 46, 22, 12, 15, 17, 38, 36, 19, 28, 82, 58, 42, 27, 74, 6, 26, 17, 11, 14, 49, 85, 40, 74, 15, 35, 14, 38, 73, 15, 16, 4, 83, 61, 75, 35, 81, 96, 17, 99, 17, 12, 52, 43, 34, 25, 60, 23, 6, 14, 73, 92, 23, 22, 90, 87, 50, 16, 67, 54, 1, 54, 32, 86, 89, 12, 72, 48, 43, 71, 55, 54, 66, 54, 69, 41, 90, 80, 79, 4, 84, 88, 58, 31, 68, 56, 1, 55, 56, 13, 4, 53, 48, 28, 23, 36, 52, 57, 14, 98, 13, 51, 92, 13, 66, 26, 12, 11, 64, 91, 91, 95, 75, 78, 37, 76, 13, 90, 31, 22, 56, 37, 38, 2, 87, 32, 26, 9, 38, 72, 85, 31, 75, 91, 91, 72, 41, 28, 98, 98, 5, 60, 56, 9, 61, 71, 65, 98, 85, 26, 16, 83, 61, 46, 43, 30, 9, 52, 72, 53, 16, 26, 20, 95, 27, 12, 31, 68, 88, 2, 95, 74, 77, 28, 97, 96, 44, 61, 36, 47, 94, 53, 84, 8, 89, 4, 79, 18, 4, 80, 42, 85, 66, 8, 54, 54, 7, 100, 73, 65, 42, 86, 92, 26, 25, 5, 10, 35, 45, 10, 56, 1, 99, 85, 42, 65, 94, 57, 67, 64, 95, 13, 63, 79, 59, 26, 58, 32, 82, 6, 22, 58, 50, 99, 47, 30, 51, 53, 29, 91, 25, 32, 62, 88, 61, 6, 3, 61, 90, 1, 6, 85, 46, 51, 31, 31, 81, 8, 24, 69, 74, 58, 45, 19, 57, 91, 58, 86, 33, 57, 49, 75, 38, 52, 54, 14, 44, 32, 26, 82, 8, 13, 51, 50, 72, 54, 42, 15, 18, 51, 48, 78, 43, 11, 66, 92, 35, 70, 86, 66, 52, 96, 71, 42, 16, 21, 61, 91, 38, 100, 82, 98, 4, 22, 79, 34, 40, 30, 2, 70, 56, 63, 16, 68, 74, 8, 99, 62, 39, 57, 59, 40, 47, 22, 89, 94, 21, 1, 66, 64, 16, 54, 29, 24, 33, 64, 10, 27, 37, 44, 55, 5, 11, 29, 69, 32, 78, 44, 21, 83, 83, 21, 79, 73, 25, 40, 54, 16, 63, 11, 62, 7, 93, 46, 77, 35, 70, 17, 79, 20, 53, 22, 69, 97, 67, 61, 70, 8, 37, 95, 50, 6, 57, 67, 44, 34, 53, 21, 76, 72, 68, 45, 4, 81, 87, 97, 24, 52, 24, 3, 63, 89, 65, 26, 91, 46, 41, 17, 79, 61, 56, 32, 12, 56, 31, 63, 26, 99, 44, 37, 14, 33, 24, 13, 19, 94, 22, 99, 74, 41, 61, 17, 11, 35, 78, 30, 72, 7, 96, 72, 25, 10, 51, 74, 80, 75, 92, 70, 78, 48, 41, 19, 7, 12, 5, 76, 84, 46, 12, 36, 51, 61, 16, 44, 34, 27, 30, 1, 63, 38, 36, 100, 74, 82, 74, 36, 53, 83, 33, 20, 10, 31, 100, 30, 38, 70, 2, 23, 31, 11, 93, 35, 70, 48, 57, 27, 77, 18, 96, 24, 90, 29, 83, 89, 64, 60, 73, 64, 59, 78, 72, 46, 6, 23, 55, 15, 99, 39, 47, 25, 44, 19, 23, 79, 59, 31, 70, 54, 44, 96, 83, 94, 21, 51, 37, 69, 18, 9, 45, 49, 67, 94, 16, 40, 61, 93, 17, 16, 18, 19, 96, 7, 83, 25, 99, 22, 66, 54, 99, 23, 69, 88, 10, 88, 24, 34, 47, 3, 53, 73, 77, 37, 65, 44, 72, 58, 60, 98, 26, 30, 99, 57, 70, 41, 24, 91, 72, 76, 12, 70, 6, 71, 17, 82, 55, 42, 23, 24, 89, 7, 34, 8, 80, 89, 79, 97, 93, 4, 4, 73, 10, 16, 80, 21, 67, 88, 94, 55, 99, 95, 39, 18, 6, 21, 44, 70, 4, 76, 42, 55, 42, 93, 57, 4, 41, 86, 97, 31, 31, 42, 11, 94, 35, 37, 33, 39, 53, 72, 80, 64, 17, 54, 66, 36, 58, 64, 98, 98, 36, 27, 21, 8, 66, 48, 100, 57, 93, 71, 85, 69, 59, 79, 92, 81, 69, 85, 96, 79, 67, 81, 72, 12, 12, 10, 90, 95, 17, 6, 1, 30, 5, 91, 22, 60, 60, 66, 39, 4, 90, 6, 100, 8, 70, 20, 19, 95, 55, 1, 94, 90, 27, 8, 10, 83, 46, 45, 87, 35, 88, 96, 29, 93, 64, 55, 96, 16, 8, 36, 61, 74, 98, 76, 99, 48, 10, 73, 21, 97, 21, 88, 73, 91, 46, 64, 49, 15, 49, 53, 9, 6, 49, 92, 72, 53, 57, 8, 59, 89, 79, 99, 17, 88, 92, 16, 23, 90, 54, 41, 19, 10, 93, 24, 1, 32, 22, 37, 20, 28, 7, 73, 28, 17, 72, 69, 98, 34, 90, 44, 61, 44, 37, 56, 95, 50, 18, 68, 75, 17, 29, 49, 96, 36, 93, 9, 1, 44, 14, 25, 96, 17, 33, 25, 14, 64, 11, 56, 7, 88, 100, 85, 9, 54, 24, 75, 9, 11, 65, 30, 14, 89, 8, 32, 45, 61, 71, 95, 72, 21, 84, 96, 61, 49, 75, 98, 78, 55, 31};
				_expected = 853015488;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
