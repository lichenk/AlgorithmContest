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
bool a[mz][mz];
int bf_n;
int bf(int start, int now, int state) {
  int n=bf_n;
  for (int x=0;x<n;x++) {
    if ((1<<x)&state) continue;
    
  }
}

bool adj[7][7];
vector<pii> bf(int n, int wante) {
  for (int x=1;x<=n;x++) for (auto &y:g[x]) {
    adj[x-1][y-1]=true;
    adj[y-1][x-1]=true;
  }
  vector<pii> edges;
  for (int x=0;x<n;x++) for (int y=0;y<x;y++) edges.PB(MP(x,y));
  int es=edges.size();
  int zlim=1<<es;
  for (int z=0;z<zlim;z++) {
    if (__builtin_popcount(z)!=wante) continue;
    bool ok=1;
    for (int e=0;e<es;e++) {
      if (0!=(z&(1<<e))&&adj[e.fst][e.snd]) {ok=0; break;}
    }
    if (ok) {
      for (int e=0;e<es;e++) {
        if (0!=(z&(1<<e))) {
          printf("%d %d\n",edges[e].fst+1,edges[e].snd+1);
          exit(0);
        }
      }
    }
  }
  printf("-1\n");
  exit(0);
}

const int mn=1e5+4;
vector<int> g[mn];

vector<pii> vans;
bool seen[mn];
vector<int> have;
void dfs(int x) {
  if (seen[x]) return;
  seen[x]=true;
  have.PB(x);
  for (auto &y:g[x]) {
    dfs(y);
  }
}
vector<vector<int> > comp[5];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int nn=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  if (nn<=7) bf();
  vector<int> fcomp;
  bool fc=true;
  for (int x=1;x<=nn;x++) {
    if (!seen[x]) {
      dfs(x);
      int k=have.size();
      vector<int> vcomp;
      if (k>=5) {
        if (k&1) {
          for (int t=0,i=0;i<k;i++,t=(t+2)%k) {
            vcomp.PB(have[t],have[(t+2)%k]);
          }
        }
        else {
          int t=0;
          for (int i=0;i<k;i++) {
            int nt;
            if (t==0) nt=k/2;
            else if (t<n/2) nt=k-t;
            else nt=(k-t)+1;
            vcomp.PB(have[t],have[nt]);
            t=nt;
          }
        }
        if (fc) {
          fcomp=vcomp;
          fc=false;
        }
        else {
          for (auto &w:vcomp) vans.PB(w);
        }
      }
      else {
        comp[k].PB(have);
      }
      have.clear();
    }
  }
  for (int )
}
