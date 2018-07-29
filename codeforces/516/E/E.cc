#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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
const int mn=100*1000*1000;
bitset<mn> hb,hg;
int main()
{
	time_t start=clock();
	int n=readInt(),m=readInt();
  int b=readInt();
  for (int i=0;i<b;i++) {
    hb[i]=1;
  }
  int g=readInt();
  for (int i=0;i<g;i++) {
    hg[i]=1;
  }
  int left=n+m-b-g;
  int ni=0,mi=0;
  for (ll t=0;;t++) {
    if (t&0xf==0) {
      if (clock()-start>3.5*CLOCKS_PER_SEC) {
        printf("-1\n");
        return 0;
      }
    }
    if (hb[ni]!=hg[mi]) {
      hb[ni]=1;
      hg[mi]=1;
      --left;
    }
    if (left==0) {
      printf("%lld\n",t);
      return 0;
    }
    ni++;if(ni==n) ni=0;
    mi++;if(mi==m) mi=0;
  }
}

