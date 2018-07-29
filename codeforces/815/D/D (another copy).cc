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
const int UNDEF = -1;
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
const int mn=500000+4;
int n;
void preprocess(pii *bc, vector<pii> &b2c, const int blim, const int clim) {
  b2c.PB(MP(blim+2,0));
  sort(bc,bc+n);
  int lastc=1;
  for (int i=n-1;i>=0;i--) {
    int b=bc[i].fst,c=bc[i].snd;
    if (c>lastc) {
      b2c.PB(MP(b,c));
      lastc=c;
    }
  }
  b2c.PB(MP(0,clim));
  reverse(b2c.begin(),b2c.end());
}
int rm(vector<pii> &b2c, const int b, const int clim, const int cfloor) {
  int imin=0,imax=(int)b2c.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (b2c[imid].fst<b) imin=imid+1;
    else imax=imid;
  }
  int c=max(cfloor,b2c[imin].snd+1);
  //printf("clim:%d - c:%d + 1\n",clim,c);
  return (clim-c+1);
}
int alim,blim,clim;
vector<int> a2i[mn];
int vb[mn],vc[mn];
pii bc[mn],cb[mn];
vector<pii> b2c,c2b;
int b2hc[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt(),alim=readInt(),blim=readInt(),clim=readInt();
  for (int i=0;i<n;i++) {
    int a=readInt(),b=readInt(),c=readInt();
    vb[i]=b,vc[i]=c;
    a2i[a].PB(i);
    bc[i]=MP(b,c);
    cb[i]=MP(c,b);
    chkmax(b2hc[b],c);
  }
  ll live=0;
  {
    int hic=b2hc[blim];
    for (int b=blim;b>=1;b--) {
      chkmax(hic,b2hc[b]);
      live+=clim-hic;
    }
  }
  preprocess(bc,b2c,blim,clim);
  preprocess(cb,c2b,clim,blim);
  //printf("initlive:%lld\n",live);
  int bfloor=1,cfloor=1;
  ll ans=0;
  for (int a=alim;a>=1;a--) {
    int newbfloor=bfloor,newcfloor=cfloor;
    for (auto &i:a2i[a]) {
      int b=vb[i],c=vc[i];
      chkmax(newbfloor,b+1); chkmax(newcfloor,c+1);
    }
    for (int b=bfloor;b<newbfloor;b++) {
      int ch=rm(b2c,b,clim,newcfloor);
      //printf("b:%d ch:%d\n",b,ch);
      live-=ch;
    }
    for (int c=cfloor;c<newcfloor;c++) {
      int ch=rm(c2b,c,blim,newbfloor);
      //printf("c:%d ch:%d\n",c,ch);
      live-=ch;
    }
    bfloor=newbfloor;
    cfloor=newcfloor;
    ans+=live;
    //printf("a:%d live:%lld\n",a,live);
  }
  printf("%lld\n",ans);
}
