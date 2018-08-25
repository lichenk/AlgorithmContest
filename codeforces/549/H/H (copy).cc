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
ld f[4];
ld d[4];
int sign[4];
ld solve() {
  ld imin=abs(d[0]);
  for (int i=0;i<4;i++)chkmax(imin,abs(d[i]));
  ld lhs=(f[0]+d[0])*(f[1]+d[1]);
  ld rhs=(f[2]+d[2])*(f[3]+d[3]);
  if (lhs>rhs) {
    swap()
  }
  ld imax=2e9;
  for (int k=0;k<100;k++) {
    ld lhs=
  }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b,c,d;cin>>a>>b>>c>>d;
  if (a*d==b*c) {
    printf("0\n");return 0;
  }
  ld final=2e9;
  printf("%.12f\n",(double)final);
}

