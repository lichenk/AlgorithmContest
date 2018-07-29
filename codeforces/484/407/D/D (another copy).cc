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
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
const int maxn=400;
const int maxv=400*400;
int vcnt[maxv];
int a[maxn][maxn];
int n,m;
bool solve(int dx,int dy) {
  int dup=0;
  for (int y=0;y<m-dy;y++) {
    for (int x=0;x<n-dx;x++) {
      vcnt[x][y]++;
      if (vcnt[x][y]==2) dup++;
    }
    for (int x=1;x<n-dx;x++) {
      
    }
  }
  for (int x=0;x<n-dx;x++) {
    for (int y=0;y<dy;y++) {
      vcnt[x][y]++;
      if (vcnt[x][y]==2) dup++;
    }
    for (int y=1;y<m-dy;y++) {
      for (int )
    }
  }
  return false;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt(),m=readInt();
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    a[x][y]=readInt()-1;
  }
  int imin=0,imax=n*m+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    int slim=min(round(sqrt(imid))+1,imid-1);
    set<int> divs;
    for (int d=1;d<=slim;d++) {
      if (slim%d==0) {divs.insert(slim/d); divs.insert(d);}
    }
    bool ok=0;
    for (auto &w:divs) {
      if (solve(w,slim/w)) {ok=1;break;}
    }
    if (ok) imin=imid+1;
    else imax=imid;
  }
  printf("%d\n",imin);
}

