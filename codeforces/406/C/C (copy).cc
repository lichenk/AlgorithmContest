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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=1e5+4;
set<int> g[mn];
int gsz[mn];
priority_queue<pii,vector<pii>,greater<pii> > pq;
void rm(int x, int y) {
  //printf("rm:%d %d\n",x,y);
  //fflush(stdout);
  assert(gsz[x]==(int)g[x].size());
  g[x].erase(y);
  gsz[x]--;
  assert(gsz[x]==(int)g[x].size());
  assert(gsz[y]==(int)g[y].size());
  g[y].erase(x);
  gsz[y]--;
  assert(gsz[y]==(int)g[y].size());
  if (gsz[x]>0) pq.push(MP(gsz[x],x));
  if (gsz[y]>0) pq.push(MP(gsz[y],y));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  if (m&1) {
    printf("No solution\n"); return 0;
  }
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].insert(y);
    g[y].insert(x);
  }
  for (int x=1;x<=n;x++) {
    gsz[x]=g[x].size();
    pq.push(MP(gsz[x],x));
  }
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    int x=got.snd;
    //printf("pq:%d\n",x);
    assert(gsz[x]==(int)g[x].size());
    if (gsz[x]==0) continue;
    if (gsz[x]==1) {
      int y=*(g[x].begin());
      assert(gsz[y]>=2);
      auto it=g[y].begin();
      while(*it==x) ++it;
      int z=*it;
      rm(x,y); rm(y,z);
      printf("%d %d %d\n",x,y,z);
    }
    else {
      assert(gsz[x]>=2);
      assert(gsz[x]==(int)g[x].size());
      auto it=g[x].begin();
      int y=*it;
      ++it;
      int z=*it;
      printf("%d %d %d\n",y,x,z); fflush(stdout);
      rm(x,y);
      rm(x,z);
    }
  }
}
