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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}

const int mn = 3e5+4;  // limit for array size
int vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  set<int> s;
  for (int x=1;x<=n;x++) s.insert(x);
  for (int ts=0;ts<m;ts++) {
    int l=rint(),r=rint(),val=rint();
    for (auto it=s.lower_bound(l); it!=s.end();) {
      int x=*it;
      if (x==val) {
        ++it; continue;
      }
      if (x>r) break;
      vans[x]=val;
      it=s.erase(it);
    }
  }
  for (int x=1;x<=n;x++) {
    printf("%d ",vans[x]);
  }
  printf("\n");
}

