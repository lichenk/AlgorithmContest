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
int s[20];
int a[20][100000];
int f[1<<20];
int imincache[1<<20][20];
int binsearch(int i, int key, int imin) {
  int imax=s[i];
  //printf("i:%d key:%d imin:%d imax:%d\n",i,key,imin,imax);
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (a[i][imid]<key) imin=imid+1;
    else imax=imid;
    //printf("i:%d key:%d imin:%d imax:%d imid:%d a[i][imid]:%d\n",i,key,imin,imax,imid,a[i][imid]);
  }
  //printf("i:%d key:%d got:%d\n",i,key,imin-1);
  return imin-1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint(),d=rint();
  for (int i=0;i<m;i++) {
    int sz=rint();
    s[i]=sz;
    for (int j=0;j<sz;j++) a[i][j]=rint();
    sort(a[i],a[i]+sz);
  }
  int zlim=1<<m;
  int final=m+1;
  for (int z=1;z<zlim;z++) {
    int popz=__builtin_popcount(z);
    if (popz>=final) continue;
    pii best=MP(-1,-1);
    for (int k=0;k<m;k++) {
      if (z&(1<<k)) {
        int pz=z^(1<<k);
        chkmax(best,MP(f[pz],k));
      }
    }
    int addk=best.snd;
    memcpy(imincache[z],imincache[z^(1<<addk)], sizeof(imincache[0]));
    int x=best.fst;
    while(1) {
      bool ch=0;
      for (int k=0;k<m;k++) {
        if (z&(1<<k)) {
          int gotimin=binsearch(k, x+d+1, imincache[z][k]);
          if (gotimin<0) continue;
          int nx=a[k][gotimin];
          //printf("x:%d nx:%d k:%d\n",x,nx,k);
          if (nx>x) {
            chkmax(imincache[z][k], gotimin+1);
            x=nx;
            ch=1;
            break;
          }
        }
      }
      if (!ch) break;
    }
    f[z]=x;
    //printf("z:%d x:%d\n",z,x);
    if (x>=n-d+1) {
      chkmin(final,popz);
    }
  }
  printf("%d\n",final);
}

