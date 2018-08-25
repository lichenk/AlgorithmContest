#include "bits/stdc++.h"
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
//const ll UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int maxn=1e5+4;
int vbad[maxn];
vector<int> g[maxn];
int dfs(int x, int p, int l) {
  if (l<0) return 0;
  int ans=0;
  if (vbad[x]) ans++;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=dfs(y,x,l-1);
  }
  return ans;
}
int rint();char rch();long long rlong();
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();int gd=rint();
  for (int x=1;x<=m;x++) {
    int bad=rint();
    vbad[bad]=true;
  }
  for (int i=1;i<n;i++) {
    int a=rint(),b=rint();
    g[a].PB(b); g[b].PB(a);
  }
  int final=0;
  for (int x=1;x<=n;x++) {
    if (dfs(x,-1,gd)>=m) final++;
  }
  printf("%d\n",final);
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