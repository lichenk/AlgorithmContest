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
//#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+2;


class AtLeastSegTree {
  static const int MAXSEG=mn;
  typedef int STV;
public:
  STV t[2 * MAXSEG];
  STV identity = 0;
  int segn;
  STV combine(const STV& lefts, const STV& rights) {
    return lefts+rights;
  }
  void build(vector<int> &val) {  // build the tree
    int n=val.size();
    segn=n;
    for (int i=0;i<n;i++) t[n+i]=val[i];
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modifyset(int p, const STV& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  STV query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    STV resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }

  int fatleast(int atleast, int l, int r, int p) {
    // Finds leftmost idx with sum at least atleast
    if (l+1==r) return l;
    int m=(l+r)>>1;
    if (atleast <= t[p<<1]) {
      return fatleast(atleast, l, m, p<<1);
    }
    else {
      return fatleast(atleast-t[p<<1], m, r, (p<<1)|1);
    }
  }

  int gatleast(int atleast) {
    return fatleast(atleast,0,segn,1);
  }
}

class SegTree {
  static const int MAXSEG=mn;
  typedef int STV;
public:
  STV t[2 * MAXSEG];
  STV identity = 0;
  int segn;
  STV combine(const STV& lefts, const STV& rights) {
    return lefts+rights;
  }
  void build(vector<int> &val) {  // build the tree
    int n=val.size();
    segn=n;
    for (int i=0;i<n;i++) t[n+i]=val[i];
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modifyset(int p, const STV& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  STV query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    STV resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
}

class FirstK {
  static const int MAXSEG=mn;
  typedef int STV;
  int segn;
  AtLeastSegTree al;
  SegTree st;
public:
  int init(vector<int> &val) {
    int n=val.size();
    segn=n;
    vi ones(n,1);
    al.build(ones);
    st.build(val);
  }
  void 

}






int a[mn];
void fail(int t) {
  printf("-1\n"); exit(0);
}

ll getdist(vi &vans) {
  ll dist=0;
  for (int i=1;i<vans.size();i++) {
    dist+=abs(a[vans[i]]-a[vans[i-1]]);
  }
  return dist;
}
void out(vi &vans) {
  printf("%lld\n",getdist(vans));
  for (int i=1;i<vans.size();i++) {
    printf("%d ",vans[i]);
  }
  printf("\n");
}

vi solvestart(vi &coord, int l) {
  vpii vdist;
  for (int x=0;x<coord.size()-1;x++) {
    vdist.PB(MP(a[coord[x+1]]-a[coord[x]],x));
  }
  sort(vdist.begin(),vdist.end());
  for (int )

}
int n,l,s;

int rev(int x) {return n+1-x;}
void dorev() {
  s=rev(s);
  reverse(a+1,a+n+1);
  l=n-1-l;
}

vi solvemid() {
  int r=n-1-l;
  if (l==0||r==0) fail(2);
  vi vans1;
  {
    vans1.PB(s);
    if (l<s) {
      for (int x=l;x>=1;x--) vans1.PB(x);
      for (int x=l+1;x<=n;x++) if (x!=s) vans1.PB(x);
    }
    else {
      assert(l>=s-1);
      for (int x=s-1;x>=2;x--) vans1.PB(x);
      vi coord; coord.PB(1);
      for (int x=s+1;x<=n;x++) coord.PB(x);
      vi res=solvestart(coord, l-(s-1));
      for (auto &w:res) vans1.PB(w);
    }
  }
  return vans1;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),l=rint(),s=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  if (s==1||s==n) {
    vi coord; for (int x=1;x<=n;x++) coord.PB(x);
    if (s==1) {
      vi ans=solvestart(coord,l);
      out(ans);
    }
    else {
      dorev();
      vi ans=solvestart(coord,l);
      dorev();
      for (auto &w:ans) w=rev(w);
      out(ans);
    }
  }
  else {
    vi ans1=solvemid();
    ll d1=getdist(ans1);

    dorev();
    vi ans2=solvemid();
    dorev();
    for (auto &w:ans2) w=rev(w);
    ll d2=getdist(ans2);
    if (d2<=d1) {
      out(ans2);
    }
    else {
      out(ans1);
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