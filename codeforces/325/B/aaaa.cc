#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 lld;
typedef long double nld;
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
lld EPS=1e-3;
int rint();char rch();long long rlong();

lld quadratic(lld a, lld b, lld c) {
  lld imin=0,imax=31622+5;
  for (int k=0;k<95;k++) {
    lld imid=(imin+imax)/2;
    lld res=a*imid*imid+b*imid+c;
    if (res<-EPS) imin=imid;
    else imax=imid;
  }
  return imin;
  /*lld det=b*b-4*a*c;
  if (det<0) return -2;
  lld ans=(-b+sqrt((ld)det))/(2*a);
  return ans;*/
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  set<ll> vans;
  for (ll x=1;;x+=2) {
    ll A=(x*(x-1))/2;
    if (A>n) break;
    for (int k=0;k<=62;k++) {
      ll prod;
      bool ovf = __builtin_smulll_overflow((1LL << k) - 1, x, &prod);
      if (!ovf) {
        ll sol;
        bool ovf2=__builtin_saddll_overflow (A,prod,&sol);
        if (ovf2==false&&sol == n) {
          ll prod3;
          bool ovf3=__builtin_smulll_overflow((1LL << k), x, &prod3);
          if (!ovf3) {
            vans.insert(prod3);
          }
        }
      }
    }
  }
  //sort(vans.begin(),vans.end());
  if (vans.size()==0) {
    printf("-1\n"); return 0;
  }
  //ll prev=-1;
  for (auto &w:vans) {
    printf("%lld\n",w);
    //prev=w;
  }
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

int rint()
{
    readAhead(16);

    int x = 0;
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