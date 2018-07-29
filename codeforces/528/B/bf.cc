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
map<ll,ll> h;
int vx[55],vw[55];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=0;i<n;i++) {
    vx[i]=readInt(),vw[i]=readInt();
  }
  int mz=1<<n;
  int final=0;
  for (int z=0;z<mz;z++) {
    bool ok=true;
    for (int x=0;x<n;x++) for (int y=0;y<x;y++) {
      if (z&(1<<x)) if (z&(1<<y)) {
        if (!(abs(vx[x]-vx[y])>=vw[x]+vw[y])) {
          //if (z==14) {
          //  printf("x:%d y:%d\n",x,y);
          //}
          ok=false;
        }
      }
    }
    if (ok) chkmax(final,__builtin_popcount(z));
  }
  printf("%d\n",final);
}

