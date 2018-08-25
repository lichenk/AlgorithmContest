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
const int mn=10000+4;
int a[mn][4];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k; scanf("%d%d",&n,&k);
  int x=1;
  int forbid=4;
  int cur=2,nxt=4;
  for (int i=0;i<n;i++) {
    for (int j=0;j<4;j++) {
      if(x==forbid) {
        x++;
        forbid+=cur;
        swap(cur,nxt);
      }
      a[i][j]=x;
      x++;
    }
  }
  printf("%lld\n",1ll*k*a[n-1][3]);
  for (int i=0;i<n;i++) {
    for (int j=0;j<4;j++) {
      printf("%lld ",1ll*k*a[i][j]);
    }
    printf("\n");
  }
}

