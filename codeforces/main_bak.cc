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
inline int rri()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  int res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline ll rrl()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  ll res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline char rrc()
{
  char c;
  while (c = getchar(), c <= ' ');
  return c;
}
inline int rrs(char *target) {
  char c;
  while (c = getchar(), c <= ' ');
  int idx=-1;
  target[++idx]=c;
  while(1) {
    c=getchar();
    if (c<=' '){
      target[++idx]='\0';
      return idx;
    }
    target[++idx]=c;
  }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
}

