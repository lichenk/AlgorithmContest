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
const ll INF=9e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
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
const int mn=1e5+4;
int a[mn];
vector<int> g[mn];
int m;
ll base=0;
ll final=INF;
void go(int src, int dest) {
  ll delta=0;
  for (auto &si:g[src]) {
    ll old=(si-1>=0?abs(a[si]-a[si-1]):0)+(si+1<m?abs(a[si]-a[si+1]):0);
    ll nw=(si-1>=0?abs(dest-a[si-1]):0)+(si+1<m?abs(dest-a[si+1]):0);
    delta+=nw-old;
    //if (src==9) {
    //  printf("dest:%d delta:%d old:%lld nw:%lld\n",dest,delta,old,nw);
    //}
  }
  chkmin(final,base+delta);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int _n=readInt();
  m=readInt();
  for (int i=0;i<m;i++) {
    int x=readInt();
    a[i]=x;
    g[x].PB(i);
  }
  for (int i=0;i<m-1;i++) {
    base+=abs(a[i+1]-a[i]);
  }
  for (int i=0;i<m-1;i++) {
    int src=a[i],dest=a[i+1];
    go(src,dest);
    swap(src,dest);
    go(src,dest);
  }
  printf("%lld\n",final);
}
