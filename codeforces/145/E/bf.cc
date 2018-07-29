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

const int mn=1e6+2;
string inp;
typedef struct STTV {
  int x,y,xy,yx;
} STV;
typedef bool STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    STV ans=x;
    if (y) {
      swap(ans.x,ans.y); swap(ans.xy,ans.yx);
    }
    return ans;
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
    STV ans;
    ans.x=l.x+r.x;
    ans.y=l.y+r.y;
    int gen=max(ans.x,ans.y);
    ans.xy=max(gen,max(l.xy+r.y,l.x+r.xy));
    ans.yx=max(gen,max(l.yx+r.x,l.y+r.yx));
    //ans.xy=max(max(gen,l.x+r.y),max(l.xy,r.xy));
    //ans.yx=max(max(gen,l.y+r.x),max(l.yx,r.yx));
    //printf("l:%d %d r:%d %d xy:%d\n",l.x,l.y,r.x,r.y,ans.xy);
    return ans;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return delta;
  }

  STD initNeutralDelta() {
    return false;
  }

  bool isNeutralDelta(STD delta) {
    return !delta;
  }

  STV getInitValue(int i) {
    STV ans;
    if (inp[i]=='4') {
      ans.x=1; ans.y=0;
    }
    else {
      ans.x=0; ans.y=1;
    }
    //printf("i:%d x:%d y:%d\n",i,ans.x,ans.y);
    ans.xy=ans.yx=1;
    return ans;
  }

  STV getNeutralValue() {
    STV ans;ans.x=ans.y=ans.xy=ans.yx=0;
    return ans;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1^delta2;
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  STV *value;
  STD *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STV joinValueWithDelta(STV value, STD delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }


  void pushDelta(int root, int left, int right) {
    value[root] = joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
    delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
    delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
    delta[root] = getNeutralDelta();
  }

  SegmentTreeFast(int n) {
    _cache_neutral_delta = initNeutralDelta();
    gn = n;
    value = new STV[4 * n];
    delta = new STD[4 * n];
    init(0, 0, n - 1);
  }

  void init(int root, int left, int right) {
    if (left == right) {
      value[root] = getInitValue(left);
      delta[root] = getNeutralDelta();
    } else {
      int mid = (left + right) >> 1;
      init(2 * root + 1, left, mid);
      init(2 * root + 2, mid + 1, right);
      value[root] = queryOperation(value[2 * root + 1], value[2 * root + 2]);
      delta[root] = getNeutralDelta();
    }
  }

  STV query(int from, int to) {
    int n=gn;
    return query(from, to, 0, 0, n - 1);
  }

  STV query(int from, int to, int root, int left, int right) {
    if (from == left && to == right)
      return joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
    pushDelta(root, left, right);
    int mid = (left + right) >> 1;
    if (from <= mid && to > mid)
      return queryOperation(
          query(from, min(to, mid), root * 2 + 1, left, mid),
          query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right));
    else if (from <= mid)
      return query(from, min(to, mid), root * 2 + 1, left, mid);
    else if (to > mid)
      return query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right);
    else
      assert(0);
  }

  void modify(int from, int to, STD delta) {
    //printf("from:%d to:%d\n",from,to);
    modify(from, to, delta, 0, 0, gn - 1);
  }

  void modify(int from, int to, STD delta, int root, int left, int right) {
    if (from == left && to == right) {
      this->delta[root] = joinDeltas(this->delta[root], delta);
      return;
    }
    pushDelta(root, left, right);
    int mid = (left + right) >> 1;
    if (from <= mid)
      modify(from, min(to, mid), delta, 2 * root + 1, left, mid);
    if (to > mid)
      modify(max(from, mid + 1), to, delta, 2 * root + 2, mid + 1, right);
    value[root] = queryOperation(
        joinValueWithDelta(value[2 * root + 1], deltaEffectOnSegment(this->delta[2 * root + 1], mid - left + 1)),
        joinValueWithDelta(value[2 * root + 2], deltaEffectOnSegment(this->delta[2 * root + 2], right - mid)));
  }
};


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; cin>>n>>m;
  cin>>inp;
  SegmentTreeFast segt = SegmentTreeFast(n);
  for (int i=0;i<m;i++) {
    string t; cin>>t;
    if (t[0]=='c') {
      int l,r; cin>>l>>r;
      int ans=segt.query(l-1,r-1).xy;
      printf("%d\n",ans);
    }
    else {
      int l,r; cin>>l>>r;
      segt.modify(l-1,r-1,true);
    }
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