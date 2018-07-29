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
const int mn=22;
vector<int> g[mn];
bool rev[mn][mn];
int n;
bitset<mn> seen;
void dfs(int x, int p) {
  seen[x]=true;
  for (auto &y:g[x]) {
    if (y==p) continue;
    if (!rev[x][y]) dfs(y,x);
  }
  return;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  vector<pii> ve;
  for (int i=0;i<n-1;i++) {
    int a=rint()-1,b=rint()-1;
    ve.PB(MP(a,b));
    rev[b][a]=1;
    g[a].PB(b); g[b].PB(a);
  }
  int final=1<<30;
  int zlim=1<<(n-1);
  for (int z=0;z<zlim;z++) {
    for (int ei=0;ei<n-1;ei++) {
      int a=ve[ei].fst,b=ve[ei].snd;
      if (z&(1<<ei)) {
        rev[b][a]=0;
        rev[a][b]=1;
      }
      else {
        rev[b][a]=1;
        rev[a][b]=0;
      }
    }
    bool ok=0;
    for (int x=0;x<n;x++) {
      for (int y=0;y<x;y++) {
        seen.reset();
        dfs(x,-1);
        dfs(y,-1);
        if (seen.count()==n) {
          ok=1;
          chkmin(final,__builtin_popcount(z));
          break;
        }
      }
      if (ok) break;
    }
  }
  if (n==1) final=0;
  printf("%d\n",final);
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