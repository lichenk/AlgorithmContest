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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
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
const int mn=5e5+4;
const int mv=1e6+2;
vector<int> val2idx[mv];
int a[mn];
bitset<mn> used;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt();
    a[i]=x;
    val2idx[x].PB(i);
  }
  set<int> s;
  ll final=0;
  for (int v=mv-1;v>=0;v--) {
    for (auto &idx:val2idx[v]) {
      auto got=s.insert(idx);
      auto it=got.fst;
      int num=0;
      auto lit=it;
      while(lit!=s.begin()&&*lit>=idx-1) --lit;
      if (*lit<idx-1) num++;
      auto rit=it;
      while(rit!=s.end()&&*rit<=idx+1) ++rit;
      if (rit!=s.end()&&*rit>idx+1) num++;
      printf("idx:%d num:%d v:%d *lit:%d *rit:%d\n",idx,num,v,*lit,*rit);
      final+=num*v;
    }
  }
  printf("%lld\n",final);
}
