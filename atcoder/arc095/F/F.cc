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
typedef vector<int> vi;
const int mn=1e5+4;
vi g[mn];
bitset<mn> isleaf;
int v2l[mn];
int vdeg[mn];
vi construct(vi chain) {
  int gid=1;
  vi vans;
  int cid=gid++;
  for (auto &x:chain) {
    int leaf=v2l[x];
    //printf("x:%d leaf:%d\n",x,leaf);
    for (int i=0;i<leaf;i++) {
      vans.PB(gid++);
    }
    vans.PB(cid);
    cid=gid++;
  }
  return vans;
}
vi chain;
void dfs(int x, int p) {
  chain.PB(x);
  //printf("chain:%d\n",x);
  for (auto &y:g[x]) {
    if (y!=p&&!isleaf[y]) {
      dfs(y,x);
    }
  }
}
void fail(int t) {
  //printf("Fail t:%d\n",t);
  printf("-1\n"); exit(0);
}
int main(){ 
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for(int i=1;i<n;i++) {
    int x,y; scanf("%d%d",&x,&y); g[x].PB(y); g[y].PB(x);
  }
  if (n==2) {
    printf("1 2\n"); exit(0);
  }
  for (int x=1;x<=n;x++) {
    if (g[x].size()==1) {
      int p=g[x][0];
      v2l[p]++;
      isleaf[x]=true;
      //printf("x:%d is leaf p:%d\n",x,p);
    }
  }
  for (int x=1;x<=n;x++) {
    if (!isleaf[x]) {
      int deg=0;
      for (auto &y:g[x]) {
        if (!isleaf[y]) ++deg;
      }
      //printf("x:%d deg:%d\n",x,deg);
      vdeg[x]=deg;
    }
  }
  vi zeros;
  vi ones;
  int good=0;
  for (int x=1;x<=n;x++) {
    if (isleaf[x]) continue;
    if (vdeg[x]==0) {zeros.PB(x); good++;}
    else if (vdeg[x]==1) {ones.PB(x); good++;}
    else if (vdeg[x]==2) {good++;}
    else fail(1);
  }
  if (zeros.size()==1) {
    dfs(zeros[0],-1);
    if (good!=chain.size()) fail(3);
    int lft=2;
    int x=zeros[0];
    for (auto &y:g[x]) {
      if (isleaf[y]&&lft>0) {
        if (lft==2) {
          chain.insert(chain.begin(),y);
        }
        else if (lft==1) {
          chain.PB(y);
        }
        isleaf[y]=false;
        v2l[x]--;
        --lft;
      }
    } 
  }
  else if (ones.size()==2) {
    dfs(ones[0],-1);
    if (good!=chain.size()) fail(33);
    for (int i=0;i<2;i++) {
      int x=ones[i];
      for (auto &y:g[x]) {
        if (isleaf[y]) {
          if (i==0) {
            chain.insert(chain.begin(),y);
          }
          else {
            chain.PB(y);
          }
          isleaf[y]=false;
          v2l[x]--;
          break;
        }
      }
    }
  }
  else fail(4);
  vi ans1=construct(chain);
  reverse(chain.begin(),chain.end());
  vi ans2=construct(chain);
  vi ans=min(ans1,ans2);
  for (auto &w:ans) printf("%d ",w);
  printf("\n");
}

