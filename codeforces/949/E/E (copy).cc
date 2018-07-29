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


vi bf(vi &a) {
  const int lk=8;
  for (int z=0;z<(1<<(2*lk));z++) {
  }
}
int ilog2(unsigned int x) {
  return __builtin_clz(x);
}
const int mk=21;
bitset<2*mk> g[2*mk];
const int TNEG=1,TPOS=0;
int ed(int t, int a) {
  return a+t*mk;
}
void ae(int ta, int a, int tb, int b) {
  printf("%d -> %d\n",(ta?-1:1)*(1<<a),(tb?-1:1)*(1<<b));
  int depender=ed(ta,a),dependee=ed(tb,b);
  g[dependee][depender]=1;
  g[depender][dependee]=1;
}
pii complete(int nz, int pz) {
  for (int k=mk-2;k>=0;k--) {
    int msk0=1<<k,msk1=1<<(k+1);
    for (int r=0;r<2;r++) {
      if ((nz>>k)==3) pz|=msk0;
      if ((pz>>k)==3) nz|=msk0;
      if ((msk1&nz)!=0 && (msk0&pz)!=0) nz|=msk0;
      if ((msk1&pz)!=0 && (msk0&nz)!=0) pz|=msk0;
    }
  }
  return MP(nz,pz);
}
pii collapse(int nz, int pz) {
  for (int k=mk-2;k>=0;k--) {
    int msk0=1<<k,msk1=1<<(k+1);
    {
      if ((nz>>k)==3 && (pz&msk0)!=0) nz&=~msk0;
      if ((pz>>k)==3 && (nz&msk0)!=0) pz&=~msk0;
      if ((msk1&nz)!=0 && (msk0&pz)!=0) nz&=~msk0;
      if ((msk1&pz)!=0 && (msk0&nz)!=0) pz&=~msk0;
    }
  }
  return MP(nz,pz);
}
pair<int,pii> solve(vi &inp) {
  for (int k=0;k<2*mk;k++) g[k].reset();
  for (auto x:inp) {
    if (x==0) continue;
    int t=x<0?TNEG:TPOS;
    x=abs(x);
    int k=ilog2(x)+1;
    if (k>=mk) continue;
    int y=(1<<k)-x;
    if (y>=(1<<mk)) continue;
    printf("x:%d y:%d 2^k:%d\n",x,y,1<<k);
    for (int a=0;a<mk;a++) {
      if (x&(1<<a)) {
        ae(t,a,t,k);
        for (int b=0;b<mk;b++) {
          if (y&(1<<b)) {
            ae(t,a,t^1,b);
          }
        }
      }
    }
  }
  int initpz=0;
  for (int pos=0;pos<mk;pos++) {
    if (g[ed(TPOS,pos)][ed(TPOS,pos)]) initpz|=1<<pos;
  }
  pair<int,pii> ans=MP(INF,MP(INF,INF));
  //printf("initpz:%d\n",initpz);
  for (int initnz=0;initnz<(1<<mk);initnz++) {
    pii completed=complete(initnz,initpz);
    int nz=completed.fst,pz=completed.snd;
    bool ok=1;
    for (int neg=0;neg<mk;neg++) {
      if (nz&(1<<neg)) continue;
      for (int neg2=0;neg2<mk;neg2++) {
        if (nz&(1<<neg)) continue;
        if (g[ed(1,neg)][ed(1,neg2)]) {
          ok=0; break;
        }
      }
    }
    if (!ok) continue;
    for (int neg=0;neg<mk;neg++) {
      if (nz&(1<<neg)) continue;
      for (int pos=0;pos<mk;pos++) {
        if (g[ed(TNEG,neg)][ed(TPOS,pos)]) {
          pz|=1<<pos;
          //if (initnz==2) printf("Missing neg:%d pz needs %d\n",1<<neg,1<<pos);
        }
      }
    }
    pii collapsed=collapse(nz,pz);
    int fnz=collapsed.fst,fpz=collapsed.snd;
    int cand=__builtin_popcount(fnz)+__builtin_popcount(fpz);
    if (cand==2) printf("nz:%d pz:%d fnz:%d fpz:%d\n",nz,pz,fnz,fpz);
    chkmin(ans,MP(cand,MP(fnz,pz)));
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=0;x<16;x++) ilog2(x);
  int n=rint();
  vector<int> a(n);
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  pair<int,pii> ans=solve(a);
  printf("%d\n",ans.fst);
  for (int k=0;k<mk;k++) {
    if (ans.snd.fst&(1<<k)) printf("%d ",-(1<<k));
  }
  for (int k=0;k<mk;k++) {
    if (ans.snd.snd&(1<<k)) printf("%d ",(1<<k));
  }
  //printf("\n");
  //for (auto &x:vans) printf("%d ",x);
  //printf("\n");
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