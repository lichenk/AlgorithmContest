#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
typedef pair<int,int> pii;
const int maxn=1002;
vector<int> g[maxn];
int vans[maxn];
int sz[maxn];
int f(int x, int p) {
  int ans=1;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=f(y,x);
  }
  return sz[x]=ans;
}

typedef pair<int, int> point;

long long ccw(point a, point b, point c) {
  b.first -= a.first; b.second -= a.second;
  c.first -= a.first; c.second -= a.second;
  return b.first * (long long)c.second - c.first * (long long)b.second;
}

typedef pair<pii,int> ppii;
pii origin;
bool cmp(ppii a, ppii b) {
  return ccw(b.fst, origin, a.fst)>0;
}
void dfs(int cur, int p, vector<ppii > v) {
  {
    int topidx=0;
    int vsz=v.size();
    assert(vsz==sz[cur]);
    for (int i=1;i<vsz;i++) {
      if (v[i].fst.snd > v[topidx].fst.snd) topidx=i;
    }
    vans[cur]=v[topidx].snd;
    origin=v[topidx].fst;
    v.erase(v.begin()+topidx);
  }
  sort(v.begin(),v.end(),cmp);

  auto it=v.begin();
  for (auto &nxt:g[cur]) {
    if (nxt==p) continue;
    vector<ppii> nextv;
    int need=sz[nxt];
    for (int i=0;i<need;i++) {
      nextv.PB(*it);
      ++it;
    }
    dfs(nxt,cur,nextv);
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<n;i++) {
    int u=rint(),v=rint();
    --u;--v;
    g[u].PB(v); g[v].PB(u);
  }
  vector<ppii> vp;
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    vp.PB(MP(MP(x,y),i));
  }
  f(0,-1);
  dfs(0,-1,vp);
  for (int i=0;i<n;i++) {
    printf("%d ",vans[i]+1);
  }
  printf("\n");
}

