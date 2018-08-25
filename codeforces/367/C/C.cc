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

ll comp(ll n) {
  n--;
  if (n%2==0) {
    n/=2;
    return 2*n*n+n+1;
  }
  else {n=(n+1)/2; return 2*n*n;}
}
ll solve(ll key) {
  ll imin=0,imax=100005;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    ll got=comp(imid);
    if (got<=key) imin=imid+1;
    else imax=imid;
  }
  return imin-1;
}

int w[100000];
int main() 
{
  //for (ll n=1;n<=10;n++) printf("n:%lld ans:%lld\n",n,comp(n));
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    rint(); w[i]=rint();
  }
  sort(w,w+m,greater<int>());
  int got=solve(n);
  ll ans=0;
  for (int i=0;i<min(m,got);i++) {
    ans+=w[i];
  }
  printf("%lld\n",ans);
}

