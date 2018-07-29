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
const int MAXSZ=128*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  //preidx+=(((int)size) + 7) & ~0x07;
  preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
const int mn=1e5+2;

int segn=mn;  // array size
typedef unsigned int S;
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
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
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
const int vinf=mn-1;
inline void update(S *t, int pos, int base, int val) {
  printf("t:%x pos:%d base:%d val:%d val-base:%d\n",t,pos,base,val,val-base);
  if (base==vinf) base=0;
  
  modify(t, pos, val-base);
}

S root1[2 * mn],root2[2 * mn];

int a[mn];
set<int> shape2pos[mn];
int vl[mn],vr[mn];
int tmp[mn];
void rm(int pos, int oldshape) {
  printf("rm\n");
  int l=vl[pos],r=vr[pos];
  if (r<vinf) {
    vl[r]=l;
    update(root2,r,l,r);
  }
  if (l>0) {
    vr[l]=r;
    update(root1,l,r,l);
  }
  shape2pos[oldshape].erase(pos);
}

void ins(int pos, int newshape) {
  printf("ins\n");
  std::pair<std::set<int>::iterator,bool> ret=shape2pos[newshape].insert(pos);
  auto it=ret.fst;
  int l=0,r=vinf;
  if (it!=shape2pos[newshape].begin()) {
    --it; l=*it; r=vr[l];
  }
  else {
    ++it;
    if (it!=shape2pos[newshape].end()) {
      r=*it;
    }
  }
  vl[pos]=l; vr[pos]=r;
  if (l>0) {
    update(root1,l,pos,l);
    vr[l]=pos;
  }
  if (r<vinf) {
    update(root2,r,pos,r);
    vl[r]=pos;
  }
  update(root1,pos,r,pos);
  update(root2,pos,l,pos);
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //test(); return 0;
  printf("root1:%x root2:%x\n",root1,root2);
  int n=rint(),m=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int x=1;x<=n;x++) {
    shape2pos[a[x]].insert(x);
  }
  for (int x=n;x>=1;x--) {
    int val=a[x];
    int h=vinf;
    if (tmp[val]!=0) {
      h=tmp[val];
      vl[h]=x;
    }
    vr[x]=h;
    tmp[val]=x;
  }
  for (int x=1;x<=n;x++) {
    update(root1,x,vr[x],x);
    update(root2,x,vl[x],x);
  }
  for (int qi=0;qi<m;qi++) {
    int t=rint();
    if (t==1) {
      int pos=rint(),newshape=rint();
      //printf("pos:%d newshape:%d\n",pos,newshape);
      int oldshape=a[pos];
      if (oldshape!=newshape) {
        a[pos]=newshape;
        rm(pos, oldshape);
        ins(pos,newshape);
      }
    }
    else {
      int l=rint(),r=rint();
      S ans1=query(root1,l,r);
      S ans2=query(root2,l,r);
      printf("%u-%u=%u\n",ans2,ans1,ans2-ans1);
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