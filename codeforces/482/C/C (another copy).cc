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

int svec[50];

int zvec[20];

char s[50][22];
ld f[1<<20];
ll g[1<<20];
ll gstate[20];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int snum; scanf("%d",&snum);
  for (int i=0;i<snum;i++) {
    scanf("%s\n",s[i]);
  }
  ld final=0;
  int len=strlen(s[0]);
  for (int ans=0;ans<snum;ans++) { // 50
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    for (int p=0;p<len;p++) {
      ll state=0;
      for (int sidx=0;sidx<snum;sidx++) {
        if (s[sidx][p]==s[ans][p]) state|=1LL<<sidx;
      }
      gstate[p]=state;
    }
    f[0]=1;
    g[0]=(1LL<<snum)-1;
    int zlim=1<<len;
    for (int z=0;z<zlim;z++) { // 2**20
      ll gsig;
      if (z==0) {
        gsig=g[z];
      }
      else {
        int p=__builtin_ffs(z)-1;
        gsig=g[z^1<<p]&gstate[p];
      }
      g[z]=gsig;
      if (gsig==0) continue;
      if (!(gsig & (gsig - 1))) {
        final+=f[z]*__builtin_popcount(z);
        continue;          
      }
      // Transition f
      ld fadder=f[z]/(len-__builtin_popcount(z));
      for (int p=0;p<len;p++) { // 10
        int pmsk=1<<p;
        f[(1<<p)|z]+=fadder;
      }
    }
  }
  final/=snum;
  printf("%.10f\n",final);
}

