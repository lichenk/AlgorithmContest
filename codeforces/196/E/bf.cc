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
const int mn=20+4;
vector<pii> g[mn];
bool isportal[mn];
int k;
int n,m;
bool seen[mn];
ll go() {
  memset(seen,0,sizeof seen);
  int x=1;
  seen[x]=1;
  ll ans=0;
  vector<int> p;
  if (isportal[x]) p.PB(x);
  //vector<int> h;
  while(p.size()<k) {
    int t=rand()%(p.size()+g[x].size());
    //h.PB(x);
    if (t<p.size()) {
      x=p[t];
    }
    else {
      t-=p.size();
      ans+=g[x][t].snd;
      x=g[x][t].fst;
      if (!seen[x]) {
        seen[x]=true;
        if (isportal[x]) p.PB(x);
      }
    }
  }
  /*if (ans==6) {
    for (auto &w:h) printf("%d ",w);
    exit(0);
  }*/
  return ans;
}
ll solve() {
  ll ans=INF;
  for (int k=0;k<100000;k++) {
    srand(clock());
    chkmin(ans,go());
  }
  return ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(),w=rint();
    g[x].PB(MP(y,w));
    g[y].PB(MP(x,w));
  }
  k=rint();
  for (int i=0;i<k;i++) {
    int x=rint(); isportal[x]=true;
  }
  ll final=solve();
  printf("%lld\n",final);
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