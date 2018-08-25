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
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=1e5+2;
pii a[mn];
bitset<mn> seen;
vi gv;
void dfs(int x) {
  if (seen[x]) return;
  seen[x]=true;
  gv.PB(a[x].snd);
  dfs(a[x].snd);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=MP(rint(),i);
  sort(a,a+n);
  vvi res;
  for (int x=0;x<n;x++) {
    if (!seen[x]) {
      gv.clear();
      dfs(x);
      sort(gv.begin(),gv.end());
      res.PB(gv);
    }
  }
  printf("%d\n",(int)res.size());
  for (auto &w:res) {
    printf("%d ",(int)w.size());
    for (auto &x:w) printf("%d ",x+1);
    printf("\n");
  }
}





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