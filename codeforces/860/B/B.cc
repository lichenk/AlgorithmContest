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

const int mn=70000;
const int mc=9;
char vs[mn][mc+2];
vector<ll> vb[9];
inline ll MK(int x, int y) {
  return (((ll)x)<<32)|y;
}
int cache[mc][mc];

void solve(int i) {
  for (int x=0;x<mc;x++) {
    int sum = 0;
    for (int y = x; y < mc; y++) {
      sum *= 10;
      sum += vs[i][y] - '0';
      cache[x][y]=sum;
    }
  }
  for (int len=0;len<mc;len++) {
    for (int x=0;x<mc-len;x++) {
      int y=x+len;
      ll target=MK(cache[x][y],0);
      int imin=0,imax=vb[len].size();
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (vb[len][imid]<target) imin=imid+1;
        else imax=imid;
      }
      bool uniq=1;
      if (imin<vb[len].size()) {
        ll got=vb[len][imin];
        if (got>>32==cache[x][y]&&(got&0xffffffff)!=i) uniq=0;
      }
      if (imin+1<vb[len].size()) {
        ll got=vb[len][imin+1];
        if (got>>32==cache[x][y]&&(got&0xffffffff)!=i) uniq=0;
      }
      if (uniq) {
        for (int k=x;k<=y;k++) printf("%c",vs[i][k]);
        printf("\n",len);
        return;
      }
    }
  }
  assert(0);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%s\n",vs[i]);
    for (int x=0;x<mc;x++) {
      int sum=0;
      for (int y=x;y<mc;y++) {
        sum*=10;
        sum+=vs[i][y]-'0';
        vb[y-x].PB(MK(sum,i));
      }
    }
  }
  for (int len=0;len<mc;len++) {
    sort(vb[len].begin(),vb[len].end());
    auto it=unique(vb[len].begin(),vb[len].end());
    size_t newlen=distance(vb[len].begin(),it);
    vb[len].resize(newlen);
  }
  for (int i=0;i<n;i++) {
    solve(i);
  }
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}