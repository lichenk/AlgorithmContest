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
int memo[mc][mp];
char p[mp];
// Walk the KMP DFA from state j with letter x
int dfa(int j, char x) {
  int oldj = j;
  int z = x - 'a';
  if (memo[z][j] != -1) {
    return memo[z][j];
  }
  while (j > 0 && x != p[j]) {
    j = fail[j];
  }
  j++;
  memo[z][oldj] = j;
  return j;
}

// Build KMP failure table
void buildfail(int m)
{
  memset(memo,-1,sizeof memo);
  int j = 0;
  for (int i = 1; i <= m; i++) {
    fail[i] = j;
    while (j > 0 && p[i] != p[j]) {
      j = fail[j];
    }
    j++;
  }
  fail[m+1] = j;
}



class RmqSparseTable {

  int* logTable;
  int** rmq;
  int* a;
  int n;
  public:
  void init(int *_a, int _n) {
    a=_a;
    n=_n;

    logTable = new int[n + 1];
    fill(logTable,logTable+n+1,0);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    rmq = new int*[logTable[n] + 1];
    for (int i=0;i<logTable[n] + 1;i++) {
      rmq[i]=new int[n];
    }
    for (int i = 0; i < n; ++i)
      rmq[0][i] = i;

    for (int k = 1; (1 << k) < n; ++k) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        int x = rmq[k - 1][i];
        int y = rmq[k - 1][i + (1 << k - 1)];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }

  int minPos(int i, int j) {
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
  int minVal(int i, int j) {
    if (i>j) return INF;
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? a[x] : a[y];
  }
};

RmqSparseTable sparse[mc];

const int ms=2004;
char s[ms];
typedef pair<int,int> pii;
pii f[ms][ms];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n",s,p);
  int m=strlen(p);
  for (ll i = m-1; i>=0;i--) {p[i+1] = p[i];}
  p[0] = '$';
  buildfail(m);
  int n=strlen(s);
  for (int x=0;x<=n;x++) {
    for (int r=0;r<=n;r++) {
      f[x][r].fst=-1;
    }
  }
  for (int c=0;c<26;c++) {
    for (int t=1;t<=m;t++) {
      dfa(t,c+'a');
    }
    for (int t=1;t<=m;t++) {memo[c][t]=-memo[c][t];}
    sparse[c].init(memo[c],m+1);
  }
  f[0][0]=MP(0,1);
  for (int x=0;x<n;x++) {
    for (int r=0;r<=n;r++) {
      pii now=f[x][r];
      if (now.fst==-1) continue;
      //printf("x:%d r:%d occ:%d st:%d\n",x,r,now.fst,now.snd);
      chkmax(f[x+1][r+1],now);
      int occ=now.fst;
      int t=now.snd;
      int c=s[x]-'a';
      //printf("c:%d. %d to %d\n",c,max(0,t-r),t); fflush(stdout);
      int newstate=-sparse[c].minVal(max(1,t-r),t);
      if (newstate==m+1) {occ++; newstate=1;}
      //printf("%c (%d,%d) -> (%d,%d)\n",s[x],now.fst,now.snd,occ,newstate);
      chkmax(f[x+1][r], MP(occ,newstate));
    }
  }
  for (int r=0;r<=n;r++) {
    printf("%d ",f[n][r].fst);
  }
  printf("\n");
}

