#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1004;
int vl[mn][mn],vr[mn][mn];
bitset<mn> a[mn],oa[mn];
int vans[mn];
int qop[mn],vqx[mn],vqy[mn];
int q;
const int INF=10000;
void solve(int n, int m) {
  for (int y=0;y<m;y++) {
    {int lastl=INF;
    for (int x=0;x<n;x++) {
      if (a[x][y]) chkmin(lastl,x);
      else lastl=INF;
      vl[x][y]=lastl;
    }}
    {int lastr=-INF;
    for (int x=n-1;x>=0;x--) {
      if (a[x][y]) chkmax(lastr,x);
      else lastr=-INF;
      //printf("x:%d y:%d lastr:%d\n",x,y,lastr);
      vr[x][y]=lastr;
    }}
  }
  for (int i=0;i<q;i++) {
    int qx=vqx[i],qy=vqy[i];
    if (qop[i]==1) {
      if (a[qx][qy]) {
        a[qx][qy]=0;
        for (int x=qx;x>=0;x--) chkmin(vr[x][qy],qx-1);
        for (int x=qx;x<n;x++) chkmax(vl[x][qy],qx+1);
      }
      else {
        a[qx][qy]=1;
        int bestl,bestr;
        for (int x=qx;x>=0;x--) {
          if (a[x][qy]) bestl=x;
          else break;
        }
        for (int x=qx;x<n;x++) {
          if (a[x][qy]) bestr=x;
          else break;
        }
        for (int x=bestl;x<=bestr;x++) {
          vl[x][qy]=bestl;
          vr[x][qy]=bestr;
        }
      }
    }
    else {
      int ans=0;
      {
        {
          int bestl=vl[qx][qy],bestr=vr[qx][qy];
          for (int y=qy;y<m;y++) {
            chkmax(bestl,vl[qx][y]);
            chkmin(bestr,vr[qx][y]);
            //printf("y:%d bl:%d br:%d\n",y,bestl,bestr);
            chkmax(ans,(bestr-bestl+1)*(y-qy+1));
          }
        }
        {
          int bestl=vl[qx][qy],bestr=vr[qx][qy];
          for (int y=qy;y>=0;y--) {
            chkmax(bestl,vl[qx][y]);
            chkmin(bestr,vr[qx][y]);
            chkmax(ans,(bestr-bestl+1)*(qy-y+1));
          }
        }
      }
      int tmp=a[qx][qy];
      //printf("i:%d qx:%d qy:%d a[qx][qy]:%d ans:%d\n",i,qx,qy,tmp,ans);
      chkmax(vans[i],ans);
    }
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(); q=rint();
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      oa[i][j]=rint();
    }
    a[i]=oa[i];
  }
  for (int i=0;i<q;i++) {
    qop[i]=rint(),vqx[i]=rint()-1,vqy[i]=rint()-1;
  }
  solve(n,m);
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j]=oa[j][i];
  for (int i=0;i<q;i++) swap(vqx[i],vqy[i]);
  //printf("----=====----\n");
  solve(m,n);
  for (int i=0;i<q;i++) {
    if (qop[i]==2) printf("%d\n",vans[i]);
  }
}

