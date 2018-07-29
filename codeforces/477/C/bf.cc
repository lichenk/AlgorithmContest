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
const int ms=24;
char s[ms];
typedef pair<int,int> pii;
pii f[ms][ms];
int vans[ms];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n",s,p);
  int m=strlen(p);
  buildfail(m);
  int n=strlen(s);
  int zlim=1<<n;
  for (int z=0;z<zlim;z++) {
    int ans=0;
    int t=0;
    for (int i=0;i<n;i++) {
      if (0==(z&(1<<i))) t=dfa(t,s[i]);
      if (t==m) {
        t=0; ans++;
      }
    }
    chkmax(vans[__builtin_popcount(z)],ans);
  }
  for (int r=0;r<=n;r++) {
    printf("%d ",vans[r]);
  }
  printf("\n");
}

