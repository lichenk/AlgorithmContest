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
const int mn=1e5+4;
ll a[mn];
int n;
ll vans[mn];
ll solve1() {
  memset(vans,0,sizeof vans);
  ll final=0;
  ll prev=0;
  for (int i=n-2;i>=0;i--) {
    ll c=a[i];
    if (c==0) {
      prev=0;
      continue;
    }
    ll cand=c+prev;
    chkmax(final,cand);
    ll best1=c;
    ll d=c; if (d%2==0) d--;
    ll best2=0;
    if (d>=1) {
      best2=prev+d;
    }
    ll best=max(best1,best2);
    vans[i]=best;
    chkmax(prev,best);
  }
  return final;
}
ll solve2() {
  ll final=0;
  ll u=0;
  for (int i=0;i<n-2;i++) {
    ll x=a[i];
    if (x>=2) {
      ll inc=x;
      if (inc&1) inc--;
      u+=inc;
    }
    else u=0;
    ll cu=u;
    if (x&1) cu++;
    ll cand=cu+vans[i+1];
    /*if (cand==6) {
      for (int i=0;i<n-1;i++) printf("%d ",a[i]);
      printf("\n");
      printf("i:%d cu:%lld vans:%lld\n",i,cu,vans[i+1]);
    }*/
    //printf("i:%d cu:%lld vans:%lld\n",i,cu,vans[i+1]);
    chkmax(final,cand);
  }
  return final;
}
ll solve() {
  ll s1=solve1();
  return max(s1,solve2());
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int x=0;x<n-1;x++) a[x]=rint();
  ll b1=solve();
  reverse(a,a+n-1);
  ll b2=solve();
  ll bb=max(b1,b2);
  printf("%lld\n",bb);
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