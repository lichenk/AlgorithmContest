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

const int mn=20+4;

int c[mn];
int vl[mn],vr[mn],vp[mn];
bitset<mn> b;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  int m=rint();
  for (int x=1;x<=n;x++) c[x]=rint();
  for (int i=0;i<m;i++) {
    vl[i]=rint(),vr[i]=rint(),vp[i]=rint();
  }
  ll final=0;
  for (int z=0;z<(1<<m);z++) {
    b.reset();
    ll ans=0;
    for (int i=0;i<m;i++) {
      if (z&(1<<i)) {
        ans+=vp[i];
        for (int x=vl[i];x<=vr[i];x++) b[x]=true;
      }
    }
    for (int x=1;x<=n;x++) {
      if (b[x]) ans-=c[x];
    }
    chkmax(final,ans);
  }
  printf("%lld\n",final);
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