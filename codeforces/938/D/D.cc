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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=200000+2;
vector<pair<int,ll> > g[mn];
ll vdist[mn];
typedef pair<ll,int> pli;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(); ll w=rlong()<<1;
    g[x].PB(MP(y,w));
    g[y].PB(MP(x,w));
  }
  priority_queue<pli,vector<pli>,greater<pli> > pq;
  for (int x=1;x<=n;x++) {
    ll init=rlong(); vdist[x]=init;
    pq.push(MP(init,x));
  }
  while(!pq.empty()) {
    pli top=pq.top();pq.pop();
    ll distx=top.fst,x=top.snd;
    if (distx!=vdist[x]) continue;
    for (auto &edge:g[x]) {
      int y=edge.fst; ll cost=edge.snd;
      ll ndist=distx+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
  for (int x=1;x<=n;x++) {
    printf("%lld ",vdist[x]);
  }
  printf("\n");
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