#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=2000;
bitset<mn> g[mn],a,b,diag;

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int x=0;x<n;x++) {
    string s; cin>>s;
    for (int y=0;y<n;y++) {
      g[x][y]=s[y]-'0';
    }
  }
  int ans=0;
  for (int t=-1;t<=1;t+=2) {
    for (int d=n;d>=1;d--) {
      for (int x=0;x<n;x++) {
        int y=x+t*d;
        if (0<=y&&y<n) {
          if ((a[x]!=b[y]) != g[x][y]) {
            a[x]=!a[x]; b[y]=!b[y];
            //printf("x:%d y:%d\n",x,y);
            ++ans;
          }
        }
      }
    }
    diag^= a^b;
    a.reset(); b.reset();
  }
  for (int x=0;x<n;x++) {
    if (diag[x]!=g[x][x]) {
      ++ans;
      //printf("x:%d y:%d\n",x,x);
    }
  }
  printf("%d\n",ans);
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