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
const int mn=1e5+4;
set<int> g[mn];
set<int> odd;
set<int> pos;
vector<int> vans;
void rm(int x, int y) {
  g[x].erase(y);
  {
    int gsz=g[x].size();
    if (gsz==0) pos.erase(x);
    if (gsz&1) odd.insert(x);
    else odd.erase(x);
  }
  g[y].erase(x);
  {
    int gsz=g[y].size();
    if (gsz==0) pos.erase(y);
    if (gsz&1) odd.insert(y);
    else odd.erase(y);
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  if (m&1) {
    printf("No solution\n"); return 0;
  }
  for (int i=0;i<m;i++) {
    int x=readInt(),y=readInt();
    g[x].insert(y);
    g[y].insert(x);
  }
  for (int x=1;x<=n;x++) {
    int deg=g[x].size();
    if (deg&1) odd.insert(x);
    if (deg>0) pos.insert(x);
  }
  while(1) {
    int cur=-1,end=-1;
    if (odd.size()>0) {
      auto it=odd.begin();
      cur=*it;
      ++it;
      end=*it;
    }
    else if (pos.size()>0) cur=*(pos.begin());
    else break;
    stack<int> s;
    vector<int> circuit;
    while(1) {
      if (g[cur].size()==0) {
        circuit.PB(cur);
        if (s.empty()) break;
        printf("cur:%d stop:%d\n",cur,s.top());
        cur=s.top();s.pop();
      }
      else {
        s.push(cur);
        int w=*(g[cur].begin());
        rm(cur,w);
        printf("cur:%d w:%d\n",cur,w);
        cur=w;
      }
    }
    int csz=circuit.size();
    for (int i=0;i<csz;i++) {
      printf("%d ",circuit[i]);
    }
    printf(" end circuit\n");
    for (int i=0;i+2<csz;i+=2) {
      vans.PB(circuit[i]);
      vans.PB(circuit[i+1]);
      vans.PB(circuit[i+2]);
    }
  }
  int asz=vans.size();
  if ((asz*2)/3!=m) {
    printf("No solution\n");
  }
  else {
    for (int i=0;i<asz;i+=3) printf("%d %d %d\n",vans[i],vans[i+1],vans[i+2]);
  }
}
