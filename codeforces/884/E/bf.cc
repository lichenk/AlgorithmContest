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

int n,m;
bool a[1<<12][1<<14];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(int x, int y) {
  if (!(0<=x&&x<n&&0<=y&&y<m)) return;
  if (!a[x][y]) return;
  a[x][y]=0;
  for (int k=0;k<4;k++) {
    dfs(x+dx[k],y+dy[k]);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d%d\n",&n,&m);
  int cur=0,prev=1;
  int ans=0;
  for (int nn=0;nn<n;nn++) {
    for (int x=0;x<(m>>2);x++) {
      char c='\n'; while(c=='\n') scanf("%c",&c);
      //char c=ss[x];
      int got;
      if ('0'<=c&&c<='9') {
        got=c-'0';
      }
      else {
        assert('A'<=c);
        assert(c<='F');
        got=c-'A'+10;
      }
      //printf("%d %d: %c %d got:%d\n",nn,x,c,c,got);
      int x4=x<<2;
      for (int k=3;k>=0;k--) {
        int y=x4+k;
        if (got&1) {
          a[nn][y]=1;
        }
        got>>=1;
      }
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      if (a[x][y]) {
        ans++; dfs(x,y);
      }
    }
  }
  printf("%d\n",ans);
}
