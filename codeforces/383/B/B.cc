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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=1e5+4;
map<int, set<int> > h;
int n,m;
map<int,int> blockdown;
void down() {
  map<int,int> active[2];
  int cur=0,nxt=1;
  for (auto &w:h[1]) {
    chkmax(blockdown[w],1);
    active[cur][w]=w;
  }
  for (int y=2;y<=n;y++) {
    active[nxt].clear();
    for (auto &w:active[cur]) {
      int x=w.fst;
      chkmax(blockdown[x],y);
      for (int nx=x-1;nx<=x+1;nx++) {
        if (h[y+1].count(nx)) {
          active[nxt][nx]=max(nx,w.snd);
        }
      }
    }
    swap(cur,nxt);
  }
}
map<int,int> blockup;
map<int,int> dp[mn];
int up(int x, int y) {
  auto it=dp[y].find(x);
  if (it!=dp[y].end()) return it->snd;
  int ans=x;
  for (int nx=x-1;nx<=x+1;nx++) {
    if (h[y+1].count(nx)) {
      int got=up(nx,y+1);
      chkmax(ans,got);
    }
  }
  chkmin(blockup[x],y);
  dp[y][x]=ans;
  return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++) {
    int x,y; scanf("%d%d",&x,&y);
    h[y].insert(x);
  }
  for (int x=0;x<=n;x++) blockup[x]=n+1;
  down();
  for (auto &x:h[n]) {
    up(x,n);
  }
  for (int x=1;x<=n;x++) chkmax(blockdown[x],blockdown[x-1]);
  for (int x=n-1;x>=0;x--) chkmin(blockup[x],blockup[x+1]);
  bool ok=1;
  for (int x=0;x<=n;x++) {
    //printf("x:%d bd:%d bu:%d\n",x,blockdown[x],blockup[x]);
    if (blockdown[x]>=blockup[x]-1) {ok=0; break;}
  }
  if (ok) {
    printf("%d\n",2*(n-1));
  }
  else {
    printf("-1\n");
  }
}
