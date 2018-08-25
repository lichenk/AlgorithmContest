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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=2e5+8;
vector<int> g[mn];
int vdist[mn];
int base;
int n,k;
bool dij() {
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  for (int x=0;x<mn;x++) vdist[x]=1<<29;
  vdist[0]=0; pq.push(MP(0,0));
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    int dist=got.fst,x=got.snd;
    int coord=x; if (coord>=base) coord-=base;
    if (dist>coord) continue;
    if (coord+k>=n) return true;
    if (dist>vdist[x]) continue;
    for (auto &gg:g[x]) {
      int y=gg,cost=1;
      int ndist=dist+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
  return false;
}
string s[2];

bool isvalid(int t, int x) {
  return 0<=x&&x<n&&s[t][x]=='-';
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>k;
  cin>>s[0]>>s[1];
  base=n+1;
  for (int t=0;t<2;t++) {
    for (int x=0;x<n;x++) {
      if (!isvalid(t,x)) continue;
      if (isvalid(t,x-1)) {
        g[t*base+x].PB(t*base+x-1);
      }
      if (isvalid(t,x+1)) {
        g[t*base+x].PB(t*base+x+1);
      }
      if (isvalid(t^1,x+k)) {
        g[t*base+x].PB((t^1)*base+x+k);
      }
    }
  }
  bool ans=dij();
  if (ans) printf("YES\n");
  else printf("NO\n");
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