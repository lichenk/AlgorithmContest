#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
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

int vec[50];

char s[50][22];
ld f[1<<20][50];
ll g[1<<20][50];



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int snum; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%d",s[i]);
  }
  int len=strlen(s[0]);
  f[0][0]=1;
  g[0][0]=(1LL<<snum)-1;
  int zlim=1<<len;
  for (int z=0;z<zlim;z++) { // 2**20
    for (int first=0;first<snum;first++) { // numfirst
      ll gsig=g[z][first];
      if (gsig==0) continue;
      int vecsz=0;
      for (int sidx=0;sidx<snum;sidx++) {
        if ((1LL<<sidx)&gsig) vec[vecsz++]=sidx;
      }
      for (int p=0;p<slen;p++) { // Around 10
        if ((1<<p)&z) continue;
        for (int vecpos=0;vecpos<vecsz;vecpos++) { // 50/numfirst

        }
      }
    }
  }
}

