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
const int mn=100000;
const int mk=12;
int a[mk][mn];
const int me=mn+mk;
int r[me][2];
int vquery[mn][2];
int f[mn];
int vquerysz=0;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint(),q=rint();
  for (int x=0;x<k;x++) {
    for (int y=0;y<n;y++) {
      a[x][y]=rint();
    }
  }
  int e=k+1;
  for (int i=0;i<q;i++) {
    int t=rint(),x=rint()-1,y=rint()-1;
    if (t!=3) {
      r[e][0]=(t==2)?-x:x;
      r[e][1]=y;
      ++e;
    }
    else {
      vquery[vquerysz][0]=x;
      vquery[vquerysz][1]=y;
      ++vquerysz;
    }
  }
  for (int i=0;i<vquerysz;i++) {
    int targx=vquery[i][0];
    int c=vquery[i][1];
    for (int x=1;x<=k;x++) {
      f[x]=a[x][c];
    }
    for (int x=k+1;x<=targx;x++) {
      int p1=r[x][0]; int p2=r[x][1];
      if (p1<0) {
        f[x]=min(f[-p1],f[p2]);
      }
      else {
        f[x]=max(f[p1],f[p2]);
      }
      //printf("c:%d x:%d f:%d\n",c,x,f[x]);
    }
    printf("%d\n",f[targx]);
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