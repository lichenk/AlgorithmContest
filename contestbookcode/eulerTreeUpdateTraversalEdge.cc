//#include <bits/stdc++.h>
#include "stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int maxn=3e5+2;
typedef pair<int,int> pii;
int w[maxn];
vector<int> g[maxn];

typedef struct S {
  ll losum,hisum,sum,lobest,hibest;
  S () {
    losum=0; hisum=0; sum=0; lobest=INF; hibest=-INF;
  }
  S(const ll &_losum, const ll &_hisum, const ll &_sum, const ll &_lobest, const ll &_hibest) {
    losum=_losum; hisum=_hisum; sum=_sum; lobest=_lobest; hibest=_hibest;
  }
  S operator*(const S &b) const {
    // Must be commutative
    return S(
      min({losum,b.losum,losum+b.losum}),
      max({hisum,b.hisum,hisum+b.hisum}),
      sum+b.sum, min(lobest,b.lobest), max(hibest,b.hibest));
  }
  void upd(int x) {
    /*
    The problem may require t[x]= g(\prod_{y \in neighbor(x)} t[y]).
    At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
    So we now want to perform the operation t[x]=g(t[x]).
    This function performs that operation.
    */
    sum+=w[x];
    chkmin(lobest,min(sum-losum,sum-hisum));
    chkmax(hibest,max(sum-losum,sum-hisum));
    chkmin(losum,sum);
    chkmax(hisum,sum);
    //printf("x:%d losum:%lld hisum:%lld sum:%lld\n",x,losum,hisum,sum);
  }
} S;
S identity=S(0,0,0,INF,-INF);
typedef struct VS {
  vector<S> prefix;
  vector<S> suffix;
} VS;
S t[maxn];
VS vt[maxn];

void init(int x, int p) {
  int numchildren=g[x].size() - ((p==-1)?0:1);
  for (auto &y:g[x]) {
    if (y==p) continue;
    init(y,x);
    t[x]=t[x]*t[y];
  }
  t[x].upd(x);
  {
    S prefix=identity;
    vt[x].prefix.resize(numchildren);
    int id=0;
    for (auto &y:g[x]) {
      if (y==p) continue;
      vt[x].prefix[id]=prefix;
      prefix=prefix*t[y];
      id++;
    }
  }
  {
    S suffix=identity;
    vt[x].suffix.resize(numchildren);
    int id=0;
    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
      int y=*it;
      if (y==p) continue;
      vt[x].suffix[id]=suffix;
      //printf("x:%d id:%d suffix:%lld\n",x,numchildren-1-id,suffix.sum);
      suffix=suffix*t[y];
      id++;
    }
    reverse(vt[x].suffix.begin(),vt[x].suffix.end());
  }
  //printf("x:%d losum:%lld hisum:%lld sum:%lld\n",x,t[x].losum,t[x].hisum,t[x].sum);
}
ll finalans=-9e18;

void euler_edge(int x, int p) {
  // Start vertex custom code
  // End vertex custom code
  if (p!=-1) {
    if (t[x].lobest<=t[x].hibest&&t[p].lobest<=t[p].hibest) {
    //printf("x:%d p:%d X %lld %lld P %lld %lld\n",x,p,t[x].lobest,t[x].hibest,t[p].lobest,t[p].hibest);
    chkmax(finalans, max({
      t[x].lobest*t[p].lobest,
      t[x].lobest*t[p].hibest,
      t[x].hibest*t[p].lobest,
      t[x].hibest*t[p].hibest,
    }));
    }
  }
  int yid=0;
  for (auto &y:g[x]) {
    if (y==p) continue;

    S old_tx=t[x];
    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
    if (p!=-1) {
      t[x]=t[x]*t[p];
      //printf("x:%d p:%d yid:%d pre:%lld suf:%lld p:%lld\n",x,p,yid, vt[x].prefix[yid].sum,vt[x].suffix[yid].sum,t[p].sum);
    }
    t[x].upd(x);

    euler_edge(y,x);
    t[x]=old_tx;

    yid++;
  }
}

/*
void euler_vertex(int x, int p) {
  // Start vertex custom code
  // End vertex custom code
  int yid=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    S old_tx=t[x];
    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
    if (p!=-1) t[x]=t[x]*t[p];
    t[x].upd(x);
    S old_ty=t[y];
    t[y]=t[y]*t[x];
    euler(y,x);
    t[y]=old_ty;
    t[x]=old_tx;
    yid++;
  }
}
*/

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%d",&w[i]);
  for (int i=0;i<n-1;i++) {
    int u,v; scanf("%d%d",&u,&v);
    --u;--v;
    g[u].PB(v); g[v].PB(u);
  }
  init(0,-1);
  euler_edge(0,-1);
  printf("%lld\n",finalans);
}