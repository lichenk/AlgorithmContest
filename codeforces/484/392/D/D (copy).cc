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
const int INF=1e9;
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
const int mn=100004;

const int MAXSEG = mn;  // limit for array size
int segn;  // array size
typedef int S;
S t[2 * MAXSEG];
S identity = -1;
S combine(const S& lefts, const S& rights) {
  return max(lefts,rights);
}
void modify(int l, int r, const S& value) {
  r++;
  int n=segn;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      t[l] = combine(t[l], value);
      l++;
    }
    if (r&1) {
      --r;
      t[r] = combine(t[r], value);
    }
  }
}

S query(S *t, int p) {
  int n=segn;
  S res = identity;
  for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
  return res;
}

int va[mn],vb[mn],vc[mn],vd[3*mn];
int fa[3*mn],fb[3*mn],fc[3*mn];
int uniq[mn]; int usz=1;
int bins(int key) {
  int imin=0,imax=usz;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (a[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin+1;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  for (int i=1;i<=n;i++) va[i]=readInt();
  memcpy(vd,va+1,sizeof(int)*n);	
  for (int i=1;i<=n;i++) vb[i]=readInt();
  memcpy(vd+n,vb+1,sizeof(int)*n);
  for (int i=1;i<=n;i++) vc[i]=readInt();
  memcpy(vd+n+n,vc+1,sizeof(int)*n);
  sort(vd,vd+3*n);
  uniq[0]=vd[0];
  for (int i=1;i<3*n;i++) {
    if (vd[i]!=vd[i-1]) uniq[usz++]=vd[i];
  }
  for (int i=1;i<=n;i++) {
    int key=bins(va[i]);
    if (fa[key]==0) {fa[key]=i; va[i]=key;}
    else va[i]=0;
  }
  for (int i=1;i<=n;i++) {
    int key=bins(vb[i]);
    if (fb[key]==0) {fb[key]=i; vb[i]=key;}
    else vb[i]=0;
  }
  for (int i=1;i<=n;i++) {
    int key=bins(vc[i]);
    if (fc[key]==0) {fc[key]=i;}
  }
  segn=n+1;
  int final=INF;
  int best=INF;
  {
    int mc=0;
    for (int i=n;i>=0;i--) {
      t[segn+i]=mc;
      chkmin(best,mc+i);
      if (i==0) break;
      int key=vb[i];
      if (key) {
        if (!fa[key]) {
          if (!fc[key]) mc=INF;
          else chkmax(mc, fc[key]);
        }
      }
    }
  }
  for (int ai=n;ai>=0;ai--) {
    chkmin(final, best+ai);
    if (ai==0) break;
    int key=va[ai];
    if (key) {
      
    }
  }
}
