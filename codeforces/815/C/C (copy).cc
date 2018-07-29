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
const int mn=5002;
int c[mn],d[mn],t[mn];
bool used[mn];
bool cmp(const pair<pll,int> &x, const pair<pll,int> &y) {
  ll a=x.fst.fst,b=x.fst.snd,c=y.fst.fst,d=y.fst.snd;
  ll lhs=a*d,rhs=b*c;
  if (lhs==rhs) {
    return x.snd<y.snd;
  }
  else return lhs<rhs;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),b=readInt();
  for (int i=1;i<=n;i++) {
    c[i]=readInt(); d[i]=readInt();
    if (i>=2) t[i]=readInt();
  }
  int final=0;
  while(b>0) {
    vector<pair<pll,int> > v;
    for (int i=1;i<=n;i++) {
      if (used[i]) continue;
      ll sum=0;
      int denom=0;
      int x=i;
      while(1) {
        if (used[x]) break;
        denom++;
        sum+=c[x]-d[x];
        if (x==1) break;
        x=t[x];
      }
      v.PB(MP(MP(sum,(ll)denom),i));
    }
    sort(v.begin(),v.end(), cmp);
    bool change=0;
    for (auto &w:v) {
      ll sum=w.fst.fst;
      if (sum<=b) {
        b-=sum;
        change=true;
        final+=w.fst.snd;
        int x=w.snd;
        while(1) {
          if (used[x]) break;
          used[x]=true;
          if (x==1||used[x]) break;
          x=t[x];
        }
        break;
      }
    }
    if (!change) break;
  }
  printf("%d\n",final);
}
