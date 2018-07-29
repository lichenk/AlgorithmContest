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
const int mn=10000+4;
int a[mn],b[mn];
vector<int> v[2];
bitset<mn> oknap;
bitset<mn> knap;
bool f(int imid) {
  int si=v[I].size();
  knap=oknap;
  for (int i=imid+1;i<si;i++) {
    int w=v[I][i];
    knap|=knap<<w;
  }
  int final=0;
  for (int i=-1;i<=imid;i++) {
    if (i!=-1) {
      knap=oknap;
      int w=v[I][i];
      knap|=knap<<w;
    }
    else knap=oknap;
    int sl=(l==0)?0:knap._Find_next(l-1);
    int cand=0;
    for (int t=0;t<=imid;t++) {
      if (t==i) continue;
      if (sl>r) break;
      sl+=v[I][t];
      cand++;
    }
    chkmax(final,cand);
  }
  return final>=imid;
}
int main() 
{
  const int I=1,U=0;
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),l=rint(),r=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) b[i]=rint();
  for (int i=0;i<n;i++) v[b[i]].PB(a[i]);
  sort(v[I].begin(),v[I].end());
  oknap[0]=true;
  for (auto &w:v[U]) {
    oknap|=oknap<<w;
  }
  int si=v[I].size();
  int final=0;
  for (int i=-1;i<si;i++) {
    if (i!=-1) {
      knap=oknap;
      int w=v[I][i];
      knap|=knap<<w;
    }
    else knap=oknap;
    int sl=(l==0)?0:knap._Find_next(l-1);
    int cand=0;
    for (int t=0;t<si;t++) {
      if (t==i) continue;
      if (sl>r) break;
      sl+=v[I][t];
      cand++;
    }
    chkmax(final,cand);
  }
  printf("%d\n",final);
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