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
short f[2][mn][mn];
bitset<mn> knap;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),l=rint(),r=rint();
  for (int i=0;i<n;i++) inp[i]=rint();
  knap[0]=true;
  for (int i=0;i<n;i++) if (rint()==0) knap|=knap<<inp[i]; else a.PB(inp[i]);
  memset(f,-1,sizeof f);
  //int xlim=r,ylim=r-l;
  f[1][0][0]=0;
  short sum=0;
  for (const auto w:a) {
    printf("w:%d\n",w);
    for (int t=0;t<2;t++) for (int x=0;x<=sum;x++) {
      int y=sum-x;
      short now=f[t][x][y];
      if (t+x+y==0) printf("now:%d\n",now);
      if (now==-1) continue;
      printf("t:%d x:%d y:%d now:%d\n",t,x,y,now);
      chkmax(f[t][x+w][y],now);
      chkmax(f[t][x][y+w],(short)(now+(short)1));
      if (t==1) chkmax(f[0][x][y],now);
    }
    sum+=w;
  }
  for (int t=0;t<2;t++) for (int x=0;x<=sum;x++) for (int y=sum-1;y>=0;y--) chkmax(f[t][x][y],f[t][x][y+1]);
  short final=0;
  for (int s=0;s<=l;s++) {
    if (!knap[s]) continue;
    printf("knap s:%d\n",s);
    for (int x=l-s;x<=r;x++) {
      int y=r-x;
      {
        short cand=max(f[1][x][y],(short)(f[0][x][y]+(short)1));
        printf("x:%d y:%d cand:%d\n",x,y,cand);
        chkmax(final,cand);
      }
    }
  }
  printf("%d\n",(int)final);
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