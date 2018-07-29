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
const int mn=1e2+4;
int p[mn];
int n;
bool f() {
  stack<int> S;
  for (int x=1;x<=n;x++) {
    if (p[x]>0) S.push(p[x]);
    else {
      if (S.empty()) return 0;
      int got=S.top(); S.pop();
      if (abs(got)!=abs(p[x])) return 0;
    }
  }
  return S.empty();
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint();
  for (int x=1;x<=n;x++) p[x]=rint();
  int t=rint();
  for (int i=0;i<t;i++) {
    int x=rint();
    p[x]=-p[x];
  }
  vector<int> v;
  for (int x=1;x<=n;x++) if (p[x]>0) v.PB(x);
  int k=v.size();
  int zlim=1<<k;
  for (int z=0;z<zlim;z++) {
    for (int i=0;i<k;i++) {
      int x=v[i];
      if ((1<<i)&z) p[x]=-abs(p[x]);
      else p[x]=abs(p[x]);
    }
    //for (int x=1;x<=n;x++) printf("%d ",p[x]);
    //printf("\n"); 
    if (f()) {
      printf("YES\n");
      //for (int x=1;x<=n;x++) printf("%d ",p[x]);
      //printf("\n");
      return 0;
    }
  }
  printf("NO\n");
}

