#include <bits/stdc++.h>
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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e5+4;
vector<int> g[mn];
int v[mn];
pll dfs(int x, int p) {
  pll now=MP(0ll,0ll);
  for (auto &y:g[x]) {
    if (y==p) continue;
    pll got=dfs(y,x);
    chkmax(now.fst,got.fst);
    chkmax(now.snd,got.snd);
  }
  ll newval=v[x]+now.fst-now.snd;
  if (newval>0) now.snd+=abs(newval);
  else now.fst+=abs(newval);
  return now;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int x=1;x<=n;x++) v[x]=rint();
  pll ans=dfs(1,-1);
  ll final=ans.fst+ans.snd;
  printf("%lld\n",final);
}

