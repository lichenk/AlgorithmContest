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
const int mn=60;
int vcost[mn][mn][mn];
int n,tlim;
int f[mn][mn]; // f[t][vtx]
int dg[mn][mn][mn]; // g[dest][ch][vtx]
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();tlim=rint(); int q=rint();
  for (int t=0;t<tlim;t++) {
    for (int x=0;x<n;x++) {
      for (int y=0;y<n;y++) vcost[t][x][y]=rint();
    }
    for (int k=0;k<n;k++) {
      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
          chkmin(vcost[t][i][j],vcost[t][i][k]+vcost[t][k][j]);
        }
      }
    }
    //printf("t:%d %d\n",t,vcost[t][1][3]);
  }
  for (int d=0;d<n;d++) {
    for (int t=0;t<tlim;t++) {
      //memcpy(f[t],vcost[t][d],sizeof f[t]);
      for (int x=0;x<n;x++) {
        f[t][x]=vcost[t][x][d];
      }
    }
    auto &g=dg[d];
    {
      int c=0;
      memcpy(g[c],f[0],sizeof f[0]);
      for (int t=1;t<tlim;t++) {
        for (int x=0;x<n;x++) {
          chkmin(g[c][x],f[t][x]);
          /*if (x==0&&d==1) {
            printf("x:%d d:%d\n",x,d);
            printf("t:%d g:%d f:%d\n",t,g[c][x],f[t][x]);
          }
          if (x==1&&d==3) {
            printf("x:%d d:%d\n",x,d);
            printf("t:%d g:%d f:%d\n",t,g[c][x],f[t][x]);
          }*/
        }
      }
    }
    for (int c=1;c<n;c++) {
    //for (int c=1;c<=1;c++) { // CHANGEME
      for (int t=0;t<tlim;t++) {
        for (int x=0;x<n;x++) {
          int res=1e9;
          for (int y=0;y<n;y++) {
            chkmin(res,g[c-1][y]+vcost[t][x][y]);
          }
          f[t][x]=res;
          //chkmin(f[t][x],g[c-1][x]);
        }
      }
      memcpy(g[c],f[0],sizeof f[0]);
      for (int t=1;t<tlim;t++) {
        for (int x=0;x<n;x++) chkmin(g[c][x],f[t][x]);
      }
    }
  }
  for (int qi=0;qi<q;qi++) {
    int s=rint(),t=rint(),k=rint();
    --s; --t;
    chkmin(k,n-1);
    int ans=dg[t][k][s];
    printf("%d\n",ans);
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