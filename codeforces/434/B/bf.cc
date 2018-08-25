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
bitset<mn> a[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(); int q=rint();
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      a[i][j]=rint();
    }
  }
  for (int i=0;i<q;i++) {
    int qop=rint(),qx=rint()-1,qy=rint()-1;
    if (qop==1) {
      a[qx][qy]=!a[qx][qy];
    }
    else{int ans=0;
    for (int x1=0;x1<n;x1++) for (int x2=x1;x2<n;x2++) for (int y1=0;y1<m;y1++) for (int y2=y1;y2<m;y2++) {
      bool side=0;
      if ((x1==qx||x2==qx)&&(y1<=qy&&qy<=y2)) side=1;
      if ((y1==qy||y2==qy)&&(x1<=qx&&qx<=x2)) side=1;
      if (!side) continue;
      bool ok=1;
      for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) if (!a[x][y]) {ok=0; break;}
      if (ok) chkmax(ans,(x2-x1+1)*(y2-y1+1));
    }
    printf("%d\n",ans);}
  }
}

