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
const int mn=1006;
bitset<mn> a[mn];
int ans=0;
int n,m; clock_t start;
int dx[]={1, 1,2, 2,5,0};
int dy[]={2,-2,1,-1,0,5};
void bf() {
  time_t now=clock();
  if (now-start>0.78 * CLOCKS_PER_SEC) {
    printf("%d\n",ans); exit(0);
  }
  srand(now);
  for (int x=0;x<n;x++) a[x].reset();
  int cand=0;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if (a[x][y]) continue;
    if (rand()&1) {
      cand++;
      //printf("x:%d y:%d\n",x,y);
      for (int k=0;k<4;k++) {
        int nx=x+dx[k],ny=y+dy[k];
        if (ny>=0) a[nx][ny]=true;
      }
    }
  }
  //printf("cand:%d\n",cand);
  chkmax(ans,cand);
}

int main() 
{
  start=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  ans=0;
  while(1) bf();
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