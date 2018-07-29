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
int n;
int ovx[3],ovy[3],ovr2[3];
int vx[3],vy[3],vr2[3];
int solve1() {
  const int C=250;
  const int lo=-20*C,hi=20*C;
  for (int i=0;i<n;i++) {
    vx[i]=ovx[i]*C;
    vy[i]=ovy[i]*C;
    vr2[i]=ovr2[i]*C*C;
  }
  int final=0;
  for (int x=lo;x<=hi;x++) {
    for (int y=lo;y<=hi;y++) {
      int sig=0;
      for (int i=0;i<n;i++) {
        int dx=x-vx[i];
        int dy=y-vy[i];
        int r2=dx*dx+dy*dy;
        int ar2=vr2[i];
        if (r2<ar2) sig|=1<<i;
      }
      final|=1<<sig;
    }
  }
  int ans=__builtin_popcount(final);
  return ans;
}
int solve2() {
  const int C=147;
  const int lo=-20*C,hi=20*C;
  for (int i=0;i<n;i++) {
    vx[i]=ovx[i]*C;
    vy[i]=ovy[i]*C;
    vr2[i]=ovr2[i]*C*C;
  }
  int final=0;
  for (int x=lo;x<=hi;x++) {
    for (int y=lo;y<=hi;y++) {
      int sig=0;
      for (int i=0;i<n;i++) {
        int dx=x-vx[i];
        int dy=y-vy[i];
        int r2=dx*dx+dy*dy;
        int ar2=vr2[i];
        if (r2<ar2) sig|=1<<i;
      }
      final|=1<<sig;
    }
  }
  int ans=__builtin_popcount(final);
  return ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {
    ovx[i]=rint();
    ovy[i]=rint();
    int r=rint();
    ovr2[i]=r*r;
  }
  int ans=max(solve1(),solve2());
  printf("%d\n",ans);
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

inline int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}