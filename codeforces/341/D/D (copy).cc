#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
int n,q;
int qt[mn],qx[2][mn],qy[2][mn]
ll qv[mn], vfinal[mn];

void upd(int xl, int xh, int yl, int yh) {
  
}

void go(int k) {
  int msk=1LL<<k;

}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint();
  q=rint();
  for (int i=0;i<q;i++) {
    qt[i]=rint();
    for (int z=0;z<2;z++) {
      qx[z][i]=rint();
      qy[z][i]=rint();
    }
    if (qt[i]==2) qv[i]=rlong();
  }
  for (int k=0;k<62;k++) {
    go(k);
  }
  for (int i=0;i<q;i++) {
    if (qt[i]==1) printf("%lld\n",vfinal[i]);
  }
}

