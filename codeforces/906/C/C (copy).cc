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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=22;
int a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int x=0;x<n;x++) a[x]=1<<x;
  for (int i=0;i<m;i++) {
    int x=rint()-1,y=rint()-1;
    a[x]|=1<<y; a[y]|=1<<x;
  }
  if (m==(n*(n-1))/2) {
    printf("0\n"); exit(0);
  }
  int zlim=(1<<n);
  int zans=zlim-1,ans=n;
  for (int z=1;z<zlim;z++) {
    int zc=__builtin_popcount(z);
    if (zc>=ans) continue;
    int got=0;
    for (int x=0;x<n;x++) {
      if ((1<<x)&z) got|=a[x];
    }
    //printf("z:%d got:%d\n",z,got);
    if (got==zlim-1) {
      zans=z;ans=zc;
    }
  }
  printf("%d\n",ans);
  for (int x=0;x<n;x++) if (zans&(1<<x)) printf("%d ",x+1);
  printf("\n");
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