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
const int mn=54;
ll a[mn];
ll rem[mn];
ll dp[mn];
int n;
ll f(int x) {
  if (x==n) return 0;
  if (dp[x]!=-1) return dp[x];
  ll cand1=a[x]+rem[x+1]-f(x+1);
  ll cand2=f(x+1);
  return max(cand1,cand2);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  for (int i=0;i<n;i++) cin>>a[i];
  rem[n]=0;
  for (int i=n-1;i>=0;i--) rem[i]=rem[i+1]+a[i];
  memset(dp,-1,sizeof dp);
  ll ans=f(0);
  ll A=rem[0]-ans,B=ans;
  printf("%lld %lld\n",A,B);
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