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
ll x[2],y[2];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&x[0],&y[0]);
  scanf("%lld%lld",&x[1],&y[1]);
  int ans=0;
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    ll a,b,c; scanf("%lld%lld%lld\n",&a,&b,&c);
    int pos=0;
    for (int t=0;t<2;t++) {
      ll sign=a*x[t]+b*y[t]+c;
      if (sign>0) pos++;
    }
    if (pos==1) ans++;
  }
  printf("%d\n",ans);
}

