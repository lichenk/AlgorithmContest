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
const int mn=5002;
int a[mn];
int b[mn];
int f[mn][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); for (int i=0;i<n;i++) a[i]=rint();
  for (int l=0;l<n;l++) {
    for (int x=0;x<n-l;x++) {
      f[x][x+l]=a[x];
    }
    for (int x=0;x<n-l;x++) b[x]=a[x]^a[x+1];
    memcpy(a,b,sizeof a);
  }
  for (int l=1;l<n;l++) {
    for (int x=0;x<n;x++) {
      int y=x+l;
      if (y>=n) break;
      chkmax(f[x][y],max(f[x+1][y],f[x][y-1]));
    }
  }
  int q=rint();
  for (int i=0;i<q;i++) {
    int l=rint(),r=rint();
    --l;--r;
    printf("%d\n",f[l][r]);
  }
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