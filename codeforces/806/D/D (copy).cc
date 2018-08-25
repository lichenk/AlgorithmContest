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
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=2004;
int a[mn][mn];
ll vans[mn];
ll f[2][mn][2];
int main()
{
  time_t _start= clock();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) {
    for (int j=1;j<n-i;j++) {
      int x=rint();
      //printf("%d->%d\n",i,i+j);
      a[i][i+j]=x;
      a[i+j][i]=x;
    }
  }
  for (int x=0;x<n;x++) {
    vans[x]=INF;
  }
  int cur=0,nxt=1;
  memset(f[cur],0,sizeof f[cur]);
  for (int k=2;k<=n;k++) {
    if (clock()-_start>=2.3 * CLOCKS_PER_SEC) break;
    for (int x=0;x<n;x++) {
      for (int ns=0;ns<2;ns++) {
        ll ans=INF;
        for (int y=0;y<n;y++) {
          if (x==y) continue;
          for (int s=0;s<=ns;s++) {
            ll cand=f[cur][y][s]+((ll)a[x][y]*(ll)(ns-s+1));
            chkmin(ans, cand);
            if (ns==0) chkmin(vans[x], cand+(ll)(n-k)*(ll)a[x][y]);
          }
        }
        f[nxt][x][ns]=ans;
        printf("k:%d x:%d ns:%d ans:%lld\n",k,x,ns,ans);
      }
    }
    swap(cur,nxt);
  }
  for (int x=0;x<n;x++) printf("%lld\n",vans[x]);
}
