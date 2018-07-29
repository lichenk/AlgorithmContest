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
int final=0;
int n,m;
vector<string> _vsig[]={
{
"###",
".#.",
".#."}
,
{
"..#",
"###",
"..#"}
,
{
".#.",
".#.",
"###"}
,
{
"#..",
"###",
"#.."}
};
bool vsig[4][3][3];
clock_t start;
void dfs(bitset<81> inp) {
  chkmax(final,(int)inp.count());
  clock_t now = clock();
  /*if (now-start > 0.4 * CLOCKS_PER_SEC) {
    printf("%d\n",final); exit(0);
  }*/
  for (int k=0;k<4;k++) {
    bool kdone=0;
    for (int x=0;x<=n-3;x++) {
      for (int y=0;y<=m-3;y++) {
        bool ok=1;
        for (int a=0;a<3;a++) for (int b=0;b<3;b++) {
          if (vsig[k][a][b]) {
            if (inp[(x+a)*9+(y+b)]) {
              ok=0; a=100; break;
            }
          }
        }
        if (ok) {
          bitset<81> got=inp;
          for (int a=0;a<3;a++) for (int b=0;b<3;b++) {
            got[(x+a)*9+(y+b)]=got[(x+a)*9+(y+b)]||vsig[k][a][b];
          }
          dfs(got);
          x=100;
          break;
        }
      }
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int k=0;k<4;k++) {
    for (int a=0;a<3;a++) for (int b=0;b<3;b++) {
      vsig[k][a][b]=(_vsig[k][a][b]=='#');
    }
  }
  cin>>n>>m;
  bitset<81> inp; inp.reset();
  dfs(inp);
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