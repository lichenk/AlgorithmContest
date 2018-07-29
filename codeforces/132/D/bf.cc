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
const int mn=1e6+4;
int f[mn][2];
void reset(int cur) {
  f[cur][0]=INF; f[cur][1]=INF;
}
int vans[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string a; cin>>a;
  int n=a.length()+1;
  int targ=0;
  for (auto &w:a) {
    targ*=2;
    targ+=(w-'0');
  }
  int zlim=1; for (int i=0;i<n;i++) zlim*=3;
  int ans=INF;
  for (int tz=0;tz<zlim;tz++) {
    int z=tz;
    int res=0;
    int cnt=0;
    for (int i=0;i<n;i++) {
      res*=2;
      int got=(z%3)-1;
      if (got!=0) cnt++;
      res+=got;
      //if (tz==14) printf("got:%d res:%d\n",got,res);
      z/=3;
    }
    //if (tz==14) printf("res:%d %d\n",res,targ);
    if (res==targ) {
      chkmin(ans,cnt);
    }
  }
  printf("%d\n",ans);
}
