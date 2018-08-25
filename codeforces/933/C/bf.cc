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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

int vx[3],vy[3],vr2[3];
const int C=309;
const int lo=-20*C-4,hi=20*C+4;
int final=0;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    vx[i]=rint()*C;
    vy[i]=rint()*C;
    int r=rint()*C;
    vr2[i]=r*r;
  }
  for (int x=lo;x<=hi;x++) {
    for (int y=lo;y<=hi;y++) {
      int sig=0;
      for (int i=0;i<n;i++) {
        int dx=x-vx[i];
        int dy=y-vy[i];
        int r2=dx*dx+dy*dy;
        int ar2=vr2[i];
        if (r2<ar2) sig|=1<<i;
        else if (r2==ar2) {sig=0; break;}
      }
      final|=1<<sig;
    }
  }
  int ans=__builtin_popcount(final);
  printf("%d\n",ans);
}





inline int rint()
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