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
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1e3+4;
int dp[mn][mn];
int p[mn];
int f(int x, int y) {
  int dpv=dp[x][y];
  if (dpv!=-1) return dpv;
  int ans;
  if (x==y) ans=0;
  else {
    ans=f(x,y-1)+f(p[y-1],y-1)+2;
    ans%=MOD;
  }
  //printf("x:%d y:%d ans:%d\n",x,y,ans);
  return dp[x][y]=ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
	int n=rint();
  for (int x=1;x<=n;x++) p[x]=rint();
  int ans=f(1,n+1);
  printf("%d\n",ans);
}
