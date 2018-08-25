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
string a[102];
int x2y[102];
int n; 
void go() {
  vector<pii> v;
  for (int x=0;x<n;x++) {
    bool ok=0;
    for (int y=0;y<n;y++) if (a[x][y]=='.') {
      ok=1;
      v.PB(MP(x,y)); break;
    }
    if (!ok) return;
  }
  for (auto &w:v) printf("%d %d\n",w.fst+1,w.snd+1); exit(0);
}
void go2() {
  vector<pii> v;
  for (int x=0;x<n;x++) {
    bool ok=0;
    for (int y=0;y<n;y++) if (a[y][x]=='.') {
      ok=1;
      v.PB(MP(y,x)); break;
    }
    if (!ok) return;
  }
  for (auto &w:v) printf("%d %d\n",w.fst+1,w.snd+1); exit(0);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
  for (int x=0;x<n;x++) cin>>a[x];
  go(); go2();
  printf("-1\n");
}

