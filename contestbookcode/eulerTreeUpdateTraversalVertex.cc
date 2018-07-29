#include <bits/stdc++.h>
//#include "stdc++.h"
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

const int maxn=2e5+4;
typedef pair<int,int> pii;
int w[maxn];
vector<int> g[maxn];
int ptwo[maxn];
typedef struct S {
  ll dist,sum;
  S () {
    dist=0;
    sum=0;
  }
  S(const ll &_dist, const ll &_sum) {
    dist=_dist;
    sum=_sum;
  }
  S operator*(const S &b) const {
    // Must be commutative
    ll newsum=(sum+b.sum);
    if (newsum>=MOD) newsum-=MOD;
    return S(max(dist,b.dist),newsum);
  }
  void upd(int x) {
    /*
    The problem may require t[x]= g(\prod_{y \in neighbor(x)} t[y]).
    At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
    So we now want to perform the operation t[x]=g(t[x]).
    This function performs that operation.
    */
    sum=(sum+ptwo[dist]); if (sum>=MOD) sum-=MOD;
    dist++;
    //printf("x:%d dist:%lld sum:%lld\n",x,dist,sum);
  }
} S;
S identity=S(0,0);
typedef struct VS {
  vector<S> prefix;
  vector<S> suffix;
  S all;
} VS;
S t[maxn];
VS vt[maxn];

void euler_init(int x, int p) {
  int numchildren=g[x].size() - ((p==-1)?0:1);
  for (auto &y:g[x]) {
    if (y==p) continue;
    euler_init(y,x);
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
    vt[x].all=prefix;
  }
  {
    S suffix=identity;
    vt[x].suffix.resize(numchildren);
    int id=0;
    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
      int y=*it;
      if (y==p) continue;
      vt[x].suffix[id]=suffix;
      suffix=suffix*t[y];
      id++;
    }
    reverse(vt[x].suffix.begin(),vt[x].suffix.end());
  }
}

ll vfinal[maxn];

void euler_vertex(int x, int p) {
  // Start vertex custom code
  int ans=t[x].sum-ptwo[t[x].dist-1]+MOD;
  ans%=MOD;
  vfinal[x]=ans;
  // End vertex custom code
  int yid=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    //printf("p:%d x:%d->y:%d\n",p,x,y);
    S old_tx=t[x];
    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
    if (p!=-1) t[x]=t[x]*t[p];
    t[x].upd(x);
    S old_ty=t[y];
    t[y]=vt[y].all*t[x];
    t[y].upd(y);
    euler_vertex(y,x);
    t[y]=old_ty;
    t[x]=old_tx;
    yid++;
  }
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for (int i=0;i<n-1;i++) {
    int u,v; scanf("%d%d",&u,&v);
    --u;--v;
    g[u].PB(v); g[v].PB(u);
  }
  int cur=1;
  for (int i=0;i<maxn;i++) {
    ptwo[i]=cur;
    cur*=2;
    if (cur>=MOD) cur-=MOD;
  }
  euler_init(0,-1);
  euler_vertex(0,-1);
  for (int i=0;i<n;i++) printf("%lld\n",vfinal[i]);
}



/*void euler_edge(int x, int p) {
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
}*/
