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
const int mn=2004;
int a[mn];
int inva[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int x=0;x<n;x++) a[x]=rint()-1;
  vector<int> p; for (int x=0;x<n;x++) p.PB(x);
  int ans=0;
  do {
    bool ok=1;
    for (int x=0;x<n;x++) if (p[x]==x) {ok=0; break;}
    if (!ok) continue;
    for (int x=0;x<n;x++) if (!(p[x]==a[x]||a[x]==-2)) {ok=0; break;}
    if (!ok) continue;
    ans++;
  }while(next_permutation(p.begin(),p.end()));
  printf("%d\n",ans);
}
