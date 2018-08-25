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
int n,p;
const int mn=24;
const int iinf=1e9;
vector<int> g[mn];
bitset<mn> f[mn];
void solve() {
  scanf("%d%d",&n,&p);
  for (int x=0;x<n;x++) {
    g[x].clear(); f[x].reset();
  }
  for (int x=0;x<n;x++) f[x][x]=1;
  int need=2*n+p;
  for (int x=1;x<=n;x++) {
    if (need<=0) break;
    for (int y=x+1;y<=n;y++) {
      if (need<=0) break;
      printf("%d %d\n",x,y);
      need--;
    }
  }
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; scanf("%d",&t);
  for (int i=0;i<t;i++) solve();
}

