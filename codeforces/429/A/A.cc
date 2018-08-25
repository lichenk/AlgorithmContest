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
const int mn=1e5+4;
int init[mn],goal[mn];
vector<int> vfinal;
vector<int> g[mn];
void f(int x, int p, int a, int b) {
  if ((init[x]^a)!=goal[x]) {
    vfinal.PB(x);
    a^=1;
  }
  for (auto &y:g[x]) {
    if (y==p) continue;
    f(y,x,b,a);
  }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n-1;i++) {
    int x=rint(),y=rint();
    g[x].PB(y);
    g[y].PB(x);
  }	
  for (int x=1;x<=n;x++) init[x]=rint();
  for (int x=1;x<=n;x++) goal[x]=rint();
  f(1,-1,0,0);
  printf("%d\n",(int)(vfinal.size()));
  for (auto &w:vfinal) printf("%d\n",w);
}

