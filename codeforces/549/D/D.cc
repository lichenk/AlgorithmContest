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
const int mn=104;
string tmp[mn];
ll a[mn][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; cin>>n>>m;
  for (int i=0;i<n;i++) cin>>tmp[i];
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) a[x][y]=(tmp[x][y]=='W')?1:-1;
  int ans=0;
  for (int s=n+m;s>=0;s--) {
    for (int x=0;x<n;x++) {
      int y=s-x;
      if (0<=y&&y<m&&a[x][y]!=0) {
        ans++;
        ll k=a[x][y];
        //printf("x:%d y:%d k:%lld\n",x,y,k);
        for (int i=0;i<=x;i++) for (int j=0;j<=y;j++) a[i][j]-=k;
      }
    }
  }
  printf("%d\n",ans);
}

