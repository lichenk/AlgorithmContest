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

static const int MXN = 200000;
static const int INF = 2147483647; // long long
int n,match[MXN],matched[MXN],vx[MXN],vy[MXN];
int neigh[MXN][2];
int edge[MXN][2],lx[MXN],ly[MXN],slack[MXN];
/*void init(int _n){
  n = _n;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      edge[i][j] = 0;
}*/
/*void add_edge(int x, int y, int w){ // long long
  edge[x][y] = w;
}*/
bool DFS(int x){
  vx[x] = 1;
  for (int t=0;t<2;t++){
    int y=neigh[x][t];
    if (vy[y]) continue;
    if (lx[x]+ly[y] > edge[x][t]){
      slack[y] = min(slack[y], lx[x]+ly[y]-edge[x][t]);
    } else {
      vy[y] = 1;
      if (match[y] == -1 || DFS(match[y])){
        match[y] = x;
        matched[x]=t;
        return true;
      }
    }
  }
  return false;
}
int solve(){
  fill(matched,matched+n,-1);
  fill(match,match+n,-1);
  fill(lx,lx+n,-INF);
  fill(ly,ly+n,0);
  for (int i=0; i<n; i++)
    for (int t=0;t<2;t++)
      lx[i] = max(lx[i], edge[i][t]);
  for (int i=0; i<n; i++){
    fill(slack,slack+n,INF);
    while (true){
      fill(vx,vx+n,0);
      fill(vy,vy+n,0);
      if ( DFS(i) ) break;
      int d = INF; // long long
      for (int j=0; j<n; j++)
        if (!vy[j]) d = min(d, slack[j]);
      for (int j=0; j<n; j++){
        if (vx[j]) lx[j] -= d;
        if (vy[j]) ly[j] += d;
        else slack[j] -= d;
      }
    }
  }
  int res=0;
  for (int i=0; i<n; i++)
    if (matched[i]!=-1) res += edge[i][matched[i]];
  return res;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m=rint(),w=rint();
  n=max(m,w);
  for (int x=0;x<w;x++) {
    int a=rint()-1,b=rint()-1,d=rint();
    neigh[x][0]=a;
    neigh[x][1]=b;
    edge[x][0]=d;
    edge[x][1]=d;
  }
  int ans=solve();
  printf("%d\n",ans);
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