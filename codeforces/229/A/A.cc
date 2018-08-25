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
const int mn=104;
const int mm=1e4+4;
string a[mn];
int f[mn][mm];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; cin>>n>>m;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) f[x][y]=INT_MAX;
  for (int x=0;x<n;x++) {
    int last=-1;
    for (int y=0;y<2*m;y++) {
      int yy=y; if (yy>=m) yy-=m;
      if (a[x][yy]=='1') last=y;
      if (last!=-1) chkmin(f[x][yy],abs(last-y));
    }
    last=-1;
    for (int y=2*m-1;y>=0;y--) {
      int yy=y; if (yy>=m) yy-=m;
      if (a[x][yy]=='1') last=y;
      if (last!=-1) chkmin(f[x][yy],abs(last-y));
    }
  }
  ll ans=LLONG_MAX;
  for (int y=0;y<m;y++) {
    ll cand=0;
    for (int x=0;x<n;x++) {
      cand+=f[x][y];
    }
    chkmin(ans,cand);
  }
  if (ans>=INT_MAX) {
    ans=-1;
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