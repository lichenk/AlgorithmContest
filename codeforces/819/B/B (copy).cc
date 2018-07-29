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
const int mn=1e6+4;
int a[mn];
vector<int> t2i[mn];
int vs[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=1;i<=n;i++) a[i]=readInt();
  ll dev=0;
  int below=0,above=0,zero=0;
  for (int i=1;i<=n;i++) {
    dev+=abs(a[i]-i);
    if (a[i]<i) below++;
    else if (a[i]==i) zero++;
    else above++;
    if (a[i]<i) {
      int t=i-a[i];
      printf("i:%d t:%d\n",i,t);
      t2i[t].PB(i);
    }
  }
  pair<ll,int> best=MP(dev,0);
  printf("Initdev:%lld\n",dev);
  above+=zero; zero=0;
  dev+=above-below;
  for (int t=1;t<=n;t++) {
    // Correct t
    dev+=abs(n-a[t])-abs(0-a[t]);
    printf("t:%d above:%d below:%d zero:%d a[t]:%d dev:%d\n",t,above,below,zero,a[t],dev);
    chkmin(best,MP(dev,t));
    dev+=above-below;
    above--; below++;
    t2i[t+n-a[t]].PB(t);
    for (auto &w:t2i[t]) {
      printf("Process w:%d\n",w);
      below--;
      zero++;
    }
    //printf("t:%d above:%d below:%d zero:%d a[t]:%d dev:%d\n",t,above,below,zero,a[t],dev);
    above+=zero;
    zero=0;
  }
  best.snd=(n-best.snd)%n;
  printf("%lld %d\n",best.fst,best.snd);
}
