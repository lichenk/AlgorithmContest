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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
map<int,vector<int> > g;
template <typename LST> struct LimitedVec  {
  LST a[5002];
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
  int size() {
    return sz;
  }
  LST operator [](int i) const {return a[i];}
  LST & operator [](int i) {return a[i];}
};
LimitedVec<pii> q[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    int h,p; scanf("%d%d",&h,&p);
    g[p].PB(h);
  }
  int cur=0,nxt=1;
  for (auto &gw:g) {
    auto &v=gw.snd;
    sort(v.begin(),v.end(),greater<int>());
    int p=gw.fst;
    for (auto &h:v) {
      int sumh=0;
      int idx=-1;
      bool ok=true;
      for (int i=0;i<q[cur].sz;i++) {
        auto &w=q[cur][i];
        if (idx==-1&&sumh+w.snd>h) {
          idx=i;
          sumh+=p;
        }
        if (sumh>w.fst) ok=false;
        sumh+=w.snd;
      }
      if (idx==-1) idx=q[cur].sz;
      printf("h:%d p:%d idx:%d ok:%d\n",h,p,idx,ok);
      if (ok) {
        q[nxt].clear();
        auto it=q[cur].begin();
        for (int i=0;i<=q[cur].sz;i++) {
          if (i==idx) {
            q[nxt].PB(MP(h,p));
          }
          else {
            q[nxt].PB(*it);
            ++it;
          }
        }
        swap(cur,nxt);
      }
    }
  }
  printf("%d\n",q[cur].sz);
}
