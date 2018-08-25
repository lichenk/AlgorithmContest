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
const int mn=102;
vector<int> g[2*mn];
bool seen[2*mn];
void dfs(int x) {
  if (seen[x]) return;
  seen[x]=1;
  for (auto &y:g[x]) {
    dfs(y);
  }
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  bool all0=true;
  for (int i=0;i<n;i++) {
    int k=rint();
    if (k>0) all0=false;
    for (int j=0;j<k;j++) {
      int l=rint()+mn;
      g[i].PB(l);
      g[l].PB(i);
    }
  }
  int ans=0;
  for (int x=0;x<n;x++) {
    if (!seen[x]) {dfs(x); ans++;}
  }
  if (all0) ans++;
  printf("%d\n",ans-1);

}

