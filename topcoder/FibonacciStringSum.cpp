#include "bits/stdc++.h"
 
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define rep(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
 
using namespace std;
 
template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
  ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
  int get() const { return (int)x; }
 
  ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
 
  ModInt inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += Mod;
    ModInt res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while(k) {
    if(k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
typedef ModInt<1000000007> mint;
 
int berlekampMassey(const vector<mint> &s, vector<mint> &C) {
  int N = (int)s.size();
  C.assign(N + 1, mint());
  vector<mint> B(N + 1, mint());
  C[0] = B[0] = 1;
  int degB = 0;
  vector<mint> T;
  int L = 0, m = 1;
  mint b = 1;
  for(int n = 0; n < N; ++ n) {
    mint d = s[n];
    for(int i = 1; i <= L; ++ i)
      d += C[i] * s[n - i];
    if(d == mint()) {
      ++ m;
    } else {
      if(2 * L <= n)
        T.assign(C.begin(), C.begin() + (L + 1));
      mint coeff = -d * b.inverse();
      for(int i = 0; i <= degB; ++ i)
        C[m + i] += coeff * B[i];
      if(2 * L <= n) {
        L = n + 1 - L;
        B.swap(T);
        degB = (int)B.size() - 1;
        b = d;
        m = 1;
      } else {
        ++ m;
      }
    }
  }
  C.resize(L + 1);
  return L;
}
 
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
  int n2 = (int)a.size(), n = n2 / 2;
  assert(n2 % 2 == 0);
  int L = berlekampMassey(a, phi);
  reverse(phi.begin(), phi.begin() + (L + 1));
}
 
#pragma endregion
 
mint linearlyRecurrentSequenceValue(long long K, const vector<mint> &initValues, const vector<mint> &annPoly) {
  assert(K >= 0);
  if(K < (int)initValues.size())
    return initValues[(int)K];
  int d = (int)annPoly.size() - 1;
  assert(d >= 0);
  assert(annPoly[d].get() == 1);
  assert(d <= (int)initValues.size());
  if(d == 0)
    return mint();
  vector<mint> coeffs(d), square;
  coeffs[0] = 1;
  int l = 0;
  while((K >> l) > 1) ++ l;
  for(; l >= 0; -- l) {
    square.assign(d * 2 - 1, mint());
    for(int i = 0; i < d; ++ i)
      for(int j = 0; j < d; ++ j)
        square[i + j] += coeffs[i] * coeffs[j];
    for(int i = d * 2 - 2; i >= d; -- i) {
      mint c = square[i];
      if(c.x == 0) continue;
      for(int j = 0; j < d; ++ j)
        square[i - d + j] -= c * annPoly[j];
    }
    for(int i = 0; i < d; ++ i)
      coeffs[i] = square[i];
    if(K >> l & 1) {
      mint lc = coeffs[d - 1];
      for(int i = d - 1; i >= 1; -- i)
        coeffs[i] = coeffs[i - 1] - lc * annPoly[i];
      coeffs[0] = mint() - lc * annPoly[0];
    }
  }
  mint res;
  for(int i = 0; i < d; ++ i)
    res += coeffs[i] * initValues[i];
  return res;
}
typedef long long ll;
const ll mn=500;
const ll UNDEF=-1;
ll dp[mn][mn][2];
ll solve(ll n, ll x, ll prev) {
	const ll MOD=1000000007;
	ll v=dp[n][x][prev];
	if (v!=UNDEF) return v;
	ll ans;
	if (n==0) {
		if (x==0) ans=1;
		else ans=0;
	}
	else {
		ans=solve(n-1,x,0);
		if (prev==0&&x>0) ans=(ans+solve(n-1,x-1,1))%MOD;
	}
	//printf("%lld %lld %lld: %lld\n",n,x,prev,ans);
	return dp[n][x][prev]=ans;
}
class FibonacciStringSum {
	public:
	int get(int nn, int a, int b) {
		memset(dp,-1,sizeof dp);
		//printf("%lld\n",solve(3,0,0));
		//printf("%lld\n",solve(3,1,0));
		//printf("%lld\n",solve(3,2,0));
		//printf("%lld\n",solve(3,3,0));
		//return 0;
		vector<mint> seq;
		rer(n,0,mn-1) {
			mint sum=0;
			rer(x,0,n) {
				ll got=solve(n,x,0);
				ll y=n-x;
				mint cand=mint(got)*(mint(x)^b)*(mint(y)^a);
				sum+=cand;
			}
			//if (n==3) printf("sum:%lld\n",sum);
			seq.push_back(sum);
		}
    if(seq.size() % 2 == 1) seq.pop_back();
    vector<mint> phi;
    computeMinimumPolynomialForLinearlyRecurrentSequence(seq, phi);
    if(phi.size() >= seq.size() / 2 - 2) {
      cerr << "warning: maybe it is not enough terms" << endl;
    }
    mint ans = linearlyRecurrentSequenceValue(nn, seq, phi);
    return ans.get();
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
		cout << "Testing FibonacciStringSum (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1477484094;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FibonacciStringSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int a = 0;
				int b = 0;
				_expected = 5;
				_received = _obj.get(n, a, b); break;
			}
			case 1:
			{
				int n = 3;
				int a = 0;
				int b = 1;
				_expected = 5;
				_received = _obj.get(n, a, b); break;
			}
			case 2:
			{
				int n = 10;
				int a = 10;
				int b = 10;
				_expected = 518500021;
				_received = _obj.get(n, a, b); break;
			}
			case 3:
			{
				int n = 5000;
				int a = 20;
				int b = 20;
				_expected = 880245669;
				_received = _obj.get(n, a, b); break;
			}
			/*case 4:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.get(n, a, b); break;
			}*/
			/*case 5:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.get(n, a, b); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.get(n, a, b); break;
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
