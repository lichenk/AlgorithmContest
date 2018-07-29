#include <bits/stdc++.h>
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
const int HI=2*1000*1000*1000;
const int BASE=1000*1000*1000;
int rint();char rch();long long rlong();
const int mn=1e5+2;
template <typename LST> struct LimitedVec  {
  LST a[mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
  int size() {
    return sz;
  }
  LST operator [](int i) const    {return a[i];}
  LST & operator [](int i) {return a[i];}
};
/*struct LimitedVecUniqueIteration  {
  int a[mn];
  int vts[mn];
  int sz;
  int ts=1;
  void push_back(int val) {
    a[sz++]=val;
  }
  int * begin()
  {
    return &a[0];
  }
  int * end()
  {
    return &a[sz];
  }
  bool use_x(int x) {
    if (vts[x]==ts) return false;
    vts[x]=ts;
    return true;
  }
  void clear() {
    sz=0;
    ts++;
  }
};*/
LimitedVec<pair<int,pii> > v;
//LimitedVecUniqueIteration torm;
int mx=
int vl[mn],vr[mn],vh[mn],dp[mn];
map<int,int> g;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),t=rint();
  for (int i=0;i<n;i++) {
    int h=rint(),l=rint()+BASE,r=rint()+BASE;
    v.PB(MP(-h,MP(l,r)));
  }
  v.PB(MP(-t,MP(0,HI)));
  v.PB(MP(-0,MP(0,HI)));
  sort(v.begin(),v.end());
  int vsz=v.size();
  for (int id=0;id<vsz;id++) {
    auto &w=v[id];
    vh[id]=w.fst;
    vl[id]=w.snd.fst;
    vr[id]=w.snd.snd;
  }
  int lasth=t;
  g[0]=0;
  g[HI]=0;
  dp[0]=HI;
  for (int id=1;id<vsz;id++) {
    int h=vh[id],l=vl[id],r=vr[id];
    if (h!=lasth) {
      for (auto &yid:torm) {
        g.erase(vl[yid]); g.erase(vr[yid]);
      }
      torm.clear();
    }
    for (auto it=g.lower_bound(l+1);it!=g.end();++it) {
      //int x=it->fst;
      int yid=it->snd;
      int overlap=min(vr[yid],r)-max(vl[yid],l);
      if (overlap<=0) break;
      if (torm.use_x(yid)) torm.PB(yid);
      int cand=min(overlap,dp[yid]);
      //printf("h:%d l:%d r:%d. yl:%d yr:%d dpyid:%d cand:%d\n",h,l,r,vl[yid],vr[yid],dp[yid],cand);
      chkmax(dp[id], cand);
    }
  }
  printf("%d\n",dp[vsz-1]);
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