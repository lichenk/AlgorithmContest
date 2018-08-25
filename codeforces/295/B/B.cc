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
const int mn=502;
int od[mn][mn];
int d[mn][mn];
int a[mn];
ll vfinal[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) od[x][y]=rint();
  for (int i=0;i<n;i++) a[i]=rint()-1;
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    d[x][y]=od[a[n-1-x]][a[n-1-y]];
  }
  for (int k=0;k<n;k++) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        chkmin(d[i][j],d[i][k]+d[k][j]);
      }
    }
    ll ans=0;
    for (int i=0;i<=k;i++) for (int j=0;j<=k;j++) {
      ans+=d[i][j];
    }
    vfinal[k]=ans;
  }
  for (int k=n-1;k>=0;k--) printf("%lld ",vfinal[k]);
  printf("\n");
}

