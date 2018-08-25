#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=154;
int vt[2][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int xlim,ylim; cin>>xlim>>ylim;
  int hix=0;
  for (int x=0;x<xlim;x++) {
    string s; cin>>s;
    int lo=INT_MAX,hi=INT_MIN;
    for (int y=0;y<ylim;y++) {
      if (s[y]=='W') {
        chkmin(lo,y); chkmax(hi,y); hix=x;
      }
    }
    vt[1][x]=lo,vt[0][x]=hi;
  }
  ll ans=hix;
  int pos=0;
  for (int x=0;x<=hix;x++) {
    int t=x&1;
    {
      int target=vt[t][x];
      if (x+1<xlim) {
        if (t==0) chkmax(target,vt[t][x+1]);
        else chkmin(target,vt[t][x+1]);
      }
      if (target!=INT_MIN && target!=INT_MAX) {
        ans+=abs(target-pos);
        pos=target;
      }
    }
  }
  printf("%lld\n",ans);

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