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
const int UNDEF = -1;
const int INF=1e18;
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
const int mp=504,mc=26;
int fail[mp];
int memo[mp][mc];
char p[mp];
// Walk the KMP DFA from state j with letter x
int dfa(int k, char x) {
  for (; ; k = fail[k - 1]) {
    if (p[k] == x) {
      ++k;
      break;
    }
    if (k == 0)
      break;
  }
  return k;
}
// Build KMP failure table
void buildfail(int m) {
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k > 0 && p[k] != p[i])
      k = fail[k - 1];
    if (p[k] == p[i])
      ++k;
    fail[i] = k;
  }
}
const int ms=2004;
char s[ms];
typedef pair<int,int> pii;
pii f[ms][ms];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n",s,p);
  int m=strlen(p);
  buildfail(m);
  int n=strlen(s);
  for (int x=0;x<=n;x++) {
    for (int r=0;r<=n;r++) {
      f[x][r].fst=-1;
    }
  }
  f[0][0]=MP(0,0);
  for (int x=0;x<n;x++) {
    for (int r=0;r<=n;r++) {
      pii now=f[x][r];
      if (now.fst==-1) continue;
      chkmax(f[x+1][r+1],now);
      int occ=now.fst;
      int newstate=dfa(now.snd,s[x]);
      if (newstate==m) {occ++; newstate=0;}
      //printf("%c (%d,%d) -> (%d,%d)\n",s[x],now.fst,now.snd,occ,newstate);
      chkmax(f[x+1][r], MP(occ,newstate));
    }
  }
  for (int r=0;r<=n;r++) {
    printf("%d ",f[n][r].fst);
  }
  printf("\n");
}

