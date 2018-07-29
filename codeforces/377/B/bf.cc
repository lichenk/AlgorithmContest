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

ll readInt()
{
    readAhead(16);

    ll x = 0;
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
const int mn=20+4;
int vbug[mn],vstu[mn],vpass[mn];
int vassign[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int ns=readInt(),nb=readInt(),passlim=readInt();
  for (ll x=0;x<nb;x++) {
    vbug[x]=readInt();
  }
  for (ll x=0;x<ns;x++) vstu[x]=readInt();
  for (ll x=0;x<ns;x++) vpass[x]=readInt();
  int imin=1000000000;
  for (int k=0;k<5000000;k++) {
    if (0==(k&0xff)) srand(time(0)+clock()+rand());
    int ok=1;
    for (int x=0;x<nb;x++) {
      int stu=rand()%ns;
      int diff=vbug[x],skill=vstu[stu];
      vassign[x]=stu;
      if (diff>skill) {ok=0;break;}
    }
    if (ok) {
      map<int,int> s;
      for (int x=0;x<nb;x++) s[vassign[x]]++;
      ll pass=0;
      int ans=0;
      for (auto &w:s) {
        pass+=vpass[w.fst];
        chkmax(ans,w.snd);
      }
      if (pass<=passlim) {
        chkmin(imin,ans);
      }
    }
  }
  if (imin>=1000000000) {
    printf("NO\n");
  }
  else {
    printf("YES\n");
    printf("%d\n",imin);
    return 0;
  }
}