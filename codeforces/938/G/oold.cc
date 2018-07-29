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

struct basis
{
    static const int MAXLOG = 30;
    int32_t base[MAXLOG];

    void clear()
    {
      memset(base,0,sizeof base);
    }

    void add(int32_t val)
    {
      for(int i = MAXLOG - 1; i >= 0; i--) {
        if((val >> i) & 1)
        {
          if(!base[i]) { base[i] = val; return; }
          else val ^= base[i];
        }
      }
    }

    int32_t min_xor(int32_t seed)
    {
      int32_t res = seed;
      for(int i = MAXLOG-1; i >= 0; i--) {
        if(((res >> i) & 1) && base[i]) {res ^= base[i];}
      }
      return res;
    }

};
const int mn=200000+1;
const int me=200000*2;
const int ms=sqrt(mn)+1;
int vsrc[me],vdest[me],ved[me];
bitset<me> vee;
int es=0;
vi og[mn];
map<int,int> e2i[mn];
/*void ae(map<int,int> *g,int x,int y,int d) {
  g[x][y]=d; g[y][x]=d;
}
void rm(map<int,int> *g,int x, int y) {
  g[x].erase(y); g[y].erase(x);
}*/
int rege(int x, int y, int d) {
  if (x>y) swap(x,y);
  vsrc[es]=x;vdest[es]=y;ved[es]=d; 
  e2i[x][y]=es;
  return es++;
}
void ae(int ei) {
  int x=vsrc[ei],y=vdest[ei];
  og[x].PB(ei);
  og[y].PB(ei);
  vee[ei]=true;
}
int gei(int x, int y) {
  auto it=e2i[x].find(y);
  if (it==e2i[x].end()) return -1;
  return it->snd;
}
int vid[mn];
int a[mn];
struct basis bb;
int dfsid;
void dfs(int x, int val) {
  if (a[x]!=-1) {
    if (val!=a[x]) bb.add(val^a[x]);
    return;
  }
  a[x]=val;
  vid[x]=dfsid;
  for (auto &ei:og[x]) {
    if (!vee[ei]) continue;
    int y=(x==vsrc[ei])?vdest[ei]:vsrc[ei];
    int nv=val^ved[ei];
    dfs(y,nv);
  }
}
int n;
int gid;
//int pcnt=0;
void prepare() {
  //pcnt++;
  bb.clear();
  memset(a,-1,sizeof a);
  dfsid=0;
  for (int x=1;x<=n;x++) {
    if (a[x]==-1) {
      dfs(x,0); dfsid++;
    }
  }
}
int aa[ms];
vector<pii> p[ms];
vi offei;
struct basis b;
void dfs2(int x, int val) {
  if (aa[x]!=-1) {
    if (val!=aa[x]) b.add(val^aa[x]);
    return;
  }
  aa[x]=val;
  //printf("dfs2 x:%d val:%d\n",x,val);
  for (auto &w:p[x]) {
    int y=w.fst;int nv=val^w.snd;
    dfs2(y,nv);
  }
}

int query(const vi &ve, int offeilo, int qx, int qy) {
  memcpy(b.base,bb.base,sizeof bb.base);
  for (int x=0;x<ms;x++) p[x].clear();
  for (auto &ei:ve) {
    int x=vsrc[ei],y=vdest[ei],d=ved[ei];
    int xid=vid[x],yid=vid[y];
    if (xid==yid) {
      b.add(d^a[x]^a[y]);
    }
    else {
      p[xid].PB(MP(yid,d^a[x]^a[y]));
      p[yid].PB(MP(xid,d^a[x]^a[y]));
    }
  }
  for (int i=offei.size()-1;i>=offeilo;i--) {
    int ei=offei[i];
    int x=vsrc[ei],y=vdest[ei],d=ved[ei];
    int xid=vid[x],yid=vid[y];
    if (xid==yid) {
      b.add(d^a[x]^a[y]);
    }
    else {
      p[xid].PB(MP(yid,d^a[x]^a[y]));
      p[yid].PB(MP(xid,d^a[x]^a[y]));
    }
  }
  memset(aa,-1,sizeof aa);
  dfs2(0,0);
  int seed=aa[vid[qx]]^aa[vid[qy]]^a[qx]^a[qy];
  //printf("qx:%d a[qx]:%d\n",qx,a[qx]);
  int ans=b.min_xor(seed);
  //printf("seed:%d ans:%d. %d %d %d %d.\n",seed,ans,aa[vid[qx]],aa[vid[qy]],a[qx],a[qy]);
  return ans;
}
int vx[mn],vy[mn],vt[mn],qei[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(),d=rint();
    ae(rege(x,y,d));
  }
  int qn=rint();
  for (int i=0;i<qn;i++) {
    int t=rint(); vt[i]=t;
    int x=rint(); int y=rint();
    //printf("t:%d x:%d y:%d\n",t,x,y);
    if (x>y) swap(x,y);
    if (t==1) {
      int d=rint();
      qei[i]=rege(x,y,d);
      //printf("x:%d y:%d d:%d\n",x,y,d);
    }
    else if (t==2) {
      //printf("x:%d y:%d\n",x,y); fflush(stdout);
      qei[i]=gei(x,y);
    }
    else {
      vx[i]=x; vy[i]=y;
    }
  }
  for (int qb=0;qb<qn;qb+=ms) {
    int qlim=min(qb+ms,qn);
    offei.clear();
    for (int qi=qb;qi<qlim;qi++) {
      if (vt[qi]==2) {
        int ei=qei[qi];
        if (vee[ei]) {vee[ei]=false; offei.PB(ei);}
      }
    }
    prepare();
    for (auto &ei:offei) {vee[ei]=true;}
    vi vadd;
    int offeilo=0;
    for (int qi=qb;qi<qlim;qi++) {
      if (vt[qi]==1) {
        int ei=qei[qi];
        ae(ei);
        vadd.PB(ei);
      }
      else if (vt[qi]==2) {
        int ei=qei[qi]; vee[ei]=false;
        offeilo++;
      }
      else {
        int ans=query(vadd,offeilo,vx[qi],vy[qi]);
        printf("%d\n",ans);
      }
    }
  }
  //printf("FINAL:%d\n",pcnt);
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