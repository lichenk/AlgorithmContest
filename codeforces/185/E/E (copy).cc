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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1e5+4;
int dx[mn],dy[mn],sx[mn],sy[mn];
int n,k;

struct Point{
  int dist;
  int t;
  int id;
  Node(int dist, int t, int id): dist(dist), t(t), id(id), {}
  bool operator < (Node b)const{
    // MUST reverse since priority_queue is a max-heap.
    // Do not just do !(a<b). This function must return false for equality.
    return dist>b.dist;
  }
};
const int D=0,S=1;
int vdist[2][mn];
void dij() {
  priority_queue<Node,vector<Node>,greater<Node> > pq;
  for (int t=0;t<2;t++) for (int x=0;x<mn;x++) vdist[t][x]=INT_MAX;
  for (int x=0;x<k;x++) {
    vdist[S]=0;
    pq.push(Node(0,S,x));
  }
  while(!pq.empty()) {
    auto &got=pq.top(); pq.pop();
    int dist=got.dist; int t=got.t; int id=got.id;
    if (dist>vdist[t][id]) continue;
    for (auto &gg:g[x]) {
      int y=gg.fst,cost=gg.snd;
      int ndist=dist+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
}
bool f(int imid) {
  for (int i=0;i<n;i++) {
    int lx=dx[i]
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();k=rint();
  for (int i=0;i<n;i++) {
    int px=rint(),py=rint();
    int x=px-py;
    int y=py+px;
    dx[i]=x,dy[i]=i;
  }
  for (int i=0;i<k;i++) {
    int px=rint(),py=rint();
    int x=px-py;
    int y=py+px;
    sx[i]=x,sy[i]=i;
  }
  int imin=0,imax=(4e8)+4;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (!f(imid*2)) imin=imid+1;
    else imax=imid;
  }

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