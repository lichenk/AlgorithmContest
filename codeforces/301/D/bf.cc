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
const int mn=200000;
pair<pii, int> q[mn];
const int blk=sqrt(mn);
bool cmp(const pair<pii, int> &x, const pair<pii, int> &y) {
  int l1=x.first.first/blk,l2=y.first.first/blk;
  int r1=x.first.second,r2=y.first.second;
  return (l1<l2)||(l1==l2&&r1<r2);
}
int p2v[mn];
int v2p[mn+1];
const int mh=4544226;
int _prealloc[mh];
int _preallocsz=0;
int *p2m[mn];
int p2msz[mn];
int binsearch(int p, int key, int imin, int imax) {
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (p2m[p][imid]<key) imin=imid+1;
    else imax=imid;
  }
  //printf("p:%d x:%d ans:%d\n",p,key,imin);
  return imin;
}
int query(int p, int l, int r) {
  int sz=p2msz[p];
  int lans=binsearch(p,l,0,sz);
  int rans=binsearch(p,r+1,lans,sz);
  return rans-lans;
}
int mo_left=0,mo_right=-1;
ll live=0;
void ins(int p) {
  int got=query(p,mo_left,mo_right);
  live+=got;
  //printf("INS p:%d l:%d r:%d got:%d live:%d\n",p,mo_left,mo_right,got,live);
}
void rm(int p) {
  int got=query(p,mo_left,mo_right);
  live-=got;
  //printf("RM p:%d l:%d r:%d got:%d live:%d\n",p,mo_left,mo_right,got,live);
  //assert(live>=0);
}
ll vans[mn];
int tmp[mn+1];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),qn=rint();
  memset(v2p,-1,sizeof v2p);
  for (int p=0;p<n;p++) {
    int v=rint();
    p2v[p]=v;
    v2p[v]=p;
  }
  for (int x=1;x<=n;x++) {
    for (int y=x+x;y<=n;y+=x) tmp[y]++;
  }
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    p2m[p]=_prealloc+_preallocsz;
    _preallocsz += tmp[v] + n/v - 1;
  }
  //printf("%d\n",_preallocsz); exit(0);
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    _preallocsz += n/v;
    for (int x=v+v;x<=n;x+=v) {
      int posx=v2p[x];
      if (posx!=-1) {
        //printf("p:%d v:%d x:%d posx:%d\n",p,v,x,posx);
        p2m[p][p2msz[p]++]=posx;
        p2m[posx][p2msz[posx]++]=p;
      }
    }
  }
  for (int p=0;p<n;p++) {
    //printf("p:%d v:%d\n",p,p2v[p]);
    //int v=p2v[p];
    //assert(p2msz[p]<=tmp[v] + n/v - 1);
    //for (int i=0;i<p2msz[p];i++) {
    //  printf("q:%d qv:%d\n",p2m[p][i],p2v[p2m[p][i]]);
    //}
    sort(p2m[p],p2m[p]+p2msz[p]);
  }
  for (int qi=0;qi<qn;qi++) {
    int L=rint()-1,R=rint()-1;
    q[qi]=MP(MP(L,R),qi);
  }
  sort(q,q+qn,cmp);
  for (int i=0;i<qn;i++) {
    int L=q[i].first.first,R=q[i].first.second;
    while(mo_right<R) ins(mo_right+1),mo_right++;
    while(mo_right>R) rm(mo_right),mo_right--;
    while(mo_left>L) ins(mo_left-1),mo_left--;
    while(mo_left<L) rm(mo_left),mo_left++;
    int qi=q[i].snd;
    vans[qi]=live+R-L+1;
  }
  for (int qi=0;qi<qn;qi++) {
    printf("%lld\n",vans[qi]);
  }
}

