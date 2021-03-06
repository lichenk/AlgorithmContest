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
const ll INF=1e15;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}

const int mn=1e5+4;
ll a[mn],dp[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),s=rint(),l=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  dp[0]=0;
  for (int i=1;i<=n;i++) dp[i]=INF;
  for (int i=1;i<=n;i++) {
    ll lo=INF,hi=-INF;
    ll ans=INF;
    ll take=0;
    for (int x=i-1;x>=0;x--) {
      chkmin(lo,a[x]); chkmax(hi,a[x]);
      if (hi-lo>s) {
        break;
      }
      take++;
      if (take>=l) {
        //printf("i:%d x:%d\n",i,x);
        chkmin(ans,dp[x]+1);
      }
    }
    dp[i]=ans;
  }
  ll ans=dp[n];
  if (ans>=INF) ans=-1;
  printf("%lld\n",ans);
}