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
set<int> g[mn];
int gsz[mn];
priority_queue<pii,vector<pii>,greater<pii> > pq;
void rm(int x, int y) {
  //printf("rm:%d %d\n",x,y);
  //fflush(stdout);
  assert(gsz[x]==(int)g[x].size());
  g[x].erase(y);
  gsz[x]--;
  assert(gsz[x]==(int)g[x].size());
  assert(gsz[y]==(int)g[y].size());
  g[y].erase(x);
  gsz[y]--;
  assert(gsz[y]==(int)g[y].size());
  if (gsz[x]>0) pq.push(MP(gsz[x],x));
  if (gsz[y]>0) pq.push(MP(gsz[y],y));
}
vector<int> tree[mn];
bool seen[mn];
void dfs1(int x) {
  seen[x]=1;
  for (auto &y:g[x]) {
    if (!seen[y]) {
      tree[x].PB(y);
      parent[y]=x;
      dfs1(y);
    }
  }
}
void dfs2(int x, int p) {
  for (auto &y:tree[x]) {
    dfs2()
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  if (m&1) {
    printf("No solution\n"); return 0;
  }
  for (int i=0;i<m;i++) {
    int x=readInt(),y=readInt();
    g[x].insert(y);
    g[y].insert(x);
  }
  for (int x=1;x<=n;x++) {
    gsz[x]=g[x].size();
    pq.push(MP(gsz[x],x));
  }
  parent[1]=-1;
  dfs1(1);

}
