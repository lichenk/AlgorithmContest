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
const int mn=100000;
int a[mn];
ll g(int i, int j) {
    ll sum = 0;
    for (int k = min(i, j) + 1; k <= max(i, j); k = k + 1)
        sum = sum + a[k];
    return sum;
}
int main()
{
	int n=rint();
  ll ans=1LL<<62;
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
    if (i==j) continue;
    ll g1=g(i,j);
    ll res=g1*g1+(i-j)*(i-j);
    //printf("i:%d j:%d g1:%lld res:%lld\n",i,j,g1,res);
    chkmin(ans,res);
  }
  printf("%lld\n",ans);
}

