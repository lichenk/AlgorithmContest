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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=2e5+2;
int aa[mn],b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) aa[i]=rint();
  sort(aa,aa+n);
  int bsz=0;
  b[bsz++]=aa[0];
  for (int i=1;i<n;i++) {
    if (aa[i]!=aa[i-1]) b[bsz++]=aa[i];
  }
  n=bsz;
  int ans=0;
  for (int i=0;i<n;i++) {
    int m=b[i];
    if (m==1) continue;
    int tlim=1000000+m;
    for (int t=m+m;t<=tlim;t+=m) {
      int imin=0,imax=n;
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (b[imid]<t) imin=imid+1;
        else imax=imid;
      }
      imin--;
      //printf("t:%d b[imin]:%d\n",t,b[imin]);
      int diff=b[imin]-(t-m);
      //if (diff<0) break;
      chkmax(ans,diff);
    }
  }
  printf("%d\n",ans);
}

