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
const int mn=10000+4;
int a[mn],b[mn];
vector<int> v[2];
bitset<mn> vknap[mn][2];
int sufsum[mn][2];
int n,l,r;
const int I=1,U=0;
bool f(int imid) {
  if (imid==0) return true;
  int take=imid-1;
  int si=v[I].size();
  int sl=(l==0)?0:vknap[take][1]._Find_next(l-1);
  if (sl>r) return false;
  int ans=0;
  //printf("sl:%d\n",sl);
  for (int i=0;i<take;i++) {
    int w=v[I][i];
    if (sl>=r) break;
    //printf("w:%d add\n",w);
    ans++;
    sl+=w;
  }
  if (sl<=r) ans++;
  return ans>=imid;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),l=rint(),r=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) b[i]=rint();
  for (int i=0;i<n;i++) v[b[i]].PB(a[i]);
  sort(v[I].begin(),v[I].end());
  int si=v[I].size();
  {
    auto &oknap=vknap[si][0];
    oknap[0]=true;
    for (auto &w:v[U]) {
      oknap|=oknap<<w;
    }
  }
  for (int x=si-1;x>=0;x--) {
    int w=v[I][x];
    vknap[x][0]=vknap[x+1][0]|(vknap[x+1][0]<<w);
    vknap[x][1]=vknap[x+1][0]|(vknap[x+1][1]<<w);
    //printf("x:%d sufsum:%d\n",x,sufsum[x]);
  }
  //dbg("F %d\n",f(2)); return 0;
  int imin=0,imax=si+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (f(imid)) imin=imid+1;
    else imax=imid;
  }
  int final=max(0,imin-1);
  printf("%d\n",final);
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