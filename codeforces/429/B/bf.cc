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
const ll INF=1e18;
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
int f[2][2][mn][mn];
int a[mn][mn];
int n,m;
bool ok(int x, int y) {
  return 1<=x&&x<=n&&1<=y&&y<=m;
}
void init(int xz,int yz) {
  int dx,dy,xs,ys,xt,yt;
  if (!xz) dx=1,xs=1,xt=n;
  else dx=-1,xs=n,xt=1;
  if (!yz) dy=1,ys=1,yt=m;
  else dy=-1,ys=m,yt=1;
  for (int x=xs;x!=xt+dx;x+=dx) {
    for (int y=ys;y!=yt+dy;y+=dy) {
      chkmax(f[xz][yz][x+dx][y],f[xz][yz][x][y]+a[x][y]);
      chkmax(f[xz][yz][x][y+dy],f[xz][yz][x][y]+a[x][y]);
    }
  }
  //for (int x=1;x<=n;x++) {for (int y=1;y<=m;y++) {printf("%d ",f[xz][yz][x][y]+a[x][y]);} printf("\n");} printf(" end %d %d.\n",xz,yz);
}
pair<int, pair<int,int> > go(int xz, int yz, int cx, int cy, int choosex) {
  int dx=xz?1:-1; int dy=yz?1:-1;
  int x=cx,y=cy;
  if (choosex) x+=dx;
  else y+=dy;
  if (ok(x,y)) {
    return MP(f[xz][yz][x][y]+a[x][y],MP(x,y));
  }
  //if ((cx==1||cx==n)&&(cy==1||cy==m)) return MP(0,MP(cx,cy));
  return MP(-1,MP(-1,-1));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint(),m=rint();
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=rint();
  for (int xz=0;xz<2;xz++) for (int yz=0;yz<2;yz++) init(xz,yz);
  int final=0;
  for (int x=1;x<=n;x++) for (int y=1;y<=m;y++) {
    for (int zt=0;zt<(1<<4);zt++) {
      set<pair<int,int> > st;
      int z=zt;
      int ans=0;
      bool fail=0;
      for (int xz=0;xz<2;xz++) for (int yz=0;yz<2;yz++) {
        auto got=go(xz,yz,x,y,z&1);
        //if(zt==6&&x==2&&y==3) printf("xz:%d yz:%d x:%d y:%d zt:%d got:%d %d %d\n",xz,yz,x,y,zt,got.fst,got.snd.fst,got.snd.snd);
        if (got.fst==-1) fail=1;
        ans+=got.fst;
        st.insert(got.snd);
        z=z>>1;
      }
      if (st.size()==4&&fail==0) {
        chkmax(final,ans);
      }
    }
  }
  printf("%d\n",final);
}

