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
const int mz=1<<mn;
bitset<mn> a[mz][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint()-1,y=rint()-1;
    a[0][x][y]=1; a[0][y][x]=1;
  }
  for (int x=0;x<n;x++) a[0][x][x]=1;
  int zlim=(1<<n)-1;
  int want=n*n;
  int ans=n;
  int zans=zlim;
  for (int z=1;z<zlim;z++) {
    int zc=__builtin_popcount(z);
    if (zc>ans) continue;
    int s=__builtin_ffs(z)-1;
    int oz=z^(1<<s);
    int bitcnt=0;
    for (int x=0;x<n;x++) {
      if (x!=s&&a[oz][s][x]) {
        a[z][x]=a[oz][x]|a[oz][s];
      }
      else {
        a[z][x]=a[oz][x];
      }
      bitcnt+=a[z][x].count();
    }
    //printf("z:%d s:%d bitcnt:%d\n",z,s,bitcnt);
    if (bitcnt==want) {
      ans=zc;
      zans=z;
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