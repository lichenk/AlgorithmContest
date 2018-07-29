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


const int mk=7;
const int mn=(1<<mk)+1;
int vl[mn],vr[mn];
ld vp[mn][mn];
ld dp[mn][mn];
int k,n;
ld f(int node, int player) {
  if (node>=n) return 1.0L;
  if (dp[node][player]>=-1) return dp[node][player];
  int ln=node*2; int rn=ln+1;
  if (player>vr[ln]) swap(ln,rn);
    ld A=f(ln,player);
    ld B=0;
    for (int q=vl[rn];q<=vr[rn];q++) {
      ld cand=f(rn,q);
      chkmax(B,cand);
    }
  ld ans=A+B;
  return dp[node][player]=ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  k = rint();
  n = 1 << k;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int p = rint();
      vp[x][y] = p / 100.0L;
    }
  }
  for (int node=n;node<2*n;node++) {
    vl[node]=vr[node]=node-n;
  }
  for (int node=n-1;node>=1;node--) {
    vl[node]=vl[node*2];
    vr[node]=vr[(node*2)+1];
  }
  for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) dp[x][y]=-2;
  ld final=0;
  for (int player=0;player<n;player++) {
    ld got=f(node,player);
    chkmax(final,got);
  }
  printf("%.15f\n",(double)final);
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