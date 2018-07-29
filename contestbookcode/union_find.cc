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


Use in SRM 473, 500-pointer


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