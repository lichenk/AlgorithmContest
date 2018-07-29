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

const int mn=20+2;
char a[mn];
char b[mn];
int n,t;
int numh=0;
int g(int imid, int zz) {
  if (numh==0) return 0;
  int z=zz;
  for (int i=0;i<n;i++) b[i]=a[i];
  int k=imid;
  int x=0;
  int lft=numh;
  for (int st=1;st<20;st++) {
    if (b[x]=='S') {
      k++;
      b[x]='.';
    }
    else if (b[x]=='H') {
      if (k>0) {
        b[x]='.';
        k--;
        lft--;
        if (lft==0) {
          //if (st==6) printf("zz:%d\n",zz);
          return st;
        }
      }
    }
    if (x==0) x++;
    else if (x==n-1) x--;
    else {
      if (z&1) x++;
      else x--;
      z=z>>1;
    }
  }
  return 100;
}
ll f(int imid) {
  ll ans=1e9;
  for (int z=0;z<(1<<20);z++) {
    chkmin(ans,(ll)g(imid,z));
  }
  if (ans>=30) ans=1e18;
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d %d\n%s\n",&n,&t,a);
  assert(n==strlen(a));
  
  for (int i=0;i<n;i++) if(a[i]=='H') numh++;
  for (int imid=0;imid<=numh;imid++) printf("%d:%lld\n",imid,f(imid));
  return 0;
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