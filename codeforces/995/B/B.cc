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
const int mn=102*2;
int a[mn];
int vl[mn],vr[mn];
int vd[mn];
//int al[mn],ar[mn];
const int L=1,R=2;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<2*n;i++) {
  	a[i]=rint()-1;
  }
  memset(vl,-1,sizeof vl);memset(vr,-1,sizeof vr);
  for (int p=0;p<2*n;p++) {
  	int x=a[p];
  	if (vl[x]==-1) {vl[x]=p; vd[p]=R;}
  	else {vr[x]=p; vd[p]=L;}
  }
  int cost=0;
  for (int x=0;x<n;x++) cost+=vr[x]-vl[x]-1;
  int save=0;
  for (int x=0;x<n;x++) {
    int xl=vl[x],xr=vr[x];
    for (int p=xl+1;p<=xr-1;p++) {
      int y=a[p];
      int yl=vl[y],yr=vr[y];
      if (yl<xl && xl<yr && yr<xr) save++;
    }
  }
  int ans=cost-save;
  printf("%d\n",ans);
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