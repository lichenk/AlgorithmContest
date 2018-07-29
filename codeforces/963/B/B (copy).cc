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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();




const int mn=2e5+4;
bool bf(vector<int> inp) 
{
  set<int> g[mn];
  bitset<mn> done;
  done.reset();
  int n=inp.size()-1;
  for (int i=1;i<=n;i++) {
    int pi=inp[i];
    if (pi!=0) {
      g[i].insert(pi); g[pi].insert(i);
    }
  }
  queue<int> q;
  for (int x=1;x<=n;x++) {
    if (g[x].size()%2==0) q.push(x);
  }
  vi ans;
  while(!q.empty()) {
    int x=q.front(); q.pop();
    if (done[x]) continue;
    int xsz=g[x].size();
    if (xsz%2) continue;
    //printf("done:%d\n",x);
    ans.PB(x);
    done[x]=true;
    for (auto &y:g[x]) {
      g[y].erase(x);
      if ((!done[y])&&g[y].size()%2==0) q.push(y);
    }
    g[x].clear();
  }
  if (done.count()!=n) {
    //printf("NO\n");
    return false;
  }
  //printf("YES\n");
  //for (auto &w:ans) {printf("%d\n",w);
  return true;
}

bool smart(vector<int> inp) {
  set<int> g[mn];
  vi vans;
  bitset<mn> done;
  bitset<mn> isleaf;
  done.reset(); isleaf.reset();
  int n=inp.size()-1;
  for (int i=1;i<=n;i++) {
    int pi=inp[i];
    if (pi!=0) {
      g[i].insert(pi); g[pi].insert(i);
    }
  }
  queue<int> q;
  for (int x=1;x<=n;x++) {
    if (g[x].size()==1) {
      q.push(x);
      isleaf[x]=true;
    }
    else if (g[x].size()==0) {
      done[x]=true;
      vans.PB(x);
    }
  }
  while(!q.empty()) {
    int leaf=q.front(); q.pop();
    if(done[leaf]) continue;
    int parent=*(g[leaf].begin());
    printf("Considering leaf:%d parent:%d with leaves:",leaf,parent);
    vector<int> leaves;
    for (auto &otherleaf:g[parent]) {
      if (isleaf[otherleaf]) {
        printf("%d, ",otherleaf);
        leaves.PB(otherleaf);
      }
    }
    printf("\n");
    if (leaves.size()%2) continue;
    for (auto &otherleaf:leaves) {
      g[otherleaf].clear();
      g[parent].erase(otherleaf);
      if (!done[otherleaf]) {
        done[otherleaf]=true;
        vans.PB(otherleaf);
      }
    }
    if (g[parent].size()==0) {
      printf("parent %d has no neighbors done\n",parent);
      if (!done[parent]) {
        done[parent]=true;
        vans.PB(parent);
      }
    }
    else {
      if (!isleaf[parent]) {
        printf("parent %d is leaf\n",parent);
        isleaf[parent]=true;
        q.push(parent);
      }
    }
  }
  assert(done.count()==vans.size());
  if (vans.size()!=n) return false;
  /*{
    reverse(vans.begin(),vans.end());
    printf("YES\n");
    for (auto &w:vans) printf("%d\n",w);
  }*/
  return true;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  vector<int> inp(n+1);
  for (int i=1;i<=n;i++) inp[i]=rint();
  bool bfgot=bf(inp);
  bool smans=smart(inp);
  if (bfgot&&!smans) {
    printf("BAD\n");
    assert(0);
  }
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