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

ll comp(ll n) {
  n--;
  if (n%2==0) {
    n/=2;
    return 2*n*n+n+1;
  }
  else {n=(n+1)/2; return 2*n*n;}
}
ll solve(ll key) {
  ll imin=0,imax=100005;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    ll got=comp(imid);
    if (got<=key) imin=imid+1;
    else imax=imid;
  }
  return imin-1;
}

int w[100000];
int main() 
{
  //for (ll n=1;n<=10;n++) printf("n:%lld ans:%lld\n",n,comp(n));
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  for (int i=0;i<m;i++) {
    readInt(); w[i]=readInt();
  }
  sort(w,w+m,greater<int>());
  int got=solve(n);
  ll ans=0;
  for (int i=0;i<min(m,got);i++) {
    ans+=w[i];
  }
  printf("%lld\n",ans);
}

