#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

template<int MOD>
struct ModInt {
  static const int Mod = MOD;
	inline int _norm(int y) {
	  if (y<0) y+=Mod;
	  return y;
	}
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {sig=_norm(sig); x=sig;}
  ModInt(signed long long sig) {sig=_norm(sig); x=sig;}
  int get() const { return (int)x; }
 
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
typedef ModInt<998244353> mint;

const int MAXFACT=51;
mint fact[MAXFACT+1],invfact[MAXFACT+1];
void init() {
  mint got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=got*(x+1);
  }
  got=got.inverse();
  for (int x=MAXFACT;x>=0;x--) {
    got=got*(x+1);
    invfact[x]=got;
  }
}

int dpf[51][51][51][51][2];
const mint BASE=mint(1);
int f(int nodes,int basecyc,int curcyc, int take, int parity);
int fnew(int nodes, int cyclen, int parity) {
	assert(nodes>=0);
	if (nodes==0) {return (BASE*(1-parity)).get();}
	int take=(nodes/cyclen)*cyclen;
	return f(nodes,cyclen,take,take,parity);
}
int f(int nodes,int basecyc,int curcyc, int take, int parity) {
	if (nodes==0) {return (BASE*(1-parity)).get();}
	if (curcyc==0) return 0;
	assert(nodes>0);
	assert(curcyc%basecyc==0);
	assert(take%curcyc==0);
	assert(0<=parity&&parity<2);
	int dpval=dpf[nodes][basecyc][curcyc][take][parity];
	if (dpval!=-1) return dpval;
	int newcurcyc=curcyc;
	int newtake=take-curcyc;
	if (newtake<=0) {
		newcurcyc-=basecyc;
		if(newcurcyc) newtake=(nodes/newcurcyc)*newcurcyc;
		else newtake=-1;
	}
	if (take==0) {
		return dpf[nodes][basecyc][curcyc][take][parity]=f(nodes,basecyc,newcurcyc,newtake,parity);
	}
	int chain=curcyc/basecyc;
	mint permuteGroupAction=(fact[chain]^basecyc)*(mint(chain).inverse());
	mint choose=invfact[curcyc];
	mint multiplier=permuteGroupAction*choose;
	mint child[2];
	for (int p=0;p<2;p++) {
		child[p]=multiplier*fnew(take-curcyc,curcyc,p);
		if (basecyc==1&&curcyc==3){
			printf("p:%d permuteGroupAction:%d choose:%d fnew:%d\n"
				,p,permuteGroupAction.get(),choose.get(),fnew(take-curcyc,curcyc,p));
		}
	}
	int glim=max(0,nodes/take);
	mint ans=0;
	mint c0=1;
	for (int g0=0;g0<=glim;g0++, c0*=child[0]) {
		mint c1=1;
		for (int g1=0;g1<=glim-g0;g1++, c1*=child[1]) {
			int wantParity=(parity^(((curcyc+1)&(g0+g1)))^g1)&1;
			mint rem=f(nodes-(g0+g1)*take,basecyc,newcurcyc,newtake,wantParity);
			mint anti=invfact[g0]*invfact[g1];
			mint contrib=rem*c0*c1*anti;
			//if (nodes==2&&basecyc==2&&curcyc==2&&take==2&&parity==1){
			//	printf("g0:%d g1:%d contrib:%d rem:%d c0:%d c1:%d anti:%d\n"
			//		,g0,g1,contrib.get(),rem.get(),c0.get(),c1.get(),anti.get());
			//}
			ans+=contrib;
		}
	}
	//if (nodes==2&&basecyc==2&&curcyc==2&&take==2&&parity==1){printf("nodes:%d basecyc:%d curcyc:%d take:%d parity:%d ans:%d\n",
	//	nodes,basecyc,curcyc,take,parity,ans.get());
	//}
	return dpf[nodes][basecyc][curcyc][take][parity]=ans.get();
}

vector<int> vquo[51];

int h(int nodes, int basecyc, int icurcyc, int take, int parity) {
	if (nodes<0) return 0;
	if (nodes==0) {return 1-parity;}
	if (icurcyc==vquo[basecyc].size()) {return 0;}
	int curcyc=vquo[basecyc][icurcyc];
	assert(basecyc%curcyc==0);
	assert(take%curcyc==0);
	int newicurcyc=icurcyc; int newcurcyc=vquo[newicurcyc];
	int newtake=take-curcyc;
	if (newtake<=0) {
		newicurcyc--;
		if (newicurcyc<vquo[basecyc].size()) {
			newcurcyc=vquo[newicurcyc];
			newtake=(nodes/newbasecyc)*newbasecyc;
		}
		else newtake=-1;
	}
	mint child[2]; child[0]=child[1]=0;
	mint multiplier=invfact[curcyc];
	int dup=(basecyc/curcyc);
	for (int p=0;p<2;p++) {
		mint childraw=fnew(take-curcyc,curcyc,p);
		mint sub=0;
		if (curcyc==1) sub=f(take-curcyc,curcyc,1,take-curcyc,p);
		mint res=(childraw-sub);
		child[((p+curcyc)*dup)&1]+=multiplier*res;
	}
	int glim=max(0,nodes/(take*dup));
	mint ans=0;
	mint c0=1;
	for (int g0=0;g0<=glim;g0++, c0*=child[0]) {
		mint c1=1;
		for (int g1=0;g1<=glim-g0;g1++, c1*=child[1]) {
			int wantParity=(parity^g1)&1;
			//int wantParity=(parity^g1)&1;
			mint rem=h(nodes-(g0+g1)*take*dup,basecyc,newicurcyc,newtake,wantParity);
			mint anti=invfact[g0]*invfact[g1];
			mint contrib=rem*c0*c1*anti;
			//if(nodes==3&&basecyc==3&&take==3&&parity==0)printf("g0:%d g1:%d contrib:%d\n",g0,g1,contrib.get());
			ans+=contrib;
		}
	}
  //if(nodes==4)printf("nodes:%d basecyc:%d take:%d parity:%d ans:%d\n",nodes,basecyc,take,parity,(fact[4]*ans).get());
	return dph[nodes][basecyc][take][parity]=ans.get();
}

