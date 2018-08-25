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
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint();char rch();long long rlong();

const int mn=5e5+4;

template <typename LST> struct LimitedVec  {
  LST a[mn*32];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};

int ufParent[mn];
inline void ufreset(int x) {
  ufParent[x]=x;
}

void finit(int n) {
  for (int x=1;x<=n;x++) {
    ufParent[x]=x;
  }
}
LimitedVec<pii> rb;
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
void funion_root(int xr, int yr) {
  if (rand()&1) swap(xr,yr);
  ufParent[xr] = yr;
}
int rbffind(int x) {
  if (ufParent[x] != x) {
    int res=rbffind(ufParent[x]);
    rb.PB(MP(x,ufParent[x]));
    ufParent[x] = res;
  }
  return ufParent[x];
}
void rbfunion_root(int xr, int yr) {
  if (rand()&1) swap(xr,yr);
  rb.PB(MP(xr,ufParent[xr]));
  ufParent[xr] = yr;
}
void rollback() {
  int sz=rb.sz;
  for (int i=sz-1;i>=0;i--) {
    pii got=rb.a[i];
    int x=got.fst,val=got.snd;
    ufParent[x]=val;
  }
  rb.clear();
}


int sorted_edges[mn];

vi ve[mn]; int va[mn],vb[mn],vc[mn];
vector<pair<int, vi> > c2[mn];
bitset<mn> vbad;
bool cmp(const int &x, const int &y) {
  return vc[x]<vc[y];
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=1;i<=m;i++) {
    va[i]=rint(),vb[i]=rint(),vc[i]=rint();
    sorted_edges[i]=i;
  }

  sort(sorted_edges+1,sorted_edges+m+1, cmp);

  int q=rint();
  for (int qi=0;qi<q;qi++) {
    int k=rint();
    ve[qi].reserve(k);
    for (int i=0;i<k;i++) ve[qi].PB(rint());
    sort(ve[qi].begin(),ve[qi].end(),cmp);
    auto &v=ve[qi];
    vector<int> group;
    int cost=-1;
    for (int i=0;i<k;i++) {
      if (i==0||vc[v[i]]!=vc[v[i-1]]) {
        if (cost!=-1) {
          c2[cost].PB(MP(qi,group));
        }
        group.clear();
        cost=vc[v[i]];
        //printf("CLEAR\n");
      }
      group.PB(v[i]);
      //printf("Push:%d\n",v[i]);
    }
    if (cost!=-1) c2[cost].PB(MP(qi,group));
  }
  finit(n);
  int sei=1;
  for (int cost=0;cost<mn;cost++) {
    while (sei<=m) {
      int e=sorted_edges[sei];
      int c=vc[e];
      if (c>=cost) break;
      int x=va[e],y=vb[e];
      int xr=ffind(x),yr=ffind(y);
      if (xr!=yr) {
        //printf("x:%d y:%d c:%d\n",x,y,c);
        funion_root(xr,yr);
      }
      sei++;
    }
    for (auto &qg: c2[cost]) {
      int qi=qg.fst;
      if (vbad[qi]) continue;
      auto &v=qg.snd;
      for (auto &e:v) {
        int x=va[e],y=vb[e];
        int xr=rbffind(x),yr=rbffind(y);
        //printf("x:%d y:%d. xr:%d yr:%d\n",x,y,xr,yr);
        if (xr!=yr) {
          rbfunion_root(xr,yr);
        }
        else {
          vbad[qi]=true;
          break;
        }
      }
      rollback();
    }
  }
  for (int qi=0;qi<q;qi++) {
    bool ans=!vbad[qi];
    /*if (ans) {
      int k=ve[qi].size();
    for (int i=0;i<k;i++) {
      int e=ve[qi][i];
      int x=va[e],y=vb[e];
      ufreset(x); ufreset(y);
    }
    for (int i=0;i<k;i++) {
      int e=ve[qi][i];
      int x=va[e],y=vb[e];
      int xr=ffind(x),yr=ffind(y);
      if (xr!=yr) {funion_root(xr,yr);}
      else {ans=0;}
    }
    }*/
    if (ans) printf("YES\n");
    else printf("NO\n");
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