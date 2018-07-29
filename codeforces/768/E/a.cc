#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
//const ll lim=24;
//ll dp[lim][1<<(lim)];
ll f(ll x, ll msk) {
  if (x==0) return 0;
  //if (x-1<lim) {
  //  if (dp[x-1][msk]!=-1) return dp[x-1][msk];
  //}
  vector<ll> v;
  for (ll y=1;y<=x;y++) {
    if (msk&(1LL<<y)) continue;
    ll got=f(x-y,msk|(1LL<<y));
    v.PB(got);
    //printf("x:%lld msk:%lld y:%lld got:%lld\n",x,msk,y,got);
  }
  sort(v.begin(),v.end());
  ll nim=0;
  for (auto &w:v) {
    if (w==nim) nim++;
  }
  //if (x-1<lim) dp[x-1][msk]=nim;
  return nim;
}
int main()
{
  //memset(dp,-1,sizeof dp);
  for (ll x=0;x<60;x++) {
    printf("x:%lld nim:%lld\n",x,f(x,0));
  }
}

