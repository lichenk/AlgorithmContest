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
const int s=(1000*1000)-1;
const int klim=(s/2)+1;
int p[klim];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<=n;i++) {
    int x=rint();
    x--;
    int y=s-x;
    if (x<y) {
      p[x]|=1;
    }
    else {
      p[y]|=2;
    }
  }
  vector<int> vans;
  int need=0;
  for (int x=0;x<klim;x++) {
    int y=s-x;
    if (p[x]==3) need++;
    else if (p[x]==1) vans.PB(y);
    else if (p[x]==2) vans.PB(x);
  }
  for (int x=0;x<klim;x++) {
    int y=s-x;
    if (p[x]==0&&need>0) {
      need--;
      vans.PB(x);
      vans.PB(y);
    }
  }
  printf("%d\n",(int)vans.size());
  for (auto &w:vans) printf("%d ",w+1);
  printf("\n");
}
