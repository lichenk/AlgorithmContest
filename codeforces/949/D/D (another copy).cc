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

template<int _SEGSZ> class SumSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef ll S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  void setmodify(int p, const S& value) { // set value at position p
    sset(p,combine(query(p,p),value));
  }

  S query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};
int n,d,b;
const int mn=1e5+4;
int origa[mn];

SumSegTree<mn> st;
bool go(const int l, ll &lsum, const int dir) {
        ll al=st.query(l,l);
        lsum+=al;
        if (lsum>=b) {
          lsum-=b;
          st.setmodify(l,-b);
        }
        else {
          ll now;
          if (dir==1) now=query(l+dir,min(l+t*(ll)d,(ll)n));
          else now=query(max(1LL,l-t*(ll)d),l+dir);
          if (now+lsum<b) return false;
          ll need=b;
          ll take=min(lsum,b);
          need-=take;
          lsum-=take;
          st.setmodify(l,-take);
          if (take>0) {
            st.setmodify(l+dir,-need);
          }
        }
        return true;
}
bool f(int imid) {
  st.init(n+1);
  for (int x=1;x<=n;x++) st.t[st.segn+x]=origa[x];
  int ans=0;
  int lgood=l+(imid-1);
  int rgood=r-(imid-1);
  {
    int l=0,r=n+1;
    ll lsum=0,rsum=0;
    for (int t=1;t<=(n+1)/2;t++) {
      bool gol=0,gor=0;
      if (l<(n+1)/2) {l++;gol=1;}
      if (r>(n+1)/2+1) {r--;gor=1;}
      if (gol) {
        bool res=go(l,lsum,1); if (!res) return false;
      }
      if (gor) {
        bool res=go(r,rsum,-1); if (!res) return false;
      }
    }
  }
  return true;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),d=rint(),b=rint();
  for (int x=1;x<=n;x++) origa[x]=rint();
  //for (int x=1;x<=n;x++) pre[x]=pre[x-1]+origa[x];
  int imin=0,imax=((n+1)/2)+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (!f(imid)) imin=imid+1;
    else imax=imid;
  }
  printf("%d\n",imin);
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