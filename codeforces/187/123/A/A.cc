#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1004;
const int mx=1e6+2;
class UnionFind {
  typedef int UFTYPE;
public:
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
UnionFind uf;
char vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string a; cin>>a;
  sort(a.begin(),a.end());
  map<char,int> hc;
  for (auto &c:a) ++hc[c];
  vector<pair<int,char> > vc; 
  for (auto &w:hc) vc.PB(MP(w.snd,w.fst));
  sort(vc.begin(),vc.end());
	reverse(vc.begin(),vc.end());
  int n=a.length();
  vector<int> vp;
  uf.init(mn);
  for (int x=2;x<=n;x++) {
  	bool isp=true;
  	for (int y=2;y<x;y++) {
  		if (x%y==0) {isp=0; break;}
  	}
  	if (isp) vp.PB(x);
  }
  for (auto &p:vp) for (int i=2;i<=n/p;i++) {
  	uf.funion(p,i*p);
  }
  map<int,int> hx;
  for (int x=1;x<=n;x++) {
  	++hx[uf.ffind(x)];
  }
  vector<pair<int,int> > vx; 
  for (auto &w:hx) vx.PB(MP(w.snd,w.fst));
  sort(vx.begin(),vx.end());
	reverse(vx.begin(),vx.end());
	if (vx[0].fst>vc[0].fst) {
		printf("NO\n"); exit(0);
	}
	else {
		printf("YES\n");
		int id=vx[0].snd;
		vector<int> pos;
		for (int x=1;x<=n;x++) if (uf.ffind(x)==id) pos.PB(x);
		for (int x=1;x<=n;x++) if (uf.ffind(x)!=id) pos.PB(x);
		int k=0;
		for (auto &w:vc) {
			for (int i=0;i<w.fst;i++) vans[pos[k++]]=w.snd;
		}
		printf("%s\n",vans+1);
	}
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}