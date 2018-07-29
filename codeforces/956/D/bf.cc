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

//ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
class rat {
public:
  ll nu, de;
  rat(const ll &n = 0, const ll &d = 1) {
    nu = n; de = d;
    if (de < 0) { nu = -nu; de = -de; } }
  rat operator+(const rat& b) const
  { return rat( nu*b.de+de*b.nu, de*b.de ); }
  rat operator-(const rat& b) const
  { return rat( nu*b.de-de*b.nu, de*b.de ); }
  rat operator-() { return rat(-nu, de); }
  rat operator*(const rat& b) const
  { return rat( nu*b.nu, de*b.de ); }
  rat operator/(const rat& b) const
  { return rat( nu*b.de, de*b.nu ); }
  bool operator== (const rat & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const rat& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const rat& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const rat& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const rat& b) const { return nu * b.de >= b.nu * de; }
};

template<typename T> class RemapUnique {
public:
  vector<T> v;
  void sortmakeunique(vector<T> & myvector) {
    sort(myvector.begin(), myvector.end());
    auto it = std::unique (myvector.begin(), myvector.end());
    myvector.resize( std::distance(myvector.begin(),it) );
  }
  void init(vector<T> &_inp) { // Mutates the input!
    v=_inp;
    sortmakeunique(v);
    //for (auto &w:v) printf("%d ",w); printf("ENDDII\n");
  }
  int size() {
    return v.size();
  }
  int GTE(const T &key) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<key) imin=imid+1;
      else imax=imid;
    }
    //printf("key:%d imin:%d\n",key,imin);
    return imin;
  }
};

template<int _SEGSZ> class SumSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
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

  void modify(int p, const S& value) { // modify value at position p
    int n=segn;
    p+=n;
    for (t[p] = combine(t[p],value); p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
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


ll bf1(vector<pii> a) {
  set<pii> ans;
  for (int x=0;x<a.size();x++) for (int y=0;y<a.size();y++) {
    if (x==y) continue;
    if ((a[x].fst<=a[y].fst)&&a[y].snd<=a[x].snd) {
      ans.insert(MP(min(x,y),max(x,y)));
    }
  }
  return ans.size();
}

ll bf2(vector<pii> a, vector<pii> b) {
  int ans=0;
  for (int x=0;x<a.size();x++) for (int y=0;y<b.size();y++) {
    if (!(
      a[x].snd<b[y].fst||
      a[x].fst>b[y].snd
      )) {
      ans++;
    }
  }
  return ans;
}


const int mn=2e5+4;
vi a[mn][2][2];
int open[2];
SumSegTree<mn> closebyl[2];
vector<pii> tmp[2];
const int L=0,R=1;
ll ans1[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int w=rint();
  vector<pii> inp[2];
  vector<rat> seed;
  for (int i=0;i<n;i++) {
    int x=rint(),v=rint();
    int t=(x>0)?1:0;
    x=abs(x),v=abs(v);
    inp[t].PB(MP(x,v));
    seed.PB(rat(v-w,x));
    seed.PB(rat(v+w,x));
  }
  RemapUnique<rat> remap;
  remap.init(seed);
  for (int t=0;t<2;t++) {
    for (auto &p:inp[t]) {
      int x=p.fst,v=p.snd;
      int l=remap.GTE(rat(v-w,x));
      int r=remap.GTE(rat(v+w,x));
      //printf("t:%d l:%d r:%d\n",t,l,r);
      a[l][t][L].PB(r);
      a[r][t][R].PB(l);
      tmp[t].PB(MP(l,r));
    }
    for (int x=0;x<mn;x++) sort(a[x][t][R].begin(),a[x][t][R].end(),greater<int>());
  }
  for (int t=0;t<2;t++) closebyl[t].init(remap.size());
  ll ans2=0;
  for (int x=0;x<mn;x++) {
    {
      const int t=0;
      open[t]+=a[x][t][L].size();
    }
    /*for (int t=0;t<2;t++) {
      for (auto &l:a[x][t][R]) {
        closebyl[t].modify(l, 1);
      }
    }*/
    for (int t=0;t<2;t++) {
      for (auto &l:a[x][t][R]) {
        int got=(closebyl[t].query(l,x));
        closebyl[t].modify(l, 1);
        ans1[t]+=got;
        //printf("t:%d l:%d r:%d add:%d\n",t,l,x,got);
      }
      ll c2=a[x][t][L].size()*(ll)open[t^1];
      ans2+=c2;
      //if (c2) printf("t:%d x:%d open:%d c2:%lld\n",t,x,open[t^1],c2);
    }
    {
      const int t=1;
      open[t]+=a[x][t][L].size();
    }
    for (int t=0;t<2;t++) {
      open[t]-=a[x][t][R].size();
    }
  }
  //printf("%lld %lld\n",ans1[0],bf1(tmp[0])); return 0;
  //assert(ans1[0]==bf1(tmp[0]));
  //assert(ans1[1]==bf1(tmp[1]));
  //assert(ans2==bf2(tmp[0],tmp[1]));
  ll ans=ans1[0]+ans1[1]+ans2;
  printf("%lld\n",ans);
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