int dpg[51][51][51][2];
int g(int nodes, int basecyc, int take, int parity) {
	if (nodes==0) {return 1-parity;}
	if (basecyc==0) {return 0;}
	assert(nodes>=0);
	assert(take%basecyc==0);
	assert(basecyc>=0);
	assert(0<=parity&&parity<2);
	int dpval=dpg[nodes][basecyc][take][parity];
	if (dpval!=-1) return dpval;
	int newbasecyc=basecyc;
	int newtake=take-basecyc;
	if (newtake<=0) {
		newbasecyc--;
		if (newbasecyc) newtake=(nodes/newbasecyc)*newbasecyc;
		else newtake=-1;
	}
	if (take==0) {return dpg[nodes][basecyc][take][parity]=g(nodes,newbasecyc,newtake,parity);}
	mint child[2];
	mint multiplier=1;
	if (basecyc!=1) {
		multiplier=0;
		multiplier+=mint(1)*(take/basecyc)*fact[basecyc-1];
		//if(basecyc==3&&take==3)printf("M:%d\n",multiplier.get());
		multiplier += (fact[basecyc-1])*(take/basecyc)*(basecyc-1);
		//if(basecyc==3&&take==3)printf("G:%d INV:%d\n",multiplier.get(),fact[basecyc].get());
		multiplier*=invfact[basecyc];
	}
	//if(nodes==4&&basecyc==2&&take==2&&parity==0)printf("mul:%d/%d\n",((fact[basecyc-1]+1)*fact[basecyc-1]).get(),fact[basecyc].get());
	for (int p=0;p<2;p++) {
		mint childraw=fnew(take-basecyc,basecyc,p);
		mint sub=0;
		if (basecyc==1) sub=f(take-basecyc,basecyc,1,take-basecyc,p);
		child[p]=multiplier*(childraw-sub);
		//if(nodes==3&&basecyc==3&&take==3&&parity==0)if(child[p].get())printf("take:%d basecyc:%d p:%d child:%d childraw:%d sub:%d\n",take,basecyc,p,child[p].get(),childraw.get(),sub.get());
	}
	int glim=max(0,nodes/take);
	mint ans=0;
	mint c0=1;
	for (int g0=0;g0<=glim;g0++, c0*=child[0]) {
		mint c1=1;
		for (int g1=0;g1<=glim-g0;g1++, c1*=child[1]) {
			int wantParity=(parity^(((basecyc+1)&(g0+g1)))^g1)&1;
			//int wantParity=(parity^g1)&1;
			mint rem=g(nodes-(g0+g1)*take,newbasecyc,newtake,wantParity);
			mint anti=invfact[g0]*invfact[g1];
			mint contrib=rem*c0*c1*anti;
			//if(nodes==3&&basecyc==3&&take==3&&parity==0)printf("g0:%d g1:%d contrib:%d\n",g0,g1,contrib.get());
			ans+=contrib;
		}
	}
  //if(nodes==4)printf("nodes:%d basecyc:%d take:%d parity:%d ans:%d\n",nodes,basecyc,take,parity,(fact[4]*ans).get());
	return dpg[nodes][basecyc][take][parity]=ans.get();
}


class Trisomorphism {
	public:
	int maxSubset(int n) {
		memset(dpf,-1,sizeof dpf);
		memset(dpg,-1,sizeof dpg);
		init();
		for (int x=1;x<=n;x++) {
			for (int y=x;y<=n;y+=x) {
				vquo[y].PB(x);
			}
		}
		//printf("%d==%d\n",fnew(3,3,0),mint(3).inverse().get());
		//assert(fnew(3,3,0)==invfact[3].get());
		//printf("%d\n",fnew(2,2,1));
		mint ans=0;
		for (int x=0;x<=n;x++) {
			//if (x!=4) continue;
			mint contrib=fact[n]*invfact[n-x]*g(x,x,x,0)*(mint(n-x)^(n-x)).get();;
			printf("x:%d contrib:%d\n",x,contrib.get());
			ans+=contrib;
		}
		mint G=(n==1)?1:(fact[n]/2);
		mint final=ans/G;
		return final.get();
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
		cout << "Testing Trisomorphism (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517096766;
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
		Trisomorphism _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 4;
				_received = _obj.maxSubset(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 11;
				_received = _obj.maxSubset(n); break;
			}
			case 2:
			{
				int n = 5;
				_expected = 67;
				_received = _obj.maxSubset(n); break;
			}
			case 3:
			{
				int n = 13;
				_expected = 188742;
				_received = _obj.maxSubset(n); break;
			}
			case 4:
			{
				int n = 42;
				_expected = 441900824;
				_received = _obj.maxSubset(n); break;
			}
			case 5:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.maxSubset(n); break;
			}
			case 6:
			{
				int n = 4;
				_expected = 28;
				_received = _obj.maxSubset(n); break;
			}
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.maxSubset(n); break;
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
