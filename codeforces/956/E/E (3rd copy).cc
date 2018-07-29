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
const int mn=10000+1;
short inp[mn];
vector<short> a;
short f[mn][mn];
bitset<mn> knap;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),l=rint(),r=rint();
  for (int i=0;i<n;i++) inp[i]=rint();
  knap[0]=true;
  for (int i=0;i<n;i++) if (rint()==0) knap|=knap<<inp[i]; else a.PB(inp[i]);
  sort(a.begin(),a.end());
  memset(f,-1,sizeof f);
  //int xlim=r,ylim=r-l;
  f[0][0]=0;
  short sum=0;
  for (const auto w:a) {
    printf("w:%d\n",w);
    for (int x=0;x<=sum;x++) {
      int y=sum-x;
      short now=f[x][y];
      if (now==-1) continue;
      printf("x:%d y:%d now:%d\n",x,y,now);
      chkmax(f[x+w][y],now);
      chkmax(f[x][y+w],(short)(now+(short)1));
    }
    sum+=w;
  }
  for (int x=0;x<=sum;x++) {
    for (int y=1;y<=sum;y++) {
      chkmax(f[x][y],f[x][y-1]);
    }
  }
  for (int x=6;x<=6;x++) for (int y=0;y<=r;y++) printf("x:%d y:%d f:%d\n",x,y,f[x][y]);
  short final=0;
  for (int s=0;s<l;s++) {
    if (!knap[s]) continue;
    printf("knap s:%d\n",s);
    for (int z=l;z<=r;z++) {
      int x=z-s;
      if (x>sum) continue;
      int y=r-z;
      {
        short cand=f[x][min((int)sum,y)];
        if (f[x][sum]>cand) {cand++; chkmax(cand,(short)1);}
        printf("x:%d y:%d cand:%d\n",x,y,cand);
        chkmax(final,cand);
      }
    }
  }
  for (int s=l;s<=r;s++) {
    if (!knap[s]) continue;
    short cand=f[0][min((int)sum,r-s)];
    if (f[0][sum]>cand) {cand++; chkmax(cand,(short)1);}
    //printf("s:%d r-s:%d cand:%d\n",s,r-s,cand);
    chkmax(final,cand);
  }
  printf("%d\n",(int)final);
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