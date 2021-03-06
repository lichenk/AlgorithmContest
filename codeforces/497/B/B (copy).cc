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
const int mn=1e5+4;
int a[mn];
int b[mn];
int n;
int f(int start, int t) {
  int imin=start+1,imax=n+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    int da=a[imid]-a[start];
    int db=b[imid]-b[start];
    if (da<t&&db<t) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
vector<pair<int,int> > vans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint();
  for (int i=1;i<=n;i++) {
    int x=rint();
    if (x==1) a[i]++;
    else b[i]++;
  }
  for (int i=1;i<=n;i++) {a[i]+=a[i-1]; b[i]+=b[i-1];}
  for (int t=1;t<=n;t++) {
    int sa=0,sb=0;
    int x=0;
    while(x<n) {
      int y=f(x,t);
      int da=a[y]-a[x];
      int db=b[y]-b[x];
      if (y!=n+1) {
        if ((da>=t) == (db>=t)) {
          printf("t:%d. %d->%d. da:%d db:%d. n+1:%d\n",t,x,y,da,db,n+1);
        }
        assert((da>=t) != (db>=t));
      }
      if (da>=t) sa++;
      else sb++;
      //printf("t:%d. %d->%d\n",t,x,y);
      x=y;
    }
    if (x==n&&sa!=sb) {
      int s=max(sa,sb);
      vans.PB(MP(s,t));
    }
  }
  sort(vans.begin(),vans.end());
  printf("%d\n",(int)vans.size());
  for (auto &w:vans) printf("%d %d\n",w.fst,w.snd);
}

