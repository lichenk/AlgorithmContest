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
const int mn=2001;
char s[2004];
map<int,int> f[2][mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,klim; scanf("%d %d\n%s\n",&n,&klim,s);
  int cur=0,nxt=1;
  f[cur][0][0]=1;
  for (int x=1;x<=n;x++) {
    for (int k=0;k<=klim;k++) f[nxt][k].clear();
    int c=s[n-x]-'a';
    for (int k=0;k<=klim;k++) {
      int sum0=0;
      for (auto &w:f[cur][k]) {
        int prev=w.fst,cnt=w.snd;
        //printf("x:%d k:%d prev:%d cnt:%d c:%d\n",x,k,prev,cnt,c);
        if (c) {
          sum0=(sum0+cnt*(ll)(c))%MOD;
        }
        if (k+prev<=klim) {
          auto it=f[nxt][k+prev].find(prev);
          if (it==f[nxt][k+prev].end()) f[nxt][k+prev][prev]=cnt;
          else {
            int sum=it->snd+cnt; if (sum>=MOD) sum-=MOD;
            it->snd=sum;
          }
        }
        if (k+x<=klim&&25-c>0) {
          int key=(k+x+x<=klim)?x:klim;
          auto it=f[nxt][k+x].find(key);
          if (it==f[nxt][k+x].end()) f[nxt][k+x][key]=(cnt*(ll)(25-c))%MOD;
          else it->snd=(it->snd+cnt*(ll)(25-c))%MOD;
        }
      }
      if (sum0) {
        auto it=f[nxt][k].find(0);
        if (it==f[nxt][k].end()) f[nxt][k][0]=sum0;
        else {
          int sum=it->snd+sum0; if (sum>=MOD) sum-=MOD;
          it->snd=sum;
        }
      }
    }
    swap(cur,nxt);
  }
  int ans=0;
  for (auto &w:f[cur][klim]) {
    //printf("x:%d k:%d prev:%d cnt:%d\n",n+1,klim,w.fst,w.snd);
    ans+=w.snd;
    if (ans>=MOD) ans-=MOD;
  }
  printf("%d\n",ans);
}