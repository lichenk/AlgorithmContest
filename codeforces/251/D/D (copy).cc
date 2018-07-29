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
int rint();char rch();long long rlong();
const int mn=1e5+2;
const int maxd=61;
vector<ll> a;
vector<vector<int> > b;
int gauss() {
  //O(alen * sizeof(int)) Binary gaussian elimination.
  //Returns the size of the basis.
  //Set maxd = sizeof(int)
  int alen=a.size();
  int st=0;
  for (int d=maxd-1;d>=0;d--) {
    ll msk=1LL<<d;
    for (int x=st;x<alen;x++) {
      if (a[x]&msk) {
        if (x!=st) {
          swap(a[x],a[st]);
          swap(b[x],b[st]);
        }
        for (int y=st+1;y<alen;y++) if (a[y]&msk) {
          //printf("a[y]:%lld a[st]:%lld\n",a[y],a[st]);
          a[y]^=a[st];
          for (auto &w:b[st]) {
            b[y].PB(w);
          }
        }
        st++;
        break;
      }
    }
  }
  return st;
}

ll getleft(ll x) {
  for (auto &y:a) {
    int bit=63-__builtin_clzll(y);
    ll msk=1LL<<bit;
    //printf("bit:%d msk:%lld x:%lld y:%lld\n",bit,msk,x,y);
    if (msk&x) {
      x^=y;
    }
  }
  return x;
}

bool inbasis(ll x) {
  for (auto &y:a) {
    int bit=63-__builtin_clzll(y);
    ll msk=1LL<<bit;
    //printf("bit:%d msk:%lld x:%lld y:%lld\n",bit,msk,x,y);
    if (msk&x) {
      x^=y;
    }
  }
  return x==0;
}

bool vans[mn];
void getbasis(ll x) {
  int alen=a.size();
  set<int> ans;
  for (int i=0;i<alen;i++) {
    int y=a[i];
    int bit=63-__builtin_clzll(y);
    ll msk=1LL<<bit;
    if (msk&x) {
      x^=y;
      for (auto &w:b[i]) {
        vans[w]^=1;
      }
    }
  }
}
vector<int> urg;
ll inp[mn];
int vcnt[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) inp[i]=rlong();
  for (int d=0;d<maxd;d++) {
    int cnt=0;
    ll msk=1LL<<d;
    for (int i=0;i<n;i++) {
      if (inp[i]&msk) cnt++;
    }
    vcnt[d]=cnt;
  }
  for (int d=maxd-1;d>=0;d--) {
    int cnt=vcnt[d];
    if (cnt==0) continue;
    if (0==(cnt%2)) {
      //printf("d0:%d\n",d);
      urg.PB(d);
    }
  }
  for (int d=maxd-1;d>=0;d--) {
    int cnt=vcnt[d];
    if (cnt==0) continue;
    if (1==(cnt%2)) {
      //printf("d1:%d\n",d);
      urg.PB(d);
    }
  }
  int usz=urg.size();
  for (int i=0;i<n;i++) {
    ll x=inp[i];
    ll y=0;
    for (int i=0;i<usz;i++) {
      ll msk=1LL<<urg[i];
      if (x&msk) {
        y|=1LL<<(maxd-1-i);
      }
    }
    inp[i]=y;
  }
  //ll xorall=0;
  //for (int i=0;i<n;i++) xorall^=inp[i];
  for (int i=0;i<n;i++) {
    ll x=inp[i];
    if (inbasis(x)) continue;
    a.PB(x);
    vector<int> tmp={i};
    b.PB(tmp);
    gauss();
  }
  //for (auto &w:a) {
  //  printf("%lld\n",w);
  //}
  ll her=0;
  ll care=0;
  for (auto &w:urg) {
    int d=w;
    ll msk=1LL<<d;
    care|=msk;
    ll lft=getleft(her|msk);
    //printf("lft:%lld care:%lld d:%d her:%lld msk:%lld\n",lft,care,d,her,msk);
    if (0==(lft&care)) {
      her|=msk;
    }
  }
  her=getleft(her)|her;
  ll my=xorall^her;
  //printf("my:%lld her:%lld\n",my,her);
  assert(my<=her);
  assert(inbasis(her));
  getbasis(her);
  ll gother=0;
  for (int i=0;i<n;i++) {
    if (vans[i]) {
      printf("2 ");
      gother^=inp[i];
    }
    else {
      printf("1 ");
    }
  }
  assert(gother==her);
  printf("\n");
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