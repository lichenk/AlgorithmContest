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
const ll INF=1e18;
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

const int mn=1e5+4;
const int mx=2e4+4;
vector<pii> x2v[mx];
pii vp[mn];
vector<pair<int,ld> > g[mn];
ld gdist(int a, int b) {
  ll dx=vp[a].fst-vp[b].fst;
  ll dy=vp[a].snd-vp[b].snd;
  return sqrt((ld)(dx*dx+dy*dy));
}

const int MAXSEG = 2*mn;  // limit for array size
int segn;  // array size
typedef pii S;
S t[2 * MAXSEG];
S identity = MP(INT_MAX,INT_MIN);
S combine(const S& lefts, const S& rights) {
  return MP(min(lefts.fst,rights.fst),max(lefts.snd,rights.snd));
}
void build(S *t) {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(S *t, int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(S *t, int l, int r) { // sum on interval [l, r]
  r++;
  if (l>r) r+=segn;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

ld vdist[mn];
typedef pair<ld,int> pfi;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) vp[i]=MP(rint(),rint());
  int gs=rint()-1,gt=rint()-1;
  segn=2*n;
  for (int i=0;i<2*n;i++) t[segn+i]=MP(vp[i].fst,vp[i].fst);
  build(t);
  for (int x=0;x<n;x++) {
    int y=x+1; if (y>=n) y=0;
    ld dist=gdist(x,y);
    g[x].PB(MP(y,dist));
    g[y].PB(MP(x,dist));
  }
  for (int i=0;i<n;i++) {
    int x=vp[i].fst,y=vp[i].snd;
    x2v[x+mx/2].PB(MP(y,i));
  }
  for (int x=-(mx/2)+1;x<(mx/2)-1;x++) {
    auto vv=x2v[x+mx/2];
    if (vv.size()==0) continue;
    sort(vv.begin(),vv.end());
    for (int i=0;i<vv.size()-1;i++) {
      int a=vv[i+1].snd;
      int b=vv[i].snd;
      printf("a:%d b:%d\n",a,b);
      int ay=vp[a].snd,by=vp[b].snd;
      if (a>b) {
        pii got=query(t,b,a);
        if (got.fst>=x) {
          g[a].PB(MP(b,abs(ay-by)));
        }
      }
      else {
        pii got=query(t,a,b);
        if (got.snd<=x) {
          g[a].PB(MP(b,abs(ay-by)));
        }
      }
    }
  }
  priority_queue<pfi,vector<pfi>,greater<pfi> > pq;
  for (int x=0;x<n;x++) vdist[x]=1e18;
  vdist[gs]=0; pq.push(MP(0,gs));
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    ld dist=got.fst; int x=got.snd;
    if (dist>vdist[x]) continue;
    if (gt==x) {
      printf("%.12f\n",(double)dist);
      return 0;
    }
    for (auto &gg:g[x]) {
      int y=gg.fst; ld cost=gg.snd;
      ld ndist=dist+cost;
      if (ndist<vdist[y]) {
        vdist[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
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