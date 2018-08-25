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
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=500000+4;
int n;
int alim,blim,clim;
vector<int> a2i[mn];
int vb[mn],vc[mn];
int b2c[mn],c2b[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint(),alim=rint(),blim=rint(),clim=rint();
  for (int i=0;i<n;i++) {
    int a=rint(),b=rint(),c=rint();
    vb[i]=b,vc[i]=c;
    a2i[a].PB(i);
    chkmax(b2c[b],c);
    chkmax(c2b[c],b);
  }
  for (int c=clim;c>=1;c--) {
    chkmax(c2b[c],c2b[c+1]);
  }
  ll live=0;
  for (int b=blim;b>=1;b--) {
    chkmax(b2c[b],b2c[b+1]);
    live+=clim-b2c[b];
  }
  int bfloor=1,cfloor=1;
  ll ans=0;
  for (int a=alim;a>=1;a--) {
    int newbfloor=bfloor,newcfloor=cfloor;
    for (auto &i:a2i[a]) {
      int b=vb[i],c=vc[i];
      chkmax(newbfloor,b+1); chkmax(newcfloor,c+1);
    }
    for (int b=bfloor;b<newbfloor;b++) {
      int c=max(cfloor,b2c[b]+1);
      int del=clim-c+1;
      //printf("b:%d c:%d del:%d\n",b,c,del);
      live-=del;
    }
    for (int c=cfloor;c<newcfloor;c++) {
      int b=max(newbfloor,c2b[c]+1);
      int del=blim-b+1;
      //printf("c:%d b:%d del:%d\n",c,b,del);
      live-=del;
    }
    bfloor=newbfloor;
    cfloor=newcfloor;
    ans+=live;
    //printf("a:%d live:%lld\n",a,live);
  }
  printf("%lld\n",ans);
}
