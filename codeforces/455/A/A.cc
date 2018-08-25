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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int maxx=1e5+4;
ll vcnt[maxx];
ll dp[maxx];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint();
    vcnt[x]+=x;
  }
  memset(dp,-1,sizeof dp);
  dp[0]=0;
  for (int x=0;x<maxx;x++) {
    if (dp[x]==-1) continue;
    ll gain=vcnt[x];
    chkmax(dp[x+1],dp[x]);
    chkmax(dp[x+2],dp[x]+gain);
  }
  printf("%lld\n",dp[maxx-2]);
}

