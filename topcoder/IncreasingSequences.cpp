#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const int GMOD = 998244353;
const int INF = 1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {sig=_norm(sig); x=sig;}
  ModInt(signed long long sig) {sig=_norm(sig); x=sig;}
  int get() const { return (int)x; }

	inline int _norm(int y) {
	  if (y<0) y+=MOD;
	  return y;
	}

 
  ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

  ModInt &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  ModInt &operator/=(int that) {that=_norm(that); return *this *= ModInt(that).inverse(); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

  ModInt operator+(int that) const { return ModInt(*this) += that; }
  ModInt operator-(int that) const { return ModInt(*this) -= that; }
  ModInt operator*(int that) const { return ModInt(*this) *= that; }
  ModInt operator/(int that) const { return ModInt(*this) /= that; }


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
typedef ModInt<GMOD> mint;



const int mn=304;
const int ms=(mn*2*2)+4;
int vsegl[ms],vsegr[ms];
int segn=0;
void addseg(int l, int r) {
	if (l<=r) {
		//printf("l:%d r:%d\n",l,r);
		vsegl[segn]=l;
		vsegr[segn]=r;
		segn++;
	}
}
vector<int> GL,GR;
bool isvalid(int idx, int seg) {
	return GL[idx]<=vsegl[seg]&&vsegr[seg]<=GR[idx];
}
mint f[mn][ms];
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

const int MAXFACT=mn;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%GMOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,GMOD-2,GMOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}

class IncreasingSequences {
	public:
	int count(vector <int> L, vector <int> R) {
		init();
		L.insert(L.begin(),-1000000000);
		R.insert(R.begin(),-1000000000);
		int n=L.size();
		for (int i=0;i<n;i++) {L[i]-=i; R[i]-=i;}
		for (int i=1;i<n;i++) {chkmax(L[i],L[i-1]);}
		for (int i=n-2;i>=0;i--) {chkmin(R[i],R[i+1]);}
		for (int i=0;i<n;i++) {if (L[i]>R[i]) return 0;}
		GL=L;GR=R;
		{
			set<int> s;
			for (int i=0;i<n;i++) {
				s.insert(L[i]); s.insert(R[i]);
				//printf("%d to %d\n",L[i],R[i]);
			}
			vector<int> vs; for (auto &w:s) vs.PB(w);
			for (int i=0;i<vs.size();i++) {
				addseg(vs[i],vs[i]);
				if (i+1<vs.size()) addseg(vs[i]+1,vs[i+1]-1);
			}
		}
		f[0][0]=1;
		for (int src=0;src<n;src++) {
			//for (int seg=0;seg<segn;seg++) printf("%d ",f[src][seg].get());
			//printf(" end src:%d\n",src);
			if (src==n-1) break;
			for (int seg=segn-1;seg>=0;seg--) f[src][seg]=f[src][seg-1];
			for (int seg=1;seg<segn;seg++) f[src][seg]+=f[src][seg-1];
			//for (int seg=0;seg<segn;seg++) printf("src:%d seg:%d f:%d ppp\n",src,seg,f[src][seg].get());
			for (int seg=0;seg<segn;seg++) {
				if (!isvalid(src+1,seg)) continue;
				int dy=vsegr[seg]-vsegl[seg];
				//printf("src:%d seg:%d dy:%d\n",src,seg,dy);
				mint numer=1;
				mint current=f[src][seg];
				int k=1;
				for (int dest=src+1;dest<n;dest++) {
					numer*=(dy+k);
					if (!isvalid(dest,seg)) continue;
					mint manhattan=numer*(invfact[k]);
					//printf("src:%d dest:%d seg:%d current:%d manhattan:%d numer:%d denom:%d\n",
					//	src,dest,seg,current.get(),manhattan.get(),numer.get(),denom.get());
					f[dest][seg]+=current*manhattan;
					k++;
				}
			}
		}
		ll final=0;
		for (int seg=0;seg<segn;seg++) {
			final+=f[n-1][seg].get();
		}
		return final%GMOD;
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
		cout << "Testing IncreasingSequences (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517089315;
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
		IncreasingSequences _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L[] = {1, 3, 1, 4};
				int R[] = {6, 5, 4, 6};
				_expected = 4;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int L[] = {10, 30};
				int R[] = {20, 40};
				_expected = 121;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int L[] = {30, 10};
				int R[] = {40, 20};
				_expected = 0;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int L[] = {4, 46, 46, 35, 20, 77, 20};
				int R[] = {41, 65, 84, 90, 49, 86, 88};
				_expected = 2470;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				int L[] = {1};
				int R[] = {1000000000};
				_expected = 1755647;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 5:
			{
				int L[] = {1};
				int R[] = {1};
				_expected = 1;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 6:
			{
				int L[] = {1,3};
				int R[] = {2,3};
				_expected = 2;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 7:
			{
				int L[] = {1,3};
				int R[] = {2,4};
				_expected = 4;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 8:
			{
				int L[] = {1,2};
				int R[] = {2,3};
				_expected = 3;
				_received = _obj.count(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
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
